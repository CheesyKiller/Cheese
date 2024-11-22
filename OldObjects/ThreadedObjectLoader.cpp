#include "ThreadedObjectLoader.h"

import WindowManager;

#include "BlenderObjectReader.h"
#include "ShaderProgram.h"
#include "BlenderObject.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>

std::shared_ptr<ThreadedObjectLoader> ThreadedObjectLoader::instance;

ThreadedObjectLoader::ThreadedObjectLoader() {
    stop = false;
    writer = std::thread(&ThreadedObjectLoader::writer_thread, this);
    update_detector = std::thread(&ThreadedObjectLoader::update_detector_thread, this);
    draw_thread_handle = std::thread(&ThreadedObjectLoader::draw_thread, this);
}

std::shared_ptr<ThreadedObjectLoader> ThreadedObjectLoader::getInstance() {
    if (instance == nullptr) {
        instance = std::shared_ptr<ThreadedObjectLoader>(new ThreadedObjectLoader());
    }
    return instance;
}

ThreadedObjectLoader::~ThreadedObjectLoader() {
    stop = true;
    cv.notify_all();

    if (writer.joinable()) {
        writer.join();
#ifdef _DEBUG
        std::cout << "Writer thread joined" << std::endl;
#endif
    }

    if (update_detector.joinable()) {
        update_detector.join();
#ifdef _DEBUG
        std::cout << "Update detector thread joined" << std::endl;
#endif
    }

    if (draw_thread_handle.joinable()) {
        draw_thread_handle.join();
#ifdef _DEBUG
        std::cout << "Draw thread joined" << std::endl;
#endif
    }
}

void ThreadedObjectLoader::writer_thread() {
    try {
		WindowManager::getInstance()->createWindow("Writer", []() {}, []() {}, 800, 600);

        while (!stop) {
            std::unique_lock<std::mutex> lk(m);
            cv.wait(lk, [this] { return ready || stop; });

            if (stop) break;

            std::cout << "Worker thread is processing data" << std::endl;

            BlenderObjectData dataObjectData = BlenderObjectReader::getInstance()->readBlenderFile("cube");

            {
                std::lock_guard<std::mutex> read_lk(read_m);
                BlenderObject blenderObject(dataObjectData);
                std::cout << "Worker thread created BlenderObject" << std::endl;
            }

            processed = true;
            ready = false;
            std::cout << "Worker thread has processed data" << std::endl;
            lk.unlock();
            cv.notify_one();
        }

        std::cout << "Worker thread: context released" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception in writer thread: " << e.what() << std::endl;
    }
}

void ThreadedObjectLoader::update_detector_thread() {
    try {
        std::filesystem::path filePath = folderPath + "//" + "cube.blend";
        auto lastWriteTime = std::filesystem::last_write_time(filePath);

        while (!stop) {
            std::this_thread::sleep_for(std::chrono::seconds(1)); // Check more frequently

            auto currentWriteTime = std::filesystem::last_write_time(filePath);

            if (currentWriteTime != lastWriteTime) {
                std::lock_guard<std::mutex> lk(m);
                ready = true;
                lastWriteTime = currentWriteTime;
                cv.notify_one();
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception in update detector thread: " << e.what() << std::endl;
    }
}

void ThreadedObjectLoader::draw_thread() {
    try {
        WindowManager::getInstance()->createWindow("Draw", []() {}, []() {}, 800, 600);

        while (!stop) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            {
                std::lock_guard<std::mutex> read_lk(read_m);
				WindowManager::getInstance()->run();
            }
        }

        std::cout << "Draw thread: context released" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception in draw thread: " << e.what() << std::endl;
    }
}
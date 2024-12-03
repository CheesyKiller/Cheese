import RenderObjectThreadedLoader;

import WindowManager;
import RenderObjectBlenderReader;

namespace RenderObject {
    ThreadedLoader::ThreadedLoader() {
        stop = false;
        writer = std::thread(&ThreadedLoader::writer_thread, this);
        update_detector = std::thread(&ThreadedLoader::update_detector_thread, this);
        draw_thread_handle = std::thread(&ThreadedLoader::draw_thread, this);
    }

    ThreadedLoader* ThreadedLoader::getInstance() {
        static ThreadedLoader instance;
        return &instance;
    }

    ThreadedLoader::~ThreadedLoader() {
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

    void ThreadedLoader::writer_thread() {
        try {
            WindowManager::getInstance()->createWindow("Writer", []() {}, []() {}, 800, 600);

            while (!stop) {
                std::unique_lock<std::mutex> lk(m);
                cv.wait(lk, [this] { return ready || stop; });

                if (stop) break;

                std::cout << "Worker thread is processing data" << std::endl;

                Data data = BlenderReader::getInstance()->read("cube");

                {
                    std::lock_guard<std::mutex> read_lk(read_m);
                    RenderObject blenderObject(data);
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

    void ThreadedLoader::update_detector_thread() {
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

    void ThreadedLoader::draw_thread() {
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
}
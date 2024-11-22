#pragma once

#include "BlenderObject.h"
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>
#include <string>

static std::string folderPath = "D://Visual Studio//Distortion//Models";

class ThreadedObjectLoader : public std::enable_shared_from_this<ThreadedObjectLoader> {
    static std::shared_ptr<ThreadedObjectLoader> instance;

    std::mutex m;
    std::mutex read_m;
    std::condition_variable cv;
    bool ready = true;
    bool processed = false;
    std::atomic<bool> stop = false;

    std::thread writer;
    std::thread update_detector;
    std::thread draw_thread_handle;

    void writer_thread();
    void update_detector_thread();
    void draw_thread();

    ThreadedObjectLoader();

public:
    static std::shared_ptr<ThreadedObjectLoader> getInstance();
    ~ThreadedObjectLoader();
};
export module RenderObjectThreadedLoader;

export import RenderObject;

import std.core;
import std.threading;

export namespace RenderObject {
    

    struct ThreadedLoader {
        static ThreadedLoader* getInstance();
        ~ThreadedLoader();

        ThreadedLoader(const ThreadedLoader&) = delete;
        ThreadedLoader& operator=(const ThreadedLoader&) = delete;
    private:
        std::string folderPath = "D://Visual Studio//Distortion//Models";

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

        ThreadedLoader();
    };
}
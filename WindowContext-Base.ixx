module;

#include <functional>
#include <string>

export module WindowContext:Base;

namespace WindowContext {

    // Window interface class
    export class Window {
    public:
        Window(std::string title, int width = 800, int height = 600, Window* sharedWindow = nullptr);
        ~Window();

        void SwapBuffers();
        bool ShouldClose();

        // Future-proofing: Methods to set window properties, handle input, etc.
        void SetTitle(std::string title);
		std::string GetTitle() const;

        void PollEvents();

		void MakeCurrent();

		void Show();
		void Hide();

        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

    private:
        struct Impl;      // Forward declaration of implementation struct
        Impl* impl;       // Pointer to the implementation struct (Pimpl idiom)
    };

}

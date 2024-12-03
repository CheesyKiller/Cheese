module;

#include <chrono>

export module GLAD;

export import :V4_6;

export namespace GLAD {
	struct Time {
		static Time* getInstance();
		~Time() = default;

		float timeElapsed();

		Time(const Time&) = delete;
		Time& operator=(const Time&) = delete;
	private:
		Time() : initializedGlad(std::chrono::system_clock::now()) {}
		std::chrono::time_point<std::chrono::system_clock> initializedGlad = std::chrono::system_clock::now();
	};

	int gladLoadGL(void);
	float gladGetDeltaTime();

	void gladError(const std::string& message = "") {
		GLAD::GLenum error = GLAD::glGetError();
		while (error != GLAD::GL_NO_ERROR) {
			std::cerr << "OpenGL error: " << error << std::endl << std::to_string(error) << std::endl;
			if (!message.empty()) {
				std::cerr << message << std::endl;
			}
		}
	}

	void ErrorMessageCallback(GLAD::GLenum source,
		GLAD::GLenum type,
		GLAD::GLuint id,
		GLAD::GLenum severity,
		GLAD::GLsizei length,
		const GLAD::GLchar* message,
		const void* userParam)
	{
		using namespace std::string_view_literals;

		std::string_view typeStr = (type == GLAD::GL_DEBUG_TYPE_ERROR) ? "** GL ERROR **"sv : ""sv;

		std::cerr << "GL CALLBACK: " << typeStr
			<< " type = 0x" << std::hex << type
			<< ", severity = 0x" << severity
			<< ", message = " << message
			<< std::endl;
	}
}

export import :WGL;
export module GLADTypes;

import KHR;

export namespace GLAD {
	using namespace KHR;

	export using GLenum = unsigned int;
	export using GLboolean = unsigned char;
	export using GLbitfield = unsigned int;
	export using GLvoid = void;
	export using GLbyte = khronos_int8_t;
	export using GLubyte = khronos_uint8_t;
	export using GLshort = khronos_int16_t;
	export using GLushort = khronos_uint16_t;
	export using GLint = int;
	export using GLuint = unsigned int;
	export using GLclampx = khronos_int32_t;
	export using GLsizei = int;
	export using GLfloat = khronos_float_t;
	export using GLclampf = khronos_float_t;
	export using GLdouble = double;
	export using GLclampd = double;
	export using GLeglClientBufferEXT = void*;
	export using GLeglImagesOES = void*;
	export using GLchar = char;
	export using GLcharARB = char;


#ifdef __APPLE__
	export using GLhandleARB = void*;
#else
	export using GLhandleARB = unsigned int;
#endif

	export using GLhalf = khronos_uint16_t;
	export using GLhalfARB = khronos_uint16_t;
	export using GLfixed = khronos_int32_t;
	export using GLintptr = khronos_intptr_t;
	export using GLintptrARB = khronos_intptr_t;
	export using GLsizeiptr = khronos_ssize_t;
	export using GLsizeiptrARB = khronos_ssize_t;
	export using GLint64 = khronos_int64_t;
	export using GLint64EXT = khronos_int64_t;
	export using GLuint64 = khronos_uint64_t;
	export using GLuint64EXT = khronos_uint64_t;
	export using GLsync = struct __GLsync*;
	export struct _cl_context;
	export struct _cl_event;

	export using GLDEBUGPROC = void(*)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
	export using GLDEBUGPROCARB = void(*)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
	export using GLDEBUGPROCKHR = void(*)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
	export using GLDEBUGPROCAMD = void(*)(GLuint id, GLenum category, GLenum severity, GLsizei length, const GLchar* message, void* userParam);
	export using GLVULKANPROCNV = void(*)(void);

	export using GLhalfNV = unsigned short;
	export using GLvdpauSurfaceNV = GLintptr;

	export struct gladGLversionStruct {
		int major;
		int minor;
	};
}
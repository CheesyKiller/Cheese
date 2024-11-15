module;

#include <Windows.h>

export module KeyboardInput:WindowsImpl;

export import :Base;

export namespace Input {
	using KEY_CODE = int;

	constexpr KEY_CODE KEY_UP = VK_UP;
	constexpr KEY_CODE KEY_DOWN = VK_DOWN;
	constexpr KEY_CODE KEY_LEFT = VK_LEFT;
	constexpr KEY_CODE KEY_RIGHT = VK_RIGHT;
	constexpr KEY_CODE KEY_ESCPAE = VK_ESCAPE;
	constexpr KEY_CODE KEY_SPACE = VK_SPACE;
	constexpr KEY_CODE KEY_ENTER = VK_RETURN;
	constexpr KEY_CODE KEY_BACK = VK_BACK;
	constexpr KEY_CODE KEY_TAB = VK_TAB;
	constexpr KEY_CODE KEY_SHIFT = VK_SHIFT;

	constexpr KEY_CODE KEY_TILDE = VK_OEM_3;
	constexpr KEY_CODE KEY_EQUAL = VK_OEM_PLUS;
	constexpr KEY_CODE KEY_MINUS = VK_OEM_MINUS;
	constexpr KEY_CODE KEY_UNDERSCORE = VK_OEM_MINUS;
	constexpr KEY_CODE KEY_PLUS = VK_OEM_PLUS;
	constexpr KEY_CODE KEY_LBRACKET = VK_OEM_4;
	constexpr KEY_CODE KEY_RBRACKET = VK_OEM_6;
	constexpr KEY_CODE KEY_SEMICOLON = VK_OEM_1;
	constexpr KEY_CODE KEY_QUOTE = VK_OEM_7;
	constexpr KEY_CODE KEY_COMMA = VK_OEM_COMMA;
	constexpr KEY_CODE KEY_PERIOD = VK_OEM_PERIOD;
	constexpr KEY_CODE KEY_SLASH = VK_OEM_2;
	constexpr KEY_CODE KEY_BACKSLASH = VK_OEM_5;
	constexpr KEY_CODE KEY_GRAVE = VK_OEM_3;
	constexpr KEY_CODE KEY_CTRL_L = VK_LCONTROL;
	constexpr KEY_CODE KEY_CTRL_R = VK_RCONTROL;
	constexpr KEY_CODE KEY_ALT_L = VK_LMENU;
	constexpr KEY_CODE KEY_ALT_R = VK_RMENU;
	constexpr KEY_CODE KEY_SHIFT_L = VK_LSHIFT;
	constexpr KEY_CODE KEY_SHIFT_R = VK_RSHIFT;
	constexpr KEY_CODE KEY_WIN_L = VK_LWIN;
	constexpr KEY_CODE KEY_WIN_R = VK_RWIN;
	constexpr KEY_CODE KEY_ESCAPE = VK_ESCAPE;

	constexpr KEY_CODE KEY_CTRL = VK_CONTROL;
	constexpr KEY_CODE KEY_ALT = VK_MENU;
	constexpr KEY_CODE KEY_CAPS_LOCK = VK_CAPITAL;
	constexpr KEY_CODE KEY_NUM_LOCK = VK_NUMLOCK;
	constexpr KEY_CODE KEY_SCROLL_LOCK = VK_SCROLL;
	constexpr KEY_CODE KEY_INSERT = VK_INSERT;
	constexpr KEY_CODE KEY_DELETE = VK_DELETE;
	constexpr KEY_CODE KEY_HOME = VK_HOME;
	constexpr KEY_CODE KEY_END = VK_END;
	constexpr KEY_CODE KEY_PAGE_UP = VK_PRIOR;
	constexpr KEY_CODE KEY_PAGE_DOWN = VK_NEXT;
	constexpr KEY_CODE KEY_PRINT_SCREEN = VK_SNAPSHOT;
	constexpr KEY_CODE KEY_PAUSE = VK_PAUSE;
	constexpr KEY_CODE KEY_MENU = VK_APPS;

	constexpr KEY_CODE KEY_F1 = VK_F1;
	constexpr KEY_CODE KEY_F2 = VK_F2;
	constexpr KEY_CODE KEY_F3 = VK_F3;
	constexpr KEY_CODE KEY_F4 = VK_F4;
	constexpr KEY_CODE KEY_F5 = VK_F5;
	constexpr KEY_CODE KEY_F6 = VK_F6;
	constexpr KEY_CODE KEY_F7 = VK_F7;
	constexpr KEY_CODE KEY_F8 = VK_F8;
	constexpr KEY_CODE KEY_F9 = VK_F9;
	constexpr KEY_CODE KEY_F10 = VK_F10;
	constexpr KEY_CODE KEY_F11 = VK_F11;
	constexpr KEY_CODE KEY_F12 = VK_F12;

	constexpr KEY_CODE KEY_0 = 0x30;
	constexpr KEY_CODE KEY_1 = 0x31;
	constexpr KEY_CODE KEY_2 = 0x32;
	constexpr KEY_CODE KEY_3 = 0x33;
	constexpr KEY_CODE KEY_4 = 0x34;
	constexpr KEY_CODE KEY_5 = 0x35;
	constexpr KEY_CODE KEY_6 = 0x36;
	constexpr KEY_CODE KEY_7 = 0x37;
	constexpr KEY_CODE KEY_8 = 0x38;
	constexpr KEY_CODE KEY_9 = 0x39;

	constexpr KEY_CODE KEY_A = 0x41;
	constexpr KEY_CODE KEY_B = 0x42;
	constexpr KEY_CODE KEY_C = 0x43;
	constexpr KEY_CODE KEY_D = 0x44;
	constexpr KEY_CODE KEY_E = 0x45;
	constexpr KEY_CODE KEY_F = 0x46;
	constexpr KEY_CODE KEY_G = 0x47;
	constexpr KEY_CODE KEY_H = 0x48;
	constexpr KEY_CODE KEY_I = 0x49;
	constexpr KEY_CODE KEY_J = 0x4A;
	constexpr KEY_CODE KEY_K = 0x4B;
	constexpr KEY_CODE KEY_L = 0x4C;
	constexpr KEY_CODE KEY_M = 0x4D;
	constexpr KEY_CODE KEY_N = 0x4E;
	constexpr KEY_CODE KEY_O = 0x4F;
	constexpr KEY_CODE KEY_P = 0x50;
	constexpr KEY_CODE KEY_Q = 0x51;
	constexpr KEY_CODE KEY_R = 0x52;
	constexpr KEY_CODE KEY_S = 0x53;
	constexpr KEY_CODE KEY_T = 0x54;
	constexpr KEY_CODE KEY_U = 0x55;
	constexpr KEY_CODE KEY_V = 0x56;
	constexpr KEY_CODE KEY_W = 0x57;
	constexpr KEY_CODE KEY_X = 0x58;
	constexpr KEY_CODE KEY_Y = 0x59;
	constexpr KEY_CODE KEY_Z = 0x5A;

	constexpr KEY_CODE KEY_NUMPAD_0 = VK_NUMPAD0;
	constexpr KEY_CODE KEY_NUMPAD_1 = VK_NUMPAD1;
	constexpr KEY_CODE KEY_NUMPAD_2 = VK_NUMPAD2;
	constexpr KEY_CODE KEY_NUMPAD_3 = VK_NUMPAD3;
	constexpr KEY_CODE KEY_NUMPAD_4 = VK_NUMPAD4;
	constexpr KEY_CODE KEY_NUMPAD_5 = VK_NUMPAD5;
	constexpr KEY_CODE KEY_NUMPAD_6 = VK_NUMPAD6;
	constexpr KEY_CODE KEY_NUMPAD_7 = VK_NUMPAD7;
	constexpr KEY_CODE KEY_NUMPAD_8 = VK_NUMPAD8;
	constexpr KEY_CODE KEY_NUMPAD_9 = VK_NUMPAD9;
	constexpr KEY_CODE KEY_NUMPAD_ADD = VK_ADD;
	constexpr KEY_CODE KEY_NUMPAD_SUBTRACT = VK_SUBTRACT;
	constexpr KEY_CODE KEY_NUMPAD_MULTIPLY = VK_MULTIPLY;
	constexpr KEY_CODE KEY_NUMPAD_DIVIDE = VK_DIVIDE;
	constexpr KEY_CODE KEY_NUMPAD_DECIMAL = VK_DECIMAL;
	constexpr KEY_CODE KEY_NUMPAD_ENTER = VK_RETURN;
	constexpr KEY_CODE KEY_NUMPAD_LOCK = VK_NUMLOCK;

	bool IsPressed(KEY_CODE key_code) {
		return GetAsyncKeyState(key_code) & 0x8000;
	};
}
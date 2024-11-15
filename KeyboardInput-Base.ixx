export module KeyboardInput:Base;

export namespace Input {
	using KEY_CODE = int;

	bool IsPressed(KEY_CODE key_code);
}
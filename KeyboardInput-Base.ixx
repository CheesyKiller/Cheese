export module KeyboardInput:Base;

import std.core;

export namespace Input {
	using KEY_CODE = int;

    struct InputManager {
		static InputManager* GetInstance() {
			static InputManager instance;
			return &instance;
		}

		~InputManager() = default;

        void Update();

        // Check if the key was just pressed
        bool IsJustPressed(int key_code) const {
            auto it = keysJustPressed.find(key_code);
            if (it != keysJustPressed.end()) {
                return it->second;
            }
            return false;
        }

        // Check if the key was just released
        bool IsJustReleased(int key_code) const {
            auto it = keysJustReleased.find(key_code);
            if (it != keysJustReleased.end()) {
                return it->second;
            }
            return false;
        }

		// Check if the key is currently pressed
        bool IsPressed(int key_code) const {
            auto it = keysCurrentState.find(key_code);
            if (it != keysCurrentState.end()) {
                return it->second;
            }
        }
    private:
        std::vector<int> monitoredKeys;
        std::unordered_map<int, bool> keysCurrentState;
        std::unordered_map<int, bool> keysJustPressed;
        std::unordered_map<int, bool> keysJustReleased;

        InputManager();

        // Add a key to monitor
        void MonitorKey(int key_code) {
            monitoredKeys.push_back(key_code);
            keysCurrentState[key_code] = false;
            keysJustPressed[key_code] = false;
            keysJustReleased[key_code] = false;
        }
    };

}
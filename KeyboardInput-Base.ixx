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

        bool IsJustPressed(int key_code) const {
            auto currentState = keysCurrentState.find(key_code);
            auto previousState = keysPreviousState.find(key_code);
            if (currentState != keysCurrentState.end()) {
                if (currentState->second && !previousState->second) {
                    return true;
                }
            }
            return false;
        }

        bool IsJustReleased(int key_code) const {
            auto currentState = keysCurrentState.find(key_code);
            auto previousState = keysPreviousState.find(key_code);
            if (currentState != keysCurrentState.end()) {
				if (!currentState->second && previousState->second) {
					return true;
				}
            }
            return false;
        }

        bool IsPressed(int key_code) const {
            auto currentState = keysCurrentState.find(key_code);
            if (currentState != keysCurrentState.end()) {
                return currentState->second;
            }
			return false;
        }
    private:
        std::vector<int> monitoredKeys;
        std::unordered_map<int, bool> keysCurrentState;
        std::unordered_map<int, bool> keysPreviousState;

        InputManager();

        void MonitorKey(int key_code) {
            monitoredKeys.push_back(key_code);
            keysCurrentState[key_code] = false;
            keysPreviousState[key_code] = false;
        }
    };

}
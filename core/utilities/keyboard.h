#pragma once

//------------------------------------------------------------------//

#include <GLFW/glfw3.h>

#include <unordered_map>
#include <iostream>

//------------------------------------------------------------------//

class Keyboard
{
public:
	static void initialize(GLFWwindow* window);
	static bool isPressed(int key);

private:
	static void processInput(GLFWwindow* window, int key, int scancode, int action, int mods);

	static inline std::unordered_map<uint16_t, std::atomic<bool>> m_keyboard;
};

//------------------------------------------------------------------//
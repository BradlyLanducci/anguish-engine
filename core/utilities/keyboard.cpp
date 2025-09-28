#include <utilities/keyboard.h>
#include <glog/logging.h>

// #define LOG_KEYS

//------------------------------------------------------------------//

void Keyboard::initialize(GLFWwindow* window)
{
	glfwSetKeyCallback(window, Keyboard::processInput);
}

//------------------------------------------------------------------//

bool Keyboard::isPressed(int key)
{
	return m_keyboard[key];
}

//------------------------------------------------------------------//

void Keyboard::processInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		m_keyboard[key] = true;

#ifdef LOG_KEYS
		LOG(INFO) << key << " : " << " pressed";
#endif
	}
	else if (action == GLFW_RELEASE)
	{
		m_keyboard[key] = false;

#ifdef LOG_KEYS
		LOG(INFO) << key << " : " << " released";
#endif
	}
}

//------------------------------------------------------------------//

#include "window.h"

#include "data_structures.h"

#include <assert.h>
#include <iostream>

//------------------------------------------------------------------//

Vector2 Window::windowSize;
GLFWwindow* Window::window = nullptr;

constexpr uint32_t WINDOW_WIDTH = 1080;
constexpr uint32_t WINDOW_HEIGHT = 1080;

constexpr uint32_t ASPECT_RATIO_WIDTH = 16;
constexpr uint32_t ASPECT_RATIO_HEIGHT = 9;

//------------------------------------------------------------------//

Window::Window()
{
}

//------------------------------------------------------------------//

Window::~Window()
{
	destroy();
}

//------------------------------------------------------------------//

void Window::frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
	windowSize.x = width;
	windowSize.y = height;
}

//------------------------------------------------------------------//

void Window::createWindow(uint32_t width, uint32_t height)
{
	assert(glfwInit());

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, "Anguish Engine", NULL, NULL);
	assert(window);

	glfwMakeContextCurrent(window);

	assert(gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)));

	assert(gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)));

	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);

	glfwSetWindowAspectRatio(window, ASPECT_RATIO_WIDTH, ASPECT_RATIO_HEIGHT);
}

//------------------------------------------------------------------//

void Window::destroy()
{
	glfwTerminate();
}

//------------------------------------------------------------------//

GLFWwindow* Window::getWindow()
{
	createWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
	return window;
}

//------------------------------------------------------------------//

Vector2 Window::getSize()
{
	return windowSize;
}

//------------------------------------------------------------------//

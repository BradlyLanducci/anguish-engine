#pragma once

//------------------------------------------------------------------//

#include <cstdint>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

//------------------------------------------------------------------//

struct Vector2;

class Window
{
	Window() = default;
	~Window();

	static void frameBufferSizeCallback(GLFWwindow* window, int width, int height);

	static void createWindow(uint32_t width, uint32_t height);
	static void destroy();

	static Vector2 windowSize;
	static GLFWwindow* window;

public:
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

	static GLFWwindow* getWindow();
	static Vector2 getSize();
};

//------------------------------------------------------------------//

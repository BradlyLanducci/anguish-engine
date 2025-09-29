#pragma once

//------------------------------------------------------------------//

#include <GLFW/glfw3.h>

//------------------------------------------------------------------//

struct Vector2;

//------------------------------------------------------------------//

constexpr uint32_t WINDOW_WIDTH = 1920;
constexpr uint32_t WINDOW_HEIGHT = 1080;

constexpr uint32_t ASPECT_RATIO_WIDTH = 16;
constexpr uint32_t ASPECT_RATIO_HEIGHT = 9;

//------------------------------------------------------------------//

class Window
{
    Window() = default;
    ~Window();

    static void frameBufferSizeCallback(GLFWwindow *window, int width, int height);

    static void createWindow(uint32_t width, uint32_t height);
    static void destroy();

    static Vector2 windowSize;
    static GLFWwindow *window;

public:
    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

    static GLFWwindow *getWindow();
    static Vector2 getSize();
};

//------------------------------------------------------------------//

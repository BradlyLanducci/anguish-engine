#include <utilities/window.h>
#include <utilities/data_structures.h>
#include <utilities/keyboard.h>

#include <cstdint>
#include <cassert>
#include <glad/glad.h>

//------------------------------------------------------------------//

Vector2 Window::windowSize;
GLFWwindow *Window::window = nullptr;

//------------------------------------------------------------------//

Window::~Window()
{
    destroy();
}

//------------------------------------------------------------------//

void Window::frameBufferSizeCallback(GLFWwindow *_window, int width, int height)
{
    (void)_window;
    glViewport(0, 0, width, height);
    windowSize.x = static_cast<float>(width);
    windowSize.y = static_cast<float>(height);
}

//------------------------------------------------------------------//

void Window::createWindow(uint32_t width, uint32_t height)
{
    assert(glfwInit());

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(static_cast<int>(width), static_cast<int>(height), "Anguish Engine", nullptr, nullptr);
    assert(window);

    glfwMakeContextCurrent(window);

    assert(gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)));

    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);

    glfwSetWindowAspectRatio(window, ASPECT_RATIO_WIDTH, ASPECT_RATIO_HEIGHT);

    Keyboard::initialize(window);

    windowSize = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
}

//------------------------------------------------------------------//

void Window::destroy()
{
    glfwTerminate();
}

//------------------------------------------------------------------//

GLFWwindow *Window::getWindow()
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

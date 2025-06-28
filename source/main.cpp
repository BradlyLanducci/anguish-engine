//------------------------------------------------------------------//

#include "utilities/window.h"

#include <glog/logging.h>
#include <iostream>

#include "utilities/file_io.h"
#include "utilities/gl_error.h"

#include "ogl/object_2d.h"

//------------------------------------------------------------------//

int main(void)
{
	GLFWwindow* window = Window::getWindow();
	if (!window)
	{
		LOG(INFO) << "Failed to start Anguish.";
		return -1;
	}

	double deltaTime = 0.0;
	double lastTime = 0.0;

	Object2D object;

	while (!glfwWindowShouldClose(window))
	{
		double currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		object.draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glUseProgram(0);

	return 0;
}

//------------------------------------------------------------------//
//------------------------------------------------------------------//

#include <utilities/window.h>

#include <glog/logging.h>

#include <physics/physics_manager.h>

#include <ogl/object_2d.h>

//------------------------------------------------------------------//

int main(void)
{
	GLFWwindow* window = Window::getWindow();
	if (!window)
	{
		LOG(INFO) << "Failed to start Anguish.";
		return -1;
	}

	PhysicsManager& p = PhysicsManager::get();

	Object2D* obj = new Object2D;

	while (!glfwWindowShouldClose(window))
	{
		float currentTime = glfwGetTime();

		p.update(currentTime);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glUseProgram(0);

	p.destroy();

	return 0;
}

//------------------------------------------------------------------//
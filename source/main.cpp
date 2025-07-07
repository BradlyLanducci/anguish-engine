//------------------------------------------------------------------//

#include <utilities/window.h>

#include <glog/logging.h>

#include <idle/idle_manager.h>
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

	IdleManager& i = IdleManager::get();
	PhysicsManager& p = PhysicsManager::get();

	Object2D* obj = new Object2D;
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		float currentTime = glfwGetTime(); // Should they use their own current time??
		i.update(currentTime);
		p.update(currentTime);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glUseProgram(0);

	p.destroy();

	return 0;
}

//------------------------------------------------------------------//
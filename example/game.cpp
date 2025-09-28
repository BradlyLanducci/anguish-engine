#include <game.h>

#include <utilities/window.h>

#include <glog/logging.h>

#include <idle/idle_manager.h>
#include <physics/physics_manager.h>
#include <renderer/rendering_manager.h>

//------------------------------------------------------------------//

Game::Game()
{
}

//------------------------------------------------------------------//

Game::~Game()
{
}

//------------------------------------------------------------------//

int Game::run()
{
	GLFWwindow* window = Window::getWindow();
	if (!window)
	{
		LOG(INFO) << "Failed to start Anguish.";
		return -1;
	}

	IdleManager& i = IdleManager::get();
	PhysicsManager& p = PhysicsManager::get();
	RenderingManager& r = RenderingManager::get();

	// root->addChild(c);
	// root->addChild(g);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		float currentTime = glfwGetTime(); // Should they use their own current time??
		i.update(currentTime);
		p.update(currentTime);
		r.update(currentTime);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glUseProgram(0);

	i.destroy();
	p.destroy();
	r.destroy();

	// delete root;

	return 0;
}

//------------------------------------------------------------------//

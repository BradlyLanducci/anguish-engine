#include <game.h>

#include <utilities/window.h>
#include <idle/idle_manager.h>
#include <physics/physics_manager.h>
#include <renderer/rendering_manager.h>
#include <scenes/scene.h>

#include <glog/logging.h>

//------------------------------------------------------------------//

Game::~Game()
{
	if (m_scene)
	{
		delete m_scene;
		m_scene = nullptr;
	}
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

	return 0;
}

//------------------------------------------------------------------//

void Game::setScene(Scene* s)
{
	if (m_scene)
	{
		delete m_scene;
	}

	m_scene = s;
}

//------------------------------------------------------------------//

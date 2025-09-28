#include <game.h>

#include <idle/idle_manager.h>
#include <physics/physics_manager.h>
#include <renderer/rendering_manager.h>
#include <scenes/scene.h>

#include <glog/logging.h>

//------------------------------------------------------------------//

Game::Game()
	: mp_window(Window::getWindow())
{
}

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
	if (!mp_window)
	{
		LOG(INFO) << "Failed to start Anguish.";
		return -1;
	}

	while (!glfwWindowShouldClose(mp_window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		float currentTime = static_cast<float>(glfwGetTime()); // Should they use their own current time??
		IdleManager::update(currentTime);
		PhysicsManager::update(currentTime);
		RenderingManager::update(currentTime);

		glfwSwapBuffers(mp_window);
		glfwPollEvents();
	}

	glUseProgram(0);

	IdleManager::destroy();
	PhysicsManager::destroy();
	RenderingManager::destroy();

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

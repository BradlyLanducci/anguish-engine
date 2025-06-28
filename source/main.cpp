//------------------------------------------------------------------//

#include "utilities/window.h"
#include "shaders/shader_program.h"

#include <glog/logging.h>
#include <iostream>

#include "utilities/file_io.h"
#include "utilities/gl_error.h"

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

	float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

	uint32_t vbo;
	glGenBuffers(1, &vbo);
	checkGLError();
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	checkGLError();
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	checkGLError();

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	checkGLError();
	glBindVertexArray(VAO);
	checkGLError();

	ShaderProgram shaderProgram;
	shaderProgram.setVertexShader("source/shaders/vert.vs");
	shaderProgram.setFragmentShader("source/shaders/frag.fs");

	while (!glfwWindowShouldClose(window))
	{
		double currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		checkGLError();
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		checkGLError();
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		checkGLError();
		glEnableVertexAttribArray(0);
		checkGLError();
		glUseProgram(shaderProgram.get());
		checkGLError();
		glBindVertexArray(VAO);
		checkGLError();
		glDrawArrays(GL_TRIANGLES, 0, 3);
		checkGLError();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glUseProgram(0);

	return 0;
}

//------------------------------------------------------------------//
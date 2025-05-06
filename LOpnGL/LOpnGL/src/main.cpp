#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

// callback that handle changes of window size
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main()
{
	// GLFW Configuration
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create the window check if everything is ok
	GLFWwindow* window = glfwCreateWindow(800, 600, "LOpnGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window!" << std::endl;
		glfwTerminate();
		return -1;
	}

	// parallel thread stuff, make the window the current thread context
	glfwMakeContextCurrent(window);

	// prepping GLAD, GLAD manages function pointers for OpenGL

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD! " << std::endl;
		return -1;
	}
	// setting the viewport,sets the width and height of the area we working on
	glViewport(0, 0, 800, 600);

	// calling the resize function
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// we work in here
	while (!glfwWindowShouldClose(window))
	{
		// custom made function, processing esc and the close button
		processInput(window);

		// rendering
		glClearColor(0.5f, 0.0f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// terminate everything
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
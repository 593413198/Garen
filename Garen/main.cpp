#include <GLFW/glfw3.h>
#include "global.h"
#include "draw.h"
#include "input.h"

GLFWwindow* window;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main(void)
{

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(1024, 720, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{

		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);

		 //drawPoint();
		if (isKeyDown(GLFW_KEY_1))
			drawPoint(vec2(0.5f, 0.5f));
		if (isKeyDown(GLFW_KEY_2))
			drawLine();
		if (isKeyDown(GLFW_KEY_3))
			drawTriangle();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
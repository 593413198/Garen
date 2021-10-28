
#include "garengl.h"

GLFWwindow* window = nullptr;

void glInit(const unsigned int width, const unsigned int height)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		return;
	}

	// configure global opengl state
	// -----------------------------
	glEnable(GL_DEPTH_TEST);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void glSetCallback(int cb_index, void * cb)
{
	switch (cb_index)
	{
	default:
		break;
	case FRAMEBUFFER_CALLBACK:
		glfwSetFramebufferSizeCallback(window, (GLFWframebuffersizefun)cb);
		break;
	case CURSOR_POS_CALLBACK:
		glfwSetCursorPosCallback(window, (GLFWcursorposfun)cb);
		break;
	case SCROLL_CALLBACK:
		glfwSetScrollCallback(window, (GLFWscrollfun)cb);
		break;
	}
}
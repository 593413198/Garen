#include "input.h"

bool isKeyDown(uint32_t key)
{
	if (glfwGetKey(window, key) == GLFW_PRESS) {
		return true;
	}
	return false;
}
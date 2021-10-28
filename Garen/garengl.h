#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define FRAMEBUFFER_CALLBACK 0
#define CURSOR_POS_CALLBACK 1
#define SCROLL_CALLBACK 2


extern GLFWwindow* window;
void glInit(const unsigned int, const unsigned int);

void glSetCallback(int cb_index, void* cb);

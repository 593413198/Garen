#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define FRAMEBUFFER_CALLBACK 0
#define CURSOR_POS_CALLBACK 1
#define SCROLL_CALLBACK 2

GLFWwindow* window = nullptr;

extern GLFWwindow* window;
void glInit(const unsigned int width, const unsigned int height)
{
	glfwInit();
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		return;
	}

	glEnable(GL_DEPTH_TEST);

	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
}

void glSetCallback(int cb_index, void* cb)
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

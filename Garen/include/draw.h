#pragma once
#include <GLFW/glfw3.h>
#include "const.h"
#include "gvector.h"

void drawPoint(vec2 point, vec3 color = COLOR_RED, float size = 2.f);

void drawLine();

void drawTriangle();
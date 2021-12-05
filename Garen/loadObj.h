#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#define BUFFER_SIZE 1024
#define VERTEX_SIZE 32
#define vvec3 std::vector<glm::vec3>

using namespace std;

bool loadOBJ(const char* path, vvec3 &vertex, vvec3 &uv, vvec3 &normal)
{
	FILE *file = fopen(path, "r");
	if (!file)
	{
		printf("Read File Failed: %s", path);
		return false;
	}
	char v1[VERTEX_SIZE], v2[VERTEX_SIZE], v3[VERTEX_SIZE];
	while (1)
	{
		char header[BUFFER_SIZE];
		int res = fscanf(file, "%s", header);
		if (res == EOF) break;
		// vertex
		if (strcmp(header, "v") == 0)
		{
			fscanf(file, "%s %s %s", &v1, &v2, &v3);
			glm::vec3 vec(atof(v1), atof(v2), atof(v3));
			vertex.push_back(vec);
		}
		// texture uv
		else if (strcmp(header, "vt") == 0)
		{
			fscanf(file, "%s %s", &v1, &v2);
			glm::vec3 vec(atof(v1), atof(v2), 0.0f);
			uv.push_back(vec);
		}
		// texture normal
		else if (strcmp(header, "vn") == 0)
		{
			fscanf(file, "%s %s %s", &v1, &v2, &v3);
			glm::vec3 vec(atof(v1), atof(v2), atof(v3));
			normal.push_back(vec);
		}
	}
	return true;
}
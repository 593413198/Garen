#include "draw.h"

// Draw a point
void drawPoint(vec2 point, vec3 color, float size)
{
	glPointSize(size);
	glBegin(GL_POINTS);
	vec2 v = vec2(0.4f, 0.4f);

	glColor3f(color.x, color.y, color.z);
	// gl coord. �ĸ�����, ������(0,0)
	glVertex2f(point.x, point.y);
	glEnd();
}


void drawLine()
{
	glLineWidth(2);//�����߶ο��
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.8f, 1.0f); //�������귶Χ

	glVertex2f(0, -1);
	glEnd();
}
void drawTriangle()
{
	glBegin(GL_TRIANGLES);

	glColor3f(1.0, 0.0, 0.0);    // Red
	glVertex3f(0.0, 1.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);    // Green
	glVertex3f(-1.0, -1.0, 0.0);

	glColor3f(0.0, 0.0, 1.0);    // Blue
	glVertex3f(1.0, -1.0, 0.0);
	glEnd();
}
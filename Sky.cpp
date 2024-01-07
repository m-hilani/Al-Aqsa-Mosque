#include <windows.h>		// Header File For Windows
#include <GL/gl.h>			// Header File For The OpenGL32 Library
#include <GL/glu.h>			// Header File For The GLu32 Library
#include <GL/glaux.h>		// Header File For The Glaux Library
#include <cmath>

class Sky
{
public:void sky(int back, int front, int left, int right, int top)
{
	glPushMatrix();
	glScaled(60, 60, 60);
	glBindTexture(GL_TEXTURE_2D, front);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -200, -200);
	glTexCoord2d(1, 0);
	glVertex3d(200, -200, -200);
	glTexCoord2d(1, 1);
	glVertex3d(200, 200, -200);
	glTexCoord2d(0, 1);
	glVertex3d(-200, 200, -200);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, back);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -200, 200);
	glTexCoord2d(1, 0);
	glVertex3d(200, -200, 200);
	glTexCoord2d(1, 1);
	glVertex3d(200, 200, 200);
	glTexCoord2d(0, 1);
	glVertex3d(-200, 200, 200);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, left);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -200, 200);
	glTexCoord2d(1, 0);
	glVertex3d(-200, -200, -200);
	glTexCoord2d(1, 1);
	glVertex3d(-200, 200, -200);
	glTexCoord2d(0, 1);
	glVertex3d(-200, 200, 200);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, right);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(200, -200, 200);
	glTexCoord2d(0, 0);
	glVertex3d(200, -200, -200);
	glTexCoord2d(0, 1);
	glVertex3d(200, 200, -200);
	glTexCoord2d(1, 1);
	glVertex3d(200, 200, 200);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, top);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, 200, -200);
	glTexCoord2d(1, 0);
	glVertex3d(200, 200, -200);
	glTexCoord2d(1, 1);
	glVertex3d(200, 200, 200);
	glTexCoord2d(0, 1);
	glVertex3d(-200, 200, 200);
	glEnd();
	glPopMatrix();
}

};
#include <windows.h>		// Header File For Windows
#include "GL.H"			// Header File For The OpenGL32 Library
#include "glu.h"			// Header File For The GLu32 Library
#include "GLAUX.H"		// Header File For The Glaux Library
#include <cmath>
#include "Model.cpp"
#include "texture.h"
#include "math3d.h"


class Qibli {

public:	;

	Model m3 = Model();


public:void QibliDome(float r, float dome_img, float x, float y, float z) {
	m3.draw_sphere( r,  dome_img,  x,  y,  z);
}
public:void QuadQibli(int front_img, int back_img, int top_img, int right_img, int leaft_img)
	{
	m3.Quads(front_img, back_img, top_img, right_img, leaft_img, 10000, 1000, -80, 1000, 500, 3000);
	}
public: void QibliModel(int SKYFRONT, int  SKYBACK, int SKYLEFT, int SKYRIGHT, int  SKYUP, int SKYDOWN, float x, float y, float z, float width, float height, float length,int side,int face, M3DMatrix44f shadow, int faceRow = 1) {
		// Center the Skybox around the given x,y,z position
		x = x - width / 2;
		y = y - height / 2;
		z = z - length / 2;
		glEnable(GL_TEXTURE_2D);

		// Draw RIGHT side
		glBindTexture(GL_TEXTURE_2D, SKYFRONT);						
		
		glBegin(GL_QUADS);
		glTexCoord2f(face, 0.0f); glVertex3f(x, y, z + length);
		glTexCoord2f(face, 1.0f); glVertex3f(x, y + height, z + length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
		glEnd();

		glDisable(GL_LIGHTING);
		glPushMatrix();
		glMultMatrixf((GLfloat*)shadow);
		glColor3d(0, 0, 0);
		glBegin(GL_QUADS);

		glVertex3f(x, y, z + length);
		glVertex3f(x, y + height, z + length);
		glVertex3f(x + width, y + height, z + length);
		glVertex3f(x + width, y, z + length);
		glEnd();

		glPopMatrix();
		glEnable(GL_DEPTH_TEST);
		glColor3d(255, 255, 255);



		// Draw LEFT side
		glBindTexture(GL_TEXTURE_2D, SKYBACK);

		glBegin(GL_QUADS);
		glTexCoord2f(face, 0.0f); glVertex3f(x + width, y, z);
		glTexCoord2f(face, 1.0f); glVertex3f(x + width, y + height, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
		glEnd();

		// Draw FRONT side
		glBindTexture(GL_TEXTURE_2D, SKYLEFT);
		
		glBegin(GL_QUADS);
		glTexCoord2f(side, faceRow); glVertex3f(x, y + height, z);
		glTexCoord2f(0.0f, faceRow); glVertex3f(x, y + height, z + length);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
		glTexCoord2f(side, 0.0f); glVertex3f(x, y, z);
		glEnd();

		// Draw BACK side
		glBindTexture(GL_TEXTURE_2D, SKYRIGHT);
	

		glBegin(GL_QUADS);
		glTexCoord2f(side, 1.0f); glVertex3f(x+width, y + height, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
		glTexCoord2f(side, 0.0f); glVertex3f(x + width, y, z);
		glEnd();

		// Draw Up side
		glBindTexture(GL_TEXTURE_2D, SKYUP);

		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
		glTexCoord2f(10.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
		glTexCoord2f(10.0f, 10.0f); glVertex3f(x, y + height, z + length);
		glTexCoord2f(0.0f, 10.0f); glVertex3f(x, y + height, z);
		glEnd();

		// Draw Down side
		glBindTexture(GL_TEXTURE_2D, SKYDOWN);

		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
		glTexCoord2f(10.0f, 0.0f); glVertex3f(x, y, z + length);
		glTexCoord2f(10.0f, 10.0f); glVertex3f(x + width, y, z + length);
		glTexCoord2f(0.0f, 10.0f); glVertex3f(x + width, y, z);
		glEnd();

		glColor3f(1, 1, 1);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
};
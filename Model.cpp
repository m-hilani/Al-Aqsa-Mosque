#pragma once
#include <windows.h>		// Header File For Windows
#include <GL/gl.h>			// Header File For The OpenGL32 Library
#include <GL/glu.h>			// Header File For The GLu32 Library
#include <GL/glaux.h>		// Header File For The Glaux Library
#include <cmath>
#define PI 3.1415927


class Model
{

public:void draw_sphere(float r, float dome_img, float x, float y, float z)
{


	float di = 0.02;
	float dj = 0.04;
	float db = di * 2 * PI;
	float da = dj * PI;


	for (float i = 0; i < 0.97; i += di) //horizonal
		for (float j = 0; j < 1.0; j += dj) //vertical
		{
			float b = i * PI;      //0     to  2pi
			float a = (j - 0.5) * PI;  //-pi/2 to pi/2


			//normal
			glNormal3f(
				cos(a + da / 2) * cos(b + db / 2),
				cos(a + da / 2) * sin(b + db / 2),
				sin(a + da / 2));

			glBindTexture(GL_TEXTURE_2D, dome_img);
			glBegin(GL_QUADS);
			//P1

			glTexCoord2f(i, j);
			glVertex3f(
				(r * cos(a) * cos(b)) + x,
				(r * cos(a) * sin(b)) + y,
				(r * sin(a)) + z);
			//P2
			glTexCoord2f(i + di, j);//P2
			glVertex3f(
				(r * cos(a) * cos(b + db)) + x,
				(r * cos(a) * sin(b + db)) + y,
				(r * sin(a)) + z);
			//P3
			glTexCoord2f(i + di, j + dj);
			glVertex3f(
				(r * cos(a + da) * cos(b + db)) + x,
				(r * cos(a + da) * sin(b + db)) + y,
				(r * sin(a + da)) + z);
			//P4
			glTexCoord2f(i, j + dj);
			glVertex3f(
				(r * cos(a + da) * cos(b)) + x,
				(r * cos(a + da) * sin(b)) + y,
				(r * sin(a + da)) + z);
			glEnd();
		}
}

public:void draw_cylinder(GLfloat radius, GLfloat height, float cylinder_img, float x, float y, float z)

{
	GLfloat x1 = 0.0;
	GLfloat z1 = 0.0;
	GLfloat angle = 0.0;
	GLfloat angle_stepsize = 0.1;
	glBindTexture(GL_TEXTURE_2D, cylinder_img);
	glBegin(GL_QUAD_STRIP);
	angle = 0.0;
	while (angle < 2 * PI) {
		x1 = radius * cos(angle);
		z1 = radius * sin(angle);
		glTexCoord2d(0, 0);
		glVertex3f(x1 + x, height + y, z1 + z);
		glTexCoord2d(1, 0);
		glVertex3f(x1 + x, y, z1 + z);
		angle = angle + angle_stepsize;
	}
	glTexCoord2d(1, 1);
	glVertex3f(radius, height + y, z);
	glTexCoord2d(0, 1);
	glVertex3f(radius, y, z);
	glEnd();

}

public:void draw_Colum(GLfloat radius, GLfloat height, int  colum_img)

{
	GLfloat x = 0.0;
	GLfloat z = 0.0;
	GLfloat angle = 0.0;
	GLfloat angle_stepsize = 0.1;
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_QUAD_STRIP);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = radius * cos(angle);
		z = radius * sin(angle);
		glTexCoord2d(0, 0);
		glVertex3f(x, height, z);
		glTexCoord2d(1, 0);
		glVertex3f(x, 0, z);
		angle = angle + angle_stepsize;
	}
	glTexCoord2d(1, 1);
	glVertex3f(radius, height, 0);
	glTexCoord2d(0, 1);
	glVertex3f(radius, 0, 0);
	glEnd();

}

public: void Arc(int colum_img, float x1, float x2)
{
	float x, y;
	glPushMatrix();//Right
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord3d(0, 0, 0);
	glVertex3f(x2, 1, 0);
	glTexCoord3d(1, 0, 0);
	glVertex3f(0, 1, 0);
	glTexCoord3d(0, 1, 0);
	glVertex3f(0, 0.7, 0);
	for (float angle = 0.0f; angle <= (PI / 2); angle += 0.01f)
	{
		x = cos(angle);
		y = sin(angle);
		glTexCoord3d(1, 1, 0);
		glVertex3f(x, y, 0.0f);
	}
	glTexCoord3d(0, 0, 1);
	glVertex3f(0.7, 0, 0);
	glTexCoord3d(1, 0, 1);
	glVertex3f(x2, 0, 0);
	glEnd();

	glPopMatrix();//Leaft
	glRotated(180, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord3d(0, 0, 0);
	glVertex3f(x1, 1, 0);
	glTexCoord3d(1, 0, 0);
	glVertex3f(0, 1, 0);
	glTexCoord3d(0, 1, 0);
	glVertex3f(0, 0.7, 0);
	for (float angle = 0.0f; angle <= (PI / 2); angle += 0.01f)
	{
		x = cos(angle);
		y = sin(angle);
		glTexCoord3d(1, 1, 0);
		glVertex3f(x, y, 0.0f);
	}
	glTexCoord3d(0, 0, 1);
	glVertex3f(0.7, 0, 0);
	glTexCoord3d(1, 0, 1);
	glVertex3f(x1, 0, 0);
	glEnd();

}

public: void drawer(int chian, int angle, float Rx, float Ry, float Rz, float Tx, float Ty, float Tz, float Sx, float Sy, float Sz)
{
	glPushMatrix();//1
	glTranslated(Tx, Ty, Tz);
	glScaled(Sx, Sy, Sz);
	glRotated(angle, Rx, Ry, Rz);
	glBindTexture(GL_TEXTURE_2D, chian);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-550, 0, 300);
	glTexCoord2d(1, 0);
	glVertex3f(-550, -20, 300);
	glTexCoord2d(1, 1);
	glVertex3f(550, -20, 300);
	glTexCoord2d(0, 1);
	glVertex3f(550, 0, 300);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, chian);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-550, -20, 300);
	glTexCoord2d(1, 0);
	glVertex3f(-550, -20, 330);
	glTexCoord2d(1, 1);
	glVertex3f(550, -20, 330);
	glTexCoord2d(0, 1);
	glVertex3f(550, -20, 300);
	glEnd();
	glPopMatrix();



}


public:void Quads(int front_img, int back_img, int top_img, int right_img, int leaft_img, float Tx, float Ty, float Tz, float Sx, float Sy, float Sz)
{
	glPushMatrix();//Bottom face
	glTranslated(Tx, Ty, Tz);
	glScaled(Sx, Sy, Sz);
	glBegin(GL_QUADS);
	glVertex3d(-2, -2, -2);
	glVertex3d(2, -2, -2);
	glVertex3d(2, -2, 2);
	glVertex3d(-2, -2, 2);
	glEnd();
	glPopMatrix();

	glPushMatrix();//top face
	glTranslated(Tx, Ty, Tz);
	glScaled(Sx, Sy, Sz);
	glBindTexture(GL_TEXTURE_2D, top_img);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2, 2, -2);
	glTexCoord2d(1, 0);
	glVertex3d(2, 2, -2);
	glTexCoord2d(1, 1);
	glVertex3d(2, 2, 2);
	glTexCoord2d(0, 1);
	glVertex3d(-2, 2, 2);
	glEnd();
	glPopMatrix();

	glPushMatrix();//front face
	glTranslated(Tx, Ty, Tz);
	glScaled(Sx, Sy, Sz);
	glBindTexture(GL_TEXTURE_2D, front_img);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2, -2, 2);
	glTexCoord2d(1, 0);
	glVertex3d(2, -2, 2);
	glTexCoord2d(1, 1);
	glVertex3d(2, 2, 2);
	glTexCoord2d(0, 1);
	glVertex3d(-2, 2, 2);
	glEnd();
	glPopMatrix();
	glPushMatrix();//back face
	glTranslated(Tx, Ty, Tz);
	glScaled(Sx, Sy, Sz);
	glBindTexture(GL_TEXTURE_2D, back_img);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2, -2, -2);
	glTexCoord2d(1, 0);
	glVertex3d(2, -2, -2);
	glTexCoord2d(1, 1);
	glVertex3d(2, 2, -2);
	glTexCoord2d(0, 1);
	glVertex3d(-2, 2, -2);
	glEnd();
	glPopMatrix();

	glPushMatrix();//right face
	glTranslated(Tx, Ty, Tz);
	glScaled(Sx, Sy, Sz);
	glBindTexture(GL_TEXTURE_2D, right_img);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(2, -2, 2);
	glTexCoord2d(1, 0);
	glVertex3d(2, -2, -2);
	glTexCoord2d(1, 1);
	glVertex3d(2, 2, -2);
	glTexCoord2d(0, 1);
	glVertex3d(2, 2, 2);
	glEnd();
	glPopMatrix();

	glPushMatrix();//leaft face
	glTranslated(Tx, Ty, Tz);
	glScaled(Sx, Sy, Sz);
	glBindTexture(GL_TEXTURE_2D, leaft_img);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2, -2, 2);
	glTexCoord2d(1, 0);
	glVertex3d(-2, 2, 2);
	glTexCoord2d(1, 1);
	glVertex3d(-2, 2, -2);
	glTexCoord2d(0, 1);
	glVertex3d(-2, -2, -2);
	glEnd();
	glPopMatrix();


}

public:void door_windo(int image, float Tx, float Ty, float Tz, float Sx, float Sy, float Sz, int angle, float Rx, float Ry, float Rz)
{

	glPushMatrix();
	glTranslated(Tx, Ty, Tz);
	glScaled(Sx, Sy, Sz);
	glRotated(angle, Rx, Ry, Rz);
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2, -2, 2);
	glTexCoord2d(1, 0);
	glVertex3d(-2, 2, 2);
	glTexCoord2d(1, 1);
	glVertex3d(-2, 2, -2);
	glTexCoord2d(0, 1);
	glVertex3d(-2, -2, -2);
	glEnd();
	glPopMatrix();


}

};

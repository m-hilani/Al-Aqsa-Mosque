#include <windows.h>		// Header File For Windows
#include "GL.H"			// Header File For The OpenGL32 Library
#include "glu.h"			// Header File For The GLu32 Library
#include "GLAUX.H"	// Header File For The Glaux Library
#include <cmath>
class Floor
{
public:void floor(int image)
{
	glPushMatrix();
	glScaled(50, 3, 30);
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-300, -30, 200);
	glTexCoord2d(1, 0);
	glVertex3f(300, -30, 200);
	glTexCoord2d(1, 1);
	glVertex3f(300, -30, -165);
	glTexCoord2d(0, 1);
	glVertex3f(-300, -30, -165);
	glEnd();
	glPopMatrix();

	glPushMatrix();//Land of the door of mercy and repentanceارض باب الرحمة والتوبة
	glTranslated(-500, -250, -7000);
	glScaled(45, 3, 20);
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-300, -30, 120);
	glTexCoord2d(1, 0);
	glVertex3f(300, -30, 120);
	glTexCoord2d(1, 1);
	glVertex3f(300, -30, -250);
	glTexCoord2d(0, 1);
	glVertex3f(-300, -30, -250);
	glEnd();
	glPopMatrix();


}

};

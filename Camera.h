#pragma once
#include <windows.h>		// Header File For Windows
#include <GL/gl.h>			// Header File For The OpenGL32 Library
#include <GL/glu.h>			// Header File For The GLu32 Library
#include <GL/glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "Main.cpp"

class Camera
{
	double movX, movY, movZ;
	double lX, lY;

	void camera()
	{
		gluLookAt(movX, movY, movZ, lX, lY, -5, 0, 1, 0);
		if (keys['D'])
			movX += 0.001;
		if (keys['A'])
			movX -= 0.001;
		if (keys['W'])
			movY += 0.001;
		if (keys['S'])
			movY -= 0.001;
		if (keys['Z'])
			movZ += 0.001;
		if (keys['X'])
			movZ -= 0.001;
		if (keys[VK_LEFT])
			lX += 0.001;
		if (keys[VK_RIGHT])
			lX -= 0.001;
		if (keys[VK_UP])
			lY += 0.001;
		if (keys[VK_DOWN])
			lY -= 0.001;
	}
};


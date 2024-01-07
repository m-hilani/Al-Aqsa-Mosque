#include <windows.h>		// Header File For Windows
#include "GL.H"			// Header File For The OpenGL32 Library
#include "glu.h"			// Header File For The GLu32 Library
#include "GLAUX.H"	// Header File For The Glaux Library
#include <cmath>
#include "Model.cpp"





class Fields_Trees
{

	Model m1 = Model();



public: void fields_trees(int image, float Tx, float Ty, float Tz, float Sx, float Sy, float Sz)
{

	glPushMatrix();
	glTranslated(Tx, Ty, Tz);
	glScaled(Sx, Sy, Sz);
	glBindTexture(GL_TEXTURE_2D, image);
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

}

public: void Grass(int image, int colum_img, int chian, int platform_colum, int platform_img)
{
	//field1 right
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2500, -100, -2520, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2500, -100, -3300, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -520, -100, -2920, 10, 20, 190);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -4490, -100, -2920, 10, 20, 190);
	fields_trees(image, -2500, -90, -2900, 990, 5, 190);
	//field2 right
	glPushMatrix();
	glTranslated(0, 0, -1600);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2500, -100, -2520, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2500, -100, -3300, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -520, -100, -2920, 10, 20, 190);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -4490, -100, -2920, 10, 20, 190);
	fields_trees(image, -2500, -90, -2900, 990, 5, 190);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2600, -130, -3330, 1100, 100, 10);//wall
	glPopMatrix();
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -390, -130, -5500, 300, 100, 10);//1حائط درج باب الرحمة و التوبة
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 250, -130, -5230, 20, 100, 150);

	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -6750, -130, -5230, 20, 100, 150);//2حائط درج باب الرحمة و التوبة
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -7370, -130, -5230, 20, 100, 150);
	glPushMatrix();//المسطبة شبه اسطوانية
	glTranslated(-5100, 50, -4600);
	m1.draw_cylinder(200, 50, chian, 0, 0, 0);
	glPopMatrix();
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -5100, -130, -4610, 300, 100, 150);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -5700, -130, -4930, 510, 100, 10);
	//field3 right
	glPushMatrix();
	glTranslated(-7000, 0, -1600);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2500, -100, -2520, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2500, -100, -3300, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -520, -100, -2920, 10, 20, 190);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -4490, -100, -2920, 10, 20, 190);
	fields_trees(image, -2500, -90, -2900, 990, 5, 190);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2600, -130, -3330, 1100, 100, 10);//wall
	glPopMatrix();

	//field4
	glPushMatrix();
	glTranslated(2000, -250, -3600);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2500, -100, -2320, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2500, -100, -3500, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -520, -100, -2920, 10, 20, 290);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -4490, -100, -2920, 10, 20, 290);
	fields_trees(image, -2500, -90, -2900, 990, 5, 290);
	glPopMatrix();

	//field5
	glPushMatrix();
	glTranslated(3500, -250, -5600);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2500, -100, -2320, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2500, -100, -3500, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -520, -100, -2920, 10, 20, 290);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -4490, -100, -2920, 10, 20, 290);
	fields_trees(image, -2500, -90, -2900, 990, 5, 290);
	glPopMatrix();

	//field6
	glPushMatrix();
	glTranslated(-1900, -250, -7000);
	glRotated(20, 0, 1, 0);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2300, -100, -2320, 300, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2300, -100, -3500, 300, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -1720, -100, -2920, 10, 20, 290);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2880, -100, -2920, 10, 20, 290);
	fields_trees(image, -2300, -90, -2900, 290, 5, 290);
	glPopMatrix();

	////field7
	glPushMatrix();
	glTranslated(-3200, -250, -3600);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2500, -100, -2600, 900, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2500, -100, -3200, 900, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -720, -100, -2920, 10, 20, 150);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -4300, -100, -2920, 10, 20, 150);
	fields_trees(image, -2500, -90, -2900, 890, 5, 150);
	glPopMatrix();

	//field8
	glPushMatrix();
	glTranslated(-6000, -250, -5000);
	glRotated(20, 0, 1, 0);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2300, -100, -2320, 300, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2300, -100, -3500, 300, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -1720, -100, -2920, 10, 20, 290);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2880, -100, -2920, 10, 20, 290);
	fields_trees(image, -2300, -90, -2900, 290, 5, 290);
	glPopMatrix();

	//field2 leaft
	glPushMatrix();
	glTranslated(-100, 0, -1600);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 2500, -100, -2520, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 2500, -100, -3300, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 520, -100, -2920, 10, 20, 190);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 4490, -100, -2920, 10, 20, 190);
	fields_trees(image, 2500, -90, -2900, 990, 5, 190);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 2550, -130, -3330, 1100, 100, 10);//wall
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 5500, -130, -3330, 1100, 100, 10);//wall
	glPopMatrix();

	//field1 leaft
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 2500, -100, -2520, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 2500, -100, -3300, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 520, -100, -2920, 10, 20, 190);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 4490, -100, -2920, 10, 20, 190);
	fields_trees(image, 2500, -90, -2900, 990, 5, 190);

	//field3 leaft
	glPushMatrix();
	glTranslated(5400, 0, -1600);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 2500, -100, -2520, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 2500, -100, -3300, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 520, -100, -2920, 10, 20, 190);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 4490, -100, -2920, 10, 20, 190);
	fields_trees(image, 2500, -90, -2900, 990, 5, 190);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 2300, -130, -3330, 1100, 100, 10);//wall
	glPopMatrix();

	glPushMatrix();//مسطبة صبرة وشاتيلا
	glTranslated(5600, -35, -4200);
	m1.draw_cylinder(40, 25, platform_colum, 0, 0, 0);
	m1.draw_cylinder(35, 40, platform_colum, 0, 0, 0);
	m1.draw_cylinder(30, 55, platform_colum, 0, 0, 0);
	m1.draw_cylinder(25, 70, platform_colum, 0, 0, 0);
	m1.draw_cylinder(20, 95, platform_colum, 0, 0, 0);
	glPopMatrix();
	m1.Quads(platform_img, platform_img, platform_img, platform_img, platform_img, 5200, -100, -4500, 350, 35, 200);

	//field4 leaft
	glPushMatrix();
	glTranslated(2000, -250, -3600);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 2500, -100, -2320, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 2500, -100, -3500, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 520, -100, -2920, 10, 20, 290);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, 4490, -100, -2920, 10, 20, 290);
	fields_trees(image, 2500, -90, -2900, 990, 5, 290);
	glPopMatrix();

	//field5 leaft
	glPushMatrix();
	glTranslated(8000, -250, -5600);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2500, -100, -2320, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -2500, -100, -3500, 1000, 20, 10);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -520, -100, -2920, 10, 20, 290);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -4490, -100, -2920, 10, 20, 290);
	fields_trees(image, -2500, -90, -2900, 990, 5, 290);
	m1.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -3000, -100, -2920, 250, 20, 250);
	m1.Quads(platform_img, platform_img, platform_img, platform_img, platform_img, 2000, -100, -2000, 500, 20, 400);
	glPopMatrix();





}


};

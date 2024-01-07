#include <windows.h>		// Header File For Windows
#include "GL.H"			// Header File For The OpenGL32 Library
#include "glu.h"			// Header File For The GLu32 Library
#include "GLAUX.H"		// Header File For The Glaux Library
#include <cmath>
#include "Model.cpp"

//الابواب الخارجية مع الثور الخارجي

class Door
{
	Model m2 = Model();

public:void door(int colum_img, int door_mercy_img, int chian, int  DarAlHadith, int DarAlHadith2, int Door_alasibat, int Door_alasibat2)
{
	//door_mercyباب الرحمة
	m2.Quads(door_mercy_img, door_mercy_img, colum_img, colum_img, colum_img, -3000, 0, -10200, 400, 350, 100);
	//wall_mercy1 الحائط على يمين باب الرحمة
	glPushMatrix();
	glRotated(20, 0, 1, 0);
	m2.Quads(chian, chian, chian, chian, chian, -5000, 0, -11000, 2500, 300, 20);
	m2.Quads(DarAlHadith, DarAlHadith2, DarAlHadith2, DarAlHadith2, DarAlHadith2, -3400, 0, -10300, 400, 250, 350);// DarAlHadith
	glPopMatrix();
	//wall_mercy2الحائط على يسار باب الرحمة
	m2.Quads(chian, chian, chian, chian, chian, 5000, 0, -10200, 3700, 300, 20);
	//مصطبة باب الاسباط
	m2.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -12700, -230, -5900, 450, 100, 500);
	m2.Quads(chian, chian, chian, chian, chian, -11760, -300, -6200, 30, 100, 620);
	m2.Quads(chian, chian, chian, chian, chian, -11680, -360, -6200, 30, 100, 620);
	m2.Quads(chian, chian, chian, chian, chian, -11600, -420, -6200, 30, 100, 620);
	m2.Quads(chian, chian, chian, chian, chian, -11520, -480, -6200, 30, 100, 620);
	//باب الاسباط
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -14000, -170, -5900, 550, 100, 500);//land
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -14200, 400, -6900, 500, 500, 25);//wall
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -15200, 400, -5900, 25, 500, 500);//wall
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -13000, 400, -5000, 50, 500, 50);//colum1
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -13050, 400, -6820, 75, 500, 50);//colum2
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -14000, 400, -5000, 50, 500, 50);//colum2
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -14000, 1400, -5900, 550, 10, 500);//roof
	glPushMatrix();//1
	glTranslated(-12900, 900, -5900);
	glScaled(500, 500, 1000);
	glRotated(90, 0, 1, 0);
	m2.Arc(Door_alasibat2, 1, 1);
	glPopMatrix();
	glPushMatrix();//2
	glTranslated(-13500, 900, -5000);
	glScaled(500, 500, 500);
	m2.Arc(Door_alasibat2, 1, 1);
	glPopMatrix();
	glPushMatrix();//3
	glTranslated(-14600, 900, -5000);
	glScaled(500, 500, 500);
	m2.Arc(Door_alasibat2, 1, 1);
	glPopMatrix();
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat, Door_alasibat, -15150, 600, -4200, 20, 400, 400);//door
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -14700, 400, -3400, 400, 500, 25);//wall
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -14500, 1400, -4200, 300, 10, 500);//roof
	glPushMatrix();
	glTranslated(-14000, 900, -4200);
	glScaled(500, 500, 800);
	glRotated(90, 0, 1, 0);
	m2.Arc(Door_alasibat2, 1, 1);
	glPopMatrix();




}



};

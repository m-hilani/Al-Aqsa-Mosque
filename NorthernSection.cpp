#include <windows.h>		// Header File For Windows
#include "GL.H"			// Header File For The OpenGL32 Library
#include "glu.h"			// Header File For The GLu32 Library
#include "GLAUX.H"		// Header File For The Glaux Library
#include <cmath>
#include "Model.cpp"

class Northern_section
{
	Model m2 = Model();

public:void Northern_schools(int Door_alasibat2, int school, int Door_build2, int colum_img, int chian, int school2, int Door_school2, int school4, int school5, int school6, int school9, int school8, int minaret)
{                             //ثانوية الاقصى الشرعية
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school, Door_alasibat2, -14000, 700, -2600, 300, 400, 300);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school, Door_alasibat2, -14000, 700, -1400, 300, 400, 300);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school, Door_alasibat2, -14000, 700, -200, 300, 400, 300);
	//مأذنة باب الاسباط
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_build2, Door_alasibat2, -14000, 500, 700, 350, 300, 150);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -14000, 1400, 700, 350, 150, 150);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -14000, 5600, 685, 200, 100, 200);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -14000, 3600, 685, 200, 50, 200);
	glPushMatrix();
	glTranslated(-14000, 1500, 700);
	m2.draw_Colum(300, 3900, colum_img);
	m2.draw_sphere(350, chian, 1, 4400, 1);
	glPopMatrix();
	glPushMatrix();//1
	glTranslated(-14000, 5800, 700);
	m2.draw_Colum(350, 100, chian);
	glPopMatrix();
	glPushMatrix();//11
	glTranslated(-14000, 6200, 700);
	m2.draw_Colum(20, 250, chian);
	glPopMatrix();
	glPushMatrix();//2
	glTranslated(-14000, 2500, 700);
	m2.draw_Colum(305, 20, chian);
	glPopMatrix();
	glPushMatrix();//3
	glTranslated(-14000, 4500, 700);
	m2.draw_Colum(305, 20, chian);
	glPopMatrix();
	//المدرسة الغادرية
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school2, Door_alasibat2, -14000, 700, 1500, 300, 400, 300);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school2, Door_alasibat2, -14000, 700, 2700, 300, 400, 300);
	//المدرسة السعردية
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school5, Door_alasibat2, -14000, 700, 4900, 300, 400, 300);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school5, Door_alasibat2, -14000, 700, 6100, 300, 400, 300);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school5, Door_alasibat2, -14000, 700, 7300, 300, 400, 300);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school4, Door_alasibat2, -14000, 2100, 4900, 300, 400, 300);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school4, Door_alasibat2, -14000, 2100, 6100, 300, 400, 300);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school4, Door_alasibat2, -14000, 2100, 7300, 300, 400, 300);
	//المدرسة العمرية
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school6, Door_alasibat2, -14000, 700, 8500, 300, 400, 300);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school6, Door_alasibat2, -14000, 700, 9700, 300, 400, 300);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school9, Door_alasibat2, -14000, 700, 10900, 300, 400, 300);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school8, Door_alasibat2, -14000, 2200, 8500, 300, 400, 300);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school8, Door_alasibat2, -14000, 2200, 9700, 300, 400, 300);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school8, Door_alasibat2, -14000, 2200, 10900, 300, 400, 300);
	//الزاوية الرفاعية
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school2, Door_alasibat2, -14000, 700, 12100, 300, 400, 300);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_build2, Door_alasibat2, -14000, 700, 13300, 300, 400, 300);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school2, Door_alasibat2, -14000, 700, 14500, 300, 400, 300);
	//مأذنة باب الغوانمة
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -14000, 700, 15700, 300, 400, 300);
	m2.Quads(minaret, minaret, Door_alasibat2, minaret, minaret, -14000, 2500, 15700, 250, 500, 250);
	m2.Quads(minaret, minaret, Door_alasibat2, minaret, minaret, -14000, 4500, 15700, 250, 500, 250);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -14000, 5400, 15700, 320, 30, 320);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -14000, 6300, 15700, 320, 30, 320);
	glPushMatrix();//1
	glTranslated(-13500, 5400, 15200);
	m2.draw_Colum(30, 900, Door_alasibat2);
	glPopMatrix();
	glPushMatrix();//2
	glTranslated(-14500, 5400, 15200);
	m2.draw_Colum(30, 900, Door_alasibat2);
	glPopMatrix();
	glPushMatrix();//3
	glTranslated(-14500, 5400, 16200);
	m2.draw_Colum(30, 900, Door_alasibat2);
	glPopMatrix();
	glPushMatrix();//4
	glTranslated(-13500, 5400, 16200);
	m2.draw_Colum(30, 900, Door_alasibat2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-14000, 6350, 15700);
	m2.draw_Colum(400, 300, chian);
	m2.draw_sphere(400, chian, 1, 300, 1);
	glPopMatrix();

	glPushMatrix();//5
	glTranslated(-14000, 7000, 15700);
	m2.draw_Colum(40, 200, chian);
	glPopMatrix();
	//قبة أحباب النبي صلى الله عليه وسلم
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -8800, -100, -700, 50, 500, 50);//colum1
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -9800, -100, -700, 50, 500, 50);//colum2
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -8800, -100, 300, 50, 500, 50);//colum3
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -9800, -100, 300, 50, 500, 50);//colum4
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -9300, 900, -200, 300, 20, 300);//roof
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -9500, -90, -200, 400, 20, 300);//land
	m2.Quads(colum_img, colum_img, colum_img, colum_img, colum_img, -10500, -60, -200, 300, 20, 300);//land
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -10500, -100, -200, 20, 300, 50);//colum5
	m2.draw_sphere(400, Door_alasibat2, -9300, 900, -200);
	glPushMatrix();//1
	glTranslated(-8700, 600, -200);
	glScaled(300, 300, 500);
	glRotated(90, 0, 1, 0);
	m2.Arc(Door_alasibat2, 1, 1);
	glPopMatrix();
	glPushMatrix();//2
	glTranslated(-9900, 600, -200);
	glScaled(300, 300, 500);
	glRotated(90, 0, 1, 0);
	m2.Arc(Door_alasibat2, 1, 1);
	glPopMatrix();
	glPushMatrix();//3
	glTranslated(-9300, 600, -800);
	glScaled(500, 300, 300);
	m2.Arc(Door_alasibat2, 1, 1);
	glPopMatrix();
	glPushMatrix();//4
	glTranslated(-9300, 600, 400);
	glScaled(500, 300, 300);
	m2.Arc(Door_alasibat2, 1, 1);
	glPopMatrix();

}


};
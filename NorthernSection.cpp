#include <windows.h>		// Header File For Windows
#include <GL/gl.h>			// Header File For The OpenGL32 Library
#include <GL/glu.h>			// Header File For The GLu32 Library
#include <GL/glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "Model.cpp"

class Northern_section
{
	Model m2 = Model();

public:void Northern_schools(int Door_alasibat2, int school, int Door_build2, int colum_img, int chian)
{                             //ثانوية الاقصى الشرعية
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school, Door_alasibat2, -14000, 700, -2600, 300, 400, 300);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school, Door_alasibat2, -14000, 700, -1400, 300, 400, 300);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, school, Door_alasibat2, -14000, 700, -200, 300, 400, 300);
	//مأذنة باب الاسباط
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_build2, Door_alasibat2, -14000, 500, 700, 350, 300, 150);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -14000, 1400, 700, 350, 150, 150);
	m2.Quads(Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, Door_alasibat2, -14000, 5600, 675, 200, 100, 200);

	glPushMatrix();
	glTranslated(-14000, 1500, 700);
	m2.draw_Colum(300, 3900, colum_img);
	m2.draw_sphere(350, chian, 1, 4300, 1);
	glPopMatrix();
}



};
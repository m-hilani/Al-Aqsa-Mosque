#include <windows.h>		// Header File For Windows
#include "GL.H"			// Header File For The OpenGL32 Library
#include "glu.h"			// Header File For The GLu32 Library
#include "GLAUX.H"			// Header File For The Glaux Library
#include <cmath>
#include"Model.cpp"
#define PI 3.1415927





class Dome_Rock
{
	Model m = Model();

	//Floor of the Dome of the Rock Mosque
public:void land_of_theRock(int image)
{

	glPushMatrix();//1
	glTranslated(0, 0, 1000);
	glScaled(20, 0, 40);
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-125, 0, 100);
	glTexCoord2d(1, 0);
	glVertex3f(-25, 0, 100);
	glTexCoord2d(1, 1);
	glVertex3f(-25, 0, 25);
	glTexCoord2d(0, 1);
	glVertex3f(-125, 0, 25);
	glEnd();
	glPopMatrix();

	glPushMatrix();//2
	glTranslated(-250, 0, 1000);
	glScaled(30, 0, 40);
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(25, 0, 100);
	glTexCoord2d(1, 0);
	glVertex3f(125, 0, 100);
	glTexCoord2d(1, 1);
	glVertex3f(125, 0, 25);
	glTexCoord2d(0, 1);
	glVertex3f(25, 0, 25);
	glEnd();
	glPopMatrix();
	glPushMatrix();//3
	glTranslated(-250, 0, 1750);
	glScaled(30, 0, 34);
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(25, 0, -25);
	glTexCoord2d(1, 0);
	glVertex3f(125, 0, -25);
	glTexCoord2d(1, 1);
	glVertex3f(125, 0, -125);
	glTexCoord2d(0, 1);
	glVertex3f(25, 0, -125);
	glEnd();
	glPopMatrix();
	glPushMatrix();//4
	glTranslated(0, 0, 1750);
	glScaled(20, 0, 34);
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-25, 0, -25);
	glTexCoord2d(1, 0);
	glVertex3f(-25, 0, -125);
	glTexCoord2d(1, 1);
	glVertex3f(-125, 0, -125);
	glTexCoord2d(0, 1);
	glVertex3f(-125, 0, -25);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, 1400);
	glScaled(23.5, 0, 25);
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-100, 0, 25);
	glTexCoord2d(1, 0);
	glVertex3f(-100, 0, -25);
	glTexCoord2d(1, 1);
	glVertex3f(-20, 0, -25);
	glTexCoord2d(0, 1);
	glVertex3f(-20, 0, 25);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, 1650);
	glScaled(20, 0, 40);
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-25, 0, 80);
	glTexCoord2d(1, 0);
	glVertex3f(25, 0, 80);
	glTexCoord2d(1, 1);
	glVertex3f(25, 0, 0);
	glTexCoord2d(0, 1);
	glVertex3f(-25, 0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(350, 0, 1400);
	glScaled(30, 0, 25);
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(100, 0, 25);
	glTexCoord2d(1, 0);
	glVertex3f(100, 0, -25);
	glTexCoord2d(1, 1);
	glVertex3f(0, 0, -25);
	glTexCoord2d(0, 1);
	glVertex3f(0, 0, 25);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, 1600);
	glScaled(20, 0, 40);
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(25, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3f(-25, 0, 0);
	glTexCoord2d(1, 1);
	glVertex3f(-25, 0, -100);
	glTexCoord2d(0, 1);
	glVertex3f(25, 0, -100);
	glEnd();
	glPopMatrix();


}
	  //Dome of the Rock Mosque
public: void dome_of_theRock_mosque(int cylinder_img, int dome_img, int roof_img, int wall_img1, int  wall_img2)
{
	m.draw_cylinder(600, 300, cylinder_img, 550, 1000, 1500);
	m.draw_sphere(600, dome_img, 550, 1300, 1500);
	m.draw_sphere(30, dome_img, 550, 2100, 1500);
	glPushMatrix();
	glTranslated(550, 1800, 1500);
	m.draw_cylinder(30, 300, dome_img, 1, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(500, 0, 2000);
	glScaled(50, 1, 60);
	glBegin(GL_POLYGON);
	glVertex3f(-10, 0, 10);//1
	glVertex3f(10, 0, 10);//2
	glVertex3f(23, 0, -1);//3
	glVertex3f(23, 0, -19);//4
	glVertex3f(10, 0, -30);//5
	glVertex3f(-10, 0, -30);//6
	glVertex3f(-23, 0, -19);//7
	glVertex3f(-23, 0, -1);//8
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(500, 0, 2000);
	glScaled(50, 50, 60);
	glBindTexture(GL_TEXTURE_2D, roof_img);
	glBegin(GL_POLYGON);
	glTexCoord3d(0, 0, 0);
	glVertex3f(-10, 20, 10);//1*
	glTexCoord3d(1, 0, 0);
	glVertex3f(10, 20, 10);//2*
	glTexCoord3d(0, 1, 0);
	glVertex3f(23, 20, -1);//3*
	glTexCoord3d(1, 1, 0);
	glVertex3f(23, 20, -19);//4*
	glTexCoord3d(0, 0, 1);
	glVertex3f(10, 20, -30);//5*
	glTexCoord3d(1, 0, 1);
	glVertex3f(-10, 20, -30);//6*
	glTexCoord3d(0, 1, 1);
	glVertex3f(-23, 20, -19);//7*
	glTexCoord3d(1, 1, 1);
	glVertex3f(-23, 20, -1);//8*
	glEnd();
	glPopMatrix();

	glPushMatrix();///1
	glTranslated(500, 0, 2000);
	glScaled(50, 50, 60);
	glBindTexture(GL_TEXTURE_2D, wall_img1);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-10, 0, 10);//1
	glTexCoord2d(1, 0);
	glVertex3f(10, 0, 10);//2
	glTexCoord2d(1, 1);
	glVertex3f(10, 20, 10);//2*
	glTexCoord2d(0, 1);
	glVertex3f(-10, 20, 10);//1*
	glEnd();
	glPopMatrix();

	glPushMatrix();///2
	glTranslated(500, 0, 2000);
	glScaled(50, 50, 60);
	glBindTexture(GL_TEXTURE_2D, wall_img2);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(10, 0, 10);//2
	glTexCoord2d(1, 0);
	glVertex3f(23, 0, -1);//3
	glTexCoord2d(1, 1);
	glVertex3f(23, 20, -1);//3*
	glTexCoord2d(0, 1);
	glVertex3f(10, 20, 10);//2*
	glEnd();
	glPopMatrix();

	glPushMatrix();///3
	glTranslated(500, 0, 2000);
	glScaled(50, 50, 60);
	glBindTexture(GL_TEXTURE_2D, wall_img1);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(23, 0, -1);//3
	glTexCoord2d(1, 0);
	glVertex3f(23, 0, -19);//4
	glTexCoord2d(1, 1);
	glVertex3f(23, 20, -19);//4*
	glTexCoord2d(0, 1);
	glVertex3f(23, 20, -1);//3*
	glEnd();
	glPopMatrix();


	glPushMatrix();///4
	glTranslated(500, 0, 2000);
	glScaled(50, 50, 60);
	glBindTexture(GL_TEXTURE_2D, wall_img2);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(23, 0, -19);//4
	glTexCoord2d(1, 0);
	glVertex3f(10, 0, -30);//5
	glTexCoord2d(1, 1);
	glVertex3f(10, 20, -30);//5*
	glTexCoord2d(0, 1);
	glVertex3f(23, 20, -19);//4*
	glEnd();
	glPopMatrix();

	glPushMatrix();///5
	glTranslated(500, 0, 2000);
	glScaled(50, 50, 60);
	glBindTexture(GL_TEXTURE_2D, wall_img1);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(10, 0, -30);//5
	glTexCoord2d(1, 0);
	glVertex3f(-10, 0, -30);//6
	glTexCoord2d(1, 1);
	glVertex3f(-10, 20, -30);//6*
	glTexCoord2d(0, 1);
	glVertex3f(10, 20, -30);//5*
	glEnd();
	glPopMatrix();

	glPushMatrix();///6
	glTranslated(500, 0, 2000);
	glScaled(50, 50, 60);
	glBindTexture(GL_TEXTURE_2D, wall_img2);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-10, 0, -30);//6
	glTexCoord2d(1, 0);
	glVertex3f(-23, 0, -19);//7
	glTexCoord2d(1, 1);
	glVertex3f(-23, 20, -19);//7*
	glTexCoord2d(0, 1);
	glVertex3f(-10, 20, -30);//6*
	glEnd();
	glPopMatrix();

	glPushMatrix();///7
	glTranslated(500, 0, 2000);
	glScaled(50, 50, 60);
	glBindTexture(GL_TEXTURE_2D, wall_img1);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-23, 0, -19);//7
	glTexCoord2d(1, 0);
	glVertex3f(-23, 0, -1);//8
	glTexCoord2d(1, 1);
	glVertex3f(-23, 20, -1);//8*
	glTexCoord2d(0, 1);
	glVertex3f(-23, 20, -19);//7*
	glEnd();
	glPopMatrix();

	glPushMatrix();///8
	glTranslated(500, 0, 2000);
	glScaled(50, 50, 60);
	glBindTexture(GL_TEXTURE_2D, wall_img2);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-10, 0, 10);//1
	glTexCoord2d(1, 0);
	glVertex3f(-23, 0, -1);//8
	glTexCoord2d(1, 1);
	glVertex3f(-23, 20, -1);//8*
	glTexCoord2d(0, 1);
	glVertex3f(-10, 20, 10);//1*
	glEnd();
	glPopMatrix();


}
	  //Surrounding domes for Dome of the Rock Mosque
public: void Quads_Chain_dome(int chian_img2, int angle, float Rx, float Ry, float Rz, float Tx, float Ty, float Tz)
{
	glPushMatrix();

	glTranslated(Tx, Ty, Tz);
	glScaled(8, 2, 9);
	glRotated(angle, Rx, Ry, Rz);
	glBindTexture(GL_TEXTURE_2D, chian_img2);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-10, 0, 10);//1
	glTexCoord2d(1, 0);
	glVertex3f(10, 0, 10);//2
	glTexCoord2d(1, 1);
	glVertex3f(10, 20, 10);//1
	glTexCoord2d(0, 1);
	glVertex3f(-10, 20, 10);//2
	glEnd();
	glPopMatrix();
}
public:void Chain_dome(int colum_img, int chian, int  chian_img2)
{
	glPushMatrix();
	glTranslated(1, 1, -1230);
	glScaled(7.5, 7.5, 7.5);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-10, 0, 10);//1
	glTexCoord2d(1, 0);
	glVertex3f(10, 0, 10);//2
	glTexCoord2d(1, 1);
	glVertex3f(23, 0, -1);//3
	glTexCoord2d(0, 1);
	glVertex3f(23, 0, -19);//4
	glTexCoord2d(0, 0);
	glVertex3f(10, 0, -30);//5
	glTexCoord2d(1, 0);
	glVertex3f(-10, 0, -30);//6
	glTexCoord2d(1, 1);
	glVertex3f(-23, 0, -19);//7
	glTexCoord2d(0, 1);
	glVertex3f(-23, 0, -1);//8
	glEnd();
	glPopMatrix();

	columns_middle(colum_img, 10, 137, -69, 0, -1170);//colum1
	columns_middle(colum_img, 10, 137, 71, 0, -1170);//colum2
	columns_middle(colum_img, 10, 137, 140, 0, -1237);//colum3
	columns_middle(colum_img, 10, 137, 162, 0, -1363);//colum4
	columns_middle(colum_img, 10, 137, 71, 0, -1440);//colum5
	columns_middle(colum_img, 10, 137, -71, 0, -1440);//colum6
	columns_middle(colum_img, 10, 137, -162, 0, -1373);//colum7
	columns_middle(colum_img, 10, 137, -135, 0, -1237);//colum8

	glPushMatrix();   //roof     
	glTranslated(1, -10, -1215);
	glScaled(9.5, 8.6, 9.5);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-10, 20, 10);//1(-89,150,-1125)
	glTexCoord2d(1, 0);
	glVertex3f(10, 20, 10);//2(91,150,-1125)
	glTexCoord2d(1, 1);
	glVertex3f(23, 20, -1);//3
	glTexCoord2d(0, 1);
	glVertex3f(23, 20, -19);//4
	glTexCoord2d(0, 0);
	glVertex3f(10, 20, -30);//5
	glTexCoord2d(1, 0);
	glVertex3f(-10, 20, -30);//6
	glTexCoord2d(1, 1);
	glVertex3f(-23, 20, -19);//7
	glTexCoord2d(0, 1);
	glVertex3f(-23, 20, -1);//8
	glEnd();
	glPopMatrix();

	glPushMatrix();   //roof1     
	glTranslated(1, -50, -1215);
	glScaled(9.2, 8.5, 9.2);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-10, 20, 10);//1 
	glTexCoord2d(1, 0);
	glVertex3f(10, 20, 10);//2   
	glTexCoord2d(1, 1);
	glVertex3f(23, 20, -1);//3
	glTexCoord2d(0, 1);
	glVertex3f(23, 20, -19);//4
	glTexCoord2d(0, 0);
	glVertex3f(10, 20, -30);//5
	glTexCoord2d(1, 0);
	glVertex3f(-10, 20, -30);//6
	glTexCoord2d(1, 1);
	glVertex3f(-23, 20, -19);//7
	glTexCoord2d(0, 1);
	glVertex3f(-23, 20, -1);//8
	glEnd();
	glPopMatrix();

	Quads_Chain_dome(chian_img2, 0, 0, 0, 0, 1, 120, -1220);
	Quads_Chain_dome(chian_img2, 45, 0, 1, 0, 105, 120, -1250);
	Quads_Chain_dome(chian_img2, 145, 0, 1, 0, -200, 120, -1100);
	Quads_Chain_dome(chian_img2, 90, 0, 1, 0, 135, 120, -1330);
	Quads_Chain_dome(chian_img2, 90, 0, 1, 0, -295, 120, -1310);
	Quads_Chain_dome(chian_img2, 150, 0, 1, 0, 100, 120, -1380);
	Quads_Chain_dome(chian_img2, 215, 0, 1, 0, -100, 120, -1380);
	Quads_Chain_dome(chian_img2, 0, 0, 0, 0, -5, 120, -1590);


	glPushMatrix();//dome
	glTranslated(1, 40, -1300);
	m.draw_sphere(100, chian, 0, 157, 0);
	glPopMatrix();

	glPushMatrix(); //cylinder2
	glTranslated(1, 10, -1300);
	m.draw_cylinder(100, 50, chian_img2, 0, 147, 0);
	glPopMatrix();



}
public:void Chain_dome_Small(int colum_img, int chian, int  chian_img2)
{
	glPushMatrix();
	glTranslated(-800, 0, 2800);
	glScaled(4.1, 2, 4.1);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-10, 0, 10);//1
	glTexCoord2d(1, 0);
	glVertex3f(10, 0, 10);//2
	glTexCoord2d(1, 1);
	glVertex3f(23, 0, -1);//3
	glTexCoord2d(0, 1);
	glVertex3f(23, 0, -19);//4
	glTexCoord2d(0, 0);
	glVertex3f(10, 0, -30);//5
	glTexCoord2d(1, 0);
	glVertex3f(-10, 0, -30);//6
	glTexCoord2d(1, 1);
	glVertex3f(-23, 0, -19);//7
	glTexCoord2d(0, 1);
	glVertex3f(-23, 0, -1);//8
	glEnd();
	glPopMatrix();

	columns_middle(colum_img, 5, 100, -840, 0, 2840);//colum1
	columns_middle(colum_img, 5, 100, -760, 0, 2840);//colum2
	columns_middle(colum_img, 5, 100, -708, 0, 2800);//colum3
	columns_middle(colum_img, 5, 100, -708, 0, 2724);//colum4
	columns_middle(colum_img, 5, 100, -760, 0, 2680);//colum5
	columns_middle(colum_img, 5, 100, -840, 0, 2680);//colum6
	columns_middle(colum_img, 5, 100, -892, 0, 2724);//colum7
	columns_middle(colum_img, 5, 100, -892, 0, 2800);//colum8

	glPushMatrix();   //roof     
	glTranslated(-800, 100, 2800);
	glScaled(4.3, 2, 4.3);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-10, 0, 10);//1
	glTexCoord2d(1, 0);
	glVertex3f(10, 0, 10);//2
	glTexCoord2d(1, 1);
	glVertex3f(23, 0, -1);//3
	glTexCoord2d(0, 1);
	glVertex3f(23, 0, -19);//4
	glTexCoord2d(0, 0);
	glVertex3f(10, 0, -30);//5
	glTexCoord2d(1, 0);
	glVertex3f(-10, 0, -30);//6
	glTexCoord2d(1, 1);
	glVertex3f(-23, 0, -19);//7
	glTexCoord2d(0, 1);
	glVertex3f(-23, 0, -1);//8
	glEnd();
	glPopMatrix();
	glPushMatrix();   //roof0     
	glTranslated(-800, 80, 2800);
	glScaled(4.3, 2, 4.3);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-10, 0, 10);//1
	glTexCoord2d(1, 0);
	glVertex3f(10, 0, 10);//2
	glTexCoord2d(1, 1);
	glVertex3f(23, 0, -1);//3
	glTexCoord2d(0, 1);
	glVertex3f(23, 0, -19);//4
	glTexCoord2d(0, 0);
	glVertex3f(10, 0, -30);//5
	glTexCoord2d(1, 0);
	glVertex3f(-10, 0, -30);//6
	glTexCoord2d(1, 1);
	glVertex3f(-23, 0, -19);//7
	glTexCoord2d(0, 1);
	glVertex3f(-23, 0, -1);//8
	glEnd();
	glPopMatrix();

	glPushMatrix();//dome
	glTranslated(-800, 120, 2760);
	m.draw_sphere(70, chian, 0, 0, 0);
	glPopMatrix();
	glPushMatrix(); //cylinder
	glTranslated(-800, 100, 2760);
	m.draw_cylinder(70, 20, colum_img, 0, 0, 0);
	glPopMatrix();

}
	  //Entrances  for Dome of the Rock Mosque
public:void  columns_middle(int colum_img, int R, int h, float x, float y, float z)
{
	glPushMatrix();  //colum1
	glTranslated(x, y, z);
	m.draw_Colum(R, h, colum_img);
	glPopMatrix();


}
public:void  Columns_ends(int colum_img, float x, float y, float z)
{
	glPushMatrix();  ////colum4
	glTranslated(x, y, z);
	glScaled(25, 175, 20);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_QUAD_STRIP);
	glTexCoord3d(0, 0, 0);
	glVertex3d(-2, 2, 0);
	glTexCoord3d(1, 0, 0);
	glVertex3d(-2, -2, 0);
	glTexCoord3d(0, 1, 0);
	glVertex3d(2, 2, 0);
	glTexCoord3d(1, 1, 0);
	glVertex3d(2, -2, 0);
	glTexCoord3d(0, 0, 1);
	glVertex3d(2, 2, -4);
	glTexCoord3d(1, 0, 1);
	glVertex3d(2, -2, -4);
	glTexCoord3d(1, 1, 1);
	glVertex3d(-2, 2, -4);
	glTexCoord3d(0, 0, 0);
	glVertex3d(-2, -2, -4);
	glTexCoord3d(0, 1, 0);
	glVertex3d(-2, 2, 0);
	glTexCoord3d(0, 0, 1);
	glVertex3d(-2, -2, 0);
	glEnd();
	glPopMatrix();


}
public:void  arch(int colum_img, int angle, float Rx, float Ry, float Rz, float Tx, float Ty, float Tz, float x1_Arc, float x2_Arc)
{
	glPushMatrix();
	glTranslated(Tx, Ty, Tz);
	glScaled(150, 150, 150);
	glRotated(angle, Rx, Ry, Rz);
	m.Arc(colum_img, x1_Arc, x2_Arc);
	glPopMatrix();

}
public:void Entrance(int colum_img)
{   //The first entrance to the Dome of the Rock
	columns_middle(colum_img, 28, 355, 0, 0, 4820);
	columns_middle(colum_img, 28, 355, -250, 0, 4820);
	columns_middle(colum_img, 28, 355, 250, 0, 4820);
	Columns_ends(colum_img, -540, 1, 4840);
	Columns_ends(colum_img, 540, 1, 4840);
	arch(colum_img, 0, 0, 0, 0, -385, 350, 4840, 1.35, 1);//arc1_front
	arch(colum_img, 0, 0, 0, 0, -385, 350, 4800, 1.35, 1);//arc1_back
	arch(colum_img, 0, 0, 0, 0, -125, 350, 4840, 1, 1);//arc2_front
	arch(colum_img, 0, 0, 0, 0, -125, 350, 4800, 1, 1);//arc2_back
	arch(colum_img, 0, 0, 0, 0, 125, 350, 41840, 1, 1);//arc3_front
	arch(colum_img, 0, 0, 0, 0, 125, 350, 4800, 1, 1);//arc3_back
	arch(colum_img, 0, 0, 0, 0, 385, 350, 4840, 1, 1.3);//arc4_front
	arch(colum_img, 0, 0, 0, 0, 385, 350, 4800, 1, 1.3);//arc4_back

	//The first entrance to the Dome of the Rock 2
	/*columns_middle(colum_img, 20, 200, -1950, 0, 1970);
	columns_middle(colum_img, 20, 200, -2450, 0, 1970);*/
	Columns_ends(colum_img, -1980, 1, 4980);
	Columns_ends(colum_img, -2400, 1, 4980);
	arch(colum_img, 0, 0, 0, 0, -2200, 350, 4980, 1.7, 1.8);//arc2_front
	arch(colum_img, 0, 0, 0, 0, -2200, 350, 4910, 1.7, 1.8);//arc2_back

	glPushMatrix();//leaft
	glTranslated(-785, 350, 4840);
	glScaled(150, 150, 150);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(1.35, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3f(1.35, 1, 0);
	glTexCoord2d(1, 1);
	glVertex3f(1.35, 1, -0.3);
	glTexCoord2d(0, 1);
	glVertex3f(1.35, 0, -0.3);
	glEnd();
	glPopMatrix();
	glPushMatrix();//right
	glTranslated(378, 350, 4840);
	glScaled(150, 150, 150);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(1.35, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3f(1.35, 1, 0);
	glTexCoord2d(1, 1);
	glVertex3f(1.35, 1, -0.3);
	glTexCoord2d(0, 1);
	glVertex3f(1.35, 0, -0.3);
	glEnd();
	glPopMatrix();
	glPushMatrix();//top
	glTranslated(0, 0, 3310);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-582, 500, 1490);
	glTexCoord2d(1, 0);
	glVertex3f(-582, 500, 1535);
	glTexCoord2d(1, 1);
	glVertex3f(580, 500, 1535);//
	glTexCoord2d(0, 1);
	glVertex3f(580, 500, 1490);//
	glEnd();
	glPopMatrix();
	//The second entrance to the Dome of the Rock
	columns_middle(colum_img, 28, 355, 0, 0, -2325);
	columns_middle(colum_img, 28, 355, -250, 0, -2325);
	columns_middle(colum_img, 28, 355, 255, 0, -2325);
	Columns_ends(colum_img, -540, 1, -2320);
	Columns_ends(colum_img, 540, 1, -2320);
	arch(colum_img, 0, 0, 0, 0, -385, 350, -2350, 1.35, 1);//arc1_front
	arch(colum_img, 0, 0, 0, 0, -385, 350, -2320, 1.35, 1);//arc1_back
	arch(colum_img, 0, 0, 0, 0, -125, 350, -2350, 1, 1);//arc2_front
	arch(colum_img, 0, 0, 0, 0, -125, 350, -2320, 1, 1);//arc2_back
	arch(colum_img, 0, 0, 0, 0, 125, 350, -2350, 1, 1);//arc3_front
	arch(colum_img, 0, 0, 0, 0, 125, 350, -2320, 1, 1);//arc3_back
	arch(colum_img, 0, 0, 0, 0, 385, 350, -2350, 1, 1.3);//arc4_front
	arch(colum_img, 0, 0, 0, 0, 385, 350, -2320, 1, 1.3);//arc4_back
	glPushMatrix();//leaft
	glTranslated(-785, 350, -2320);
	glScaled(150, 150, 150);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(1.3, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3f(1.3, 1, 0);
	glTexCoord2d(1, 1);
	glVertex3f(1.3, 1, -0.3);
	glTexCoord2d(0, 1);
	glVertex3f(1.3, 0, -0.3);
	glEnd();
	glPopMatrix();
	glPushMatrix();//right
	glTranslated(378, 350, -2320);
	glScaled(150, 150, 150);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(1.3, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3f(1.3, 1, 0);
	glTexCoord2d(1, 1);
	glVertex3f(1.3, 1, -0.3);
	glTexCoord2d(0, 1);
	glVertex3f(1.3, 0, -0.3);
	glEnd();
	glPopMatrix();
	glPushMatrix();//top
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-582, 500, -2320);
	glTexCoord2d(1, 0);
	glVertex3f(-582, 500, -2350);
	glTexCoord2d(1, 1);
	glVertex3f(580, 500, -2350);
	glTexCoord2d(0, 1);
	glVertex3f(580, 500, -2320);
	glEnd();
	glPopMatrix();

	//Third entrance to the Dome of the Rock
	columns_middle(colum_img, 28, 355, 3320, 0, 1500);
	columns_middle(colum_img, 28, 355, 3320, 0, 1775);
	columns_middle(colum_img, 28, 355, 3320, 0, 1225);
	Columns_ends(colum_img, 3320, 0, 1010);
	Columns_ends(colum_img, 3320, 0, 2090);
	arch(colum_img, 90, 0, 1, 0, 3300, 350, 1900, 1.35, 1);//arc1_front
	arch(colum_img, 90, 0, 1, 0, 3330, 350, 1900, 1.35, 1);//arc1_back
	arch(colum_img, 90, 0, 1, 0, 3300, 350, 1650, 1, 1);//arc2_front
	arch(colum_img, 90, 0, 1, 0, 3330, 350, 1650, 1, 1);//arc2_back
	arch(colum_img, 90, 0, 1, 0, 3300, 350, 1350, 1, 1);//arc3_front
	arch(colum_img, 90, 0, 1, 0, 3330, 350, 1350, 1, 1);//arc3_back
	arch(colum_img, 90, 0, 1, 0, 3300, 350, 1100, 1, 1.3);//arc4_front
	arch(colum_img, 90, 0, 1, 0, 3330, 350, 1100, 1, 1.3);//arc4_back
	glPushMatrix();//leaft
	glTranslated(3330, 350, 2300);
	glScaled(150, 150, 150);
	glRotated(90, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(1.35, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3f(1.35, 1, 0);
	glTexCoord2d(1, 1);
	glVertex3f(1.35, 1, -0.3);
	glTexCoord2d(0, 1);
	glVertex3f(1.35, 0, -0.3);
	glEnd();
	glPopMatrix();
	glPushMatrix();//right
	glTranslated(3330, 350, 1105);
	glScaled(150, 150, 150);
	glRotated(90, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(1.35, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3f(1.35, 1, 0);
	glTexCoord2d(1, 1);
	glVertex3f(1.35, 1, -0.3);
	glTexCoord2d(0, 1);
	glVertex3f(1.35, 0, -0.3);
	glEnd();
	glPopMatrix();
	glPushMatrix();//top
	glTranslated(1800, 0, 1480);
	glRotated(90, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-582, 500, 1490);
	glTexCoord2d(1, 0);
	glVertex3f(-582, 500, 1535);
	glTexCoord2d(1, 1);
	glVertex3f(580, 500, 1535);
	glTexCoord2d(0, 1);
	glVertex3f(580, 500, 1490);
	glEnd();
	glPopMatrix();

	//four entrance to the Dome of the Rock
	columns_middle(colum_img, 28, 355, -2320, 0, 1425);
	columns_middle(colum_img, 28, 355, -2320, 0, 1675);
	columns_middle(colum_img, 28, 355, -2320, 0, 1175);
	Columns_ends(colum_img, -2300, 0, 940);
	Columns_ends(colum_img, -2330, 0, 1990);
	arch(colum_img, -90, 0, 1, 0, -2300, 350, 1800, 1, 1.35);//arc1_front
	arch(colum_img, -90, 0, 1, 0, -2330, 350, 1800, 1, 1.35);//arc1_back
	arch(colum_img, -90, 0, 1, 0, -2300, 350, 1550, 1, 1);//arc2_front
	arch(colum_img, -90, 0, 1, 0, -2330, 350, 1550, 1, 1);//arc2_back
	arch(colum_img, -90, 0, 1, 0, -2300, 350, 1300, 1, 1);//arc3_front
	arch(colum_img, -90, 0, 1, 0, -2330, 350, 1300, 1, 1);//arc3_back
	arch(colum_img, -90, 0, 1, 0, -2300, 350, 1050, 1.3, 1);//arc4_front
	arch(colum_img, -90, 0, 1, 0, -2330, 350, 1050, 1.3, 1);//arc4_back
	glPushMatrix();//leaft
	glTranslated(-2300, 350, 2200);
	glScaled(150, 150, 150);
	glRotated(90, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(1.35, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3f(1.35, 1, 0);
	glTexCoord2d(1, 1);
	glVertex3f(1.35, 1, -0.3);
	glTexCoord2d(0, 1);
	glVertex3f(1.35, 0, -0.3);
	glEnd();
	glPopMatrix();
	glPushMatrix();//right
	glTranslated(-2300, 350, 1055);
	glScaled(150, 150, 150);
	glRotated(90, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(1.35, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3f(1.35, 1, 0);
	glTexCoord2d(1, 1);
	glVertex3f(1.35, 1, -0.3);//
	glTexCoord2d(0, 1);
	glVertex3f(1.35, 0, -0.3);//
	glEnd();
	glPopMatrix();
	glPushMatrix();//top
	glTranslated(-800, 0, 1430);
	glRotated(-90, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, colum_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-582, 500, 1490);
	glTexCoord2d(1, 0);
	glVertex3f(-582, 500, 1535);
	glTexCoord2d(1, 1);
	glVertex3f(580, 500, 1535);//
	glTexCoord2d(0, 1);
	glVertex3f(580, 500, 1490);//
	glEnd();
	glPopMatrix();



}
	  //drawers for Dome of the Rock Mosque
public: void drawer(int chian)
{
	//The first drawer
	m.drawer(chian, 0, 0, 0, 0, 0, 0, 4550, 1, 1, 1);
	m.drawer(chian, 0, 0, 0, 0, 0, -20, 4580, 1, 1, 1);
	m.drawer(chian, 0, 0, 0, 0, 0, -40, 4610, 1, 1, 1);
	m.drawer(chian, 0, 0, 0, 0, 0, -60, 4640, 1, 1, 1);
	m.drawer(chian, 0, 0, 0, 0, 0, -80, 4670, 1, 1, 1);

	//The first drawer 2
	m.drawer(chian, 0, 0, 0, 0, -2200, 0, 4700, 0.5, 1, 1);
	m.drawer(chian, 0, 0, 0, 0, -2200, -20, 4730, 0.5, 1, 1);
	m.drawer(chian, 0, 0, 0, 0, -2200, -40, 4760, 0.5, 1, 1);
	m.drawer(chian, 0, 0, 0, 0, -2200, -60, 4790, 0.5, 1, 1);
	m.drawer(chian, 0, 0, 0, 0, -2200, -80, 4770, 0.5, 1, 1);

	//The second drawer
	m.drawer(chian, 180, 0, 1, 0, 0, 0, -2050, 1, 1, 1);
	m.drawer(chian, 180, 0, 1, 0, 0, -20, -2080, 1, 1, 1);
	m.drawer(chian, 180, 0, 1, 0, 0, -40, -2110, 1, 1, 1);
	m.drawer(chian, 180, 0, 1, 0, 0, -60, -2140, 1, 1, 1);
	m.drawer(chian, 180, 0, 1, 0, 0, -80, -2170, 1, 1, 1);
	//thrid drawer
	m.drawer(chian, 90, 0, 1, 0, 3050, 0, 1450, 1, 1, 1);
	m.drawer(chian, 90, 0, 1, 0, 3080, -20, 1450, 1, 1, 1);
	m.drawer(chian, 90, 0, 1, 0, 3110, -40, 1450, 1, 1, 1);
	m.drawer(chian, 90, 0, 1, 0, 3140, -60, 1450, 1, 1, 1);
	m.drawer(chian, 90, 0, 1, 0, 3170, -80, 1450, 1, 1, 1);
	//four drawer
	m.drawer(chian, -90, 0, 1, 0, -2050, 0, 1450, 1, 1, 1);
	m.drawer(chian, -90, 0, 1, 0, -2080, -20, 1450, 1, 1, 1);
	m.drawer(chian, -90, 0, 1, 0, -2110, -40, 1450, 1, 1, 1);
	m.drawer(chian, -90, 0, 1, 0, -2140, -60, 1450, 1, 1, 1);
	m.drawer(chian, -90, 0, 1, 0, -2170, -80, 1450, 1, 1, 1);
	// platform drawer
	m.drawer(chian, -90, 0, 1, 0, 3220, 0, 2100, 1, 1, 0.1);
	m.drawer(chian, -90, 0, 1, 0, 3250, 20, 2100, 1, 1, 0.1);
	m.drawer(chian, -90, 0, 1, 0, 3280, 40, 2100, 1, 1, 0.1);
	m.drawer(chian, -90, 0, 1, 0, 3310, 60, 2100, 1, 1, 0.1);
	m.drawer(chian, -90, 0, 1, 0, 3340, 80, 2100, 1, 1, 0.1);
	m.drawer(chian, -90, 0, 1, 0, 3370, 100, 2100, 1, 1, 0.1);
	m.drawer(chian, -90, 0, 1, 0, 3400, 120, 2100, 1, 1, 0.1);
	m.drawer(chian, -90, 0, 1, 0, 3430, 140, 2100, 1, 1, 0.1);

	//1درج باب الرحمة و التوبة
	glPushMatrix();
	glTranslated(2000, -100, -5200);
	glScaled(1, 1, 0.5);
	m.drawer(chian, -90, 0, 1, 0, -2050, 0, -50, 1, 1, 1);
	m.drawer(chian, -90, 0, 1, 0, -2080, -20, -50, 1, 1, 1);
	m.drawer(chian, -90, 0, 1, 0, -2110, -40, -50, 1, 1, 1);
	m.drawer(chian, -90, 0, 1, 0, -2140, -60, -50, 1, 1, 1);
	m.drawer(chian, -90, 0, 1, 0, -2170, -80, -50, 1, 1, 1);
	m.drawer(chian, -90, 0, 1, 0, -2200, -100, -50, 1, 1, 1);//
	m.drawer(chian, -90, 0, 1, 0, -2230, -120, -50, 1, 1, 1);
	m.drawer(chian, -90, 0, 1, 0, -2260, -140, -50, 1, 1, 1);
	m.drawer(chian, -90, 0, 1, 0, -2290, -160, -50, 1, 1, 1);
	m.drawer(chian, -90, 0, 1, 0, -2320, -180, -50, 1, 1, 1);
	glPopMatrix();
	m.Quads(chian, chian, chian, chian, chian, -30, -290, -5200, 150, 100, 140);

	//2درج باب الرحمة و التوبة
	glPushMatrix();
	glTranslated(-7050, -100, -2630);
	glScaled(0.5, 1, 1);
	m.drawer(chian, 180, 0, 1, 0, 0, 20, -2020, 1, 1, 1);
	m.drawer(chian, 180, 0, 1, 0, 0, 0, -2050, 1, 1, 1);
	m.drawer(chian, 180, 0, 1, 0, 0, -20, -2080, 1, 1, 1);
	m.drawer(chian, 180, 0, 1, 0, 0, -40, -2110, 1, 1, 1);
	m.drawer(chian, 180, 0, 1, 0, 0, -60, -2140, 1, 1, 1);
	m.drawer(chian, 180, 0, 1, 0, 0, -80, -2170, 1, 1, 1);
	m.drawer(chian, 180, 0, 1, 0, 0, -100, -2200, 1, 1, 1);//
	m.drawer(chian, 180, 0, 1, 0, 0, -120, -2230, 1, 1, 1);
	m.drawer(chian, 180, 0, 1, 0, 0, -140, -2260, 1, 1, 1);
	m.drawer(chian, 180, 0, 1, 0, 0, -160, -2290, 1, 1, 1);
	m.drawer(chian, 180, 0, 1, 0, 0, -180, -2320, 1, 1, 1);
	m.drawer(chian, 180, 0, 1, 0, 0, -200, -2350, 1, 1, 1);
	m.drawer(chian, 180, 0, 1, 0, 0, -220, -2380, 1, 1, 1);


	glPopMatrix();
}

	  //platform for Dome of the Rock Mosque
public:void platform(int  platform_colum, int platform_dome, int platform_img, int chian)
{
	glPushMatrix();//earth
	glTranslated(3130, 0, 1750);
	glBindTexture(GL_TEXTURE_2D, chian);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(0, 140, 290);
	glTexCoord2d(1, 0);
	glVertex3f(0, 140, 400);
	glTexCoord2d(1, 1);
	glVertex3f(150, 140, 400);
	glTexCoord2d(0, 1);
	glVertex3f(150, 140, 290);
	glEnd();
	glPopMatrix();

	glPushMatrix();//wall
	glTranslated(3130, 0, 1755);
	glBindTexture(GL_TEXTURE_2D, platform_img);
	glBegin(GL_POLYGON);
	glTexCoord3d(0, 0, 0);
	glVertex3f(150, 0, 400);
	glTexCoord3d(1, 0, 0);
	glVertex3f(150, 200, 400);
	glTexCoord3d(0, 1, 0);
	glVertex3f(0, 200, 400);
	glTexCoord3d(1, 1, 0);
	glVertex3f(0, 170, 400);
	glTexCoord3d(0, 0, 1);
	glVertex3f(-210, 30, 400);
	glTexCoord3d(1, 0, 1);
	glVertex3f(-210, 0, 400);
	glEnd();
	glPopMatrix();

	glPushMatrix();//wall
	glTranslated(3130, 0, 1645);
	glBindTexture(GL_TEXTURE_2D, platform_img);
	glBegin(GL_POLYGON);
	glTexCoord3d(0, 0, 0);
	glVertex3f(150, 0, 400);
	glTexCoord3d(1, 0, 0);
	glVertex3f(150, 200, 400);
	glTexCoord3d(0, 1, 0);
	glVertex3f(0, 200, 400);
	glTexCoord3d(1, 1, 0);
	glVertex3f(0, 170, 400);
	glTexCoord3d(0, 0, 1);
	glVertex3f(-210, 30, 400);
	glTexCoord3d(1, 0, 1);
	glVertex3f(-210, 0, 400);
	glEnd();
	glPopMatrix();

	glPushMatrix();//back
	glTranslated(3130, 0, 1755);
	glBindTexture(GL_TEXTURE_2D, platform_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(150, 0, 400);
	glTexCoord2d(1, 0);
	glVertex3f(150, 200, 400);
	glTexCoord2d(1, 1);
	glVertex3f(150, 200, 290);
	glTexCoord2d(0, 1);
	glVertex3f(150, 0, 290);
	glEnd();
	glPopMatrix();

	columns_middle(platform_colum, 5, 250, 3300, 0, 2155);
	columns_middle(platform_colum, 5, 250, 3330, 0, 2050);
	columns_middle(platform_colum, 5, 250, 3140, 0, 2155);
	columns_middle(platform_colum, 5, 250, 3140, 0, 2050);

	glPushMatrix();//roof1
	glTranslated(3130, 110, 1760);
	glBindTexture(GL_TEXTURE_2D, platform_img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(0, 140, 290);
	glTexCoord2d(1, 0);
	glVertex3f(0, 140, 400);
	glTexCoord2d(1, 1);
	glVertex3f(150, 140, 400);
	glTexCoord2d(0, 1);
	glVertex3f(150, 140, 290);
	glEnd();
	glPopMatrix();
	glPushMatrix();//dome
	glTranslated(3200, 270, 2100);
	m.draw_sphere(30, platform_dome, 0, 0, 0);
	glPopMatrix();

	glPushMatrix(); //cylinder
	glTranslated(3200, 250, 2100);
	m.draw_cylinder(30, 20, platform_dome, 0, 0, 0);
	glPopMatrix();

}

	  //walls for Dome of the Rock Mosque

public:void wall(int Wall, int angle, float Rx, float Ry, float Rz, float Tx, float Ty, float Tz, float Sx, float Sy, float Sz)

{
	glPushMatrix();
	glTranslated(Tx, Ty, Tz);
	glScaled(Sx, Sy, Sz);
	glRotated(angle, Rx, Ry, Rz);
	glBindTexture(GL_TEXTURE_2D, Wall);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-2500, 0, 2000);
	glTexCoord2d(1, 0);
	glVertex3f(-500, 0, 2000);
	glTexCoord2d(1, 1);
	glVertex3f(-500, -100, 2000);
	glTexCoord2d(0, 1);
	glVertex3f(-2500, -100, 2000);
	glEnd();
	glPopMatrix();

}
public:void walls(int wall_img)
{
	//(img,     angle,Rx,Ry,Rz,   Tx, Ty, Tz,    Sx,Sy,Sz)
	wall(wall_img, 0, 0, 0, 0, 0, 0, 2995, 1, 1, 1);//1
	wall(wall_img, 90, 0, 1, 0, -2500, 0, 2500, 1, 1, 1);//2
	wall(wall_img, 90, 0, 1, 0, -1500, 0, 2500, 1, 1, 1);//3
	wall(wall_img, 0, 0, 0, 0, 3000, 0, 2995, 1, 1, 1);//4
	wall(wall_img, 0, 0, 0, 0, 4000, 0, 2995, 1, 1, 1);//4
	wall(wall_img, 90, 0, 1, 0, 1500, 0, 1250, 1, 1, 1.5);//5
	wall(wall_img, 0, 0, 0, 0, 4000, 0, 0, 1, 1, 1);//6
	wall(wall_img, 0, 0, 0, 0, 4000, 0, -1100, 1, 1, 1);//7
	wall(wall_img, 90, 0, 1, 0, 1500, 0, -3000, 1, 1, 1);//8
	wall(wall_img, 90, 0, 1, 0, 1500, 0, -1600, 1, 1, 1);//8
	wall(wall_img, 0, 0, 0, 0, 3000, 0, -4500, 1, 1, 1);//9
	wall(wall_img, 0, 0, 0, 0, 4000, 0, -4500, 1, 1, 1);//9
	wall(wall_img, 90, 0, 1, 0, -2500, 0, -3000, 1, 1, 1);//10
	wall(wall_img, 90, 0, 1, 0, -1500, 0, -3000, 1, 1, 1);//11
	wall(wall_img, 0, 0, 0, 0, 0, 0, -4500, 1, 1, 1);//12
	wall(wall_img, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1);//13
	wall(wall_img, 0, 0, 0, 0, 0, 0, -1100, 1, 1, 1);//14
	wall(wall_img, 90, 0, 1, 0, -4500, 0, 1230, 1, 1, 1.51);//15
	wall(wall_img, 90, 0, 1, 0, -4500, 0, -3000, 1, 1, 1);//16
	wall(wall_img, 90, 0, 1, 0, -4500, 0, -1600, 1, 1, 1);//16

}
	  //leaft platform for Dome of the Rock Mosque

public:void bulid1_Surrounding(int windo_build1_img, int Door_build1_img, int colume_img, int chian, int dome2, int platform_colum)
{
	//bulid0
	m.Quads(colume_img, colume_img, colume_img, colume_img, colume_img, 3250, 0, -2250, 125, 10, 125);

	//bulid1
	m.Quads(colume_img, colume_img, colume_img, colume_img, colume_img, 3240, 100, 4740, 125, 100, 125);
	m.Quads(colume_img, colume_img, colume_img, colume_img, colume_img, 3340, 0, 4400, 75, 125, 75);
	glPushMatrix();//dome
	glTranslated(3240, 340, 4740);
	m.draw_sphere(150, chian, 0, 0, 0);
	glPopMatrix();
	glPushMatrix(); //cylinder
	glTranslated(3240, 300, 4740);
	m.draw_cylinder(150, 40, chian, 0, 0, 0);
	glPopMatrix();
	m.door_windo(Door_build1_img, 3030, 70, 4620, 25, 50, 25, 0, 0, 0, 0);//door
	m.door_windo(windo_build1_img, 3030, 140, 4840, 20, 20, 25, 0, 0, 0, 0);// windo1
	m.door_windo(windo_build1_img, 3200, 140, 4360, 20, 20, 25, 0, 0, 0, 0);// windo2

	//bulid2
	m.Quads(colume_img, colume_img, colume_img, colume_img, colume_img, 700, 0, 4850, 75, 125, 75);
	glPushMatrix();//dome
	glTranslated(700, 250, 4850);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	m.door_windo(windo_build1_img, 700, 140, 5050, 20, 20, 25, -90, 0, 1, 0);//windo back
	m.door_windo(windo_build1_img, 700, 140, 4740, 20, 20, 25, -90, 0, 1, 0);//windo front
	m.door_windo(Door_build1_img, 900, 70, 4775, 25, 50, 25, 0, 0, 0, 0);//Door

	//bulid3
	m.Quads(colume_img, colume_img, colume_img, colume_img, colume_img, -700, 0, 4850, 75, 125, 75);
	glPushMatrix();//dome
	glTranslated(-700, 250, 4850);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	m.door_windo(windo_build1_img, -700, 140, 4740, 20, 20, 25, -90, 0, 1, 0);//windo front
	m.door_windo(windo_build1_img, -700, 140, 5050, 20, 20, 25, -90, 0, 1, 0);////windo back
	m.door_windo(Door_build1_img, -800, 70, 4775, 25, 50, 25, 0, 0, 0, 0);//door

	//build4
	m.Quads(colume_img, colume_img, colume_img, colume_img, colume_img, -1500, 0, 4825, 155, 125, 90);
	m.Quads(colume_img, colume_img, colume_img, colume_img, colume_img, -1500, 0, 4700, 155, 10, 150);
	glPushMatrix();//dome1
	glTranslated(-1500, 250, 4850);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();//dome2
	glTranslated(-1700, 250, 4850);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();//dome2
	glTranslated(-1300, 250, 4850);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	m.door_windo(windo_build1_img, -1700, 140, 5060, 20, 20, 25, -90, 0, 1, 0);//windo front
	m.door_windo(windo_build1_img, -1300, 140, 5060, 20, 20, 25, -90, 0, 1, 0);////windo2 front
	m.door_windo(Door_build1_img, -1500, 100, 4690, 20, 40, 25, -90, 0, 1, 0);//door
	glPushMatrix();//top 
	glTranslated(-1500, 230, 4700);
	glScaled(155, 10, 150);
	glBindTexture(GL_TEXTURE_2D, colume_img);
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
	columns_middle(platform_colum, 20, 250, -1790, 0, 4420);
	columns_middle(platform_colum, 20, 250, -1210, 0, 4420);

	//bulid5
	m.Quads(colume_img, colume_img, colume_img, colume_img, colume_img, -1200, 0, -2350, 75, 125, 75);
	glPushMatrix();//dome
	glTranslated(-1200, 250, -2350);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	m.door_windo(windo_build1_img, -1200, 140, -2460, 20, 20, 25, -90, 0, 1, 0);//windo front
	m.door_windo(Door_build1_img, -1200, 100, -2160, 20, 50, 25, -90, 0, 1, 0);//windo front

	//bulid6
	m.Quads(colume_img, colume_img, colume_img, colume_img, colume_img, -2600, 0, -1500, 100, 125, 350);
	glPushMatrix();//dome
	glTranslated(-2600, 250, -1500);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();//dome
	glTranslated(-2600, 250, -1250);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();//dome
	glTranslated(-2600, 250, -1750);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();//dome
	glTranslated(-2600, 250, -1000);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();//dome
	glTranslated(-2600, 250, -2050);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	m.door_windo(Door_build1_img, -2350, 70, -2050, 25, 50, 25, 0, 0, 0, 0);///Door1
	m.door_windo(Door_build1_img, -2350, 70, -1000, 25, 50, 25, 0, 0, 0, 0);///Door2
	m.door_windo(windo_build1_img, -2350, 100, -1750, 25, 25, 50, 0, 0, 0, 0);;//windo1
	m.door_windo(windo_build1_img, -2350, 100, -1250, 25, 25, 50, 0, 0, 0, 0);;//windo2

	//bulid6
	m.Quads(colume_img, colume_img, colume_img, colume_img, colume_img, -2600, 0, -1500, 100, 125, 350);
	glPushMatrix();//dome
	glTranslated(-2600, 250, -1500);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();//dome
	glTranslated(-2600, 250, -1250);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();//dome
	glTranslated(-2600, 250, -1750);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();//dome
	glTranslated(-2600, 250, -1000);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();//dome
	glTranslated(-2600, 250, -2050);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	m.door_windo(Door_build1_img, -2350, 70, -2050, 25, 50, 25, 0, 0, 0, 0);///Door1
	m.door_windo(Door_build1_img, -2350, 70, -1000, 25, 50, 25, 0, 0, 0, 0);///Door2
	m.door_windo(windo_build1_img, -2350, 100, -1750, 25, 25, 50, 0, 0, 0, 0);;//windo1
	m.door_windo(windo_build1_img, -2350, 100, -1250, 25, 25, 50, 0, 0, 0, 0);;//windo2

	//bulid7
	m.Quads(colume_img, colume_img, colume_img, colume_img, colume_img, -2600, 0, 2600, 100, 125, 200);
	glPushMatrix();//dome
	glTranslated(-2600, 250, 2900);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	glPushMatrix();//dome
	glTranslated(-2600, 250, 2650);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();//dome
	glTranslated(-2600, 250, 2400);
	m.draw_sphere(100, dome2, 0, 0, 0);
	glPopMatrix();
	m.door_windo(Door_build1_img, -2350, 70, 2400, 25, 50, 25, 0, 0, 0, 0);///Door
	m.door_windo(windo_build1_img, -2350, 100, 2750, 25, 25, 40, 0, 0, 0, 0);;//windo

}
};

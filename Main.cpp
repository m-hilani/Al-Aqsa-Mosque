#include <windows.h>		// Header File For Windows
#include <GL/gl.h>			// Header File For The OpenGL32 Library
#include <GL/glu.h>			// Header File For The GLu32 Library
//#include<GL/glut.h>
#include <GL/glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <stdio.h>
#include "GL/texture.h"
#define _CRT_SECURE_NO_WARNINGS
#define GLUT_DISABLE_ATEXIT_HACK




HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Cntext
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 700.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

int Land,Wall,wall_img3, wall_img2,img,dome;
int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glEnable(GL_TEXTURE_2D);
	Land = LoadTexture((CHAR*)"land.bmp", 255);
	Wall = LoadTexture((CHAR*)"C:\\Users\\ASUS\\Pictures\\Saved Pictures\\Walls.bmp",255);
	wall_img2= LoadTexture((CHAR*)"C:\\Users\\ASUS\\Pictures\\Saved Pictures\\wall_img2.bmp", 255);
	img= LoadTexture((CHAR*)"C:\\Users\\ASUS\\Pictures\\Saved Pictures\\img.bmp", 255);
	dome= LoadTexture((CHAR*)"C:\\Users\\ASUS\\Pictures\\Saved Pictures\\dome.bmp", 255);
	wall_img3= LoadTexture((CHAR*)"C:\\Users\\ASUS\\Pictures\\Saved Pictures\\wall_img3.bmp", 255);
	return TRUE;										// Initialization Went OK
}
double movX, movY, movZ;
double lX, lY;

void camera()
{    /* if(-100< movX <100&&0< movY <300&&-75< movZ <75)*/
	gluLookAt(movX, movY, movZ, lX, lY, -5, 0, 1, 0);
	if (keys['D'])
		movX += 0.05;
	if (keys['A'])
		movX -= 0.05;
	if (keys['W'])
		movY += 0.05;
	if (keys['S'])
		movY -= 0.05;
	if (keys['Z'])
		movZ += 0.05;
	if (keys['X'])
		movZ -= 0.05;
	if (keys[VK_LEFT])
		lX += 0.005;
	if (keys[VK_RIGHT])
		lX -= 0.005;
	if (keys[VK_UP])
		lY += 0.005;
	if (keys[VK_DOWN])
		lY -= 0.005;
	
}
void land()
{    
	glPushMatrix();
	glScaled(4,0,4);
	glBindTexture(GL_TEXTURE_2D, Land);
	
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-100, 0, 75);
	glTexCoord2d(1, 0);
	glVertex3f(100, 0, 75);
	glTexCoord2d(1, 1);
	glVertex3f(100, 0, -75);
	glTexCoord2d(0, 1);
	glVertex3f(-100, 0, -75);
	glEnd();
	glPopMatrix();
}
void wall()
{
	glPushMatrix();
	glScaled(4, 1, 4);
	glBindTexture(GL_TEXTURE_2D, Wall);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-100, 0, 75);
	glTexCoord2d(1, 0);
	glVertex3f(100, 0, 75);
	glTexCoord2d(1, 1);
	glVertex3f(100, 10, 75);
	glTexCoord2d(0, 1);
	glVertex3f(-100, 10, 75);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, Wall);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(100, 0, 75);
	glTexCoord2d(1, 0);
	glVertex3f(100, 10, 75);
	glTexCoord2d(1, 1);
	glVertex3f(100, 10, -75);
	glTexCoord2d(0, 1);
	glVertex3f(100, 0, -75);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, Wall);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(100, 0, -75);
	glTexCoord2d(1, 0);
	glVertex3f(100, 10, -75);
	glTexCoord2d(1, 1);
	glVertex3f(-100, 10, -75);
	glTexCoord2d(0, 1);
	glVertex3f(-100, 0, -75);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, Wall);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-100, 0, -75);
	glTexCoord2d(1, 0);
	glVertex3f(-100, 10, -75);
	glTexCoord2d(1, 1);
	glVertex3f(-100, 10, 75);
	glTexCoord2d(0, 1);
	glVertex3f(-100, 0, 75);
	glEnd();
	glPopMatrix();

}
//GLfloat t = 0;
//void init() {
//	glClearColor(1, 1, 0, 0);
//	glMatrixMode(GL_MODELVIEW);
//	glOrtho(0, 500, 0, 500, 0, 10);
//}
//void mouse(int button, int state, int x, int y) {
//	if (button == GLUT_LEFT_BUTTON) {
//		t--;
//	}
//	else if (button == GLUT_RIGHT_BUTTON) {
//		t++;
//	}
//	else {
//
//	}
//	glutPostRedisplay();
//}                 
void draw_sphere(float r)
{

	float pi = 3.141592;
	float di = 0.02;
	float dj = 0.04;
	float db = di * 2 * pi;
	float da = dj * pi;

	
	for (float i = 0; i < 0.97; i += di) //horizonal
		for (float j = 0; j < 1.0; j += dj) //vertical
		{
			float b = i * pi;      //0     to  2pi
			float a = (j - 0.5) * pi;  //-pi/2 to pi/2


			//normal
			glNormal3f(
				cos(a + da / 2) * cos(b + db / 2),
				cos(a + da / 2) * sin(b + db / 2),
				sin(a + da / 2));

			glBindTexture(GL_TEXTURE_2D, dome);
			glBegin(GL_QUADS);
			//P1
			
			glTexCoord2f(i, j);
			glVertex3f(
				r * cos(a) * cos(b),
				(r * cos(a) * sin(b))+60,
				(r * sin(a))-25);
			//P2
			glTexCoord2f(i + di, j);//P2
			glVertex3f(
				r * cos(a) * cos(b + db),
				(r * cos(a) * sin(b + db))+60,
				(r * sin(a))-25);
			//P3
			glTexCoord2f(i + di, j + dj);
			glVertex3f(
				r * cos(a + da) * cos(b + db),
				(r * cos(a + da) * sin(b + db))+60,
				(r * sin(a + da))-25);
			//P4
			glTexCoord2f(i, j + dj);
			glVertex3f(
				r * cos(a + da) * cos(b),
				(r * cos(a + da) * sin(b))+60,
				(r * sin(a + da))-25);
			glEnd();
		}
}
void dome_of_theRock_mosque()
{   

	draw_sphere(45);
	glPushMatrix();
	glScaled(3, 1, 3);
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
	glScaled(3, 3, 3);
	glBindTexture(GL_TEXTURE_2D, img);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-10, 20, 10);//1*
	glTexCoord2d(1, 0);
	glVertex3f(10, 20, 10);//2*
	glTexCoord2d(1, 1);
	glVertex3f(23, 20, -1);//3*
	glTexCoord2d(0,1);
	glVertex3f(23, 20, -19);//4*
	glTexCoord2d(0, 0);
	glVertex3f(10, 20, -30);//5*
	glTexCoord2d(1, 0);
	glVertex3f(-10, 20, -30);//6*
	glTexCoord2d(1,1);
	glVertex3f(-23, 20, -19);//7*
	glTexCoord2d(0, 1);
	glVertex3f(-23, 20, -1);//8*
	glEnd();
	glPopMatrix();

	glPushMatrix();///1
	glScaled(3, 3, 3);
	glBindTexture(GL_TEXTURE_2D, wall_img2);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-10, 0, 10);//1
	glTexCoord2d(1, 0);
	glVertex3f(10, 0, 10);//2
	glTexCoord2d(1,1);
	glVertex3f(10, 20, 10);//2*
	glTexCoord2d(0,1);
	glVertex3f(-10, 20, 10);//1*
	glEnd();
	glPopMatrix();

	glPushMatrix();///2
	glScaled(3, 3, 3);
	glBindTexture(GL_TEXTURE_2D, wall_img3);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(10, 0, 10);//2
	glTexCoord2d(1, 0);
	glVertex3f(23, 0, -1);//3
	glTexCoord2d(1, 1);
	glVertex3f(23, 20, -1);//3*
	glTexCoord2d(0,1);
	glVertex3f(10, 20, 10);//2*
	glEnd();
	glPopMatrix();

	glPushMatrix();///3
	glScaled(3, 3, 3);
	glBindTexture(GL_TEXTURE_2D, wall_img2);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(23, 0, -1);//3
	glTexCoord2d(1, 0);
	glVertex3f(23, 0, -19);//4
	glTexCoord2d(1,1);
	glVertex3f(23, 20, -19);//4*
	glTexCoord2d(0,1);
	glVertex3f(23, 20, -1);//3*
	glEnd();
	glPopMatrix();


	glPushMatrix();///4
	glScaled(3, 3, 3);
	glBindTexture(GL_TEXTURE_2D, wall_img3);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(23, 0, -19);//4
	glTexCoord2d(1, 0);
	glVertex3f(10, 0, -30);//5
	glTexCoord2d(1,1);
	glVertex3f(10, 20, -30);//5*
	glTexCoord2d(0,1);
	glVertex3f(23, 20, -19);//4*
	glEnd();
	glPopMatrix();

	glPushMatrix();///5
	glScaled(3, 3, 3);
	glBindTexture(GL_TEXTURE_2D, wall_img2);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(10, 0, -30);//5
	glTexCoord2d(1, 0);
	glVertex3f(-10, 0, -30);//6
	glTexCoord2d(1,1);
	glVertex3f(-10, 20, -30);//6*
	glTexCoord2d(0,1);
	glVertex3f(10, 20, -30);//5*
	glEnd();
	glPopMatrix();

	glPushMatrix();///6
	glScaled(3, 3, 3);
	glBindTexture(GL_TEXTURE_2D, wall_img3);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-10, 0, -30);//6
	glTexCoord2d(1, 0);
	glVertex3f(-23, 0, -19);//7
	glTexCoord2d(1,1);
	glVertex3f(-23, 20, -19);//7*
	glTexCoord2d(0,1);
	glVertex3f(-10, 20, -30);//6*
	glEnd();
	glPopMatrix();

	glPushMatrix();///7
	glScaled(3, 3, 3);
	glBindTexture(GL_TEXTURE_2D, wall_img2);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-23, 0, -19);//7
	glTexCoord2d(1,0);
	glVertex3f(-23, 0, -1);//8
	glTexCoord2d(1,1);
	glVertex3f(-23, 20, -1);//8*
	glTexCoord2d(0,1);
	glVertex3f(-23, 20, -19);//7*
	glEnd();
	glPopMatrix();

	glPushMatrix();///8
	glScaled(3, 3, 3);
	glBindTexture(GL_TEXTURE_2D, wall_img3);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);
	glVertex3f(-10, 0, 10);//1
	glTexCoord2d(1, 0);
	glVertex3f(-23, 0, -1);//8
	glTexCoord2d(1,1);
	glVertex3f(-23, 20, -1);//8*
	glTexCoord2d(0,1);
	glVertex3f(-10, 20, 10);//1*
	glEnd();
	glPopMatrix();


}





int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	/*glClear(GL_COLOR_BUFFER_BIT);*/
	
	/*glTranslated(0, 0, -8);*/
    camera();
	
	land();
	
	wall();
	dome_of_theRock_mosque();
	
	


	/*glFlush();*/
	
	
	




	
	

	
	
	




	return TRUE;
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, (char*)"Release Of DC And RC Failed.", (char*)"SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, (char*)"Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "GL template", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	switch (uMsg)									// Check For Windows Messages
	{
	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
		if (!HIWORD(wParam))					// Check Minimization State
		{
			active = TRUE;						// Program Is Active
		}
		else
		{
			active = FALSE;						// Program Is No Longer Active
		}

		return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:							// Intercept System Commands
	{
		switch (wParam)							// Check System Calls
		{
		case SC_SCREENSAVE:					// Screensaver Trying To Start?
		case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
			return 0;							// Prevent From Happening
		}
		break;									// Exit
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
		PostQuitMessage(0);						// Send A Quit Message
		return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
		keys[wParam] = TRUE;					// If So, Mark It As TRUE
		return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
		keys[wParam] = FALSE;					// If So, Mark It As FALSE
		return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
		return 0;								// Jump Back
	}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow((CHAR*)"OpenGL template", 640, 480, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	while (!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
			{
				done = TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{
				if (keys[VK_ESCAPE])				// Was ESC Pressed?
				{
					done = TRUE;						// ESC Signalled A Quit
				}
				else								// Not Time To Quit, Update Screen
				{
					DrawGLScene();					// Draw The Scene
					SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
				}
			}

			if (keys[VK_F1])						// Is F1 Being Pressed?
			{
				keys[VK_F1] = FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen = !fullscreen;				// Toggle Fullscreen / Windowed Mode
				// Recreate Our OpenGL Window
				if (!CreateGLWindow((CHAR*)"OpenGL template", 640, 480, 16, fullscreen))
				{
					return 0;						// Quit If Window Was Not Created
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}

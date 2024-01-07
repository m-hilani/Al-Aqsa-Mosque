#include <windows.h>		// Header File For Windows
#include <GL/gl.h>			// Header File For The OpenGL32 Library
#include <GL/glu.h>			// Header File For The GLu32 Library
#include <GL/glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <GL/texture.h>
#include "Sky.cpp"
#include "Floor.cpp"
#include "DomeOf_TheRock.cpp"
#include "Fields_Trees.cpp"
#include "Door.cpp"
//#include "3DTexture.cpp"
//#include "Model_3DS.cpp"
#include "3DTexture.h"
#include "Model_3DS.h"
#include "NorthernSection.cpp"
#include <stdio.h>
#include <math.h>

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
	gluPerspective(60.0f, (GLfloat)width / (GLfloat)height, 3.1f, 80000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

int back, front, left, right, top, land, land_Rock, cylinder_img, wall_img1, wall_img2,
roof_img, wall, dome_img, colum_img, chian, chian_img2, bulid_img, platform_img, platform_dome, platform_colum,
windo_build1_img, Door_build1_img, dome2, grass, door_mercy, DarAlHadith, DarAlHadith2,
Door_alasibat, Door_alasibat2, school, Door_build2;



GLfloat lightpos[] = { 3.0f,3.0f,1.0f,0.0f };
GLfloat lightamp[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat lightdiff[] = { 0.8f,0.8f,0.8f,1.0f };
GLfloat lightspec[] = { 0.7f,0.7f,0.7f,1.0f };

GLfloat matamp[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat matdif[] = { 0.8f,0.8f,0.8f,1.0f };
GLfloat matspec[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat matshin[] = { 128.0f };

Model_3DS tree1;
//tree
GLTexture m1, m2;

int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	m1.LoadBMP((char*)"bark_loo.bmp");
	m2.LoadBMP((char*)"bark_loo.bmp");

	tree1 = Model_3DS();
	char ab[] = "M_TREE5.3DS";
	tree1.Load(ab);
	tree1.pos.x = 0;
	tree1.pos.y = -0;
	tree1.pos.z = -6;
	tree1.scale = 0.8;
	tree1.Materials[0].tex = m1;
	tree1.Materials[1].tex = m2;

	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Lighting:

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);  //light source


	// lighting 0
		glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightamp);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightdiff);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightspec);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

	//object lighting
	glMaterialfv(GL_FRONT, GL_AMBIENT, matamp);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matdif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matspec);
	glMaterialfv(GL_FRONT, GL_SHININESS, matshin);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);


	//specular is the shininess color
	/* float sp[] = {0,0,0};
	glLightfv(GL_LIGHT0, GL_SPECULAR, sp); */

	//enabling color material restores sets the color in glColor3f to the ambient & diffuse material components for the objects
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);



	glEnable(GL_TEXTURE_2D);
	back = LoadTexture((CHAR*)"textures\\back.bmp", 255);
	front = LoadTexture((CHAR*)"textures\\front.bmp", 255);
	left = LoadTexture((CHAR*)"textures\\left.bmp", 255);
	right = LoadTexture((CHAR*)"textures\\right.bmp", 255);
	top = LoadTexture((CHAR*)"textures\\top.bmp", 255);
	land = LoadTexture((CHAR*)"textures\\floor.bmp", 255);
	land_Rock = LoadTexture((CHAR*)"textures\\landrock.bmp", 255);
	cylinder_img = LoadTexture((CHAR*)"textures\\cylinder_img.bmp", 255);
	wall_img1 = LoadTexture((CHAR*)"textures\\wall_img1.bmp", 255);
	wall_img2 = LoadTexture((CHAR*)"textures\\wall_img2.bmp", 255);
	roof_img = LoadTexture((CHAR*)"textures\\roof_img.bmp", 255);
	dome_img = LoadTexture((CHAR*)"textures\\dome_img.bmp", 255);
	dome2 = LoadTexture((CHAR*)"textures\\dome2.bmp", 255);
	colum_img = LoadTexture((CHAR*)"textures\\colum_img.bmp", 255);
	chian_img2 = LoadTexture((CHAR*)"textures\\chian_img2.bmp", 255);
	chian = LoadTexture((CHAR*)"textures\\chian.bmp", 255);
	platform_colum = LoadTexture((CHAR*)"textures\\platform_colum.bmp", 255);
	platform_dome = LoadTexture((CHAR*)"textures\\platform_dome.bmp", 255);
	platform_img = LoadTexture((CHAR*)"textures\\platform_img.bmp", 255);
	wall = LoadTexture((CHAR*)"textures\\wall.bmp", 255);
	bulid_img = LoadTexture((CHAR*)"textures\\bulid_img.bmp", 255);
	Door_build1_img = LoadTexture((CHAR*)"textures\\Door_build1_img.bmp", 255);
	windo_build1_img = LoadTexture((CHAR*)"textures\\windo_build1_img.bmp", 255);
	grass = LoadTexture((CHAR*)"textures\\grass.bmp", 255);
	door_mercy = LoadTexture((CHAR*)"textures\\door_mercy.bmp", 255);
	DarAlHadith = LoadTexture((CHAR*)"textures\\DarAlHadith.bmp", 255);
	DarAlHadith2 = LoadTexture((CHAR*)"textures\\DarAlHadith2.bmp", 255);
	Door_alasibat = LoadTexture((CHAR*)"textures\\Door_alasibat.bmp", 255);
	Door_alasibat2 = LoadTexture((CHAR*)"textures\\Door_alasibat2.bmp", 255);
	school = LoadTexture((CHAR*)"textures\\school.bmp", 255);
	Door_build2 = LoadTexture((CHAR*)"textures\\Door_build2.bmp", 255);
	return TRUE;										// Initialization Went OK
}
float cameraX = 0.0f;
float cameraY = 200.0f;
float cameraZ = 5.0f; // Initial position along Z-axis
float cameraAngleX = 0.0f;
float cameraAngleY = 0.0f;
int lastMouseX = -1;
int lastMouseY = -1;
double movX, movY, movZ, lX, lY;
void Camera()
{
	gluLookAt(cameraX, cameraY, cameraZ,
		cameraX + cos(cameraAngleX) * cos(cameraAngleY),
		cameraY + sin(cameraAngleY),
		cameraZ + sin(cameraAngleX) * cos(cameraAngleY),
		0.0f, 1.0f, 0.0f);
	float moveSpeed = 200.0f;


	if (keys['A'])
	{
		cameraX += moveSpeed * sin(cameraAngleX);
		cameraZ -= moveSpeed * cos(cameraAngleX);
	}
	if (keys['D'])
	{
		cameraX -= moveSpeed * sin(cameraAngleX);
		cameraZ += moveSpeed * cos(cameraAngleX);
	}
	if (keys['W'])
	{
		cameraX += moveSpeed * cos(cameraAngleX);
		cameraZ += moveSpeed * sin(cameraAngleX);
	}
	if (keys['S'])
	{
		cameraX -= moveSpeed * cos(cameraAngleX);
		cameraZ -= moveSpeed * sin(cameraAngleX);
	}
		movY -= 60;
	if (keys['Q'])
		cameraY += 100;
	if (keys['E'])
		cameraY -= 100;
	/*if (keys[VK_LEFT])
		lX += 280;
	if (keys[VK_RIGHT])
		lX -= 280;
	if (keys[VK_UP])
		lY += 280;
	if (keys[VK_DOWN])
		lY -= 200;*/


}

int mouseX = 0, mouseY = 0;
bool isClicked = 0, isRClicked = 0;
int x = 0, angle = 360;
double k = 0, l = 0, h = 0;
void mouse(int x, int y)
{
	if (lastMouseX == -1 || lastMouseY == -1) {
		lastMouseX = x;
		lastMouseY = y;
		return;
	}

	float sensitivity = 0.01f; // Adjust sensitivity as needed

	float deltaX = x - lastMouseX;
	float deltaY = y - lastMouseY;

	cameraAngleX += deltaX * sensitivity;
	cameraAngleY -= deltaY * sensitivity;

	// Limit vertical angle to avoid flipping
	if (cameraAngleY >3.14 / 2.0f) cameraAngleY = 3.14 / 2.0f;
	if (cameraAngleY < -3.14 / 2.0f) cameraAngleY = -3.14 / 2.0f;

	lastMouseX = x;
	lastMouseY = y;




}

//aazzzwsaassaaaxxxxxxxxxxassxa
float lamX = 3.0f,lamY = 7.0f, lamZ = 3.0f;
Sky s = Sky();
Floor f = Floor();
Dome_Rock r = Dome_Rock();
Fields_Trees fields = Fields_Trees();
Door d = Door();
Northern_section n = Northern_section();

int DrawGLScene(GLvoid)		
// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	Camera();
	mouse(mouseX, mouseY);
	
	tree1.Draw();

	s.sky(back, front, left, right, top);
	f.floor(land);
	r.land_of_theRock(land_Rock);
	r.dome_of_theRock_mosque(cylinder_img, dome_img, roof_img, wall_img1, wall_img2);
	r.Chain_dome(colum_img, chian, chian_img2);
	r.Chain_dome_Small(colum_img, chian, chian_img2);
	r.Entrance(colum_img);
	r.drawer(chian);
	r.platform(platform_colum, platform_dome, platform_img, chian);
	r.walls(wall);
	r.bulid1_Surrounding(windo_build1_img, Door_build1_img, colum_img, chian, dome2, platform_colum);
	fields.Grass(grass, colum_img, chian, platform_colum, platform_img);
	d.door(colum_img, door_mercy, chian, DarAlHadith, DarAlHadith2, Door_alasibat, Door_alasibat2);
	n.Northern_schools(Door_alasibat2, school, Door_build2, colum_img, chian);
	lightpos[0] = lamX;
	lightpos[1] = lamY;
	lightpos[2] = lamZ;
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

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
	static PAINTSTRUCT ps;

	switch (uMsg)									// Check For Windows Messages
	{
	case WM_MOUSEMOVE:
	{
		mouseX = (int)LOWORD(lParam);
		mouseY = (int)HIWORD(lParam);
		isClicked = (LOWORD(wParam) & MK_LBUTTON) ? true : false;
		isRClicked = (LOWORD(wParam) & MK_RBUTTON) ? true : false;
		break;
	}
	case WM_LBUTTONUP:
		isClicked = false; 	 break;
	case WM_RBUTTONUP:
		isRClicked = false;   break;
	case WM_LBUTTONDOWN:
		isClicked = true; 	break;
	case WM_RBUTTONDOWN:
		isRClicked = true;	break;
	case WM_PAINT:
		DrawGLScene();
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_TIMER:
		DrawGLScene();
		return 0;

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
	return (msg.wParam);							// Exit The Program
}

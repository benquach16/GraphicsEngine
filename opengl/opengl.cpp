//////////////////////////////////////////////////////////////////////
///Copyright (C) 2012 Benjamin Quach
//
//This file is part of bengine
//
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "opengl.h"


//WIN32 STUFF GOES HERE
bool win_windows_closed;
bool keys[256];

enum WIN_KEYS
{
	KEY_ESCAPE = 0x1B,
	KEY_LEFT = 0x25,
	KEY_UP = 0x26,
	KEY_RIGHT = 0x27,
	KEY_DOWN = 0x28,
	KEY_0 = 0x30,
	KEY_1 = 0x31,
	KEY_2 = 0x32,
	KEY_3 = 0x33,
	KEY_4 = 0x34,
	KEY_5 = 0x35,
	KEY_6 = 0x36,
	KEY_7 = 0x37,
	KEY_8 = 0x38,
	KEY_9 = 0x39,
	KEY_A = 0x41,
	KEY_B = 0x42,
	KEY_C = 0x43,
	KEY_D = 0x44,
	KEY_E = 0x45,
	KEY_F = 0x46,
	KEY_G = 0x47,
	KEY_H = 0x48,
	KEY_I = 0x49,
	KEY_J = 0x4A,
	KEY_K = 0x4B,
	KEY_L = 0x4C,
	KEY_M = 0x4D,
	KEY_N = 0x4E,
	KEY_O = 0x4F,
	KEY_P = 0x50,
	KEY_Q = 0x51,
	KEY_R = 0x52,
	KEY_S = 0x53,
	KEY_T = 0x54,
	KEY_U = 0x55,
	KEY_V = 0x56,
	KEY_W = 0x57,
	KEY_X = 0x58,
	KEY_Y = 0x59,
	KEY_Z = 0x5A
};

GLRender::GLRender() : window_closed(false), hWnd(0), hDC(0), hRC(0)
{
#if _WIN32
	for(unsigned i = 0; i <256; i++)
	{
		keys[i] = false;
	}
#endif
	//reset();
}

GLRender::~GLRender()
{
	delete imageloader;
	delete eventmanager;
	delete scenemanager;
	purge();
}

void GLRender::init()
{
	hDC = ::GetDC(hWnd);

	::PIXELFORMATDESCRIPTOR pixel_descriptor;
	//lets allocate some meomry
	ZeroMemory(&pixel_descriptor, sizeof(pixel_descriptor));

	//specify pixel descriptor with important opengl stuff
	pixel_descriptor.nSize = sizeof(pixel_descriptor);
	pixel_descriptor.nVersion = 1;
	pixel_descriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pixel_descriptor.iPixelType = PFD_TYPE_RGBA;
	pixel_descriptor.cColorBits = 24;
	pixel_descriptor.cDepthBits = 16;
	pixel_descriptor.iLayerType = PFD_MAIN_PLANE;

	int format = ::ChoosePixelFormat(hDC, &pixel_descriptor);
	::SetPixelFormat(hDC, format, &pixel_descriptor);

	hRC = ::wglCreateContext(hDC);
	::wglMakeCurrent(hDC, hRC);

	imageloader = new CImageLoader();
	scenemanager = new CSceneManager();
	eventmanager = new CEventManager();

	glMatrixMode(GL_PROJECTION);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1);
	glEnable(GL_LIGHTING);
	glMatrixMode(GL_MODELVIEW);

	glShadeModel (GL_SMOOTH);
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	//temporary dlete later
	glEnable(GL_LIGHT0);
	GLfloat lightpos[] = {1, 1, -3, 1};
	GLfloat lightcol[] = {0.9, 0.9, 0.9, 0.1};
	GLfloat amb[] = {0.1,0.1,0.1,0.1};
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightcol);


	//initialize a window
	//then create an opengl renderer
	float width = window_size.X;
	float height = window_size.Y;
	glViewport(0,0,(GLsizei)width,(GLsizei)height);
	window_size = vector2d(width,height);
	glMatrixMode(GL_PROJECTION);
	float aspect = width / height;
	glOrtho(-aspect,aspect,-1,1,-1,1);
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
}


void GLRender::reset()
{
	hWnd = NULL;
	hDC = NULL;
	hRC = NULL;
}

void GLRender::swapBuffers()
{
	::SwapBuffers(hDC);
}

void GLRender::purge()
{
	//if it exists
	//delete it
	if(hRC)
	{
		::wglMakeCurrent(NULL,NULL);
		::wglDeleteContext(hRC);
	}

	if(hWnd && hDC)
	{
		::ReleaseDC(hWnd, hDC);
	}
	reset();
}

void GLRender::drop()
{

	delete this;
}

void GLRender::drawScene()
{
	//TODO : create a scene graph
	//then render all objects from that
#if _WIN32
	getWindowsMessages();
#endif

	beginDrawScene();
	glLoadIdentity();

	//multiply everything by the inverse of the camera matrix
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	
	if(scenemanager->getActiveCamera())
	{
		//test code
		//scenemanager->getActiveCamera()->render();
		matrix4 m= scenemanager->getActiveCamera()->getProjectionMatrix();
		m.inverse();
		glLoadMatrixf(m.m);
	}
	scenemanager->render();
	glPopMatrix();
	//delete later test func

#if _WIN32
	eventmanager->windowsKeyHook(keys);
#endif
	endDrawScene();
}

void GLRender::beginDrawScene()
{
	glClearColor( 0.2f, 0.2f, 0.5f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glPushMatrix();
}

void GLRender::endDrawScene()
{
	glPopMatrix();
	swapBuffers();
}


/////////////////////////////////
//Windows stuff goes below here

void GLRender::windowsSetHinstance(HINSTANCE hInstance)
{
	this->hInstance = hInstance;
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		//do windows stuff
	case WM_PAINT:
		{
			break;
		}
	case WM_CLOSE:
		{
			DestroyWindow(hWnd);
			break;
		}
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
	case WM_KEYDOWN:
		{
			//create enum table
			//delete this later
			//hopefully we can condense this down into a function taht can easily do this
			if(wParam == WIN_KEYS::KEY_0)
			{
				keys[E_KEY_TYPES::E_KEY_0] = true;
			}
			if(wParam == WIN_KEYS::KEY_1)
			{
				keys[E_KEY_TYPES::E_KEY_1] = true;
			}
			if(wParam == WIN_KEYS::KEY_2)
			{
				keys[E_KEY_TYPES::E_KEY_2] = true;
			}
			if(wParam == WIN_KEYS::KEY_3)
			{
				keys[E_KEY_TYPES::E_KEY_3] = true;
			}
			if(wParam == WIN_KEYS::KEY_A)
			{
				keys[E_KEY_TYPES::E_KEY_A] = true;
			}
			if(wParam == WIN_KEYS::KEY_B)
			{
				keys[E_KEY_TYPES::E_KEY_B] = true;
			}
			if(wParam == WIN_KEYS::KEY_C)
			{
				keys[E_KEY_TYPES::E_KEY_C] = true;
			}
			if(wParam == WIN_KEYS::KEY_D)
			{
				keys[E_KEY_TYPES::E_KEY_D] = true;
			}
			if(wParam == WIN_KEYS::KEY_E)
			{
				keys[E_KEY_TYPES::E_KEY_E] = true;
			}
			if(wParam == WIN_KEYS::KEY_Z)
			{
				keys[E_KEY_TYPES::E_KEY_Z] = true;
			}
			if(wParam == WIN_KEYS::KEY_LEFT)
			{
				keys[E_KEY_TYPES::E_KEY_LEFT] = true;
			}
			if(wParam == WIN_KEYS::KEY_UP)
			{
				keys[E_KEY_TYPES::E_KEY_UP] = true;
			}
			if(wParam == WIN_KEYS::KEY_RIGHT)
			{
				keys[E_KEY_TYPES::E_KEY_RIGHT] = true;
			}
			if(wParam == WIN_KEYS::KEY_DOWN)
			{
				keys[E_KEY_TYPES::E_KEY_DOWN] = true;
			}
			break;
		}
	case WM_KEYUP:
		{
			if(wParam == WIN_KEYS::KEY_C)
			{
				keys[E_KEY_TYPES::E_KEY_C] = false;
			}
			if(wParam == WIN_KEYS::KEY_LEFT)
			{
				keys[E_KEY_TYPES::E_KEY_LEFT] = false;
			}
			if(wParam == WIN_KEYS::KEY_UP)
			{
				keys[E_KEY_TYPES::E_KEY_UP] = false;
			}
			if(wParam == WIN_KEYS::KEY_RIGHT)
			{
				keys[E_KEY_TYPES::E_KEY_RIGHT] = false;
			}
			if(wParam == WIN_KEYS::KEY_DOWN)
			{
				keys[E_KEY_TYPES::E_KEY_DOWN] = false;
			}
			break;
		}
	default:
		{
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}
	}
	return 0;
}

bool GLRender::createOpenGlWindow(const char *title, int width, int height, int bits, bool fullscreen)
{

	window_size = vector2d((float)width,(float)height);
#if _WIN32
	WNDCLASSEX wnd;
	DWORD ex_style;
	DWORD style;
	static TCHAR szWindowClass[] = _T("win32");
	static TCHAR szWndName[] = _T("OPENGLTEST");
	
	wnd.cbSize = sizeof(WNDCLASSEX);
	wnd.style = 0;
	wnd.lpfnWndProc = WndProc;
	wnd.cbClsExtra = 0;
	wnd.cbWndExtra = 0;
	wnd.hInstance = hInstance;
	wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wnd.hCursor = LoadCursor(NULL,IDC_ARROW);
	wnd.hbrBackground = (HBRUSH)(COLOR_MENU);
	wnd.lpszMenuName = NULL;
	wnd.lpszClassName = szWindowClass;
	wnd.hIconSm = LoadIcon(NULL,IDI_APPLICATION);
    if(!RegisterClassEx(&wnd))
    {
		//crashes cause we can't make a window
		return false;
    }

	if(fullscreen)
	{
		::DEVMODE screen;
		screen.dmSize = sizeof(screen);
		screen.dmPelsWidth = width;
		screen.dmPelsHeight = height;
		screen.dmBitsPerPel = bits;
		screen.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
		::ChangeDisplaySettingsW(&screen, CDS_FULLSCREEN);
								
		ShowCursor(FALSE);	
		ex_style = WS_EX_APPWINDOW;
		style = WS_POPUP;
	}
	else
	{
		ex_style = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
		style = WS_OVERLAPPEDWINDOW;
	}

	/*
	hWnd = CreateWindow(szWindowClass,szWndName,
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
		CW_USEDEFAULT,CW_USEDEFAULT,
		width,height,NULL,NULL, hInstance, NULL); */
	hWnd = CreateWindowEx(ex_style, szWindowClass, szWndName, style,
		0,0, width, height, NULL, NULL, hInstance, NULL);
	
	ShowWindow(hWnd,SW_SHOW);
	UpdateWindow(hWnd);

	return true;

#else if __unix__
	//COMPILE WITH G++ CAUSE GLUT
	glutInit();
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
#endif


}

void GLRender::getWindowsMessages()
{
	MSG Msg;
	PeekMessage( &Msg, NULL, 0, 0, PM_REMOVE);


	// handle or dispatch messages
	if ( Msg.message == WM_QUIT ) 
	{
		window_closed = true;
	} 
	else 
	{
		TranslateMessage( &Msg );
		DispatchMessage( &Msg );
	}
}
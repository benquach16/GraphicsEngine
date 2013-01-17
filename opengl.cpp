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


GLRender::GLRender()
{
	t = 0;
	reset();
}

GLRender::~GLRender()
{
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
	image = imageloader->loadBMP("test.bmp");
	scenemanager = new CSceneManager();

	//glEnable(GL_TEXTURE_2D);
	//glEnable(GL_DEPTH_TEST);
	//glEnable(GL_LIGHTING);
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
	//TODO : deallocate memory
	delete this;
}

void GLRender::drawScene()
{
	//create a scene graph
	//then render all objects from that

	beginDrawScene();
	glLoadIdentity();
	scenemanager->render();
	glRotatef(t,0,1,0);
	glBegin( GL_TRIANGLES );
	::glColor3f(0.0f,1.0f,1.0f);	
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
	::glColor3f(1.0f,0.0f,1.0f);	
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);  // Bottom Right Of The Texture and Quad
	::glColor3f(1.0f,0.0f,0.0f);	
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f,  0.5f);  // Top Right Of The Texture and Quad
	::glColor3f(0.0f,1.0f,1.0f);	
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
	::glColor3f(1.0f,0.0f,1.0f);	
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);  // Bottom Right Of The Texture and Quad
	::glColor3f(1.0f,1.0f,0.0f);	
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f,  0.5f);  // Top Right Of The Texture and Quad    

	glEnd();
	endDrawScene();
	t+=0.01;
}

void GLRender::beginDrawScene()
{
	glClearColor( 0.2f, 0.2f, 0.5f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT );
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
		
	default:
		{
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}

	return 0;
	}
}

bool GLRender::createOpenGlWindow(const char *title, int width, int height, int bits, bool fullscreen)
{
	//initialize a window
	//then create an opengl renderer
	//heres windows code

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

#else
#if __unix__
#endif
#endif


}

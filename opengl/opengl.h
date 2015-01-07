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

#ifndef _OPENGL_H_
#define _OPENGL_H_

#include "Resource.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include "imageloader.h"
#include "meshloader.h"
#include "scenemanager.h"
#include "eventmanager.h"
#include "mesh.h"
#include "scenenode.h"
#include "lightscenenode.h"
#include "meshscenenode.h"
#include "camerascenenode.h"
#include "texture.h"
#include "vector2d.h"
#include "vector3d.h"
#include "color.h"

//make this easier on ourselves by standardizing it
struct CCreationParams
{
	int x;
	int y;
	int bits;
	bool fullscreen;
};

//most of the heavy lifting is done in this class
class GLRender
{
public:
	GLRender();
	~GLRender();
	void reset();
	//initialize everything opengl
	void init();
	//function should be run in main loop
	//calls everything needed to render
	//should be at the end of the loop
	void drawScene();

	//swaps the buffers
	void swapBuffers();
	void purge();
	void drop();


	//Windows Functions
	void windowsSetHinstance(HINSTANCE hInstance);
	bool createOpenGlWindow(const char *title, int width, int height, int bits, bool fullscreen);

	//accessor functions
	//get the image loader
	CImageLoader *getImageLoader() const
	{
		return imageloader;
	}
	//get the scene manager
	CSceneManager *getSceneManager() const
	{
		return scenemanager;
	}
	//get the mesh loader
	CMeshLoader *getMeshLoader() const
	{
		return meshloader;
	}
	CEventManager *getEventManager() const
	{
		return eventmanager;
	}
	vector2d getWindowSize() const
	{
		return window_size;
	}

	bool getWindowClosed() const
	{
		return window_closed;
	}

	
protected:
	void beginDrawScene();
	void endDrawScene();
	void getWindowsMessages();

private:
	//Windows essential variables
	HINSTANCE hInstance;
	HWND hWnd;
    HDC hDC;
    HGLRC hRC;

	CImageLoader *imageloader;
	CSceneManager *scenemanager;
	CMeshLoader *meshloader;
	CEventManager *eventmanager;




	vector2d window_size;
	bool window_closed;
};

#endif
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
#include "mesh.h"
#include "scenenode.h"
#include "lightscenenode.h"
#include "meshscenenode.h"
#include "camerascenenode.h"
#include "texture.h"

//most of the heavy lifting is done in this class
class GLRender
{
public:
	GLRender();
	~GLRender();
	void reset();
	void init();
	//function should be run in main loop
	void drawScene();

	void swapBuffers();
	void purge();
	void drop();
	//Windows Functions
	void windowsSetHinstance(HINSTANCE hInstance);
	bool createOpenGlWindow(const char *title, int width, int height, int bits, bool fullscreen);

	CImageLoader *getImageLoader()
	{
		return imageloader;
	}
	CSceneManager *getSceneManager()
	{
		return scenemanager;
	}
	CMeshLoader *getMeshLoader()
	{
		return meshloader;
	}

protected:
	void beginDrawScene();
	void endDrawScene();

private:
	HINSTANCE hInstance;
	HWND hWnd;
    HDC hDC;
    HGLRC hRC;

	CImageLoader *imageloader;
	CSceneManager *scenemanager;
	CMeshLoader *meshloader;
	CTexture *image;
	float t;
};

#endif
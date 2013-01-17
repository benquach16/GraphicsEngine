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
#include "main.h"

#pragma comment(lib, "opengl32.lib")


//Framework for Windows to use OpenGL
//could be used in a custom game engine
GLRender *createGraphicsEngine()
{
	GLRender *render = new GLRender();
	return render;
}

//when releasing as a lib, probably should delete this
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	MSG Msg;


	GLRender *render = createGraphicsEngine();
	render->windowsSetHinstance(hInstance);
	render->createOpenGlWindow("TEST", 800,600,32,false);
	render->init();

	bool quit = false;
	

	while(!quit)
	{
		PeekMessage( &Msg, NULL, 0, 0, PM_REMOVE);


		// handle or dispatch messages
		if ( Msg.message == WM_QUIT ) 
		{
			quit = true;
		} 
		else 
		{
			TranslateMessage( &Msg );
			DispatchMessage( &Msg );
		}

		render->drawScene();

	

	}
	return Msg.wParam;
}
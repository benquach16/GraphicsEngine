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
//mostly a test harness function
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	GLRender *render = createGraphicsEngine();
	render->createOpenGlWindow("TEST", 800,600,32,false);
	render->init();
	
	CMeshSceneNode *mesh = render->getSceneManager()->createBoxSceneNode(1, vector3d(0,0,1), vector3d(0,0,0));
	CCameraSceneNode *cam = render->getSceneManager()->createCameraSceneNode(vector3d(0,0,0));
	while(!render->getWindowClosed())
	{
		vector3d rot = cam->getRotation();
		if(render->getEventManager()->getKeyState(E_KEY_TYPES::E_KEY_C))
		{
			rot.Z+= 1;
			cam->setRotation(rot);
		}

		vector3d pos = cam->getPosition();
		if(render->getEventManager()->getKeyState(E_KEY_TYPES::E_KEY_LEFT))
		{
			pos.X -= 0.0001;
			cam->setPosition(pos);
		}
		if(render->getEventManager()->getKeyState(E_KEY_TYPES::E_KEY_RIGHT))
		{
			pos.X += 0.0001;
			cam->setPosition(pos);
		}
		if(render->getEventManager()->getKeyState(E_KEY_TYPES::E_KEY_UP))
		{
			pos.Y += 0.0001;
			cam->setPosition(pos);
		}
		if(render->getEventManager()->getKeyState(E_KEY_TYPES::E_KEY_DOWN))
		{
			pos.Y -= 0.0001;
			cam->setPosition(pos);
		}
		if(render->getEventManager()->getKeyState(E_KEY_TYPES::E_KEY_A))
		{
			pos.Z += 0.01;
			cam->setPosition(pos);
		}
		if(render->getEventManager()->getKeyState(E_KEY_TYPES::E_KEY_Z))
		{
			pos.Z -= 0.01;
			cam->setPosition(pos);
		}
		render->drawScene();
	}
	render->drop();
	return 0;
}
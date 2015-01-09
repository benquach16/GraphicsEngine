#include "stdafx.h"
#include "main.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")


//Framework for Windows to use OpenGL
//could be used in a custom game engine
GLRender *createGraphicsEngine()
{
	GLRender *render = new GLRender();
	return render;
}

//when releasing as a lib, probably should delete this
//mostly a test harness function
int main()
{

	GLRender *render = createGraphicsEngine();
	render->createOpenGlWindow("TEST", 800,600,32,false);
	render->init();
	
	CMeshSceneNode *mesh = render->getSceneManager()->createBoxSceneNode(1, vector3d(0,0,0), vector3d(0,0,0));
	CCameraSceneNode *cam = render->getSceneManager()->createCameraSceneNode(vector3d(0,0,0));
	CLightSceneNode *light = render->getSceneManager()->createLightSceneNode(200,200,vector3d(1,0,-2));
	CMeshSceneNode *mesh2 = render->getSceneManager()->createMeshSceneNode(render->getMeshLoader()->loadOBJ("teapot.obj"), vector3d(0, 0, -4)); 
	CTexture *t = render->getImageLoader()->loadBMP("test.bmp");
	
	while(!render->getWindowClosed())
	{
		vector3d rot = cam->getRotation();
		if(render->getEventManager()->getKeyState(E_KEY_TYPES::E_KEY_C))
		{
			rot.X -= 0.1;
			cam->setRotation(rot);
		}

		vector3d pos = cam->getPosition();
		if(render->getEventManager()->getKeyState(E_KEY_TYPES::E_KEY_LEFT))
		{
			pos.X -= 0.01;
			cam->setPosition(pos);
		}
		if(render->getEventManager()->getKeyState(E_KEY_TYPES::E_KEY_RIGHT))
		{
			pos.X += 0.01;
			cam->setPosition(pos);
		}
		if(render->getEventManager()->getKeyState(E_KEY_TYPES::E_KEY_UP))
		{
			pos.Y += 0.01;
			cam->setPosition(pos);
		}
		if(render->getEventManager()->getKeyState(E_KEY_TYPES::E_KEY_DOWN))
		{
			pos.Y -= 0.01;
			cam->setPosition(pos);
		}
		if(render->getEventManager()->getKeyState(E_KEY_TYPES::E_KEY_A))
		{
			pos.Z += 0.05;
			cam->setPosition(pos);
		}
		if(render->getEventManager()->getKeyState(E_KEY_TYPES::E_KEY_Z))
		{
			pos.Z -= 0.005;
			cam->setPosition(pos);
		}
		if(render->getEventManager()->getKeyState(E_KEY_TYPES::E_KEY_R))
		{
			cam->setPosition(vector3d(0,0,0));
		}
		render->drawScene();
	}
	render->drop();
	return 0;
}

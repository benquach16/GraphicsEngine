#include "stdafx.h"
#include "scenemanager.h"
#include "scenenode.h"
#include "meshscenenode.h"
#include "camerascenenode.h"
#include "lightscenenode.h"


CSceneManager::CSceneManager()
	: active_camera(0),
	  root(new CSceneNode(this, vector3d(0,0,0),vector3d(0,0,0),vector3d(0,0,0),0))

								 
{
	
}

CSceneManager::~CSceneManager()
{
	//delete everything
	//should recursively delete from root
	delete root;

}

void CSceneManager::render()
{
	//get all of the nodes childed to root
	//depth first search to get them
	root->render();
}

CMeshSceneNode *CSceneManager::createBoxSceneNode(float size, vector3d position, vector3d rotation, vector3d scale, CSceneNode *parent)
{
	//construct a cube manually

	CMeshSceneNode *node = new CMeshSceneNode(this, PREFAB_CUBE, size, position, rotation, scale, parent);
	if(parent)
	{
		parent->addChild(node);
	}
	else
		root->addChild(node);
	return node;
}

CMeshSceneNode *CSceneManager::createMeshSceneNode(CMesh *mesh, vector3d position, vector3d rotation, vector3d scale, CSceneNode *parent)
{
	CMeshSceneNode *node = new CMeshSceneNode(mesh, this, position, rotation, scale, parent);
	if(parent)
		parent->addChild(node);
	else
		root->addChild(node);
	return node;
}

CCameraSceneNode *CSceneManager::createCameraSceneNode(vector3d position, vector3d rotation, CSceneNode *parent)
{
	CCameraSceneNode *node = new CCameraSceneNode(this, position, rotation, parent);
	if(!active_camera)
		active_camera = node;
	if(parent)
		parent->addChild(node);
	else
		root->addChild(node);

	return node;
}

CLightSceneNode *CSceneManager::createLightSceneNode(float strength, float radius,
													 vector3d position, vector3d rotation,
													 const color newcolor,
													 CSceneNode* parent)
{
	CLightSceneNode *node = new CLightSceneNode(
		this, strength, radius,
		position, rotation, newcolor, TYPE_OMNI, parent);
	if(parent)
		parent->addChild(node);
	else
		root->addChild(node);
	return node;
}


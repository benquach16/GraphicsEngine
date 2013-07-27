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
#include "scenemanager.h"
#include "scenenode.h"
#include "meshscenenode.h"
#include "camerascenenode.h"
#include "lightscenenode.h"


CSceneManager::CSceneManager() : active_camera(0),
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

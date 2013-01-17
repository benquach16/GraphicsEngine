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

CSceneManager::CSceneManager()
{
	root = new CSceneNode(vector3d(0,0,0),vector3d(0,0,0),vector3d(0,0,0),0);
}

void CSceneManager::render()
{
	//get all of the nodes childed to root
	//render them
	for(int i =0; i < renderable_scene_nodes.size(); i++)
	{
		renderable_scene_nodes[i]->render();
	}
}

CMeshSceneNode *CSceneManager::createBoxSceneNode(float size, vector3d position, vector3d rotation, vector3d scale, CSceneNode *parent)
{
	//construct a cube manually

	CMeshSceneNode *node = new CMeshSceneNode();
	if(parent)
	{
		parent->addChild(node);
	}
	else
		root->addChild(node);
	return node;
}

CCameraSceneNode *CSceneManager::createCameraSceneNode(vector3d position, vector3d rotation, vector3d scale, CSceneNode *parent)
{
	CCameraSceneNode *node = new CCameraSceneNode(position, rotation, parent);
	if(!active_camera)
		active_camera = node;

	return node;
}

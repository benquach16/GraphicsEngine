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
#include "meshscenenode.h"

CMeshSceneNode::CMeshSceneNode(CMesh *mesh, CSceneManager *manager, vector3d position, vector3d rotation, vector3d scale, CSceneNode *parent) :
CSceneNode(manager, position, rotation, scale, parent)
{
}

CMeshSceneNode::CMeshSceneNode(CSceneManager *manager, E_MESH_PREFABS prefab, float size, vector3d position, vector3d rotation, vector3d scale, CSceneNode *parent) : 
CSceneNode(manager, position, rotation, scale, parent)
{
	mesh = new CMesh(prefab, size);
}

CMeshSceneNode::~CMeshSceneNode()
{
}

void CMeshSceneNode::render()
{
	CSceneNode::render();
	mesh->render(position, rotation, scale);
}
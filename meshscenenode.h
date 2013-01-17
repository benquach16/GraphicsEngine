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

#ifndef _MESHSCENENODE_H_
#define _MESHSCENENODE_H_

#pragma once

#include "scenenode.h"
#include "mesh.h"

class CMeshSceneNode : public CSceneNode
{
public:
	friend class CSceneNode;
	//base mesh scenenode
	//use the meshloader object in order to load a mesh
	//then send as an argument
	CMeshSceneNode(CMesh *mesh = 0,
		vector3d position = vector3d(0,0,0),
		vector3d rotation = vector3d(0,0,0),
		vector3d scale = vector3d(0,0,0),
		CSceneNode *parent = 0);
	~CMeshSceneNode();

	//self explanitory really
	void setMesh(CMesh *new_mesh);
	CMesh* getMesh();

private:
	CMesh *mesh;
};

#endif
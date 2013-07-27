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
#include "scenemanager.h"
#include "mesh.h"
#include "texture.h"


class CMeshSceneNode : public CSceneNode
{
public:
	//base mesh scenenode
	//use the meshloader object in order to load a mesh
	//then send as an argument
	CMeshSceneNode(CMesh *mesh,
		CSceneManager *manager = 0,
		vector3d position = vector3d(0,0,0),
		vector3d rotation = vector3d(0,0,0),
		vector3d scale = vector3d(1,1,1),
		CSceneNode *parent = 0);
	CMeshSceneNode(
		CSceneManager *manager = 0,
		E_MESH_PREFABS prefab = PREFAB_CUBE,
		float size = 1.f,
		vector3d position = vector3d(0,0,0),
		vector3d rotation = vector3d(0,0,0),
		vector3d scale = vector3d(1,1,1),
		CSceneNode *parent = 0);
	void render();
	~CMeshSceneNode();

	//self explanitory really
	void setMesh(CMesh *new_mesh);
	//accessor function
	CMesh* getMesh();
	void setTexture(CTexture *new_texture);
	CTexture *getTexture();

private:
	CMesh *mesh;
};

#endif
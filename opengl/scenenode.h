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

#ifndef _SCENENODE_H_
#define _SCENENODE_H_

#pragma once

#include "vector3d.h"
#include "vector2d.h"
#include "color.h"
#include "mesh.h"
#include "vector"
#include "list"
#include "matrix4.h"
#include "scenemanager.h"

enum E_SCENE_NODE_TYPE
{
	TYPE_SCENENODE,
	TYPE_LIGHT,
	TYPE_MESH,
	TYPE_ANIMATEDMESH,
	TYPE_CAMERA,
	TYPE_TERRAIN
};

//comment this fuckin code
class CSceneNode
{
public:
	//Constructor
	CSceneNode(CSceneManager *manager = 0,
		const vector3d &position = vector3d(0,0,0),
		const vector3d &rotation = vector3d(0,0,0),
		const vector3d &scale = vector3d(1,1,1),
		CSceneNode *parent = 0);
	//copy constructor
	CSceneNode(const CSceneNode &n);
	//assignment operator
	CSceneNode& operator=(const CSceneNode &n);

	//Destructor
	virtual ~CSceneNode();

	//virtual function
	virtual void render();

	//accessor functoin
	//returns an rvalue
	std::list<CSceneNode*> getChildren() const;

	//removing a node
	//if there isn't a parent then
	virtual void remove();

	//delete the node
	//make sure we do this every time we create a new pointer
	virtual void drop();

	//remove a child
	bool removeChild(CSceneNode *child);

	//add a child
	void addChild(CSceneNode *child);

	//mutator function
	//set a parent node
	void setParent(CSceneNode *parent)
	{
		this->parent = parent;
	}
	//accessor function
	//return functions
	CSceneNode *getParent()
	{
		return parent;
	}

	//returns the position
	//as an rvalue
	//most of these functions should be self explanitory
	const vector3d getPosition() const
	{
		return position;
	}
	const vector3d getRotation() const
	{
		return rotation;
	}
	const vector3d getScale() const
	{
		return scale;
	}
	void setPosition(const vector3d &new_position)
	{
		position = new_position;
	}
	void setRotation(const vector3d &new_rotation)
	{
		rotation = new_rotation;
	}
	void setScale(const vector3d &new_scale)
	{
		scale = new_scale;
	}

protected:
	CSceneManager *manager;
	vector3d position;
	vector3d rotation;
	vector3d scale;
	matrix4 transform;

	CSceneNode *parent;

	std::list<CSceneNode*> children;

	E_SCENE_NODE_TYPE scene_node_type;
};

#endif
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
#include "mesh.h"
#include "vector"

//comment this fuckin code
class CSceneNode
{
public:
	//Constructor
	CSceneNode(vector3d position = vector3d(0,0,0),
		vector3d rotation = vector3d(0,0,0),
		vector3d scale = vector3d(1,1,1),
		CSceneNode *parent = 0)
	{
		if(!parent)
		{
			//no parent exists
			//so set parent to root scenenode
		}
	}
	~CSceneNode();
	void render()
	{
		//inherit position and rotaiton from parent
	}
	std::vector<CSceneNode*> getChildren()
	{
		return children;
	}
	//removing a node
	//if there isn't a parent then
	void remove()
	{
		if(parent)
			parent->removeChild(this);
	}

	void drop()
	{
		delete this;
	}
	//remove a child
	bool removeChild(CSceneNode *child)
	{
		for(int i = 0; i < children.size(); i++)
		{
			if(children[i] == child)
			{
				child->setParent(0);
				child->drop();
				return true;
			}
		}
		return false;
	}
	//add a child
	void addChild(CSceneNode *child)
	{
		child->setParent(this);
		children.push_back(child);
	}
	//set a parent node
	void setParent(CSceneNode *parent)
	{
		this->parent = parent;
	}

	//return functions
	CSceneNode *getParent()
	{
		return parent;
	}
	const vector3d getPosition()
	{
		return position;
	}
	const vector3d getRotation()
	{
		return rotation;
	}
	const vector3d getScale()
	{
		return scale;
	}
	void setPosition(vector3d new_position)
	{
		position = new_position;
	}
	void setRotation(vector3d new_rotation)
	{
		rotation = new_rotation;
	}
	void setScale(vector3d new_scale)
	{
		scale = new_scale;
	}

protected:
	vector3d position;
	vector3d rotation;
	vector3d scale;

private:
	CSceneNode *parent;


	std::vector<CSceneNode*> children;
};

#endif
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

#ifndef _LIGHTSCENENODE_H_
#define _LIGHTSCENENODE_H_

#pragma once

#include "scenenode.h"

enum E_LIGHT_TYPE
{
	TYPE_OMNI,
	TYPE_DIRECTIONAL
};

class CLightSceneNode : public CSceneNode
{
public:
	//default constructor
	CLightSceneNode(CSceneManager *manager = 0,
		float strength = 200.f, float radius = 100.f,
		const vector3d &position = vector3d(0,0,0),
		const vector3d &rotation = vector3d(0,0,0),
		E_LIGHT_TYPE light_type = TYPE_OMNI,
		CSceneNode *parent = 0);
	~CLightSceneNode();

	void render();
private:
	//light variables go here
	float strength;
	float radius;
};

#endif
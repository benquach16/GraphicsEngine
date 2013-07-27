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

#ifndef _CAMERASCENENODE_H_
#define _CAMERASCENENODE_H_

#pragma once

#include "scenenode.h"
#include "scenemanager.h"

class CCameraSceneNode : public CSceneNode
{
public:

	CCameraSceneNode(CSceneManager *manager = 0,
		const vector3d &position = vector3d(0,0,0),
		const vector3d &rotation = vector3d(0,0,0),
		CSceneNode *parent = 0);
	virtual ~CCameraSceneNode();
	//render function will update the viewing matrix
	virtual void render();
	matrix4 getProjectionMatrix() const;

protected:
	//This matrix is different from the camera transformation matrix
	//this is the actual viewprojection matrix
	matrix4 viewprojection;

};

#endif
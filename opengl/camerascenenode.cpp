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
#include "camerascenenode.h"

CCameraSceneNode::CCameraSceneNode(CSceneManager *manager, 
								   const vector3d &position,
								   const vector3d &rotation,
								   CSceneNode *parent) : 
CSceneNode(manager, position, rotation, vector3d(1,1,1), parent)
{
	viewprojection.setPosition(position);
}

CCameraSceneNode::~CCameraSceneNode()
{
}

void CCameraSceneNode::render()
{
	//update camera scene if its the active camera
	//glTranslated(position.X, position.Y, position.Z);
	//update the viewing matrix with the rotation and position
	viewprojection.setPosition(position);

	CSceneNode::render();
}

matrix4 CCameraSceneNode::getProjectionMatrix() const
{
	return viewprojection;
}
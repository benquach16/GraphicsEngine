#include "stdafx.h"
#include "camerascenenode.h"
#pragma hdrstop

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
	glRotatef(-getRotation().X , 1.0, 0.0, 0.0);
	glRotatef(-getRotation().Y , 0.0, 1.0, 0.0);
	glRotatef(-getRotation().Z , 0.0, 0.0, 1.0);
	glTranslatef(-position.X, -position.Y, -position.Z);
	//update the viewing matrix with the rotation and position
	//viewprojection.setPosition(position);

	CSceneNode::render();
}

matrix4 CCameraSceneNode::getProjectionMatrix() const
{
	return viewprojection;
}
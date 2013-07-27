#include "stdafx.h"
#include "lightscenenode.h"

CLightSceneNode::CLightSceneNode(CSceneManager *manager, float strength, float radius,
	const vector3d &position, const vector3d &rotation,
	E_LIGHT_TYPE light_type, CSceneNode *parent) :
strength(strength), radius(radius),
	CSceneNode(manager, position, rotation, vector3d(1,1,1), parent)
{
}

CLightSceneNode::~CLightSceneNode()
{
}


void CLightSceneNode::render()
{

}
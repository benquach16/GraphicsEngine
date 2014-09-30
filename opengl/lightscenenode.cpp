#include "stdafx.h"
#include "lightscenenode.h"

int CLightSceneNode::lightCount = 0;

CLightSceneNode::CLightSceneNode(
	CSceneManager *manager, float strength, float radius,
	const vector3d &position, const vector3d &rotation,
	const color& newcolor,
	E_LIGHT_TYPE light_type, CSceneNode *parent) 
	:
	strength(strength), radius(radius), lightColor(newcolor),
	CSceneNode(manager, position, rotation, vector3d(1,1,1), parent)
{
	int currentLight = GL_LIGHT0 + lightCount;
	glEnable(currentLight);
	GLfloat gposition[] = {position.X, position.Y, position.Z, 1};
	GLfloat lightcol[] = {newcolor.getClampedR(), newcolor.getClampedG(), newcolor.getClampedB(), newcolor.getClampedA()};
	//GLfloat lightcol[] = {0.9, 0.9, 0.9, 0.1};
	GLfloat amb[] = {0.1,0.1,0.1,0.1};
	glLightfv(currentLight, GL_POSITION, gposition);
	glLightfv(currentLight, GL_AMBIENT, amb);
	glLightfv(currentLight, GL_DIFFUSE, lightcol);

	lightCount++;

}

CLightSceneNode::~CLightSceneNode()
{
}


void CLightSceneNode::render()
{

}
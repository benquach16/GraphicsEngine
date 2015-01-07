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
	GLfloat gposition[] = {position.X, position.Y, position.Z, 0};
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lightcol[] = {newcolor.getClampedR(), newcolor.getClampedG(), newcolor.getClampedB(), newcolor.getClampedA()};
	//GLfloat lightcol[] = {0.9, 0.9, 0.9, 0.1};
	GLfloat amb[] = {0.3,0.3,0.3,1.0};
	glLightfv(currentLight, GL_POSITION, gposition);
	glLightfv(currentLight, GL_AMBIENT, amb);
	glLightfv(currentLight, GL_DIFFUSE, lightcol);
	glLightfv(currentLight, GL_SPECULAR, mat_specular);
	glLightfv(currentLight, GL_SHININESS, mat_shininess);
	glLightf(currentLight, GL_CONSTANT_ATTENUATION, 1.5);
	glLightf(currentLight, GL_LINEAR_ATTENUATION, 0.5);
	glLightf(currentLight, GL_QUADRATIC_ATTENUATION, 0.2);
	lightCount++;

}

CLightSceneNode::~CLightSceneNode()
{
}


void CLightSceneNode::render()
{

}
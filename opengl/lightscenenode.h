#ifndef _LIGHTSCENENODE_H_
#define _LIGHTSCENENODE_H_

#pragma once

#include "scenenode.h"
#include "color.h"

enum E_LIGHT_TYPE
{
	TYPE_OMNI,
	TYPE_DIRECTIONAL
};
//VERY IMPORTANT NOTE ABOUT LIGHT NODES
//THESE LIGHTS USE THE BUILTIN OPENGL LIGHTS AND SUCK
//REAL LIGHTING REQUIRES SHADERS/DEFERRED RENDERING!!!!!
//MAKE A DYNAMICLIGHTSCENENODE FOR BETTER LIGHTING
class CLightSceneNode : public CSceneNode
{
public:
	static int lightCount;
	//default constructor
	CLightSceneNode(CSceneManager *manager = 0,
		float strength = 200.f, float radius = 100.f,
		const vector3d &position = vector3d(0,0,0),
		const vector3d &rotation = vector3d(0,0,0),
		const color& newcolor = color(255,255,255,255),
		E_LIGHT_TYPE light_type = TYPE_OMNI,
		CSceneNode *parent = 0);
	~CLightSceneNode();

	void render();
private:
	//light variables go here
	float strength;
	float radius;
	color lightColor;

	
};

#endif
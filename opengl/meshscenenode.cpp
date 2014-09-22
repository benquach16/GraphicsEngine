#include "stdafx.h"
#include "meshscenenode.h"
#pragma hdrstop

CMeshSceneNode::CMeshSceneNode(
	CMesh *mesh, CSceneManager *manager, vector3d position, vector3d rotation, vector3d scale, CSceneNode *parent) :
CSceneNode(manager, position, rotation, scale, parent)
{
}

CMeshSceneNode::CMeshSceneNode(
	CSceneManager *manager, E_MESH_PREFABS prefab, float size, vector3d position, vector3d rotation, vector3d scale, CSceneNode *parent) : 
CSceneNode(manager, position, rotation, scale, parent)
{
	mesh = new CMesh(prefab, size);
}

CMeshSceneNode::~CMeshSceneNode()
{
}

void CMeshSceneNode::render()
{
	CSceneNode::render();
	mesh->render(position, rotation, scale);
}
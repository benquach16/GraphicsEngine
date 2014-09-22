#include "stdafx.h"
#include "mesh.h"
#pragma once

CMesh::CMesh()
{
	
}

CMesh::CMesh(E_MESH_PREFABS prefab, float size)
{
	if(prefab == PREFAB_CUBE)
	{
		//construct a cube
		//vertex by vertex
		//first triangle
		
		vertices.push_back(vector3d(-0.5,-0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,-0.5,0.5) * size);
		vertices.push_back(vector3d(-0.5,0.5,0.5) * size);
		
		//second triangle
		vertices.push_back(vector3d(-0.5,0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,-0.5,0.5) * size);
		
		//back triangle
		vertices.push_back(vector3d(-0.5,-0.5,-0.5) * size);
		vertices.push_back(vector3d(0.5,-0.5,-0.5) * size);
		vertices.push_back(vector3d(-0.5,0.5,-0.5) * size);

		//back triangle
		vertices.push_back(vector3d(-0.5,0.5,-0.5) * size);
		vertices.push_back(vector3d(0.5,0.5,-0.5) * size);
		vertices.push_back(vector3d(0.5,-0.5,-0.5) * size);

		//side triangle
		vertices.push_back(vector3d(-0.5,-0.5,0.5) * size);
		vertices.push_back(vector3d(-0.5,0.5,0.5) * size);
		vertices.push_back(vector3d(-0.5,0.5,-0.5) * size);

		//side triangle
		vertices.push_back(vector3d(-0.5,-0.5,-0.5) * size);
		vertices.push_back(vector3d(-0.5,-0.5,0.5) * size);
		vertices.push_back(vector3d(-0.5,0.5,-0.5) * size);		

		//side triangle
		vertices.push_back(vector3d(0.5,-0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,0.5,-0.5) * size);

		//side triangle
		vertices.push_back(vector3d(0.5,-0.5,-0.5) * size);
		vertices.push_back(vector3d(0.5,-0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,0.5,-0.5) * size);		

		//top triangle 
		vertices.push_back(vector3d(-0.5,-0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,-0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,-0.5,-0.5) * size);		

		//top triangle 
		vertices.push_back(vector3d(-0.5,-0.5,-0.5) * size);
		vertices.push_back(vector3d(0.5,-0.5,-0.5) * size);
		vertices.push_back(vector3d(-0.5,-0.5,0.5) * size);		

		//bottom triangle 
		vertices.push_back(vector3d(-0.5,0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,0.5,-0.5) * size);		

		//bottom triangle 
		vertices.push_back(vector3d(-0.5,0.5,-0.5) * size);
		vertices.push_back(vector3d(0.5,0.5,-0.5) * size);
		vertices.push_back(vector3d(-0.5,0.5,0.5) * size);		

	}
	else if(prefab == PREFAB_SPHERE)
	{
		//uhhh
		//making a sphere with code is incredibly anonying
	}
}

CMesh::~CMesh()
{
}

void CMesh::render(vector3d position, vector3d rotation, vector3d scale)
{
	//make sure to set everything in the matrix to be multiplied by view transformation


	//rotate around the camera position and rotation first?



	//need to transform by rotation scale and position
	quaternion rot = rotation.convertToQuaternion();

	//hopefully we can just do one matrix multiplication
	glScalef(scale.X,scale.Y,scale.Z);
	glRotatef(rot.W,rot.X,rot.Y,rot.Z);
	glTranslatef(position.X, position.Y, position.Z);



	glBegin(GL_TRIANGLES);

	
	for(unsigned i = 0; i < vertices.size(); i++)
	{
		//this function only works if lighting is disabled
		glColor3f(1.0f,1.0f,1.0f);
		
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(vertices[i].X,
			vertices[i].Y,
			vertices[i].Z);
	}
	glEnd();
}
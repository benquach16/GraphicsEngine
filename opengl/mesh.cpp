#include "stdafx.h"
#include "mesh.h"
#include <iostream>
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

		faces.push_back(Face(0,1,2));
		
		//second triangle
		vertices.push_back(vector3d(-0.5,0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,-0.5,0.5) * size);
		faces.push_back(Face(3,4,5));
		
		//back triangle
		vertices.push_back(vector3d(-0.5,-0.5,-0.5) * size);
		vertices.push_back(vector3d(0.5,-0.5,-0.5) * size);
		vertices.push_back(vector3d(-0.5,0.5,-0.5) * size);
		faces.push_back(Face(6,7,8));

		//back triangle
		vertices.push_back(vector3d(-0.5,0.5,-0.5) * size);
		vertices.push_back(vector3d(0.5,0.5,-0.5) * size);
		vertices.push_back(vector3d(0.5,-0.5,-0.5) * size);
		faces.push_back(Face(9,10,11));
						
		//side triangle
		vertices.push_back(vector3d(-0.5,-0.5,0.5) * size);
		vertices.push_back(vector3d(-0.5,0.5,0.5) * size);
		vertices.push_back(vector3d(-0.5,0.5,-0.5) * size);
		faces.push_back(Face(12,13,14));

		//side triangle
		vertices.push_back(vector3d(-0.5,-0.5,-0.5) * size);
		vertices.push_back(vector3d(-0.5,-0.5,0.5) * size);
		vertices.push_back(vector3d(-0.5,0.5,-0.5) * size);
		faces.push_back(Face(15,16,17));

		//side triangle
		vertices.push_back(vector3d(0.5,-0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,0.5,-0.5) * size);
		faces.push_back(Face(18,19,20));
		
		//side triangle
		vertices.push_back(vector3d(0.5,-0.5,-0.5) * size);
		vertices.push_back(vector3d(0.5,-0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,0.5,-0.5) * size);
		faces.push_back(Face(21,22,23));

		//top triangle 
		vertices.push_back(vector3d(-0.5,-0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,-0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,-0.5,-0.5) * size);		
		faces.push_back(Face(24,25,26));

		//top triangle 
		vertices.push_back(vector3d(-0.5,-0.5,-0.5) * size);
		vertices.push_back(vector3d(0.5,-0.5,-0.5) * size);
		vertices.push_back(vector3d(-0.5,-0.5,0.5) * size);
		faces.push_back(Face(27,28,29));

		//bottom triangle 
		vertices.push_back(vector3d(-0.5,0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,0.5,0.5) * size);
		vertices.push_back(vector3d(0.5,0.5,-0.5) * size);
		faces.push_back(Face(30,31,32));

		//bottom triangle 
		vertices.push_back(vector3d(-0.5,0.5,-0.5) * size);
		vertices.push_back(vector3d(0.5,0.5,-0.5) * size);
		vertices.push_back(vector3d(-0.5,0.5,0.5) * size);
		faces.push_back(Face(33,34,35));

	}
	else if(prefab == PREFAB_SPHERE)
	{
		//uhhh
		//making a sphere with code is incredibly anonying
	}
}

CMesh::CMesh(const std::vector<vector3d> vertices, const std::vector<Face> faces)
	: vertices(vertices), faces(faces)
{

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

	/*
	for(unsigned i = 0; i < vertices.size(); i++)
	{
		//this function only works if lighting is disabled
		glColor3f(1.0f,1.0f,1.0f);
		
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(vertices[i].X,
			vertices[i].Y,
			vertices[i].Z);
	}
	*/
	std::cerr << vertices.size() << std::endl;
	std::cerr << faces.size() << std::endl;

	for(unsigned i = 0; i < faces.size(); i++)
	{
		//std::cerr << i << " " << faces.size() << std::endl;
		//assuming that our normals are right
		//and assuming that we have 3 verts per face
		glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		Face &f = faces[i];
		glVertex3f(vertices[f.vertexIndices[0]].X,
			vertices[f.vertexIndices[0]].Y,
			vertices[f.vertexIndices[0]].Z);

		glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(vertices[f.vertexIndices[1]].X,
			vertices[f.vertexIndices[1]].Y,
			vertices[f.vertexIndices[1]].Z);

		glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(vertices[f.vertexIndices[2]].X,
			vertices[f.vertexIndices[2]].Y,
			vertices[f.vertexIndices[2]].Z);
	}
	glEnd();
}

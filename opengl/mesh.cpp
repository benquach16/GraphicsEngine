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
#include "mesh.h"

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
		vertices.push_back(vector3d(-0.5,-0.5,-0.5) * size);
		vertices.push_back(vector3d(0.5,-0.5,-0.5) * size);
		vertices.push_back(vector3d(-0.5,0.5,-0.5) * size);

		//side triangle
		vertices.push_back(vector3d(-0.5,0.5,-0.5) * size);
		vertices.push_back(vector3d(0.5,0.5,-0.5) * size);
		vertices.push_back(vector3d(0.5,-0.5,-0.5) * size);
		

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

	glMatrixMode(GL_MODELVIEW);
	//rotate around the camera position and rotation first?


	glPushMatrix();

	//need to transform by rotation scale and position
	quaternion rot = rotation.convertToQuaternion();

	//hopefully we can just do one matrix multiplication
	glTranslatef(position.X, position.Y, position.Z);
	glRotatef(rot.W,rot.X,rot.Y,rot.Z);
	glScalef(scale.X,scale.Y,scale.Z);


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
	glPopMatrix();
}
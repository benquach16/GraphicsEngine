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

#ifndef _MESH_H_
#define _MESH_H_

#pragma once

#include "gl/gl.h"
#include "gl/glu.h"
#include "vector3d.h"
#include "vector2d.h"
#include "color.h"
#include "vector"
#include "quaternion.h"
#include "face.h"


using namespace std;

enum E_MESH_PREFABS
{
	PREFAB_CUBE,
	PREFAB_SPHERE
};

class CMesh
{
public:
	//default constructor
	CMesh();
	//pointer to an array
	CMesh(const vector<Face> &f);
	//for creating boxes manually
	CMesh(E_MESH_PREFABS prefab, float size);
	CMesh(std::vector<float> vertices);
	~CMesh();
	void render(vector3d position, vector3d rotation, vector3d scale);

private:
	std::vector<vector3d> vertices;
	std::vector<Face> faces;
	std::vector<color> colors;

	bool lighting;
};

#endif

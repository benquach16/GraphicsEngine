#include "stdafx.h"
#include "face.h"

Face::Face()
{
}


Face::Face(const vector3d &v1, const vector3d &v2, const vector3d &v3)
{
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);
}

Face::~Face()
{
}



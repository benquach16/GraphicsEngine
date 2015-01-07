#include "stdafx.h"
#include "face.h"

Face::Face()
{
}


Face::Face(int v1, int v2, int v3)
{
	vertexIndices.push_back(v1);
	vertexIndices.push_back(v2);
	vertexIndices.push_back(v3);
}

Face::~Face()
{
}



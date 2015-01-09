#ifndef __VERTEX_H__
#define __VERTEX_H__

#include "vector3d.h"

class Vertex
{
public:
	Vertex();
	Vertex(const vector3d &vertex);
	Vertex(const vector3d &vertex, const vector3d &normal);
	float X();
	float Y();
	float Z();
	vector3d vertex;
	vector3d normal;
};

#endif


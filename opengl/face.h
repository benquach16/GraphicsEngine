#ifndef __FACE_H__
#define __FACE_H__

#include <vector.h>
#include "vector3d.h"

class Face
{
public:
	Face();
	Face(const vector3d &v1, const vector3d &v2, const vector3d &v3);
	~Face();
	std::vector<vector3d> vertices;
};

#endif

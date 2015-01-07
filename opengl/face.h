#ifndef __FACE_H__
#define __FACE_H__

#include <vector>
#include "vector3d.h"


//faces should probably share verts
//so pass pointers
class Face
{
public:
	Face();
	Face(int v1, int v2, int v3);
	~Face();
	std::vector<int> vertexIndices;
};

#endif

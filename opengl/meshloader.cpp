#include "stdafx.h"
#include "meshloader.h"


CMeshLoader::CMeshLoader()
{
}

CMesh *CMeshLoader::loadOBJ(const char *file)
{
	std::ifstream fin(file,ios::in);
	if(!fin)
		return 0;
	

	vector<vector3d> vertex_indices;
	vector<vector3d> vertex_normals;
	vector<vector3d> vertex_texture;
	

	string line;
	while(getline(fin, line))
	{
		if(line.substr(0,2) == "v ")
		{
			//vertex information
			istringstream s(line.substr(2));
			vector3d v;
			s >> v.X;
			s >> v.Y;
			s >> v.Z;
			vertex_indices.push_back(v);
		}
		else if(line.substr(0,2) == "f ")
		{
			//face definition
		}
		else if(line.substr(0,2) == "vn")
		{
			//vertex normals
			//important for smoothing
			
		}
		else if(line.substr(0,2) == "vt")
		{
			//tex coords
		}
		else if(line[0] == '#')
		{
			//.obj comment
			//so we ignore it
		}
	}
}

#include "stdafx.h"
#include "meshloader.h"


CMeshLoader::CMeshLoader()
{
}

CMeshLoader::~CMeshLoader()
{
}

CMesh *CMeshLoader::loadOBJ(const char *file) const
{
	std::ifstream fin(file,ios::in);
	if(!fin)
		return 0;
	std::cerr << "loading obj file" << std::endl;

	vector<vector3d> vertex_indices;
	vector<vector3d> vertex_normals;
	vector<vector3d> vertex_texture;
	vector<Face> faces;

	string line;
	while(getline(fin, line))
	{
		if(line[0] == 'v' && line[1] == ' ')
		{
			//vertex information
			istringstream s(line.substr(2));
			vector3d v;
			s >> v.X;
			s >> v.Y;
			s >> v.Z;
			vertex_indices.push_back(v);
			std::cerr << v.X << " " << v.Y << " " << v.Z << std::endl;
		}
		else if (line[0] == 'f' && line[1] == ' ')
		{
			//face definition
			int v1;
			int v2;
			int v3;
			istringstream s(line.substr(2));
			s >> v1;
			s >> v2;
			s >> v3;
			//change to base 0
			v1 -= 1;
			v2 -= 1;
			v3 -= 1;
			faces.push_back(Face(v1,v2,v3));
			std::cerr << v1 << " " << v2 << " " << v3 << std::endl;
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
	std::cerr << "finished loading" << std::endl;
	CMesh *ret = new CMesh(vertex_indices, faces);
	return ret;
}

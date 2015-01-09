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
	vector<vector2d> vertex_texture;
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
			string v1;
			string v2;
			string v3;
			int v1i;
			int v2i;
			int v3i;
			istringstream s(line.substr(2));
			s >> v1;
			s >> v2;
			s >> v3;
			//find the /
			//std::cerr << v1 << std::endl;
			if (v1.find('/') != string::npos)
			{
				//has two /s
				int pos1 = v1.find('/');
				int pos2 = v1.find('/');
				string vIndex = v1.substr(0, pos1);
				string vtIndex = v1.substr(pos1, pos2);
				string vnIndex = v1.substr(pos2);
				v1i = std::stoi(vIndex);
				int vt = std::stoi(vtIndex);
				int vn = std::stoi(vnIndex);
			}
			else
				v1i = std::stoi(v1);
			if (v2.find('/') != string::npos)
			{
				//has two /s
				int pos1 = v2.find('/');
				int pos2 = v2.find('/');
				string vIndex = v2.substr(0, pos1);
				string vtIndex = v2.substr(pos1, pos2);
				string vnIndex = v2.substr(pos2);
				v2i = std::stoi(vIndex);
				int vt = std::stoi(vtIndex);
				int vn = std::stoi(vnIndex);
			}
			else
				v2i = std::stoi(v2);
			if (v3.find('/') != string::npos)
			{

				//has two /s
				int pos1 = v3.find('/');
				int pos2 = v3.find('/');
				string vIndex = v3.substr(0, pos1);
				string vtIndex = v3.substr(pos1, pos2);
				string vnIndex = v3.substr(pos2);
				v3i = std::stoi(vIndex);
				int vt = std::stoi(vtIndex);
				int vn = std::stoi(vnIndex);
			}
			else
				v3i = std::stoi(v3);
			//change to base 0
			v1i -= 1;
			v2i -= 1;
			v3i -= 1;
			faces.push_back(Face(v1i,v2i,v3i));
			std::cerr << v1 << " " << v2 << " " << v3 << std::endl;
		}
		else if(line.substr(0,2) == "vn")
		{
			//vertex normals
			//important for smoothing
			vector3d v;
			istringstream s(line.substr(0, 2));

		}
		else if(line.substr(0,2) == "vt")
		{
			//tex coords
			vector3d v;
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

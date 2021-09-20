#pragma once
#include <string>

#include "Mesh.h"
#include "Material.h"

struct MeshData
{
	MeshData()
		: MeshData(0, "", nullptr)
	{}
	MeshData(const int ID, const std::string& name, Mesh* pMesh)
		: ID(ID)
		, name(name)
		, pMesh(pMesh)
	{}
	~MeshData()
	{ DELETE_POINTER(pMesh); }

	int ID{};
	std::string name{};
	Mesh* pMesh{};
};
struct MaterialData
{
	MaterialData()
		: MaterialData(0, "", nullptr)
	{}
	MaterialData(const int ID, const std::string& name, Material* pMaterial)
		: ID(ID)
		, name(name)
		, pMaterial(pMaterial)
	{}
	~MaterialData()
	{ DELETE_POINTER(pMaterial); }

	int ID{};
	std::string name{};
	Material* pMaterial{};
};
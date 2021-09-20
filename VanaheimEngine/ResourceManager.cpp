#include "pch.h"
#include "ResourceManager.h"

#include "Mesh.h"
#include "Material.h"

#include "Graphics.h"

#include <algorithm>

ResourceManager::ResourceManager()
				: m_p3DMeshes(std::vector<MeshData*>())
				, m_p3DMaterials(std::vector<MaterialData*>())
				, m_MeshFreeId()
				, m_MaterialFreeId()
{}
ResourceManager::~ResourceManager()
{
	for (MeshData* pMeshData : m_p3DMeshes)
		DELETE_POINTER(pMeshData);
	for (MaterialData* pMaterialData : m_p3DMaterials)
		DELETE_POINTER(pMaterialData);

	m_p3DMeshes.clear();
	m_p3DMaterials.clear();
}

void ResourceManager::Initialize()
{}

Mesh* ResourceManager::Get3DMesh(const std::string& name)
{
	auto result{ std::find_if(m_p3DMeshes.begin(), m_p3DMeshes.end(), [&](MeshData* pMeshData)
	{ return pMeshData->name == name; }) };
	
	// If the mesh is found return it
	if (result != m_p3DMeshes.end())
		return (*result)->pMesh;
	return nullptr;
}

Mesh* ResourceManager::Load3DMesh(const std::string& name, const std::string& path)
{
	int meshID{};
	// Check if the Mesh exists already and return the id if it does
	if (MeshAlreadyParsed(name, meshID))
	{
		Mesh* pMesh{ m_p3DMeshes[meshID]->pMesh };

		// Check if the instance counter is on 0 if so set to 1 to start
		if (pMesh->GetAmountInstances() <= 0)
			pMesh->IncrementInstanceCount();

		pMesh->IncrementInstanceCount();
		return pMesh;
	}

	// If it does not exist
	Mesh* pMesh{ new Mesh(path) };
	pMesh->Initialize();

	// Store the mesh
	MeshData* pMeshData{ new MeshData() };
	pMeshData->ID = GetFreeMeshID();
	pMeshData->name = name;
	pMeshData->pMesh = pMesh;
	m_p3DMeshes.push_back(pMeshData);

	// Return the pointer to the mesh
	return pMesh;
}

void ResourceManager::Store3DMesh(Mesh* pMesh, const std::string& name)
{
	// Store the mesh
	MeshData* pMeshData{ new MeshData() };
	pMeshData->ID = GetFreeMeshID();
	pMeshData->name = name;
	pMeshData->pMesh = pMesh;
	m_p3DMeshes.push_back(pMeshData);
}

void ResourceManager::ResetInstancedMeshes()
{
	for (MeshData* pMeshData : m_p3DMeshes)
		pMeshData->pMesh->SetIsRendered(false);
}

bool ResourceManager::MeshAlreadyParsed(const std::string& newName, int& meshID)
{
	// Check if the map for 3D meshes is empty
	if (m_p3DMeshes.empty())
		return false;

	// Check if you find the name in the map
	auto result{ std::find_if(m_p3DMeshes.begin(), m_p3DMeshes.end(), [&](MeshData* pMeshData)
	{
		if (pMeshData->name == newName)
		{
			meshID = pMeshData->ID;
			return true;
		}
		return false;
	}) };

	// Did you find the mesh already of not
	if (result != m_p3DMeshes.end())
		return true;
	return false;
}
bool ResourceManager::MaterialAlreadyLoaded(const Material* /*material_in*/, int& /*materialID*/)
{
	//// Check if the map for materials is empty
	//if (m_p3DMaterials.empty())
	//	return false;

	//// Check if you find the name in the map
	//auto result{ std::find_if(m_p3DMaterials.begin(), m_p3DMaterials.end(), [&](MaterialData* pMaterialData)
	//{
	//	if (pMaterialData->name == material_in->GetName())
	//	{
	//		materialID = pMaterialData->ID;
	//		return true;
	//	}
	//	return false;
	//}) };
	//	
	//// Did you find the material already of not
	//if (result != m_p3DMaterials.end())
	//	return true;
	return false;
}
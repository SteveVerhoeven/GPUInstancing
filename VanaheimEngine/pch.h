#pragma once

#pragma region Includes
// ----------------------------
// External includes
// ----------------------------
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

// ----------------------------
// DirectX includes
// ----------------------------
#include <dxgi.h>
#pragma comment(lib, "dxgi.lib")

#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")
#include <d3dcompiler.h>
#pragma comment(lib, "d3dcompiler.lib")

//**EFFECTS11 (Helper for loading Effects (D3DX11))
//https://fx11.codeplex.com/
#include "d3dx11effect.h" //[AdditionalLibraries/DX_Effects11/include/d3dx11effect.h]
//#if defined(DEBUG) || defined(_DEBUG)
//#pragma comment(lib, "DxEffects11_vc14_Debug.lib")
//#else 
//#pragma comment(lib, "DxEffects11_vc14_Release.lib")
//#endif

#include <DirectXMath.h>
#include <DirectXColors.h>
#include <DirectXPackedVector.h>
#include <DirectXCollision.h>

// ----------------------------
// Vanaheim includes
// ----------------------------
#include "Locator.h"
#include "DebugLogger.h"

#include "CameraComponent.h"
#include "ModelComponent.h"
#include "RenderComponent.h"
#include "TransformComponent.h"
#pragma endregion

#pragma region Memory Leaks
//// When debugging changes all calls to "new" to be calls to "DEBUG_NEW" allowing for memory leaks to
//// give you the file name and line number where it occurred.
//// Reference: https://rhyous.wordpress.com/2009/10/13/how-to-find-the-file-and-line-number-of-memory-leaks-using-c-with-wxwidgets-in-visual-studio-2008/
//#ifdef _DEBUG
//#include <crtdbg.h>
//#define DEBUG_NEW new(_NORMAL_BLOCK ,__FILE__, __LINE__)
//#define new DEBUG_NEW
//#else
//#define DEBUG_NEW new
//#endif
#pragma endregion

#pragma region Macro
/* ***************** */
/* DELETING POINTERS */
/* ***************** */
#define DELETE_POINTER( x ) \
if (x != NULL)			   \
{						   \
    delete x;			   \
    x = nullptr;		   \
}
#define DELETE_POINTERS( x, size ) 	\
for (size_t i{}; i < size; ++i)		\
{									\
	DELETE_POINTER(x[i]);			\
}									\
x.clear();
/* ****************** */
/* DELETING RESOURCES */
/* ****************** */
#define DELETE_RESOURCE_VALID( x ) \
if (x->IsValid())           \
{                           \
    x->Release();           \
    x = nullptr;            \
}                           
#define DELETE_RESOURCE( x ) \
if (x)                      \
{                           \
    x->Release();           \
    x = nullptr;            \
}
#pragma endregion

#pragma region General structs
struct Vertex_Base
{
	DirectX::XMFLOAT3 Color{};
	DirectX::XMFLOAT2 UV{};
	DirectX::XMFLOAT3 Normal{};
	DirectX::XMFLOAT3 Tangent{};
	DirectX::XMFLOAT3 WorldPosition{};
};
struct Vertex_Input /*: Vertex_Base*/
{
	DirectX::XMFLOAT3 Position{};
	DirectX::XMFLOAT3 Color{};
	//DirectX::XMFLOAT3 InstancePosition{};
	//DirectX::XMFLOAT2 UV{};
	//DirectX::XMFLOAT3 Normal{};
	//DirectX::XMFLOAT3 Tangent{};
	//DirectX::XMFLOAT3 WorldPosition{};

	bool operator==(const Vertex_Input& v)
	{
		if (v.Position.x == Position.x && 
			v.Position.y == Position.y && 
			v.Position.z == Position.z)
			/*if (v.Normal.x == Normal.x && 
				v.Normal.y == Normal.y && 
				v.Normal.z == Normal.z)
				if (v.UV.x == UV.x &&
					v.UV.y == UV.y)*/
					return true;

		return false;
	}
};
struct Vertex_Output /*: Vertex_Base*/
{
	DirectX::XMFLOAT4 Position{};
	DirectX::XMFLOAT3 Color{};
	DirectX::XMFLOAT2 UV{};
	DirectX::XMFLOAT3 Normal{};
	DirectX::XMFLOAT3 Tangent{};
	DirectX::XMFLOAT3 WorldPosition{};

	bool operator==(const Vertex_Output& v)
	{
		if (v.Position.x == Position.x &&
			v.Position.y == Position.y &&
			v.Position.z == Position.z &&
			v.Position.w == Position.w)
			if (v.Normal.x == Normal.x &&
				v.Normal.y == Normal.y &&
				v.Normal.z == Normal.z)
				if (v.UV.x == UV.x &&
					v.UV.y == UV.y)
					return true;

		return false;
	}
};
#pragma endregion
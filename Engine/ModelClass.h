#pragma once

#include <d3d11.h>
#include <DirectXMath.h>
using namespace DirectX;

#include <fstream>
#include "float3.h"

class ModelClass
{
public:
	ModelClass();
	~ModelClass();
	bool Initialize(ID3D11Device*, char*);
	void ShutDown();
	void Render(ID3D11DeviceContext*);

	int GetIndexCount();

private:
	struct VertexType
	{
		XMFLOAT3  position;
		XMFLOAT2  texture;
		XMFLOAT3  normal;
	};

	struct ModelType
	{
		float x, y, z;
		float tu, tv;
		float nx, ny, nz;
	};

	struct FaceType 
	{
		int vIndex1, vIndex2, vIndex3;
		int tIndex1, tIndex2, tIndex3;
		int nIndex1, nIndex2, nIndex3;
	};

	bool LoadModel(char*);
	void ReleaseModel();

	bool LoadObjModel(char*);
	bool ReadCounts(char* filename, int& vertexCount, int& textureCount, int& normalCount, int& faceCount);

	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
	ModelType* m_model;
};


#pragma once

#include <d3d11.h>
#include <DirectXMath.h>
using namespace DirectX;

#include <fstream>
#include "float3.h"
enum class HitBoxType{
	Sphere,
	Cube,
	Rectangle,
	Point,
};

class ModelClass
{
public:
	ModelClass();
	~ModelClass();
	bool Initialize(ID3D11Device*, char*,HitBoxType hitboxType, float3 hitboxSize);
	void ShutDown();
	void Render(ID3D11DeviceContext*);

	int GetIndexCount();

	//HitBox Handerling
	//Seting up a Cube or Sphere Hitbox
	bool SetHitbox(float radius);
	//Seting up a Rectangle HitBox
	bool SetHitbox(float sizeX, float sizeY, float sizeZ);
	void SetHitboxType(HitBoxType hitbox);
	float3 GetHitbox();
	HitBoxType GetHitBoxType();
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

	bool LoadModel(char*);
	void ReleaseModel();

	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
	ModelType* m_model;
	//HitBox
	float3 m_HitBoxSize;
	HitBoxType m_hitboxType;
	bool InitalizeHitbox(HitBoxType hitboxType, float3 hitboxSize);
};


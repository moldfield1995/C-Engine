#pragma once
#include "float3.h"
enum class SpawnState {
	position,
	rotation,
	scale,
	model,
	texture,
	shader,
	bumpMap,
};
class GameObject
{
public:
	GameObject();
	~GameObject();
	void Initalize(int model, int texute, float3 position, float3 rotation);
	void SetPosition(float3 pos);
	void SetRotation(float3 rot);
	void SetScale(float3 scale);
	float3 GetPosition();
	float3 GetRotation();
	float3 GetScale();
	void SetOrigin(float posX, float posY, float posZ, float rotX, float rotY, float radius);
	//Model and Texture Handlering
	void SetModel(int id);
	void SetTexture(int id);
	int GetModel();
	int GetTexture();
	int GetShader();
	void SetShader(int shader);
	int GetBump();
	void SetBump(int bump);
private:
	int m_modelIndex;
	int m_textureIndex, m_bumpIndex;
	float3 m_position, m_rotation, m_scale;
	int m_shader;
};


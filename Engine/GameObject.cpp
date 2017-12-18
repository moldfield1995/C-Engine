#include "GameObject.h"
#include <math.h>


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::Initalize(int model, int texute, float3 position, float3 rotation)
{
	m_modelIndex = model;
	m_textureIndex = texute;
	m_position = position;
	m_rotation = rotation;
	m_scale = float3(1.0f, 1.0f, 1.0f);
	m_shader = 0;
	m_bumpIndex = 0;
}

void GameObject::SetPosition(float3 pos) { m_position = pos; }

void GameObject::SetRotation(float3 rot) { m_rotation = rot; }

void GameObject::SetScale(float3 scale) { m_scale = scale; }

float3 GameObject::GetPosition() { return m_position; }

float3 GameObject::GetRotation() { return m_rotation; }

float3 GameObject::GetScale() { return m_scale; }

void GameObject::SetOrigin(float posX, float posY, float posZ, float rotX, float rotY, float radius)
{
	m_position.X( posX + radius*cosf(rotX*0.0174532925f)*sinf(rotY*0.0174532925f));
	m_position.Y(posY);
	m_position.Z(posZ + radius*cosf(rotY*0.0174532925f));
}

void GameObject::SetModel(int id) { m_modelIndex = id; }

void GameObject::SetTexture(int id) { m_textureIndex = id; }

int GameObject::GetModel(){ return m_modelIndex; }

int GameObject::GetTexture(){ return m_textureIndex; }

int GameObject::GetShader()
{
	return m_shader;
}

void GameObject::SetShader(int shader)
{
	m_shader = shader;
}

int GameObject::GetBump()
{
	return m_bumpIndex;
}

void GameObject::SetBump(int bump)
{
	m_bumpIndex = bump;
}


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

void GameObject::Initalize(float3 position, float3 rotation, ModelClass * model, ID3D11ShaderResourceView* textures, Shader * shader)
{
	m_position = position;
	m_rotation = rotation;
	m_textures = textures;
	m_shader = shader;
	m_model = model;
	if (!model)
		return;
	m_hitBox = model->GetHitbox();
	m_hitboxType = model->GetHitBoxType();
}

void GameObject::SetPosition(float3 pos) { m_position = pos; }

void GameObject::SetRotation(float3 rot) { m_rotation = rot; }

void GameObject::SetScale(float3 scale) { m_scale = scale; }

float3 GameObject::GetPosition() { return m_position; }

float3 GameObject::GetRotation() { return m_rotation; }

float3 GameObject::GetScale() { return m_scale; }

void GameObject::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass& camera)
{
	if (m_model == nullptr)
		return;
	XMMATRIX renderMatrix,transformMatrix,rotationMatrix,scaleMatrix;
	transformMatrix = XMMatrixTranslation(m_position.X(), m_position.Y(), m_position.Z());
	scaleMatrix = XMMatrixScaling(m_scale.X(), m_scale.Y(), m_scale.Z());
	rotationMatrix = XMMatrixRotationRollPitchYaw(m_rotation.X(), m_rotation.Y(), m_rotation.Z());
	renderMatrix = XMMatrixMultiply(worldMatrix, transformMatrix);
	renderMatrix = XMMatrixMultiply(rotationMatrix, renderMatrix);
	renderMatrix = XMMatrixMultiply(scaleMatrix, renderMatrix);
	m_model->Render(deviceContext);
	m_shader->Render(deviceContext, m_model->GetIndexCount(), renderMatrix, viewMatrix, projectionMatrix, m_textures, light);
}



float3 GameObject::GetHitbox()
{
	return m_hitBox;
}

HitBoxType GameObject::GetHitboxType()
{
	return m_hitboxType;
}

void GameObject::SetOrigin(float posX, float posY, float posZ, float rotX, float rotY, float radius)
{
	m_position.X( posX + radius*cosf(rotX*0.0174532925f)*sinf(rotY*0.0174532925f));
	m_position.Y(posY);
	m_position.Z(posZ + radius*cosf(rotY*0.0174532925f));
}



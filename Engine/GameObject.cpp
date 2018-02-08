#include "GameObject.h"
#include <math.h>


GameObject::GameObject()
{
	m_model = 0;
	//ID3D11ShaderResourceView* m_textures;
	m_textures = new std::vector<ID3D11ShaderResourceView*>();
	m_shader=0;
	m_hitboxType = HitBoxType::Point;
	m_KillGameObject = false;

	m_Componets = std::vector<Component*>();
}

GameObject::GameObject(GameObject * go)
{
	m_position = go->m_position;
	m_rotation = go->m_rotation;
	m_scale = go->m_scale;
	m_model = go->m_model;
	m_shader = go->m_shader;
	m_Renders = m_model != nullptr;
	m_Componets = std::vector<Component*>();
	m_textures = new std::vector<ID3D11ShaderResourceView*>();
	for each (ID3D11ShaderResourceView* texture in *go->m_textures)
	{
		m_textures->push_back(texture);
	}
}


GameObject::~GameObject()
{
}


void GameObject::Initalize(float3 position, float3 rotation, ModelClass * model, ID3D11ShaderResourceView* textures, Shader * shader)
{
	m_position = position;
	m_rotation = rotation;
	m_scale = float3(1.0f, 1.0f, 1.0f);
	m_textures->push_back(textures);
	m_shader = shader;
	m_model = model;
	if (!model)
		return;
	m_Renders = true;
	m_hitbox = model->GetHitbox();
	m_hitboxType = model->GetHitBoxType();
}

void GameObject::SetPosition(float3 pos) { m_position = pos; }

void GameObject::SetRotation(float3 rot) { m_rotation = rot; }

void GameObject::SetScale(float3 scale) { m_scale = scale; }

float3 GameObject::GetPosition() { return m_position; }

float3 GameObject::GetRotation() { return m_rotation; }

float3 GameObject::GetScale() { return m_scale; }

void GameObject::Update()
{
	for each (Component* componet in m_Componets)
	{
		componet->Update();
	}
}

void GameObject::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass& camera)
{
	for each (Component* componet in m_Componets)
	{
		componet->Render(deviceContext,worldMatrix,viewMatrix,projectionMatrix,frustume,light,camera);
	}
	if (m_model == nullptr || !m_Renders)
		return;
	//ToDo check frostume
	XMMATRIX renderMatrix,transformMatrix,rotationMatrix,scaleMatrix;
	transformMatrix = XMMatrixTranslation(m_position.X, m_position.Y, m_position.Z);
	scaleMatrix = XMMatrixScaling(m_scale.X, m_scale.Y, m_scale.Z);
	rotationMatrix = XMMatrixRotationRollPitchYaw(m_rotation.X, m_rotation.Y, m_rotation.Z);
	renderMatrix = XMMatrixMultiply(worldMatrix, transformMatrix);
	renderMatrix = XMMatrixMultiply(rotationMatrix, renderMatrix);
	renderMatrix = XMMatrixMultiply(scaleMatrix, renderMatrix);
	m_model->Render(deviceContext);
	m_shader->Render(deviceContext, m_model->GetIndexCount(), renderMatrix, viewMatrix, projectionMatrix, m_textures, light);
}

void GameObject::AddComponet(Component * component)
{
	component->owner = this;
	component->Initalize();
	m_Componets.push_back(component);
}

bool GameObject::CheckColltion(GameObject * other)
{


	return false;
	/*
	gHitbox = m_GameObjects[i]->GetHitbox();
	hitboxType = m_GameObjects[i]->GetHitboxType();
	gPossition = m_GameObjects[i]->GetPosition();
	gScale = m_GameObjects[i]->GetScale();
	gHitbox.X(gHitbox.X() * gScale.X());
	gHitbox.Y(gHitbox.Y() * gScale.Y());
	gHitbox.Z(gHitbox.Z() * gScale.Z());
	switch (hitboxType)
	{
	case HitBoxType::Sphere:
		result;
		break;
	case HitBoxType::Cube:
		result;
		break;
	case HitBoxType::Rectangle:
		result = (pPosition.X() - pHitbox.X() <= gPossition.X() + gHitbox.X() && pPosition.X() + pHitbox.X() >= gPossition.X() - gHitbox.X())
			&& (pPosition.Y() - pHitbox.Y() <= gPossition.Y() + gHitbox.Y() && pPosition.Y() + pHitbox.Y() >= gPossition.Y() - gHitbox.Y())
			&& (pPosition.Z() - pHitbox.Z() <= gPossition.Z() + gHitbox.Z() && pPosition.Z() + pHitbox.Z() >= gPossition.Z() - gHitbox.Z());
		break;
	case HitBoxType::Point:
		result = false;
		break;
	default:
		result = false;
		break;
		*/
}



bool GameObject::SetHitbox(float radius)
{
	if (m_hitboxType == HitBoxType::Point || m_hitboxType == HitBoxType::Rectangle)
		return false;
	m_hitbox.X =(radius);
	return true;
}

bool GameObject::SetHitbox(float sizeX, float sizeY, float sizeZ)
{
	if (m_hitboxType != HitBoxType::Rectangle)
		return false;
	m_hitbox = float3(sizeX, sizeY, sizeZ);
	return true;
}

void GameObject::SetHitboxType(HitBoxType hitbox)
{
	m_hitboxType = hitbox;
}

float3 GameObject::GetHitbox()
{
	return m_hitbox;
}

float3 GameObject::GetHitboxScaled()
{
	return float3();
}

HitBoxType GameObject::GetHitboxType()
{
	return m_hitboxType;
}

void GameObject::SetOrigin(float posX, float posY, float posZ, float rotX, float rotY, float radius)
{
	m_position.X =(posX + radius*cosf(rotX*0.0174532925f)*sinf(rotY*0.0174532925f));
	m_position.Y =(posY);
	m_position.Z =(posZ + radius*cosf(rotY*0.0174532925f));
}

void GameObject::Destroy()
{
	for (int i = m_Componets.size(); 0 < i; i--)
	{
		if (m_Componets[i] != nullptr)
			m_Componets[i]->Destroy();
		delete(m_Componets[i]);
		m_Componets.pop_back();
	}
}

bool GameObject::IsAlive() { return !m_KillGameObject; }


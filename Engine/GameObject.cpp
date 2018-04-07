#include "GameObject.h"
#include <math.h>
#include "../TrueAxis/Physics/Physics.h"

GameObject::GameObject()
{
	m_model = 0;
	//ID3D11ShaderResourceView* m_textures;
	m_textures = new std::vector<ID3D11ShaderResourceView*>();
	m_shader=0;
	//m_hitboxType = HitBoxType::point;
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
	m_Renders = go->m_Renders;
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
	//m_hitbox = float3();
	//m_hitboxType = HitBoxType::point;
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
		if(componet->renders)
			componet->Render(deviceContext,worldMatrix,viewMatrix,projectionMatrix,frustume,light,camera);
	}
	if (m_model == nullptr || !m_Renders)
		return;
	//ToDo check frostume
	XMMATRIX renderMatrix,transformMatrix,rotationMatrix,scaleMatrix;
	transformMatrix = XMMatrixTranslation(m_position.X, m_position.Y, m_position.Z);
	scaleMatrix = XMMatrixScaling(m_scale.X, m_scale.Y, m_scale.Z);
	float3 rotationInRadens = m_rotation * 0.0174532925f;
	rotationMatrix = XMMatrixRotationRollPitchYaw(rotationInRadens.X, rotationInRadens.Y, rotationInRadens.Z);
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

void GameObject::AddTexture(ID3D11ShaderResourceView * texture, int index)
{
	if (index == -1)
	{
		m_textures->push_back(texture);
		return;
	}
	(*m_textures)[index] = texture;
}

//bool GameObject::CheckColltion(GameObject * other)
//{
//
//	return false;
//	/*
//	gHitbox = m_GameObjects[i]->GetHitbox();
//	hitboxType = m_GameObjects[i]->GetHitboxType();
//	gPossition = m_GameObjects[i]->GetPosition();
//	gScale = m_GameObjects[i]->GetScale();
//	gHitbox.X(gHitbox.X() * gScale.X());
//	gHitbox.Y(gHitbox.Y() * gScale.Y());
//	gHitbox.Z(gHitbox.Z() * gScale.Z());
//	switch (hitboxType)
//	{
//	case HitBoxType::Sphere:
//		result;
//		break;
//	case HitBoxType::Cube:
//		result;
//		break;
//	case HitBoxType::Rectangle:
//		result = (pPosition.X() - pHitbox.X() <= gPossition.X() + gHitbox.X() && pPosition.X() + pHitbox.X() >= gPossition.X() - gHitbox.X())
//			&& (pPosition.Y() - pHitbox.Y() <= gPossition.Y() + gHitbox.Y() && pPosition.Y() + pHitbox.Y() >= gPossition.Y() - gHitbox.Y())
//			&& (pPosition.Z() - pHitbox.Z() <= gPossition.Z() + gHitbox.Z() && pPosition.Z() + pHitbox.Z() >= gPossition.Z() - gHitbox.Z());
//		break;
//	case HitBoxType::Point:
//		result = false;
//		break;
//	default:
//		result = false;
//		break;
//		*/
//}
//
//
//
//bool GameObject::SetHitbox(float radius)
//{
//	if (m_hitboxType == HitBoxType::point || m_hitboxType == HitBoxType::rectangle)
//		return false;
//	m_hitbox.X =(radius);
//	return true;
//}
//
//bool GameObject::SetHitbox(float sizeX, float sizeY, float sizeZ)
//{
//	if (m_hitboxType != HitBoxType::rectangle)
//		return false;
//	m_hitbox = float3(sizeX, sizeY, sizeZ);
//	return true;
//}
//
//void GameObject::SetHitboxType(HitBoxType hitbox)
//{
//	m_hitboxType = hitbox;
//}
//
//float3 GameObject::GetHitbox()
//{
//	return m_hitbox;
//}
//
//float3 GameObject::GetHitboxScaled()
//{
//	return float3();
//}
//
//HitBoxType GameObject::GetHitboxType()
//{
//	return m_hitboxType;
//}


void GameObject::Destroy()
{
	for (int i = m_Componets.size(); 0 < i; i--)
	{
		if (m_Componets[i] != nullptr)
			m_Componets[i]->Destroy();
		delete(m_Componets[i]);
	}
	m_Componets.clear();
	//stored elss where
	m_model = 0;

	if (m_textures)
	{
		m_textures->clear();
		delete m_textures;
		m_textures = 0;
	}
	//stored else where
	m_shader = 0;

	if (m_collishonObject)
	{
		TA::Physics::GetInstance().RemoveDynamicObject(m_collishonObject);
		m_collishonObject->Release();
		m_collishonObject = 0;
	}
}

bool GameObject::IsAlive() { return !m_KillGameObject; }

void GameObject::OnCollishon(const GameObject * other)
{
	for each (Component* componet in m_Componets)
	{
		//if it retuns True the colliton has been resolved and 
		//Dose not want it to be sent to other componets
		if (componet->OnCollishon(other))
			return;
	}
}


#include "GameObject.h"
#include <math.h>
#include "../TrueAxis/Physics/Physics.h"

GameObject::GameObject()
{
	m_model = 0;
	//ID3D11ShaderResourceView* m_textures;
	m_textures = new std::vector<ID3D11ShaderResourceView*>();
	m_shader=0;
	m_colour = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
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
	m_colour = go->m_colour;
	for each (ID3D11ShaderResourceView* texture in *go->m_textures)
	{
		m_textures->push_back(texture);
	}
}


GameObject::~GameObject()
{
}


void GameObject::Initalize(Float3 position, Float3 rotation, ModelClass * model, ID3D11ShaderResourceView* textures, Shader * shader)
{
	m_position = position;
	m_rotation = rotation;
	m_scale = Float3(1.0f, 1.0f, 1.0f);
	m_textures->push_back(textures);
	m_shader = shader;
	m_model = model;
	if (!model)
		return;
	m_Renders = true;
	//m_hitbox = Float3();
	//m_hitboxType = HitBoxType::point;
}

void GameObject::SetPosition(Float3 pos) { m_position = pos; }

void GameObject::SetRotation(Float3 rot) { m_rotation = rot; }

void GameObject::SetScale(Float3 scale) { m_scale = scale; }

void GameObject::SetColour(XMFLOAT4 colour) { m_colour = colour; }

Float3 GameObject::GetPosition() { return m_position; }

Float3 GameObject::GetRotation() { return m_rotation; }

Float3 GameObject::GetScale() { return m_scale; }

XMFLOAT4 GameObject::GetColour(){ return m_colour; }

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
	Float3 rotationInRadens = m_rotation * 0.0174532925f;
	rotationMatrix = XMMatrixRotationRollPitchYaw(rotationInRadens.X, rotationInRadens.Y, rotationInRadens.Z);
	renderMatrix = XMMatrixMultiply(worldMatrix, transformMatrix);
	renderMatrix = XMMatrixMultiply(rotationMatrix, renderMatrix);
	renderMatrix = XMMatrixMultiply(scaleMatrix, renderMatrix);
	m_model->Render(deviceContext);
	m_shader->Render(deviceContext, m_model->GetIndexCount(), renderMatrix, viewMatrix, projectionMatrix, m_textures, light,&m_colour);
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

void GameObject::OnCollishon(const CollisonData * other)
{
	for each (Component* componet in m_Componets)
	{
		//if it retuns True the colliton has been resolved and 
		//Dose not want it to be sent to other componets
		if (componet->OnCollishon(other))
			return;
	}
}


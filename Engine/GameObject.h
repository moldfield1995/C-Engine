#pragma once
#include "float3.h"
#include "ModelClass.h"
#include "d3dclass.h"
#include "lightclass.h"
#include "cameraclass.h"
#include "frustumclass.h"
#include "Shader.h"
#include "textureclass.h"
#include <vector>
#include "Component.h"
#include "..\TrueAxis\Physics\DynamicObject.h"
#include "..\TrueAxis\Physics\CollisionObjectComplex.h"
//Updated In Final Year
//Created By Matthew Oldfield


class GameObject
{
	friend Component;
public:
	GameObject();
	//Duplicates a gameObject, dose NOT copy componets
	GameObject(GameObject* go);
	~GameObject();

	void Initalize(Float3 position, Float3 rotation, ModelClass* model, ID3D11ShaderResourceView* textures, Shader* shader);
	void SetPosition(Float3 pos);
	void SetRotation(Float3 rot);
	void SetScale(Float3 scale);
	void SetColour(XMFLOAT4 colour);
	Float3 GetPosition();
	Float3 GetRotation();
	Float3 GetScale();
	XMFLOAT4 GetColour();

	void Update();

	//Render
	void Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix,FrustumClass* frustume,LightClass* light,CameraClass& camera);

	//Componet
	void AddComponet(Component* component);

	//If index is not previded its just added to the top of the list
	void AddTexture(ID3D11ShaderResourceView* texture, int index = -1);

	void Destroy();
	bool IsAlive();

	void OnCollishon(const GameObject* other);


protected:

	bool m_KillGameObject,m_Renders;
	ModelClass* m_model;
	std::vector<ID3D11ShaderResourceView*>* m_textures;
	Shader* m_shader;
	XMFLOAT4 m_colour;

	std::vector<Component*> m_Componets;
	TA::DynamicObject* m_collishonObject;
private:
	Float3 m_position, m_rotation, m_scale;
};


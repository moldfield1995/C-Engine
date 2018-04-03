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

//Updated In Final Year
//Created By Matthew Oldfield

//Using lowercase enums because of a conflict with Widonws Rectangle function
enum HitBoxType
{
	point,
	sphere,
	cube,
	rectangle,
};
class GameObject
{
	friend Component;
public:
	GameObject();
	//Duplicates a gameObject, dose NOT copy componets
	GameObject(GameObject* go);
	~GameObject();

	void Initalize(float3 position, float3 rotation, ModelClass* model, ID3D11ShaderResourceView* textures, Shader* shader);
	void SetPosition(float3 pos);
	void SetRotation(float3 rot);
	void SetScale(float3 scale);
	float3 GetPosition();
	float3 GetRotation();
	float3 GetScale();
	
	void Update();

	//Render
	void Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix,FrustumClass* frustume,LightClass* light,CameraClass& camera);

	//Componet
	void AddComponet(Component* component);

	//Collition
	bool CheckColltion(GameObject* other);
	//Seting up a Cube or Sphere Hitbox
	bool SetHitbox(float radius);
	//Seting up a Rectangle HitBox
	bool SetHitbox(float sizeX, float sizeY, float sizeZ);
	void SetHitboxType(HitBoxType hitbox);
	float3 GetHitbox();
	float3 GetHitboxScaled();
	HitBoxType GetHitboxType();

	void Destroy();
	bool IsAlive();

protected:

	bool m_KillGameObject,m_Renders;
	ModelClass* m_model;
	std::vector<ID3D11ShaderResourceView*>* m_textures;
	Shader* m_shader;
	HitBoxType m_hitboxType;
	float3 m_hitbox;
	std::vector<Component*> m_Componets;
private:
	float3 m_position, m_rotation, m_scale;
	
};


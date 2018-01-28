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
	friend void Component::Update();
public:
	GameObject();
	~GameObject();

	void Initalize(int model, int texute, float3 position, float3 rotation);
	void Initalize(float3 position, float3 rotation, ModelClass* model, ID3D11ShaderResourceView* textures, Shader* shader);
	void SetPosition(float3 pos);
	void SetRotation(float3 rot);
	void SetScale(float3 scale);
	float3 GetPosition();
	float3 GetRotation();
	float3 GetScale();
	
	void Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix,FrustumClass* frustume,LightClass* light,CameraClass& camera);

	bool CheckColltion(GameObject* other);
	//Seting up a Cube or Sphere Hitbox
	bool SetHitbox(float radius);
	//Seting up a Rectangle HitBox
	bool SetHitbox(float sizeX, float sizeY, float sizeZ);
	void SetHitboxType(HitBoxType hitbox);
	float3 GetHitbox();
	float3 GetHitboxScaled();
	HitBoxType GetHitboxType();
	bool isAlive();
	//Old Below Needs replacing
	void SetOrigin(float posX, float posY, float posZ, float rotX, float rotY, float radius);

protected:
	bool m_KillGameObject;

private:
	
	float3 m_position, m_rotation, m_scale;

	ModelClass* m_model;
	//ID3D11ShaderResourceView* m_textures;
	std::vector<ID3D11ShaderResourceView*>* m_textures;
	Shader* m_shader;
	HitBoxType m_hitboxType;
	float3 m_hitbox;
	std::vector<Component*> m_Componets;
	//Old Below Needs Replacing
	int m_modelIndex;
	int m_textureIndex, m_bumpIndex;
	//int m_shader;


};


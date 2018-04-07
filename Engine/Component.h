#pragma once
#include "d3dclass.h"
#include "ModelClass.h"
#include <vector>
#include "Shader.h"
#include "..\TrueAxis\Physics\DynamicObject.h"

class FrustumClass;
class LightClass;
class CameraClass;
class GameObject;

//Updated In Final Year
//Created By Matthew Oldfield

class Component
{
	friend GameObject;
public:
	Component() {};
	~Component() {};
	void virtual Initalize() = 0;
	void virtual Update() = 0;
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera) = 0;
	void virtual Destroy() =0;
	//Return True to stop other componets being called
	bool virtual OnCollishon(const GameObject* other);
protected:
	//Acsessors and Setters for GameObject
	void SetOwnersKill(bool state);
	void SetOwnersRender(bool state);
	ModelClass* GetModel();
	std::vector<ID3D11ShaderResourceView*>* GetTextures();
	Shader* GetShader();
	void SetOwnersDynamicObject(TA::DynamicObject* value);
	TA::DynamicObject* GetOwnersDynamicObject();

	GameObject* owner;
	bool renders, killComponet,active;
private:

};

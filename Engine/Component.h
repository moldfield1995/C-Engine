#pragma once
#include "d3dclass.h"
#include "ModelClass.h"
#include <vector>
#include "Shader.h"

class FrustumClass;
class LightClass;
class CameraClass;
class GameObject;

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
protected:
	//Acsessors and Setters for GameObject
	void SetOwnersKill(bool state);
	void SetOwnersRender(bool state);
	ModelClass* GetModel();
	std::vector<ID3D11ShaderResourceView*>* GetTextures();
	Shader* GetShader();

	GameObject* owner;
	bool renders, killComponet,active;
private:

};

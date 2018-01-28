#pragma once
#include "d3dclass.h"

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
	void virtual Update() = 0;
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera) = 0;

protected:
	GameObject* owner;
	bool renders, killComponet,active;

private:

};

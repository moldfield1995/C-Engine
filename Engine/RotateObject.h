#pragma once
#include "Component.h"
class RotateObject :
	public Component
{
public:
	RotateObject(Float3 rotation);
	~RotateObject();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();
private:
	Float3 rotateSpeed;
};


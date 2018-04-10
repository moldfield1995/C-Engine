#pragma once
#include "Component.h"
class SphereCollider :
	public Component
{
public:
	SphereCollider(float radius );
	~SphereCollider();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();
private:
	float radius;
};


#pragma once
#include "Collider.h"
class SphereCollider :
	public Collider
{
public:
	SphereCollider(float radius, bool ControledByVelocity = false, CollisionLayer collisonLayer = CollisionLayer::Default);
	~SphereCollider();
	void virtual Initalize();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();
private:
	float radius;
	bool controledByVelocity;
	CollisionLayer collisonLayer;
};


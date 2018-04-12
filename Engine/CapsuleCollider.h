#pragma once
#include "Collider.h"
class CapsuleCollider :
	public Collider
{
public:
	CapsuleCollider(Float3 capsuleBegining, Float3 capsuleEnd, float capsuleRadius, bool ControledByVelocity = false, CollisionLayer collisonLayer = CollisionLayer::Default);
	~CapsuleCollider();
	void virtual Initalize();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();

private:
	Float3 capsuleBeginPoint, capsuleEndPoint;
	float radius;
	bool controledByVelocity;
	CollisionLayer collisonLayer;
};


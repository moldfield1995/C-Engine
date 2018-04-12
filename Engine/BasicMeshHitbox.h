#pragma once
#include "Collider.h"
#include "..\TrueAxis\Physics\DynamicObject.h"
#include "..\TrueAxis\Physics\CollisionObjectConvex.h"

class BasicMeshHitbox :
	public Collider
{
public:
	BasicMeshHitbox(bool ControledByVelocity = false, CollisionLayer collisonLayer = CollisionLayer::Default);
	~BasicMeshHitbox();
	void virtual Initalize();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();

private:
	TA::CollisionObjectConvex* generateConvexHull();
	bool controledByVelocity;
	CollisionLayer collisonLayer;
};


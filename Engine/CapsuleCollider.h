#pragma once
#include "Component.h"
class CapsuleCollider :
	public Component
{
public:
	CapsuleCollider(Float3 capsuleBegining, Float3 capsuleEnd, float capsuleRadius, bool ControledByVelocity = false);
	~CapsuleCollider();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();

private:
	Float3 capsuleBeginPoint, capsuleEndPoint;
	float radius;
	bool controledByVelocity;
};


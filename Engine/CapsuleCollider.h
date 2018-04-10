#pragma once
#include "Component.h"
class CapsuleCollider :
	public Component
{
public:
	CapsuleCollider(float3 capsuleBegining, float3 capsuleEnd, float capsuleRadius);
	~CapsuleCollider();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();

private:
	float3 capsuleBeginPoint, capsuleEndPoint;
	float radius;
};


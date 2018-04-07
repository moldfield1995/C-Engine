#pragma once
#include "Component.h"
class HitBoxTest :
	public Component
{
public:
	HitBoxTest(float3 size,float3 minPos, float3 maxPos);
	~HitBoxTest();

	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();
	//Return True to stop other componets being called
	bool virtual OnCollishon(const GameObject* other);
	void SetOtherCollision(HitBoxTest* other);
private:
	ID3D11ShaderResourceView *collideTexture, *defaultTexture;
	float3 hitboxSize, minPosition, maxPosition;
	HitBoxTest* other;
};


#pragma once
#include "Component.h"
class HitBoxTest :
	public Component
{
public:
	HitBoxTest(Float3 size,Float3 minPos, Float3 maxPos);
	~HitBoxTest();

	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();
	//Return True to stop other componets being called
	bool virtual OnCollishon(const CollisonData* other);
private:
	ID3D11ShaderResourceView *collideTexture, *defaultTexture;
	Float3 hitboxSize, minPosition, maxPosition;
};


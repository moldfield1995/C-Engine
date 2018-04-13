#pragma once
#include "Component.h"
class ShotComponet :
	public Component
{
public:
	ShotComponet();
	~ShotComponet();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();
	bool virtual OnCollishon(const CollisonData* other);

	void Shoot(Float3 position, Float3 direction);
	void Reset();
private:
	const static float lifeTime;
	float currentLife;
};


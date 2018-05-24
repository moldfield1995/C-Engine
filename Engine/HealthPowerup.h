#pragma once
#include "Powerup.h"
class HealthPowerup :
	public Powerup
{
public:
	HealthPowerup(GameObject* innerObject, Float3 Velosity);
	~HealthPowerup();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();

	void virtual Activate();
protected:
	const float healthAmount;
};


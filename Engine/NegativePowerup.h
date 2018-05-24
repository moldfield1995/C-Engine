#pragma once
#include "Powerup.h"
class NegativePowerup :
	public Powerup
{
public:
	NegativePowerup(GameObject* innerObject, Float3 Velosity);
	~NegativePowerup();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();

	void virtual Activate();

protected:
	const float deductionAmount;
};


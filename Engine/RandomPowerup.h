#pragma once
#include "Powerup.h"
#include "timerclass.h"
class RandomPowerup :
	public Powerup
{
public:
	RandomPowerup(GameObject* innerObject, Float3 Velosity);
	~RandomPowerup();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();

	void virtual Activate();
private:
	TimerClass * timerClass;
};


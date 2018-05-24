#include "RandomPowerup.h"



RandomPowerup::RandomPowerup(GameObject* innerObject, Float3 Velosity)
	: Powerup(innerObject,Velosity)
{
}


RandomPowerup::~RandomPowerup()
{
}

void RandomPowerup::Initalize()
{
	Powerup::Initalize();
}

void RandomPowerup::Update()
{
	Powerup::Update();
}

void RandomPowerup::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
	Powerup::Render(deviceContext, worldMatrix, viewMatrix, projectionMatrix, frustume, light, camera);
}

void RandomPowerup::Destroy()
{
	Powerup::Destroy();
}

void RandomPowerup::Activate()
{
}

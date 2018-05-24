#include "HealthPowerup.h"
#include "PlayerControler.h"


HealthPowerup::HealthPowerup(GameObject* innerObject, Float3 Velosity)
	: Powerup(innerObject, Velosity)
	, healthAmount(25.0f)
{
}


HealthPowerup::~HealthPowerup()
{
}

void HealthPowerup::Initalize()
{
	Powerup::Initalize();
}

void HealthPowerup::Update()
{
	Powerup::Update();
}

void HealthPowerup::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
	Powerup::Render(deviceContext,worldMatrix,viewMatrix,projectionMatrix,frustume,light,camera);
}

void HealthPowerup::Destroy()
{
	Powerup::Destroy();
}

void HealthPowerup::Activate()
{
	PlayerControler::GetInstance()->AddHp(healthAmount);
	SetOwnersKill(true);
}

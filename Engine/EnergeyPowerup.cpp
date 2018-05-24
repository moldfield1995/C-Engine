#include "EnergeyPowerup.h"
#include "PlayerControler.h"


EnergeyPowerup::EnergeyPowerup(GameObject* innerObject, Float3 Velosity)
	: Powerup(innerObject, Velosity)
	, energeyAmount(25.0f)
{
}


EnergeyPowerup::~EnergeyPowerup()
{
}

void EnergeyPowerup::Initalize()
{
	Powerup::Initalize();
}

void EnergeyPowerup::Update()
{
	Powerup::Update();
}

void EnergeyPowerup::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
	Powerup::Render(deviceContext, worldMatrix, viewMatrix, projectionMatrix, frustume, light, camera);
}

void EnergeyPowerup::Destroy()
{
	Powerup::Destroy();
}


void EnergeyPowerup::Activate()
{
	PlayerControler::GetInstance()->AddHp(energeyAmount);
	SetOwnersKill(true);
}

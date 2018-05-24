#include "NegativePowerup.h"
#include "PlayerControler.h"


NegativePowerup::NegativePowerup(GameObject* innerObject, Float3 Velosity)
	: Powerup(innerObject, Velosity)
	, deductionAmount(-20.f)
{
}


NegativePowerup::~NegativePowerup()
{
}

void NegativePowerup::Initalize()
{
	Powerup::Initalize();
}

void NegativePowerup::Update()
{
	Powerup::Update();
}

void NegativePowerup::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
	Powerup::Render(deviceContext, worldMatrix, viewMatrix, projectionMatrix, frustume, light, camera);
}

void NegativePowerup::Destroy()
{
	Powerup::Destroy();
}

void NegativePowerup::Activate()
{
	PlayerControler* player = PlayerControler::GetInstance();
	player->AddHp(deductionAmount);
	player->AddEnergey(deductionAmount);
	SetOwnersKill(true);
}


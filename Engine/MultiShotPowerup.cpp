#include "MultiShotPowerup.h"
#include "timerclass.h"
#include "ShotManager.h"

MultiShotPowerup::MultiShotPowerup(GameObject* innerObject, Float3 Velosity)
	: Powerup(innerObject, Velosity)
	, duration(30.f)
{
	timeToDisable = 0.f;
	activated = false;
}


MultiShotPowerup::~MultiShotPowerup()
{
}

void MultiShotPowerup::Initalize()
{
	Powerup::Initalize();
}

void MultiShotPowerup::Update()
{
	if (activated && timeToDisable <= TimerClass::GetInstance()->GetTime())
	{
		ShotManager::GetInstance()->SetMultyShot(false);
		SetOwnersKill(true);
	}
	else //If we are not active multi shot see if we shoud be destroyed
		Powerup::Update();
}

void MultiShotPowerup::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
	Powerup::Render(deviceContext, worldMatrix, viewMatrix, projectionMatrix, frustume, light, camera);
}

void MultiShotPowerup::Destroy()
{
	Powerup::Destroy();
}

void MultiShotPowerup::Activate()
{
	ShotManager::GetInstance()->SetMultyShot(true);
	timeToDisable = duration + TimerClass::GetInstance()->GetTime();
	activated = true;
}


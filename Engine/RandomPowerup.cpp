#include "RandomPowerup.h"
#include "Utills.h"
#include "PlayerControler.h"
#include "GameObject.h"

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
	owner->SetColour(XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
	timerClass = TimerClass::GetInstance();
}

void RandomPowerup::Update()
{
	Powerup::Update();
	float time = timerClass->GetTime();
	owner->SetColour(XMFLOAT4(sinf(time), cosf(time+.25f), tanf(time+.5f), 1.0f));
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
	PlayerControler *player = PlayerControler::GetInstance();
	if (Utills::RandomFloat() >= 0.5f)
	{
		player->AddHp(-30.0f);
		player->AddEnergey(-30.0f);
	}
	else
	{
		player->AddHp(30.0f);
		player->AddEnergey(30.0f);
	}
}

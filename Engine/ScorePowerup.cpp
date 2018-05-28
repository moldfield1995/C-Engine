#include "ScorePowerup.h"
#include "ScoreManager.h"
#include "timerclass.h"
#include "Collider.h"
#include "GameObject.h"

ScorePowerup::ScorePowerup(GameObject* innerObject, Float3 Velosity)
	: Powerup(innerObject, Velosity)
	, duration(30.0f)
{
	timeToDisable = -1.0f;
	activated = false;
}


ScorePowerup::~ScorePowerup()
{
}

void ScorePowerup::Initalize()
{
	Powerup::Initalize();
	owner->SetColour(XMFLOAT4(1.0f, 1.0f, 0.0f, 1.0f));
}

void ScorePowerup::Update()
{
	if (activated && timeToDisable <= TimerClass::GetInstance()->GetTime())
	{
		ScoreManager::GetInstance()->AddScoreMulityplier(-2);
		SetOwnersKill(true);
	}
	else if(!activated) //If we are not active see if we need to be destroyed
		Powerup::Update();
}

void ScorePowerup::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
	Powerup::Render(deviceContext, worldMatrix, viewMatrix, projectionMatrix, frustume, light, camera);
}

void ScorePowerup::Destroy()
{
	Powerup::Destroy();
}

void ScorePowerup::Activate()
{
	ScoreManager::GetInstance()->AddScoreMulityplier(2);
	timeToDisable = duration + TimerClass::GetInstance()->GetTime();
	activated = true;
}

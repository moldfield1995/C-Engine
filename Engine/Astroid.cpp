#include "Astroid.h"
#include "Collider.h"
#include "ScoreManager.h"
#include "GameObject.h"
#include "PlayerControler.h"
#include "PowerupManager.h"
#include "Utills.h"
#include "timerclass.h"

AstroidComponet::AstroidComponet()
	: zDeathPlain(-10.0f)
{
	rotation = Float3(Utills::RandomFloat(), Utills::RandomFloat(), Utills::RandomFloat()).Normalize() * 180.0f;
}


AstroidComponet::~AstroidComponet()
{
}

void AstroidComponet::Initalize()
{
	Reset();
}

void AstroidComponet::Update()
{
	if (owner->GetPosition().Z < zDeathPlain)
	{
		ScoreManager* scoreManager = ScoreManager::GetInstance();
		SetOwnersRender(false);
		SetOwnersKill(true);
	}
	Float3 owenerRot = owner->GetRotation();
	owenerRot = owenerRot + rotation * TimerClass::GetInstance()->GetFrameTime();
	owner->SetRotation(owenerRot);
}

void AstroidComponet::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void AstroidComponet::Destroy()
{
}

bool AstroidComponet::OnCollishon(const CollisonData * other)
{
	SetOwnersRender(false);
	SetOwnersKill(true);
	if (other->CollisionLayer == CollisionLayer::Shot)
	{
		ScoreManager* scoreManager = ScoreManager::GetInstance();
		if(scoreManager)
			scoreManager->AstroidKilled();
		PlayerControler* player = PlayerControler::GetInstance();
		PowerupManager* powerup = PowerupManager::GetInstance();
		if (powerup)
			powerup->SpawnPowerup(owner->GetPosition(), GetOwnersDynamicObject()->GetLinearVelocity());
		GetOwnersDynamicObject()->SetCollisionDisabled(true);
	}

	return true;
}

void AstroidComponet::Reset()
{
	GetOwnersDynamicObject()->SetCollisionDisabled(true);
	GetOwnersDynamicObject()->SetLinearVelocity(TA::Vec3(0.0f, 0.0f, 0.0f));
	SetOwnersKill(false);
}

void AstroidComponet::Launch(Float3 position, Float3 velosity)
{
	owner->SetPosition(position);

	TA::DynamicObject* dynamicObject = GetOwnersDynamicObject();
	dynamicObject->SetPosition(position.ToVec3());
	dynamicObject->SetCollisionDisabled(false);
	dynamicObject->SetLinearVelocity(velosity.ToVec3());
	dynamicObject->SetUpdateDisabled(false);

	SetOwnersRender(true);
}

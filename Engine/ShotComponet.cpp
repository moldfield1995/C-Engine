#include "ShotComponet.h"
#include "GameObject.h"
#include "Collider.h"
#include "timerclass.h"

const float ShotComponet::lifeTime = 10.0f;

ShotComponet::ShotComponet()
{
}


ShotComponet::~ShotComponet()
{
}

void ShotComponet::Initalize()
{
	Reset();
}

void ShotComponet::Update()
{
	currentLife += TimerClass::GetInstance()->GetFrameTime();
	if (currentLife >= lifeTime)
	{
		SetOwnersRender(false);
		SetOwnersKill(true);
	}
}

void ShotComponet::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void ShotComponet::Destroy()
{
}

bool ShotComponet::OnCollishon(const CollisonData * other)
{
	if (other->CollisionLayer == CollisionLayer::Astroid)
	{
		SetOwnersRender(false);
		SetOwnersKill(true);
	}
	return true;
}

void ShotComponet::Shoot(Float3 position, Float3 direction)
{
	owner->SetPosition(position);

	TA::DynamicObject* dynamicObject = GetOwnersDynamicObject();
	dynamicObject->SetPosition(position.ToVec3());
	dynamicObject->SetCollisionDisabled(false);
	dynamicObject->SetLinearVelocity(direction.ToVec3());
	dynamicObject->SetUpdateDisabled(false);

	SetOwnersRender(true);
}

void ShotComponet::Reset()
{
	currentLife = 0.0f;
	GetOwnersDynamicObject()->SetCollisionDisabled(true);
	GetOwnersDynamicObject()->SetLinearVelocity(TA::Vec3(0.0f, 0.0f, 0.0f));
	SetOwnersKill(false);
}

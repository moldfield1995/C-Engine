#include "ShotComponet.h"
#include "GameObject.h"
#include "Collider.h"
#include "timerclass.h"

const float ShotComponet::lifeTime = 100.0f;

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

void ShotComponet::Shoot(Float3 position)
{
	owner->SetPosition(position);
	GetOwnersDynamicObject()->SetPosition(position.ToVec3());
	SetOwnersRender(true);
	GetOwnersDynamicObject()->SetCollisionDisabled(false);
	GetOwnersDynamicObject()->SetLinearVelocity(TA::Vec3(0.0f, 0.0f, 100.0f));

}

void ShotComponet::Reset()
{
	currentLife = 0.0f;
	GetOwnersDynamicObject()->SetCollisionDisabled(true);
	GetOwnersDynamicObject()->SetLinearVelocity(TA::Vec3(0.0f, 0.0f, 0.0f));
	SetOwnersKill(false);
}

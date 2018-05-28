#include "Powerup.h"
#include "GameObject.h"
#include "SphereCollider.h"
#include "timerclass.h"

Powerup::Powerup(GameObject* innerObject, Float3 Velosity)
	: velosity(Velosity)
{
	this->innerObject = new GameObject(innerObject);
}


Powerup::~Powerup()
{
}

void Powerup::Initalize()
{
	owner->AddComponet(new SphereCollider(2.0f, true, CollisionLayer::Default));
	TA::DynamicObject* physicsObject = GetOwnersDynamicObject();
	physicsObject->SetLinearVelocity(velosity.ToVec3());
	
}

void Powerup::Update()
{
	if (owner->GetPosition().Z <= -20.0f)
	{
		SetOwnersKill(true);
	}
	Float3 rotation = owner->GetRotation();
	rotation.Y += 180.0f * TimerClass::GetInstance()->GetFrameTime();
	owner->SetRotation(rotation);
}

void Powerup::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
	//Set position to local space
	Float3 position = owner->GetPosition();
	Float3 scale = owner->GetScale();
	XMMATRIX renderMatrix = XMMatrixTranslation(position.X, position.Y, position.Z);
	XMMATRIX scaleMatrix = XMMatrixScaling(scale.X, scale.Y, scale.Z);
	renderMatrix = XMMatrixMultiply(worldMatrix, renderMatrix);
	renderMatrix = XMMatrixMultiply(scaleMatrix, renderMatrix);
	innerObject->Render(deviceContext, renderMatrix, viewMatrix, projectionMatrix, frustume, light, camera);
}

void Powerup::Destroy()
{
	if (innerObject)
	{
		innerObject->Destroy();
		delete(innerObject);
		innerObject = 0;
	}
}

bool Powerup::OnCollishon(const CollisonData * other)
{
	if (other->CollisionLayer == CollisionLayer::Player)
	{
		Activate();
		Float3 outOfScene = Float3(0.0f, 0.0f, -100.0f);
		GetOwnersDynamicObject()->SetPosition(outOfScene.ToVec3());
	}
	return true;
}



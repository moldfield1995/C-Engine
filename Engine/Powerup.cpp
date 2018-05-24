#include "Powerup.h"
#include "GameObject.h"
#include "SphereCollider.h"


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
	owner->AddComponet(new SphereCollider(1.0f, true, CollisionLayer::Default));
	GetOwnersDynamicObject()->SetLinearVelocity(velosity.ToVec3());
}

void Powerup::Update()
{
	if (owner->GetPosition().Z <= -20.0f)
	{
		SetOwnersKill(true);
	}
}

void Powerup::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
	//Set position to local space
	Float3 position = owner->GetPosition();
	XMMATRIX positionMatrix = XMMatrixTranslation(position.X, position.Y, position.Z);
	positionMatrix = XMMatrixMultiply(worldMatrix, positionMatrix);
	innerObject->Render(deviceContext, positionMatrix, viewMatrix, projectionMatrix, frustume, light, camera);
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



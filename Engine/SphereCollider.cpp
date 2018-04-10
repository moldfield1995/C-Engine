#include "SphereCollider.h"
#include "GameObject.h"
#include "..\TrueAxis\Physics\Physics.h"

SphereCollider::SphereCollider(float radius)
{
	this->radius = radius;
}


SphereCollider::~SphereCollider()
{
}

void SphereCollider::Initalize()
{
	TA::DynamicObject *dynamicObject = TA::DynamicObject::CreateNew();
	dynamicObject->InitialiseAsASphere(TA::Vec3(0.0f, 0.0f, 0.0f), radius);
	dynamicObject->SetFrame(TA::MFrame(owner->GetPosition().ToVec3(), TA::Mat33(owner->GetRotation().ToEuler())));
	dynamicObject->SetGhost(true);
	dynamicObject->SetToMoving();
	dynamicObject->SetUserData(owner);
	TA::Physics::GetInstance().AddDynamicObject(dynamicObject);
	SetOwnersDynamicObject(dynamicObject);
}

void SphereCollider::Update()
{
	GetOwnersDynamicObject()->SetFrame(TA::MFrame(owner->GetPosition().ToVec3(), TA::Mat33(owner->GetRotation().ToEuler())));
}

void SphereCollider::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void SphereCollider::Destroy()
{
}

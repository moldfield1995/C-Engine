#include "CapsuleCollider.h"
#include "GameObject.h"
#include "..\TrueAxis\Physics\Physics.h"


CapsuleCollider::CapsuleCollider(float3 capsuleBegining, float3 capsuleEnd, float capsuleRadius)
{
	capsuleBeginPoint = capsuleBegining;
	capsuleEndPoint = capsuleEnd;
	this->radius = capsuleRadius;
}


CapsuleCollider::~CapsuleCollider()
{
}

void CapsuleCollider::Initalize()
{
	TA::DynamicObject *dynamicObject = TA::DynamicObject::CreateNew();
	dynamicObject->InitialiseAsACapsule(capsuleBeginPoint.ToVec3(), capsuleEndPoint.ToVec3(), radius);
	dynamicObject->SetFrame(TA::MFrame(owner->GetPosition().ToVec3(), TA::Mat33(owner->GetRotation().ToEuler())));
	dynamicObject->SetGhost(true);
	dynamicObject->SetToMoving();
	dynamicObject->SetUserData(owner);
	TA::Physics::GetInstance().AddDynamicObject(dynamicObject);
	SetOwnersDynamicObject(dynamicObject);
}

void CapsuleCollider::Update()
{
	GetOwnersDynamicObject()->SetFrame(TA::MFrame(owner->GetPosition().ToVec3(), TA::Mat33(owner->GetRotation().ToEuler())));
}

void CapsuleCollider::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void CapsuleCollider::Destroy()
{
}

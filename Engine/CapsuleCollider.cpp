#include "CapsuleCollider.h"
#include "GameObject.h"
#include "..\TrueAxis\Physics\Physics.h"


CapsuleCollider::CapsuleCollider(Float3 capsuleBegining, Float3 capsuleEnd, float capsuleRadius , bool ControledByVelocity, CollisionLayer collisonLayer)
	: Collider(ControledByVelocity)
{
	capsuleBeginPoint = capsuleBegining;
	capsuleEndPoint = capsuleEnd;
	this->radius = capsuleRadius;
	controledByVelocity = ControledByVelocity;
	this->collisonLayer = collisonLayer;
}


CapsuleCollider::~CapsuleCollider()
{
}

void CapsuleCollider::Initalize()
{
	TA::DynamicObject *dynamicObject = TA::DynamicObject::CreateNew();
	dynamicObject->InitialiseAsACapsule(capsuleBeginPoint.ToVec3(), capsuleEndPoint.ToVec3(), radius);
	dynamicObject->SetFrame(TA::MFrame(owner->GetPosition().ToVec3(), TA::Mat33((owner->GetRotation() * Leap::DEG_TO_RAD).ToEuler())));
	dynamicObject->SetGhost(true);
	dynamicObject->SetToMoving();
	CollisonData* collisonData = new CollisonData{ collisonLayer, owner };
	dynamicObject->SetUserData(collisonData);
	TA::Physics::GetInstance().AddDynamicObject(dynamicObject);
	SetOwnersDynamicObject(dynamicObject);
}

void CapsuleCollider::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void CapsuleCollider::Destroy()
{
}

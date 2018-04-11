#include "CapsuleCollider.h"
#include "GameObject.h"
#include "..\TrueAxis\Physics\Physics.h"


CapsuleCollider::CapsuleCollider(Float3 capsuleBegining, Float3 capsuleEnd, float capsuleRadius , bool ControledByVelocity)
{
	capsuleBeginPoint = capsuleBegining;
	capsuleEndPoint = capsuleEnd;
	this->radius = capsuleRadius;
	controledByVelocity = ControledByVelocity;
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
	if (controledByVelocity)
	{
		owner->SetPosition( GetOwnersDynamicObject()->GetPosition());
		TA::Mat33 rotationMatrix = GetOwnersDynamicObject()->GetFrame().m33Rotation;
		//Taken From learnopencv.com/rotation-matrix-to-euler-angles/
		Float3 rotation = Float3();
		//use ifs so we dont need to square root
		float sy = (rotationMatrix.M11() > 0.0f ? rotationMatrix.M11() : -rotationMatrix.M11()) + (rotationMatrix.M21() > 0.0f ? rotationMatrix.M21() : -rotationMatrix.M21());

		if (sy > 0.0f)
		{
			rotation.X = atan2f(rotationMatrix.M32(), rotationMatrix.M33());
			rotation.Y = atan2f(-rotationMatrix.M31(), sy);
			rotation.Z = atan2f(rotationMatrix.M21(), rotationMatrix.M11());
		}
		else
		{
			rotation.X = atan2f(rotationMatrix.M23(), rotationMatrix.M22());
			rotation.Y = atan2f(-rotationMatrix.M31(), sy);
			rotation.Z = 0.0f;
		}

		owner->SetRotation(rotation);

	}
	else
		GetOwnersDynamicObject()->SetFrame(TA::MFrame(owner->GetPosition().ToVec3(), TA::Mat33(owner->GetRotation().ToEuler())));
}

void CapsuleCollider::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void CapsuleCollider::Destroy()
{
}
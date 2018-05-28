#include "Collider.h"
#include "GameObject.h"


Collider::Collider(bool ControledByVelocity)
{
	controledByVelocity = ControledByVelocity;
}


Collider::~Collider()
{
}

void Collider::Update()
{
	if (controledByVelocity)
	{
		owner->SetPosition(GetOwnersDynamicObject()->GetPosition());
		//TA::Mat33 rotationMatrix = GetOwnersDynamicObject()->GetFrame().m33Rotation;
		////Taken From learnopencv.com/rotation-matrix-to-euler-angles/
		//Float3 rotation = Float3();
		////use ifs so we dont need to square root
		//float sy = (rotationMatrix.M11() > 0.0f ? rotationMatrix.M11() : -rotationMatrix.M11()) + (rotationMatrix.M21() > 0.0f ? rotationMatrix.M21() : -rotationMatrix.M21());

		//if (sy < 0.0f)
		//{
		//	rotation.X = atan2f(rotationMatrix.M32(), rotationMatrix.M33());
		//	rotation.Y = atan2f(-rotationMatrix.M31(), sy);
		//	rotation.Z = atan2f(rotationMatrix.M21(), rotationMatrix.M11());
		//}
		//else
		//{
		//	rotation.X = atan2f(rotationMatrix.M23(), rotationMatrix.M22());
		//	rotation.Y = atan2f(-rotationMatrix.M31(), sy);
		//	rotation.Z = 0.0f;
		//}

		//owner->SetRotation(rotation * Leap::RAD_TO_DEG);

	}
	else
		GetOwnersDynamicObject()->SetFrame(TA::MFrame(owner->GetPosition().ToVec3(), TA::Mat33((owner->GetRotation()* Leap::DEG_TO_RAD).ToEuler())));
}

#include "RotateObject.h"
#include "GameObject.h"
#include "timerclass.h"

RotateObject::RotateObject(float3 rotation)
{
	rotateSpeed = rotation;
}


RotateObject::~RotateObject()
{
}

void RotateObject::Initalize()
{
}

void RotateObject::Update()
{
	owner->SetRotation(owner->GetRotation() + (rotateSpeed*TimerClass::GetInstance()->GetTime()));
}

void RotateObject::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void RotateObject::Destroy()
{
}

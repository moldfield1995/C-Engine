#include "HitBoxTest.h"
#include "..\TrueAxis\Physics\Physics.h"
#include "..\TrueAxis\Common\AABB.h"
#include "..\TrueAxis\Physics\DynamicObject.h"
#include "GameObject.h"
#include "timerclass.h"
#include <vector>
#include "texturemanagerclass.h"


HitBoxTest::HitBoxTest(float3 size, float3 minPos, float3 maxPos)
{
	collideTexture = 0;
	defaultTexture = 0;
	hitboxSize = size;
	minPosition = minPos;
	maxPosition = maxPos;
}


HitBoxTest::~HitBoxTest()
{
}

void HitBoxTest::Initalize()
{
	float time = TimerClass::GetInstance()->GetTime();
	float3 possition = float3::Lerp(minPosition, maxPosition, (sinf(time) + 1.0f) / 2.0f);
	owner->SetPosition(possition);
	TA::Physics& physicsInstance = TA::Physics::GetInstance();
	TA::AABB aabb;
	aabb.Initialise(TA::Vec3(0.0f,0.0f,0.0f), TA::Vec3(1.0f,1.0f,1.0f));
	TA::DynamicObject *dynamicObject = TA::DynamicObject::CreateNew();
	dynamicObject->InitialiseAsABox(aabb);
	dynamicObject->SetFrame(TA::MFrame(possition.ToVec3(), TA::Mat33(owner->GetRotation().ToEuler())));
	dynamicObject->SetGhost(true);
	dynamicObject->SetToMoving();
	physicsInstance.AddDynamicObject(dynamicObject);
	SetOwnersDynamicObject(dynamicObject);
	defaultTexture = (*GetTextures())[0];
	TextureManagerClass *textureManager = TextureManagerClass::GetInstance();
	D3DClass *d3dClass = D3DClass::GetInstance();
	int textureID = textureManager->LoadTexture(d3dClass->GetDevice(), d3dClass->GetDeviceContext(), "../Engine/data/textures/metal.tga");
	collideTexture = textureManager->GetTexture(textureID);
}

void HitBoxTest::Update()
{
	float3 possition, rotation;
	float time = TimerClass::GetInstance()->GetTime();

	possition = float3::Lerp(minPosition,maxPosition,(sinf(time)+1.0f)/2.0f);
	owner->SetPosition(possition);
	rotation = owner->GetRotation();
	if (GetOwnersDynamicObject()->GetWorldAABB().Intersects(other->GetOwnersDynamicObject()->GetWorldAABB()))
	{
		OnCollishon(nullptr);
	}
	GetOwnersDynamicObject()->SetFrame(TA::MFrame(possition.ToVec3(), TA::Mat33(rotation.ToEuler())));
	GetOwnersDynamicObject()->SetCollisionObjectChanged();
}

void HitBoxTest::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void HitBoxTest::Destroy()
{
	collideTexture = 0;
	defaultTexture = 0;
}

bool HitBoxTest::OnCollishon(const GameObject * other)
{
	std::vector<ID3D11ShaderResourceView*>* texutes = GetTextures();
	if ((*texutes)[0] == defaultTexture)
	{
		(*texutes)[0] = collideTexture;
	}
	else
		(*texutes)[0] = defaultTexture;
	return false;
}

void HitBoxTest::SetOtherCollision(HitBoxTest * other)
{
	this->other = other;
}

#include "HitBoxTest.h"
#include "..\TrueAxis\Physics\Physics.h"
#include "..\TrueAxis\Common\AABB.h"
#include "..\TrueAxis\Physics\DynamicObject.h"
#include "timerclass.h"
#include <vector>
#include "texturemanagerclass.h"
#include "GameObject.h"

HitBoxTest::HitBoxTest(Float3 size, Float3 minPos, Float3 maxPos)
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
	//Varible and object setup
	float time = TimerClass::GetInstance()->GetTime();
	Float3 possition = Float3::Lerp(minPosition, maxPosition, (sinf(time) + 1.0f) / 2.0f);
	TA::Physics& physicsInstance = TA::Physics::GetInstance();
	TextureManagerClass *textureManager = TextureManagerClass::GetInstance();
	D3DClass *d3dClass = D3DClass::GetInstance();
	owner->SetPosition(possition);
	//Set up the collishon
	TA::AABB aabb;
	aabb.Initialise(TA::Vec3(0.0f,0.0f,0.0f), TA::Vec3(1.0f,1.0f,1.0f));
	//SetUp Dynamic Object
	TA::DynamicObject *dynamicObject = TA::DynamicObject::CreateNew();
	dynamicObject->InitialiseAsABox(aabb);
	dynamicObject->SetFrame(TA::MFrame(possition.ToVec3(), TA::Mat33(owner->GetRotation().ToEuler())));
	dynamicObject->SetGhost(true);
	dynamicObject->SetToMoving();
	dynamicObject->SetUserData(owner);
	physicsInstance.AddDynamicObject(dynamicObject);
	SetOwnersDynamicObject(dynamicObject);
	//SetUo texture swiching
	defaultTexture = (*GetTextures())[0];
	int textureID = textureManager->LoadTexture(d3dClass->GetDevice(), d3dClass->GetDeviceContext(), "../Engine/data/textures/metal.tga");
	collideTexture = textureManager->GetTexture(textureID);
}

void HitBoxTest::Update()
{
	Float3 possition, rotation;
	float time = TimerClass::GetInstance()->GetTime();
	possition = Float3::Lerp(minPosition,maxPosition,(sinf(time)+1.0f)/2.0f);
	owner->SetPosition(possition);
	rotation = owner->GetRotation();
	GetOwnersDynamicObject()->SetFrame(TA::MFrame(possition.ToVec3(), TA::Mat33(rotation.ToEuler())));
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


#include "PlayerControler.h"
#include "timerclass.h"
#include "Collider.h"

PlayerControler* PlayerControler::instance = 0;


PlayerControler::PlayerControler(float maxEnergey, float maxHP)
	: hpLossPerHit(25.0f)
	, energeyLossPerSecond(100.0f)
{
	this->maxEnergey = maxEnergey;
	this->maxHP = maxHP;
}

PlayerControler::~PlayerControler()
{
}

void PlayerControler::Initalize()
{
	//Object setup
	InputClass* inputClass = InputClass::GetInstance();
	leapToWorldScale = inputClass->GetLeapToWorldScale();
	leapWorldOffset = inputClass->GetLeapOffset();
	Hand hand;
	//Hand Setup
	FindHand(inputClass, 1.0f, hand);

	//UI Setup

	//Shot Setup

	//SetInstance
	instance = this;
}

void PlayerControler::Update()
{
	InputClass* inputClass = InputClass::GetInstance();
	Hand leapHand = inputClass->GetLeapFrame().hand(currentHand);
	float timeDelta = TimerClass::GetInstance()->GetFrameTime();
	//Position Setting
	if (leapHand.isValid())
	{
		//Leap possition to world possiton
		owner->SetPosition(Float3(leapHand.palmPosition())*leapToWorldScale + leapWorldOffset);
		//Bugs out rotates werdly
		//Vector direction = leapHand.direction();
		//owner->SetRotation(Float3(direction.roll(),direction.pitch(),direction.yaw())*RAD_TO_DEG);
	}
	else
	{//Attempt to find a new hand
		FindHand(inputClass, timeDelta, leapHand);
	}
	//End Position Setting

	if (!leapHand.isValid())
		return;


}

void PlayerControler::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void PlayerControler::Destroy()
{
}

bool PlayerControler::OnCollishon(const CollisonData * other)
{
	if (other->CollisionLayer == CollisionLayer::Astroid)
	{
		currentHP -= hpLossPerHit;
		//Play sound
		if (currentHP <= 0.0f)
		{//GameOver

		}
	}
	return true;
}

void PlayerControler::HitAstroid()
{
	currentEnergey += 10.0f;
}

void PlayerControler::FindHand(InputClass * input, float timeDelta, Hand &hand)
{
	bool handFound = false;
	Frame leapFrame = input->GetLeapFrame();
	HandList currentHands = leapFrame.hands();
	for each (Hand leapHand in currentHands)
	{
		if (leapHand.isValid())
		{
			//Leap possition to world possiton
			owner->SetPosition(Float3(leapHand.palmPosition())*leapToWorldScale + leapWorldOffset);
			//Takes normal facing directon and translates it to rotational value
			//owner->SetRotation((Float3(leapHand.palmNormal()) + Float3(1.0f)) * (90.0f / PI));
			currentHand = leapHand.id();
			hand = leapHand;
			handFound = true;
			break;
		}
	}
	if (!handFound)
	{//Worce case go back to 0,0,0
		owner->SetPosition(Float3::Lerp(owner->GetPosition(), Float3(0.0f), timeDelta));
		//owner->SetRotation(Float3::Lerp(owner->GetRotation(), Float3(0.0f), timeDelta));
	}
}

PlayerControler * PlayerControler::GetInstance()
{
	return instance;
}

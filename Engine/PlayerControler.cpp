#include "PlayerControler.h"
#include "timerclass.h"
#include "Collider.h"

PlayerControler* PlayerControler::instance = 0;


PlayerControler::PlayerControler(float maxEnergey, float maxHP)
	: hpLossPerHit(25.0f)
	, energeyLossPerSecond(100.0f)
	, restingPosition(0.0f,0.0f,5.0f)
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

	rotationOffset = owner->GetRotation();

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
		owner->SetPosition(Float3(leapHand.palmPosition())*leapToWorldScale + leapWorldOffset + restingPosition);
		Vector direction = leapHand.direction();
		owner->SetRotation((Float3(direction.pitch(),direction.yaw(), -leapHand.palmNormal().roll())*RAD_TO_DEG) + rotationOffset);
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

int PlayerControler::GetCurrentHand()
{
	return currentHand;
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
			Vector direction = leapHand.direction();
			owner->SetRotation((Float3(direction.pitch(), direction.yaw(), -leapHand.palmNormal().roll())*RAD_TO_DEG) + rotationOffset);
			currentHand = leapHand.id();
			hand = leapHand;
			handFound = true;
			break;
		}
	}
	if (!handFound)
	{//Worce case go back to 0,0,0
		owner->SetPosition(Float3::Lerp(owner->GetPosition(), restingPosition, timeDelta));
		owner->SetRotation(Float3::Lerp(owner->GetRotation(), rotationOffset, timeDelta));
	}
}

PlayerControler * PlayerControler::GetInstance()
{
	return instance;
}

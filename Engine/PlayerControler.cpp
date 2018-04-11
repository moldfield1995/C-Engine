#include "PlayerControler.h"
#include "timerclass.h"

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
	
	//Hand Setup
	FindHand(inputClass, 1.0f);

	//UI Setup

	//Shot Setup

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
		//Takes normal facing directon and translates it to rotational value
		owner->SetRotation((Float3(leapHand.palmNormal()) + Float3(1.0f)) * (90.0f / PI));
	}
	else
	{//Attempt to find a new hand
		FindHand(inputClass, timeDelta);
	}
	//End Position Setting


}

void PlayerControler::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void PlayerControler::Destroy()
{
}

bool PlayerControler::OnCollishon(const GameObject * other)
{

	return true;
}

void PlayerControler::FindHand(InputClass * input, float timeDelta)
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
			owner->SetRotation((Float3(leapHand.palmNormal()) + Float3(1.0f)) * (90.0f / PI));
			currentHand = leapHand.id();
			handFound = true;
			break;
		}
	}
	if (!handFound)
	{//Worce case go back to 0,0,0
		owner->SetPosition(Float3::Lerp(owner->GetPosition(), Float3(0.0f), timeDelta));
		owner->SetRotation(Float3::Lerp(owner->GetRotation(), Float3(0.0f), timeDelta));
	}
}

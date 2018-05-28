#include "PlayerControler.h"
#include "timerclass.h"
#include "Collider.h"
#include "UIText.h"
#include "UIMannager.h"
#include "GameOverScreen.h"
#include "ShotManager.h"

PlayerControler* PlayerControler::instance = 0;


PlayerControler::PlayerControler(float maxEnergey, float maxHP, PlayerUI *playerUI, ShotManager* shotManager)
	: hpLossPerHit(10.0f)
	, energeyLossPerSecond(100.0f)
	, restingPosition(0.0f,0.0f,5.0f)
	, maxEnergey(maxEnergey)
	, maxHP(maxHP)
{
	currentEnergey = 0.0f;
	currentHP = maxHP;
	this->playerUI = playerUI;
	this->shotManager = shotManager;
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

	if (CheckSuper(leapHand))
	{
		if (!superActiveLastFrame)
		{
			shotManager->SetSuperState(true);
			superActiveLastFrame = true;
		}
		if (currentEnergey <= 0.0f)
		{
			//Dose not set superActiveLastFrame as
			//state would flipflop every frame
			currentEnergey = 0.0f;
			shotManager->SetSuperState(false);
		}
		else
			currentEnergey -= energeyLossPerSecond * timeDelta;
	}
	else
	{
		if (superActiveLastFrame)
		{
			shotManager->SetSuperState(false);
			superActiveLastFrame = false;
		}
		currentEnergey += 2.0f * timeDelta;
		if (currentEnergey > maxEnergey)
			currentEnergey = maxEnergey;
	}


	playerUI->SetSliders(currentHP, currentEnergey);

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
		if (currentEnergey >= hpLossPerHit)
			currentEnergey -= hpLossPerHit;
		else
			currentHP -= hpLossPerHit;
		//Play sound
		if (currentHP <= 0.0f)
		{//GameOver
			GameOverScreen::GetInstance()->DesplayGameOver();
			SetOwnersKill(true);
			playerUI->PlayerDied();
		}
	}
	return true;
}



int PlayerControler::GetCurrentHand()
{
	return currentHand;
}


void PlayerControler::AddHp(float value)
{
	currentHP += value;
	if (currentHP > maxHP)
		currentHP = maxHP;
	else if (currentHP <= 0.0f)
	{//GameOver
		GameOverScreen::GetInstance()->DesplayGameOver();
		SetOwnersKill(true);
		playerUI->PlayerDied();
	}
}

void PlayerControler::AddEnergey(float value)
{
	currentEnergey += value;
	if (currentEnergey > maxEnergey)
		currentEnergey = maxEnergey;
	else if (currentEnergey < 0)
		currentEnergey = 0;
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

bool PlayerControler::CheckSuper(Hand &hand)
{
	//Check to see if the provided hand exsits
	//If not we assume that super is inactive
	if (!hand.isValid())
		return false;

	//int validFingersRetracted = 0;
	FingerList fingers = hand.fingers();
	for each (Finger finger in fingers)
	{
		if (finger.type() == Finger::TYPE_THUMB)//(finger.type() == Finger::TYPE_MIDDLE || finger.type() == Finger::TYPE_RING)
		{
			if (!finger.isExtended())
			{
				//validFingersRetracted++;
				//if (validFingersRetracted == 2)
				return true;
			}
			else
				return false;
		}
	}
	return false;
}

PlayerControler * PlayerControler::GetInstance()
{
	return instance;
}

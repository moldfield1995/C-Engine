#include "ShotManager.h"
#include "CapsuleCollider.h"
#include "SphereCollider.h"
#include "timerclass.h"
#include "PlayerControler.h"


ShotManager::ShotManager(GameObject* ShotPrefab)
	: shotInterval(0.75f)
	, superInterval(0.1f)
	, shotOffset(5.0f)
	, shotSpeed(100.0f)
{
	shotPrefab = ShotPrefab;
	superActive = false;
}


ShotManager::~ShotManager()
{
}

void ShotManager::Initalize()
{
	storedShots = std::vector<ShotComponet*>();
	activeShots = std::vector<GameObject*>();
	CreateShots(5);
	timeToNextShot = 0.0f;
}

void ShotManager::Update()
{
	timeToNextShot += TimerClass::GetInstance()->GetFrameTime();
	for (int i = activeShots.size() - 1; i >= 0; i--)
	{
		activeShots[i]->Update();
		if (!activeShots[i]->IsAlive())
		{
			ShotComponet* shot = activeShots[i]->GetComponent<ShotComponet>();
			activeShots.erase(activeShots.begin() +i);
			shot->Reset();
			storedShots.push_back(shot);
		}
	}

	if (timeToNextShot >= shotInterval || (superActive && timeToNextShot >= superInterval))
	{
		Shoot();
		timeToNextShot = 0.0f;
	}
}

void ShotManager::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
	for each (GameObject* go in activeShots)
	{
		go->Render(deviceContext, worldMatrix, viewMatrix, projectionMatrix, frustume, light, camera);
	}
}

void ShotManager::Destroy()
{
	for each (GameObject* go in activeShots)
	{
		go->Destroy();
		delete go;
	}
	for each (ShotComponet* shot in storedShots)
	{
		//Get the GameObject and destroys it and all componets on it
		GameObject* go = shot->GetOwner();
		go->Destroy();
		delete go;
	}
}

void ShotManager::SetSuperState(bool value)
{
	superActive = value;
}


void ShotManager::Shoot()
{
	if (storedShots.size() == 0)
		CreateShots(5);
	ShotComponet* shot = storedShots[storedShots.size() - 1];
	storedShots.pop_back();
	//SetUp shot
	int currentHand = PlayerControler::GetInstance()->GetCurrentHand();
	Leap::Hand hand = InputClass::GetInstance()->GetLeapFrame().hand(currentHand);
	if(!hand.isValid())//We have no Hand to get data from
		shot->Shoot(owner->GetPosition() + (Float3(0.0f,0.0f,1.0f)* shotOffset), Float3(0.0f, 0.0f, 1.0f)*shotSpeed);
	else
	{
		Leap::Vector direction = hand.direction();
		Float3 rotation = (Float3(direction.pitch(), direction.yaw(), -hand.palmNormal().roll())*RAD_TO_DEG);
		Float3 shotVelosity = Float3(direction.x, direction.y, -direction.z);
		shot->Shoot(owner->GetPosition() + (shotVelosity* shotOffset), shotVelosity*shotSpeed);
	}


	activeShots.push_back(shot->GetOwner());
}

void ShotManager::CreateShots(int amount)
{
	for (int i = amount; i >= 0; i--)
	{
		GameObject* go = new GameObject(shotPrefab);
		go->AddComponet(new SphereCollider(1.0f, true, CollisionLayer::Shot));
		ShotComponet* shotComponent = new ShotComponet();
		go->AddComponet(shotComponent);
		storedShots.push_back(shotComponent);
	}
}

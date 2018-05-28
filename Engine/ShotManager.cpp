#include "ShotManager.h"
#include "CapsuleCollider.h"
#include "SphereCollider.h"
#include "timerclass.h"
#include "PlayerControler.h"

ShotManager* ShotManager::instance = 0;

ShotManager::ShotManager(GameObject* ShotPrefab)
	: shotInterval(0.5f)
	, superInterval(0.1f)
	, shotOffset(5.0f)
	, shotSpeed(100.0f)
{
	shotPrefab = ShotPrefab;
	superActive = false;
	multiShotActive = false;
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
	instance = this;
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
			activeShots.erase(activeShots.begin() + i);
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

void ShotManager::SetMultyShot(bool value)
{
	multiShotActive = value;
}


void ShotManager::Shoot()
{
	if (storedShots.size() <= 3)
		CreateShots(5);
	//SetUp shot
	int currentHand = PlayerControler::GetInstance()->GetCurrentHand();
	Leap::Hand hand = InputClass::GetInstance()->GetLeapFrame().hand(currentHand);
	if (!hand.isValid())//We have no Hand to get data from
	{
		SpawnShot(owner->GetPosition() + (Float3(0.0f, 0.0f, 1.0f)* shotOffset), Float3(0.0f, 0.0f, 1.0f)*shotSpeed);
		if (multiShotActive)
		{
			SpawnShot(owner->GetPosition() + (Float3(0.0f, 0.0f, 1.0f)* shotOffset), Float3(0.1f, 0.0f, 0.9f)*shotSpeed);
			SpawnShot(owner->GetPosition() + (Float3(0.0f, 0.0f, 1.0f)* shotOffset), Float3(-0.1f, 0.0f, 0.9f)*shotSpeed);
		}
	}
	else
	{
		Leap::Vector direction = hand.direction();
		Float3 rotation = (Float3(direction.pitch(), direction.yaw(), -hand.palmNormal().roll()));
		Float3 shotVelosity = Float3(direction.x, direction.y, -direction.z);
		SpawnShot(owner->GetPosition() + (shotVelosity* shotOffset), shotVelosity*shotSpeed);
		if (multiShotActive)
		{
			float offsetRot = 10.0f*DEG_TO_RAD;
			float yMovment, xMovment;
			//shot left
			XMVECTOR queturnionLeftRight = XMQuaternionRotationRollPitchYaw(-rotation.X, rotation.Y + (10.0f*DEG_TO_RAD), rotation.Z);
			XMVECTOR shotDirection = XMVectorSet(0.0f, 0.0f, 1.0f, 1.0f);
			XMVECTOR rotatedVector = XMVector3Rotate(shotDirection, queturnionLeftRight);
			{//handells roll movment for multi shots
				float rollRotationDegrees = rotation.Z*RAD_TO_DEG;

				float xRotationMovment = XMVectorGetX(rotatedVector) - direction.x;
				if (rollRotationDegrees <= 90.0f)
				{
					yMovment = xRotationMovment * (rollRotationDegrees / 90.0f);
					xMovment = xRotationMovment *  ((rollRotationDegrees / 90.0f)-1.0f);
				}
				else if (rollRotationDegrees <= 180.0f)
				{
					rollRotationDegrees -= 90.0f;
					yMovment = xRotationMovment * (1.0f- (rollRotationDegrees / 90.0f));
					xMovment = xRotationMovment * (rollRotationDegrees / 90.0f);
				}
				else if (rollRotationDegrees <= 270.0f)
				{
					rollRotationDegrees -= 180.0f;
					yMovment = xRotationMovment * (rollRotationDegrees / 90.0f);
					xMovment = xRotationMovment * ((rollRotationDegrees / 90.0f)-1.0f);
				}
				else if (rollRotationDegrees <= 360.0f)
				{
					rollRotationDegrees -= 270.0f;
					yMovment = xRotationMovment * (1.0f - (rollRotationDegrees / 90.0f));
					xMovment = xRotationMovment * (rollRotationDegrees / 90.0f);
				}
			}
			shotVelosity = Float3(direction.x + xMovment, XMVectorGetY(rotatedVector)+ yMovment, XMVectorGetZ(rotatedVector)).Normalize();
			SpawnShot(owner->GetPosition() + (shotVelosity* shotOffset), shotVelosity*shotSpeed);
			//shot right
			queturnionLeftRight = XMQuaternionRotationRollPitchYaw(-rotation.X, rotation.Y + (-10.0f*DEG_TO_RAD), rotation.Z);
			rotatedVector = XMVector3Rotate(shotDirection, queturnionLeftRight);
			{//handells roll movment for multi shots
				float rollRotationDegrees = rotation.Z*RAD_TO_DEG;

				float xRotationMovment = XMVectorGetX(rotatedVector) - direction.x;
				if (rollRotationDegrees <= 90.0f)
				{
					yMovment = xRotationMovment * (rollRotationDegrees / 90.0f);
					xMovment = xRotationMovment * ((rollRotationDegrees / 90.0f) - 1.0f);
				}
				else if (rollRotationDegrees <= 180.0f)
				{
					rollRotationDegrees -= 90.0f;
					yMovment = xRotationMovment * (1.0f - (rollRotationDegrees / 90.0f));
					xMovment = xRotationMovment * (rollRotationDegrees / 90.0f);
				}
				else if (rollRotationDegrees <= 270.0f)
				{
					rollRotationDegrees -= 180.0f;
					yMovment = xRotationMovment * (rollRotationDegrees / 90.0f);
					xMovment = xRotationMovment * ((rollRotationDegrees / 90.0f) - 1.0f);
				}
				else if (rollRotationDegrees <= 360.0f)
				{
					rollRotationDegrees -= 270.0f;
					yMovment = xRotationMovment * (1.0f - (rollRotationDegrees / 90.0f));
					xMovment = xRotationMovment * (rollRotationDegrees / 90.0f);
				}
			}

			shotVelosity = Float3(direction.x + xMovment, XMVectorGetY(rotatedVector) + yMovment, XMVectorGetZ(rotatedVector)).Normalize();
			SpawnShot(owner->GetPosition() + (shotVelosity* shotOffset), shotVelosity*shotSpeed);
		}
	}


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

void ShotManager::SpawnShot(Float3 position, Float3 velocity)
{
	ShotComponet* shot = storedShots[storedShots.size() - 1];
	storedShots.pop_back();
	shot->Shoot(position, velocity);
	activeShots.push_back(shot->GetOwner());
}

ShotManager * ShotManager::GetInstance()
{
	return instance;
}

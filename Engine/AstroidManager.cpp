#include "AstroidManager.h"
#include "GameObject.h"
#include "BasicMeshHitbox.h"
#include "Utills.h"
#include "timerclass.h"

AstroidManager::AstroidManager(GameObject* prefab)
	: minSpawnAstroid (0.5f)
	, maxSpawnAstroid(1.5f)
	, minPosition(-30.0f,-10.0f,400.0f)
	, maxPosition(30.0f,30.0f,400.0f)
	, astroidVelosity(0.0f,0.0f,-25.0f)
{
	prefabAstroid = prefab;
}


AstroidManager::~AstroidManager()
{
}

void AstroidManager::Initalize()
{
	storedAstroids = std::vector<AstroidComponet*>();
	activeAstroids = std::vector<GameObject*>();
	nextAstroid = Utills::Lerp(minSpawnAstroid,maxSpawnAstroid,Utills::RandomFloat());
	CreateAstroids(5);
}

void AstroidManager::Update()
{
	nextAstroid -= TimerClass::GetInstance()->GetFrameTime();
	for (int i = activeAstroids.size() - 1; i >= 0; i--)
	{
		activeAstroids[i]->Update();
		if (!activeAstroids[i]->IsAlive())
		{
			AstroidComponet* astroid = activeAstroids[i]->GetComponent<AstroidComponet>();
			activeAstroids.erase(activeAstroids.begin() + i);
			astroid->Reset();
			storedAstroids.push_back(astroid);
		}
	}

	if (nextAstroid <= 0.0f)
	{
		LaunchAstroid();
		nextAstroid = Utills::Lerp(minSpawnAstroid, maxSpawnAstroid, Utills::RandomFloat());
	}

}

void AstroidManager::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
	for each (GameObject* go in activeAstroids)
	{
		go->Render(deviceContext, worldMatrix, viewMatrix, projectionMatrix, frustume, light, camera);
	}
}

void AstroidManager::Destroy()
{
	for each (GameObject* go in activeAstroids)
	{
		go->Destroy();
		delete go;
	}
	for each (AstroidComponet* shot in storedAstroids)
	{
		//Get the GameObject and destroys it and all componets on it
		GameObject* go = shot->GetOwner();
		go->Destroy();
		delete go;
	}
}


void AstroidManager::CreateAstroids(int amount)
{
	for (int i = amount; i >= 0; i--)
	{
		GameObject* go = new GameObject(prefabAstroid);
		go->AddComponet(new BasicMeshHitbox(true, CollisionLayer::Astroid));
		AstroidComponet* astroid = new AstroidComponet;
		go->AddComponet(astroid);
		storedAstroids.push_back(astroid);
	}

}

void AstroidManager::LaunchAstroid()
{
	if (storedAstroids.size() == 0)
		CreateAstroids(5);
	AstroidComponet* astroid = storedAstroids[storedAstroids.size() - 1];
	storedAstroids.pop_back();
	//SetUp shot
	Float3 Possition = Float3(Utills::Lerp(minPosition.X, maxPosition.X, Utills::RandomFloat()),
		Utills::Lerp(minPosition.Y, maxPosition.Y, Utills::RandomFloat()),
		minPosition.Z);
	astroid->Launch(Possition, astroidVelosity);

	activeAstroids.push_back(astroid->GetOwner());
}

#include "PowerupManager.h"
#include "GameObject.h"
#include "Utills.h"
#include "ModelManager.h"
#include "texturemanagerclass.h"
#include "shadermanagerclass.h"
#include "textureshaderclass.h"
//Powerups
#include "EnergeyPowerup.h"
#include "HealthPowerup.h"
#include "MultiShotPowerup.h"
#include "NegativePowerup.h"
#include "RandomPowerup.h"
#include "ScorePowerup.h"

PowerupManager* PowerupManager::instance = 0;

PowerupManager::PowerupManager(GameObject* powerupPrefab)
	: spawnChanse(0.25f)
	, powerupPrefab(powerupPrefab)
{
	ModelManager* modelManager = ModelManager::GetInstance();
	ID3D11ShaderResourceView* texture = TextureManagerClass::GetInstance()->GetTexture(Utills::ParsString("../Engine/data/textures/IconMap.tga"));
	ID3D11Device* device = D3DClass::GetInstance()->GetDevice();
	Shader* textureShader = ShaderManagerClass::GetInstance()->GetShader<TextureShaderClass>();
	Float3 zeroFloat = Float3(0.0f);
	int modelId;

	modelId = modelManager->AddModle(device, "../Engine/data/Models/HealthIcon.obj");
	healthModel = new GameObject();
	healthModel->Initalize(zeroFloat, zeroFloat, modelManager->GetModel(modelId), texture, textureShader);
	healthModel->SetScale(0.75f);

	modelId = modelManager->AddModle(device, "../Engine/data/Models/EnergeyIcon.obj");
	powerModel = new GameObject();
	powerModel->Initalize(zeroFloat, zeroFloat, modelManager->GetModel(modelId), texture, textureShader);
	powerModel->SetScale(0.75f);

	modelId = modelManager->AddModle(device, "../Engine/data/Models/2xIcon.obj");
	scoreModel = new GameObject();
	scoreModel->Initalize(zeroFloat, zeroFloat, modelManager->GetModel(modelId), texture, textureShader);
	scoreModel->SetScale(0.75f);

	modelId = modelManager->AddModle(device, "../Engine/data/Models/MultshotIcon.obj");
	multishotModel = new GameObject();
	multishotModel->Initalize(zeroFloat, zeroFloat, modelManager->GetModel(modelId), texture, textureShader);
	multishotModel->SetScale(0.75f);

	modelId = modelManager->AddModle(device, "../Engine/data/Models/NegativeIcon.obj");
	negativeModel = new GameObject();
	negativeModel->Initalize(zeroFloat, zeroFloat, modelManager->GetModel(modelId), texture, textureShader);
	negativeModel->SetScale(0.75f);

	modelId = modelManager->AddModle(device, "../Engine/data/Models/RandomIcon.obj");
	randomModel = new GameObject();
	randomModel->Initalize(zeroFloat, zeroFloat, modelManager->GetModel(modelId), texture, textureShader);
	randomModel->SetScale(0.75f);
}


PowerupManager::~PowerupManager()
{
}

void PowerupManager::Initalize()
{
	instance = this;
}

void PowerupManager::Update()
{
	for (int i = GameObjects.size() - 1; i >= 0; i--)
	{
		if (!GameObjects[i]->IsAlive())
		{
			GameObjects[i]->Destroy();
			delete GameObjects[i];
			GameObjects.erase(GameObjects.begin() + i);
		}
		else
			GameObjects[i]->Update();
	}
}

void PowerupManager::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
	for each (GameObject* go in GameObjects)
	{
		go->Render(deviceContext, worldMatrix, viewMatrix, projectionMatrix, frustume, light, camera);
	}
}

void PowerupManager::Destroy()
{
	if (powerupPrefab)
	{
		powerupPrefab->Destroy();
		delete(powerupPrefab);
		powerupPrefab = 0;
	}

	for each (GameObject* go in GameObjects)
	{
		go->Destroy();
		delete go;
	}
	GameObjects.clear();
}

void PowerupManager::SpawnPowerup(Float3 position, Float3 velosity, bool forceSpawn)
{
	float randVal = Utills::RandomFloat();
	if (randVal <= spawnChanse || forceSpawn)
	{
		GameObject *spawnGameobject = new GameObject(powerupPrefab);
		spawnGameobject->SetPosition(position);
		//value between 0-100
		randVal = Utills::RandomFloat();
		randVal *= 100.f;
		if (randVal < 16.6f)
		{//Powerup 1
			spawnGameobject->AddComponet(new EnergeyPowerup(powerModel, velosity));
		}
		else if (randVal < 33.3f)
		{//Powerup 2
			spawnGameobject->AddComponet(new HealthPowerup(healthModel, velosity));
		}
		else if (randVal < 49.99f)
		{//Powerup 3
			spawnGameobject->AddComponet(new MultiShotPowerup(multishotModel, velosity));
		}
		else if (randVal < 66.6f)
		{//Powerup 4
			spawnGameobject->AddComponet(new NegativePowerup(negativeModel, velosity));
		}
		else if (randVal < 83.33f)
		{//Powerup 5
			spawnGameobject->AddComponet(new RandomPowerup(randomModel, velosity));
		}
		else
		{//Powerup 6
			spawnGameobject->AddComponet(new ScorePowerup(scoreModel, velosity));
		}
		GameObjects.push_back(spawnGameobject);
	}
}

PowerupManager * PowerupManager::GetInstance()
{
	return instance;
}



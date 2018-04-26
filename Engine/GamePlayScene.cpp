#include "GamePlayScene.h"
#include "BasicMeshHitbox.h"
#include "PlayerControler.h"
#include "ShotManager.h"
#include "lightshaderclass.h"
#include "textureshaderclass.h"
#include "PlayerUI.h"
#include "ScoreManager.h"
#include "AstroidManager.h"
#include "GameOverScreen.h"

GamePlayScene::GamePlayScene()
{
	m_Camera = 0;
	m_Frustum = 0;
	m_GameObjects = std::vector<GameObject*>();
	m_Light = 0;
	m_UIMannager = 0;
}


GamePlayScene::~GamePlayScene()
{
}

bool GamePlayScene::Initialize()
{
	D3DClass *Direct3D = D3DClass::GetInstance();
	ID3D11Device* device = Direct3D->GetDevice();
	ID3D11DeviceContext* deviceContex = Direct3D->GetDeviceContext();
	TextureManagerClass* textureManager = TextureManagerClass::GetInstance();
	ModelManager* modelManager = ModelManager::GetInstance();
	bool result = true;
	int defaultNormal, modelId, textureID, screenWidth, screenHeight;
	float screenDepth, screenNear;
	Direct3D->GetScreenReserlution(screenWidth, screenHeight);
	Direct3D->GetScreenDepth(screenNear, screenDepth);
	GameObject* gameObject = 0;
	// Create the camera object.
	m_Camera = new CameraClass;
	if (!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera and build the matrices needed for rendering.
	m_Camera->SetPosition(0.0f, 0.0f, -10.0f);
	m_Camera->Render();
	m_Camera->RenderBaseViewMatrix();
	m_Camera->SetActiveCamera();
	// Create the light object.
	m_Light = new LightClass;
	if (!m_Light)
	{
		return false;
	}

	// Initialize the light object.
	m_Light->SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetAmbientColor(0.5f, 0.5f, 0.5f, 1.0f);
	m_Light->SetSpecularColor(0.1f, 0.1f, 0.1f, 0.1f);
	m_Light->SetDirection(0.0f, -1.0f, 0.0f);

	// Create the frustum object.
	m_Frustum = new FrustumClass;
	if (!m_Frustum)
	{
		return false;
	}

	// Initialize the frustum object.
	m_Frustum->Initialize(screenDepth);

	m_UIMannager = new UIMannager();
	m_UIMannager->Initalize(screenWidth, screenHeight);

	Shader* shader = ShaderManagerClass::GetInstance()->GetShader<TextureShaderClass>();
	//Start Creating Player
	modelId = modelManager->AddModle(device, "../Engine/data/LizReddington/Ship1.obj");
	textureID = textureManager->LoadTexture(device, deviceContex, "../Engine/data/LizReddington/Ship1Uved.tga");
	PlayerUI* playerUI = new PlayerUI(100.0f, 100.0f);

	gameObject = new GameObject();
	gameObject->Initalize(Float3(0.0f, 0.0f, 0.0f), Float3(0.0f,180.0f,0.0f), modelManager->GetModel(modelId), textureManager->GetTexture(textureID), shader);
	gameObject->SetScale(Float3(0.01f, 0.01f, 0.01f));
	gameObject->AddComponet(new PlayerControler(100.0f, 100.0f,playerUI));
	gameObject->AddComponet(new BasicMeshHitbox());


	{//Creates the shot manager 
		modelId = modelManager->AddModle(device, "../Engine/data/Models/Sphere.obj");
		textureID = textureManager->LoadTexture(device, deviceContex, "../Engine/data/textures/Default.tga");

		GameObject* shot = new GameObject();
		shot->Initalize(Float3(0.0f, 0.0f, 0.0f), Float3(90.0f, 0.0f, 0.0f), modelManager->GetModel(modelId), textureManager->GetTexture(textureID), shader);
		gameObject->AddComponet(new ShotManager(shot));
	}
	m_GameObjects.push_back(gameObject);
	//END Creating Player

	//Creating UI Objects
	gameObject = new GameObject();
	gameObject->Initalize(Float3(0.0f, 0.0f, 0.0f), Float3(0.0f, 0.0f, 0.0f), 0, 0, 0);
	gameObject->AddComponet(playerUI);
	gameObject->AddComponet(new ScoreManager);
	m_GameObjects.push_back(gameObject);
	//End Creating UI Objects

	//Creating Astroid Manager
	gameObject = new GameObject();
	gameObject->Initalize(Float3(0.0f, 0.0f, 0.0f), Float3(0.0f, 0.0f, 0.0f), 0, 0, 0);
	{//Creates Astroid Manager
		modelId = modelManager->AddModle(device, "../Engine/data/GooglePoly/Asteroid_One.obj");
		textureID = textureManager->LoadTexture(device, deviceContex, "../Engine/data/GooglePoly/Asteroids_BaseColor.tga");

		GameObject* astroid = new GameObject();
		astroid->Initalize(Float3(0.0f, 0.0f, 0.0f), Float3(90.0f, 0.0f, 0.0f), modelManager->GetModel(modelId), textureManager->GetTexture(textureID), shader);
		gameObject->AddComponet(new AstroidManager(astroid));
	}

	m_GameObjects.push_back(gameObject);
	//End Creating Astroid Manager

	gameObject = new GameObject();
	gameObject->Initalize(Float3(0.0f, 0.0f, 0.0f), Float3(0.0f, 0.0f, 0.0f), 0, 0, 0);
	gameObject->AddComponet(new GameOverScreen(this));
	m_GameObjects.push_back(gameObject);

	return true;
}

void GamePlayScene::Shutdown()
{
	for each (GameObject* go in m_GameObjects)
	{
		go->Destroy();
		delete go;
		go = 0;
	}
	if (m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}
	if (m_Frustum)
	{
		delete m_Frustum;
		m_Frustum = 0;
	}
	if (m_Light)
	{
		delete m_Light;
		m_Light = 0;
	}
	if (m_UIMannager)
	{
		m_UIMannager->Destroy();
		delete m_UIMannager;
		m_UIMannager = 0;
	}
}

bool GamePlayScene::Frame()
{
	for (int i = m_GameObjects.size()-1; i >= 0; i--)
	{
		if (!m_GameObjects[i]->IsAlive())
		{
			m_GameObjects[i]->Destroy();
			delete m_GameObjects[i];
			m_GameObjects.erase(m_GameObjects.begin() + i);
		}
		else
			m_GameObjects[i]->Update();
	}
	m_UIMannager->Update();
	Render();
	return true;
}



bool GamePlayScene::Render()
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix, baceViewMatrix, orthoMatrix;
	D3DClass* Direct3D = D3DClass::GetInstance();
	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	Direct3D->GetWorldMatrix(worldMatrix);
	m_Camera->GetViewMatrix(viewMatrix);
	Direct3D->GetProjectionMatrix(projectionMatrix);
	m_Camera->GetBaseViewMatrix(baceViewMatrix);
	Direct3D->GetOrthoMatrix(orthoMatrix);

	// Construct the frustum.
	m_Frustum->ConstructFrustum(projectionMatrix, viewMatrix);

	// Clear the buffers to begin the scene.
	Direct3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);
	ID3D11DeviceContext* context = Direct3D->GetDeviceContext();
	for each (GameObject* gameobject in m_GameObjects)
	{
		gameobject->Render(context, worldMatrix, viewMatrix, projectionMatrix, m_Frustum, m_Light, *m_Camera);
	}

	m_UIMannager->Render(context, worldMatrix, baceViewMatrix, orthoMatrix);

	//End Render
	Direct3D->EndScene();
	return true;
}

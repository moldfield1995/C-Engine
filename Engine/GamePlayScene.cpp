#include "GamePlayScene.h"
#include "BasicMeshHitbox.h"
#include "PlayerControler.h"
#include "ShotManager.h"




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

bool GamePlayScene::Initialize(D3DClass* Direct3D, int screenWidth, int screenHeight, float screenDepth, TextureManagerClass* textureManager, ModelManager* modelManager, AudioManager* audioManager)
{
	ID3D11Device* device = Direct3D->GetDevice();
	ID3D11DeviceContext* deviceContex = Direct3D->GetDeviceContext();
	bool result = true;
	int defaultNormal, modelId, textureID;
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
	m_Light->SetAmbientColor(0.5f, 0.5f, 0.5f, 0.5f);
	m_Light->SetSpecularColor(0.1f, 0.1f, 0.1f, 0.1f);
	m_Light->SetDirection(0.5f, -1.0f, -0.5f);

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

	modelId = modelManager->AddModle(device, "../Engine/data/LizReddington/Ship1.obj");
	textureID = textureManager->LoadTexture(device, deviceContex, "../Engine/data/LizReddington/Ship1Uved.tga");

	gameObject = new GameObject();
	gameObject->Initalize(Float3(0.0f, 0.0f, 0.0f), Float3(0.0f,180.0f,0.0f), modelManager->GetModel(modelId), textureManager->GetTexture(textureID), shader);
	gameObject->SetScale(Float3(0.01f, 0.01f, 0.01f));
	gameObject->AddComponet(new PlayerControler(100.0f, 100.0f));
	gameObject->AddComponet(new BasicMeshHitbox());


	{//Creates the shot manager 
		modelId = modelManager->AddModle(device, "../Engine/data/Models/Sphere.obj");
		textureID = textureManager->LoadTexture(device, deviceContex, "../Engine/data/textures/Default.tga");

		GameObject* shot = new GameObject();
		shot->Initalize(Float3(0.0f, 0.0f, 0.0f), Float3(90.0f, 0.0f, 0.0f), modelManager->GetModel(modelId), textureManager->GetTexture(textureID), shader);
		gameObject->AddComponet(new ShotManager(shot));
	}
	m_GameObjects.push_back(gameObject);



	return true;
}

void GamePlayScene::Shutdown()
{
}

bool GamePlayScene::Frame(D3DClass* Direct3D, InputClass* Input, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager,
	ModelManager* modelManager, float frameTime, int fps, AudioManager* audioManager)
{
	for each (GameObject* gameobject in m_GameObjects)
	{
		gameobject->Update();
	}
	m_UIMannager->Update();
	Render(Direct3D, ShaderManager, TextureManager, modelManager);
	return true;
}

void GamePlayScene::HandleMovementInput(InputClass* Input, float frameTime)
{
}

bool GamePlayScene::Render(D3DClass* Direct3D, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager, ModelManager* modelManager)
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix, baceViewMatrix, orthoMatrix;
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

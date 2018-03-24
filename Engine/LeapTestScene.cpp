#include "LeapTestScene.h"
#include "HandDesplay.h"
#include "DebugDesplay.h"

LeapTestScene::LeapTestScene()
{
	m_Camera = 0;
	m_Frustum = 0;
	m_GameObjects = std::vector<GameObject*>();
	m_Light = 0;
	m_UIMannager = 0;
}


LeapTestScene::~LeapTestScene()
{
}

bool LeapTestScene::Initialize(D3DClass* Direct3D, int screenWidth, int screenHeight, float screenDepth, TextureManagerClass* textureManager, ModelManager* modelManager, AudioManager* audioManager)
{
	ID3D11Device* device = Direct3D->GetDevice();
	bool result = true;

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
	m_Light->SetAmbientColor(0.1f, 0.1f, 0.1f, 0.1f);
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

	if(!textureManager->TextureLoaded(404))
		result = textureManager->LoadTexture(device, Direct3D->GetDeviceContext(), "../Engine/data/textures/debug.tga", 404);
	if(!result)
		return false;
	if (!modelManager->ModelLoaded(ModelManager::parsString("../Engine/data/T1Assets/cubeS.txt")))
		modelManager->AddModle(device, "../Engine/data/T1Assets/cubeS.txt", ModelManager::parsString("../Engine/data/T1Assets/cubeS.txt"), HitBoxType::Point, float3());
	Shader* shader = ShaderManagerClass::GetInstance()->GetShader<LightShader>();

	GameObject* gameObject = new GameObject();
	gameObject->Initalize(float3(), float3(), modelManager->GetModel(ModelManager::parsString("../Engine/data/T1Assets/cubeS.txt")), textureManager->GetTexture(404), shader);
	
	gameObject->AddComponet(new HandDesplay());
	gameObject->AddComponet(new DebugDesplay());
	m_GameObjects.push_back(gameObject);


	return true;
}

void LeapTestScene::Shutdown()
{
}

bool LeapTestScene::Frame(D3DClass* Direct3D, InputClass* Input, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager,
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

void LeapTestScene::HandleMovementInput(InputClass* Input, float frameTime)
{
}

bool LeapTestScene::Render(D3DClass* Direct3D, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager, ModelManager* modelManager)
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

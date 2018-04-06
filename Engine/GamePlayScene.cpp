#include "GamePlayScene.h"



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





	return false;
}

void GamePlayScene::Shutdown()
{
}

bool GamePlayScene::Frame(D3DClass* Direct3D, InputClass* Input, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager,
	ModelManager* modelManager, float frameTime, int fps, AudioManager* audioManager)
{
	return false;
}

void GamePlayScene::HandleMovementInput(InputClass* Input, float frameTime)
{
}

bool GamePlayScene::Render(D3DClass* Direct3D, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager, ModelManager* modelManager)
{
	return false;
}

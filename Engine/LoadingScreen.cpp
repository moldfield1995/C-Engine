#include "LoadingScreen.h"



LoadingScreen::LoadingScreen()
{
	m_Camera = 0;
	m_running = true;
}

LoadingScreen::LoadingScreen(const LoadingScreen &)
{
}


LoadingScreen::~LoadingScreen()
{
}

bool LoadingScreen::Initialize(D3DClass* Direct3D, int screenWidth, int screenHeight, float screenDepth, TextureManagerClass* textureManager, ModelManager* modelManager, AudioManager* audioManager)
{
	float scaleY = (float)screenHeight / 720.0f;
	float scaleX = (float)screenWidth / 1280.0f;
	//m_loadingBar= new ImageElement;
	//m_loadingBar->Initialize(Direct3D->GetDevice(), Direct3D->GetDeviceContext(), screenWidth, screenHeight, 0, 100 * scaleY, "../Engine/data/minimap/LoadingBar.tga", 0, screenHeight - (300 * scaleY));
	m_Camera = new CameraClass;
	m_Camera->SetPosition(0.0f, 0.0f, -10.0f);
	m_Camera->Render();
	m_Camera->RenderBaseViewMatrix();
	m_scaleX = scaleX;
	return false;
}

void LoadingScreen::Shutdown()
{
	//if (m_loadingBar)
	//{
	//	m_loadingBar->Shutdown();
	//	delete m_loadingBar;
	//	m_loadingBar = 0;
	//}
	if (m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	if (m_level)
	{
		delete m_Camera;
		m_Camera = 0;
	}
}

bool LoadingScreen::Frame(D3DClass* Direct3D, InputClass* Input, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager,
	ModelManager* modelManager, float frameTime, int fps, AudioManager* audioManager)
{
	while (m_running)
	{
		//int sizeX, sizeY,loading;
		//m_loadingBar->GetSize(sizeX, sizeY);
		//loading = m_level->GetLoadingLevel();
		//if (loading > 0)
		//{
		//	float levelload = (float)loading / 100;
		//	sizeX = 1980 * m_scaleX * levelload;
		//	m_loadingBar->SetSize(sizeX, sizeY);
		//}
		//Render(Direct3D, ShaderManager, TextureManager, modelManager);
	}
	return true;
}

void LoadingScreen::SetRunning(bool run)
{
	m_running = run;
}

void LoadingScreen::SetLevel(GameState * level)
{
	m_level = level;
}

void LoadingScreen::HandleMovementInput(InputClass* Input, float frameTime)
{
}

bool LoadingScreen::Render(D3DClass* Direct3D, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager, ModelManager* modelManager)
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix, baseViewMatrix, orthoMatrix;
	Direct3D->GetWorldMatrix(worldMatrix);
	m_Camera->GetViewMatrix(viewMatrix);
	Direct3D->GetProjectionMatrix(projectionMatrix);
	m_Camera->GetBaseViewMatrix(baseViewMatrix);
	Direct3D->GetOrthoMatrix(orthoMatrix);
	Direct3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);
	Direct3D->TurnZBufferOff();
	Direct3D->EnableAlphaBlending();
	Direct3D->EnableAlphaToCoverageBlending();
	//if (!m_loadingBar->Render(Direct3D->GetDeviceContext()))
	//	return false;
	//if (!ShaderManager->RenderTextureShader(Direct3D->GetDeviceContext(), m_loadingBar->GetIndexCount(), worldMatrix, viewMatrix,
	//	orthoMatrix, m_loadingBar->GetTexture()))
	//	return false;
	Direct3D->EndScene();
	return true;
}

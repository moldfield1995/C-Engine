#include "SplashScreen.h"


SplashScreen::SplashScreen()
{
	m_Camera = 0;
	//m_Logo = 0;
	//m_Text = 0;
	m_currentState = StateSwich::Continue;
}

SplashScreen::SplashScreen(const SplashScreen&)
{
}

SplashScreen::~SplashScreen()
{
}
bool SplashScreen::Initialize(D3DClass* Direct3D, int screenWidth, int screenHeight, float screenDepth, TextureManagerClass* textureManager, ModelManager* modelManager, AudioManager* audioManager)
{
	//m_Logo = new ImageElement;
	//m_Logo->Initialize(Direct3D->GetDevice(), Direct3D->GetDeviceContext(), screenWidth, screenHeight, 1175, 498, "../Engine/data/minimap/Avatar.tga", 0, (screenHeight / 2) - (498 / 2));
	//m_Text = new ImageElement;
	//m_Text->Initialize(Direct3D->GetDevice(), Direct3D->GetDeviceContext(), screenWidth, screenHeight, 600, 200, "../Engine/data/minimap/text.tga",-600, (screenHeight / 2) - 100 );
	m_Camera = new CameraClass;
	m_Camera->SetPosition(0.0f, 0.0f, -10.0f);
	m_Camera->Render();
	m_Camera->RenderBaseViewMatrix();
	m_ScreenHight = screenHeight;
	m_ScreenWidth = screenWidth;
	return true;
}

void SplashScreen::Shutdown()
{
}

bool SplashScreen::Frame(D3DClass* Direct3D, InputClass* Input, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager,
	ModelManager* modelManager, float frameTime, int fps, AudioManager* audioManager)
{
	int posX, posY;
	//m_Logo->GetPosition(posX, posY);
	//posX++;
	//m_Logo->SetPosition(posX, posY);
	//m_Text->GetPosition(posX, posY);
	posX++;
	//m_Text->SetPosition(posX, posY);
	if (posX > m_ScreenWidth/2 - 300)
		m_currentState = StateSwich::Next;
	return Render(Direct3D, ShaderManager, TextureManager, modelManager);
}

void SplashScreen::HandleMovementInput(InputClass* Input, float frameTime)
{
}

bool SplashScreen::Render(D3DClass* Direct3D, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager, ModelManager* modelManager)
{
	//scaling eddit the yaw
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
	//if (!m_Logo->Render(Direct3D->GetDeviceContext()))
	//	return false;
	//if (!ShaderManager->RenderTextureShader(Direct3D->GetDeviceContext(), m_Logo->GetIndexCount(), worldMatrix, viewMatrix,
	//	orthoMatrix, m_Logo->GetTexture()))
	//	return false;
	//if (!m_Text->Render(Direct3D->GetDeviceContext()))
	//	return false;
	//if (!ShaderManager->RenderTextureShader(Direct3D->GetDeviceContext(), m_Text->GetIndexCount(), worldMatrix, viewMatrix,
	//	orthoMatrix, m_Text->GetTexture()))
	//	return false;
	Direct3D->EndScene();
	return true;
}

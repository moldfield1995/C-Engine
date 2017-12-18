#include "MainMenu.h"



MainMenu::MainMenu()
{
	m_Logo = 0;
	m_Camera = 0;
	m_Curser = 0;
	m_QuitButton = 0;
	m_StartButton = 0;
}

MainMenu::MainMenu(const MainMenu &)
{
}


MainMenu::~MainMenu()
{
}

bool MainMenu::Initialize(D3DClass* Direct3D, int screenWidth, int screenHeight, float screenDepth, TextureManagerClass* textureManager, ModelManager* modelManager, AudioManager* audioManager)
{
	float scaleY = (float)screenHeight / 720.0f;
	float scaleX = (float)screenWidth / 1280.0f;
	m_Background = new ImageElement;
	m_Background->Initialize(Direct3D->GetDevice(), Direct3D->GetDeviceContext(), screenWidth, screenHeight, 1920* scaleX, 1080*scaleY, "../Engine/data/minimap/Background.tga", 0, 0);
	m_Logo = new ImageElement;
	m_Logo->Initialize(Direct3D->GetDevice(), Direct3D->GetDeviceContext(), screenWidth, screenHeight, 590 * scaleX, 250 * scaleY, "../Engine/data/minimap/Avatar-Half.tga", (screenWidth/2) - ((590/2)*scaleX) , 50 * scaleY);
	m_QuitButton = new ImageElement;
	m_QuitButton->Initialize(Direct3D->GetDevice(), Direct3D->GetDeviceContext(), screenWidth, screenHeight, 300 * scaleX, 150 * scaleY, "../Engine/data/minimap/QuitButton.tga", (screenWidth / 2)+(50*scaleX) , (screenHeight /2));
	m_StartButton = new ImageElement;
	m_StartButton->Initialize(Direct3D->GetDevice(), Direct3D->GetDeviceContext(), screenWidth, screenHeight, 300 * scaleX, 150 * scaleY, "../Engine/data/minimap/StartButton.tga", (screenWidth / 2) - (350*scaleX), (screenHeight / 2));
	m_Curser = new ImageElement;
	m_Curser->Initialize(Direct3D->GetDevice(), Direct3D->GetDeviceContext(), screenWidth, screenHeight, 50 * scaleX, 50 * scaleY, "../Engine/data/minimap/Curser.tga", (screenWidth / 2) , (screenHeight / 2));
	m_Camera = new CameraClass;
	m_Camera->SetPosition(0.0f, 0.0f, -10.0f);
	m_Camera->Render();
	m_Camera->RenderBaseViewMatrix();
	this->screenHight = screenHeight;
	this->screenWidth = screenWidth;
	return true;
}

void MainMenu::Shutdown()
{
}

bool MainMenu::Frame(D3DClass* Direct3D, InputClass* Input, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager,
	ModelManager* modelManager, float frameTime, int fps, AudioManager* audioManager)
{
	HandleMovementInput(Input, frameTime);
	if (Input->MouseButton(0))
		UIHitboxTest();
	return Render(Direct3D,ShaderManager,TextureManager,modelManager);
}

void MainMenu::HandleMovementInput(InputClass* Input, float frameTime)
{
	int mouseX , mouseY;
	int posX , posY;
	Input->GetMouseLocation(mouseX, mouseY);
	m_Curser->GetPosition(posX, posY);
	posX += mouseX;
	posY += mouseY;
	if (posX > screenWidth)
		posX = screenWidth;
	if (posX < 0)
		posX = 0;
	if (posY > screenHight)
		posY = screenHight;
	if (posY < 0)
		posY = 0;
	m_Curser->SetPosition(mouseX + posX, mouseY + posY);
	
}

bool MainMenu::Render(D3DClass* Direct3D, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager, ModelManager* modelManager)
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
	if (!m_Background->Render(Direct3D->GetDeviceContext()))
		return false;
	if (!ShaderManager->RenderTextureShader(Direct3D->GetDeviceContext(), m_Background->GetIndexCount(), worldMatrix, viewMatrix,
		orthoMatrix, m_Background->GetTexture()))
		return false;
	if (!m_Logo->Render(Direct3D->GetDeviceContext()))
		return false;
	if (!ShaderManager->RenderTextureShader(Direct3D->GetDeviceContext(), m_Logo->GetIndexCount(), worldMatrix, viewMatrix,
		orthoMatrix, m_Logo->GetTexture()))
		return false;
	if (!m_QuitButton->Render(Direct3D->GetDeviceContext()))
		return false;
	if (!ShaderManager->RenderTextureShader(Direct3D->GetDeviceContext(), m_QuitButton->GetIndexCount(), worldMatrix, viewMatrix,
		orthoMatrix, m_QuitButton->GetTexture()))
		return false;
	if (!m_StartButton->Render(Direct3D->GetDeviceContext()))
		return false;
	if (!ShaderManager->RenderTextureShader(Direct3D->GetDeviceContext(), m_StartButton->GetIndexCount(), worldMatrix, viewMatrix,
		orthoMatrix, m_StartButton->GetTexture()))
		return false;
	if (!m_Curser->Render(Direct3D->GetDeviceContext()))
		return false;
	if (!ShaderManager->RenderTextureShader(Direct3D->GetDeviceContext(), m_Curser->GetIndexCount(), worldMatrix, viewMatrix,
		orthoMatrix, m_Curser->GetTexture()))
		return false;
	Direct3D->EndScene();
	return true;
}

void MainMenu::UIHitboxTest()
{
	int curserX, curserY;
	int hitposX, hitposY, hitscaleX, hitscaleY;
	m_Curser->GetPosition(curserX, curserY);
	m_StartButton->GetPosition(hitposX, hitposY);
	m_StartButton->GetSize(hitscaleX, hitscaleY);
	if ((curserX > hitposX && curserX <hitposX + hitscaleX) && (curserY >hitposY && curserY < hitposY + hitscaleY))
	{
		m_currentState = StateSwich::Next;
		return;
	}
	m_QuitButton->GetPosition(hitposX, hitposY);
	m_QuitButton->GetSize(hitscaleX, hitscaleY);
	if ((curserX > hitposX && curserX <hitposX + hitscaleX) && (curserY >hitposY && curserY < hitposY + hitscaleY))
	{
		m_currentState = StateSwich::Quit;
		return;
	}
}

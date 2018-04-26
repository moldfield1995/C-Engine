#include "GameOverScreen.h"
#include "UIImage.h"
#include "UIMannager.h"
#include "GameObject.h"
#include "ScoreManager.h"
GameOverScreen* GameOverScreen::instance = 0;

GameOverScreen::GameOverScreen(GameState* gameState)
{
	backgroundImage = 0;
	scoreText = 0;
	resetButton = 0;
	menuButton = 0;
	handCurser = 0;
	gameScene = gameState;
}


GameOverScreen::~GameOverScreen()
{
}

void GameOverScreen::Initalize()
{
	instance = this;
}

void GameOverScreen::Update()
{
}

void GameOverScreen::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void GameOverScreen::Destroy()
{
	if (backgroundImage)
	{
		backgroundImage->Destroy();
		backgroundImage = 0;
	}
	if (scoreText)
	{
		scoreText->Destroy();
		scoreText = 0;
	}
	if (resetButton)
	{
		resetButton->Destroy();
		__unhook(&UIButton::onClickTrigger, resetButton, &GameOverScreen::ResetGame);
		resetButton = 0;
	}
	if (menuButton)
	{
		menuButton->Destroy();
		__unhook(&UIButton::onClickTrigger, menuButton, &GameOverScreen::LoadMainMenu);
		menuButton = 0;
	}
	if (handCurser)
	{
		handCurser = 0;
	}
}

void GameOverScreen::DesplayGameOver()
{
	UIMannager *uiManager = UIMannager::GetInstance();

	backgroundImage = new UIImage("../Engine/data/UI/GameOverBackground.tga", PivotPosition::TopLeft);
	uiManager->AddComponet(backgroundImage);
	scoreText = new UIText(XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f), "Final Score : " + std::to_string(ScoreManager::GetInstance()->GetScore()), PivotPosition::Center);
	scoreText->SetPosition(Float3(-20.0f, -100.0f));
	uiManager->AddComponet(scoreText);
	resetButton = new UIButton("../Engine/data/UI/ResetButton.tga", PivotPosition::Center);
	__hook(&UIButton::onClickTrigger, resetButton, &GameOverScreen::ResetGame);
	resetButton->SetPosition(Float3(0.0f, -50.0f));
	uiManager->AddComponet(resetButton);
	menuButton = new UIButton("../Engine/data/UI/MainMenuButton.aga", PivotPosition::Center);
	__hook(&UIButton::onClickTrigger, menuButton, &GameOverScreen::LoadMainMenu);
	menuButton->SetPosition(Float3(0.0f, 50.0f));
	uiManager->AddComponet(menuButton);
	handCurser = new HandCurser("../Engine/data/UI/Cursor.tga");
	owner->AddComponet(handCurser);
}

GameOverScreen * GameOverScreen::GetInstance()
{
	return instance;
}

void GameOverScreen::ResetGame()
{
	gameScene->SetSwitchState(StateSwich::Reset);
}

void GameOverScreen::LoadMainMenu()
{
	gameScene->SetSwitchState(StateSwich::Next);
}

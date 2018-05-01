#include "MainMenuComp.h"
#include "UIMannager.h"
#include "UIButton.h"


MainMenuComp::MainMenuComp(GameState* gamestate)
{
	m_MainMenu = gamestate;
}


MainMenuComp::~MainMenuComp()
{
}

void MainMenuComp::Initalize()
{
	UIMannager* uiManager = UIMannager::GetInstance();
	UIImage* image = new UIImage("../Engine/data/UI/MainMenuBackground.tga");
	uiManager->AddComponet(image);
	UIButton* button = new UIButton("../Engine/data/UI/PlayButton.tga", PivotPosition::Center);
	__hook(&UIButton::onClickTrigger, button, &MainMenuComp::LoadGame);
	button->SetPosition(Float3(-150.0f, 0.0f));
	uiManager->AddComponet(button);
	button = new UIButton("../Engine/data/UI/QuitButton.tga", PivotPosition::Center);
	__hook(&UIButton::onClickTrigger, button, &MainMenuComp::LoadGame);
	button->SetPosition(Float3(-150.0f, -150.0f));
	uiManager->AddComponet(button);
}

void MainMenuComp::Update()
{
}

void MainMenuComp::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void MainMenuComp::Destroy()
{
	m_MainMenu = 0;
}

void MainMenuComp::LoadGame()
{
	m_MainMenu->SetSwitchState(StateSwich::Next);
}

void MainMenuComp::QuitGame()
{
	m_MainMenu->SetSwitchState(StateSwich::Quit);
}

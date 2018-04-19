#pragma once
#include "Component.h"
#include "UIButton.h"
#include "UIText.h"
#include "HandCurser.h"
#include "GameState.h"

class GameOverScreen :
	public Component
{
public:
	GameOverScreen(GameState* gameState);
	~GameOverScreen();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();

	void DesplayGameOver();

	static GameOverScreen* GetInstance();
private:
	void ResetGame();
	void LoadMainMenu();

	static GameOverScreen *instance;

	UIImage *backgroundImage;
	UIText *scoreText;
	UIButton *resetButton;
	UIButton *menuButton;
	HandCurser *handCurser;
	
	GameState *gameScene;
};


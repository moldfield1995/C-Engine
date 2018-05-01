#pragma once
#include "Component.h"
#include "GameState.h"
class MainMenuComp :
	public Component
{
public:
	MainMenuComp(GameState* gamestate);
	~MainMenuComp();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();
private:

	void LoadGame();
	void QuitGame();

	GameState * m_MainMenu;
};


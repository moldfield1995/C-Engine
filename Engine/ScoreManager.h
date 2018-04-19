#pragma once
#include "Component.h"
#include "UIText.h"

class ScoreManager :
	public Component
{
public:
	ScoreManager();
	~ScoreManager();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();

	void AstroidKilled();
	void AstroidPassedPlayer();
	int GetScore();

	static ScoreManager* GetInstance();
private:
	UIText * scoreText;
	int currentScore;

	static ScoreManager* instance;
};


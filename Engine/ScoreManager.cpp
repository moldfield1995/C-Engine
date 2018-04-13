#include "ScoreManager.h"
#include "UIMannager.h"

ScoreManager* ScoreManager::instance = 0;


ScoreManager::ScoreManager()
{
	scoreText = 0;
	currentScore = 0;
}

ScoreManager::~ScoreManager()
{
}

void ScoreManager::Initalize()
{
	scoreText = new UIText(XMFLOAT4(0.0f, 0.0f, 0.0f, 0.0f), "Score: 0", PivotPosition::TopMiddle);
	UIMannager::GetInstance()->AddComponet(scoreText);
}

void ScoreManager::Update()
{
}

void ScoreManager::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void ScoreManager::Destroy()
{
}

void ScoreManager::AstroidKilled()
{
	currentScore += 100;
	scoreText->UpdateString("Score: " + currentScore);
}

void ScoreManager::AstroidPassedPlayer()
{
	currentScore -= 200;
	scoreText->UpdateString("Score: " + currentScore);
}

int ScoreManager::GetScore()
{
	return currentScore;
}

ScoreManager * ScoreManager::GetInstance()
{
	return instance;
}

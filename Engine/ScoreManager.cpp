#include "ScoreManager.h"
#include "UIMannager.h"

ScoreManager* ScoreManager::instance = 0;


ScoreManager::ScoreManager()
{
	scoreText = 0;
	currentScore = 0;
	scoreMulityplier = 1;
}

ScoreManager::~ScoreManager()
{
}

void ScoreManager::Initalize()
{
	scoreText = new UIText(XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f), "Score: 0", PivotPosition::TopMiddle);
	scoreText->SetPosition(Float3(-50.0f, 0.0f));
	UIMannager::GetInstance()->AddComponet(scoreText);
	instance = this;
}

void ScoreManager::Update()
{
}

void ScoreManager::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void ScoreManager::Destroy()
{
	instance = 0;
	if (scoreText)
	{
		scoreText->Destroy();
		scoreText = 0;
	}
}

void ScoreManager::AstroidKilled()
{
	currentScore += 100 * scoreMulityplier;
	scoreText->UpdateString("Score: " + to_string(currentScore));
}

void ScoreManager::AstroidPassedPlayer()
{
	currentScore -= 200;
	scoreText->UpdateString("Score: " + to_string(currentScore));
}

int ScoreManager::GetScore()
{
	return currentScore;
}

void ScoreManager::AddScoreMulityplier(int value)
{
	scoreMulityplier += value;
}

ScoreManager * ScoreManager::GetInstance()
{
	return instance;
}

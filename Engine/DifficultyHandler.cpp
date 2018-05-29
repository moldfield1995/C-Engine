#include "DifficultyHandler.h"
#include "timerclass.h"
#include "UIMannager.h"

int DifficultyHandler::difficulty = 1.0f;

DifficultyHandler::DifficultyHandler()
{
}


DifficultyHandler::~DifficultyHandler()
{
}

void DifficultyHandler::Initalize()
{
	difficulty = 1.0f;
	nextDifficulty = TimerClass::GetInstance()->GetTime() + 30.0f;
	difficultyText = new UIText(XMFLOAT4(1.0f,1.0f,1.0f,1.0f), "Level: 1");
	difficultyText->SetPosition(Float3(5.0f, 5.0f));
	UIMannager::GetInstance()->AddComponet(difficultyText);
}

void DifficultyHandler::Update()
{
	if (nextDifficulty <= TimerClass::GetInstance()->GetTime())
	{
		difficulty++;
		nextDifficulty = TimerClass::GetInstance()->GetTime() + 15.0f;
		difficultyText->UpdateString("Level: " + std::to_string(difficulty));
	}
}

void DifficultyHandler::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void DifficultyHandler::Destroy()
{
	if (difficultyText)
	{
		difficultyText->Destroy();
		difficultyText = 0;
	}
}

float DifficultyHandler::GetDifficulty()
{
	return difficulty;
}

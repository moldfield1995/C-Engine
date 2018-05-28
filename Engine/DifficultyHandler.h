#pragma once
#include "Component.h"
#include "UIText.h"
class DifficultyHandler :
	public Component
{
public:
	DifficultyHandler();
	~DifficultyHandler();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();

	static float GetDifficulty();
private:
	static int difficulty;
	float nextDifficulty;
	UIText *difficultyText;
};


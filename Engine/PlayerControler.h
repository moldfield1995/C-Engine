#pragma once
#include "Component.h"
#include "GameObject.h"
#include "inputclass.h"

using namespace Leap;

class PlayerControler :
	public Component
{
public:
	PlayerControler(float maxEnergey, float maxHP);
	~PlayerControler();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();
	bool virtual OnCollishon(const GameObject* other);

private:

	void FindHand(InputClass* input, float timeDelta);

	//Leap and possition
	int currentHand;
	Float3 leapToWorldScale, leapWorldOffset;

	//GamePlay
	float currentEnergey, currentHP, maxEnergey, maxHP;
	const float hpLossPerHit, energeyLossPerSecond;

	//ShotSpawner (Seprate script)
	//UI componet
	//score (do in seprate script)
};


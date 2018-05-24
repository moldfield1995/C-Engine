#pragma once
#include "Component.h"
#include "GameObject.h"
#include "inputclass.h"
#include "PlayerUI.h"

using namespace Leap;

class ShotManager;

class PlayerControler :
	public Component
{
public:
	PlayerControler(float maxEnergey, float maxHP, PlayerUI* playerUI, ShotManager* shotManager);
	~PlayerControler();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();
	bool virtual OnCollishon(const CollisonData* other);

	int GetCurrentHand();

	void AddHp(float value);
	void AddEnergey(float value);

private:

	void FindHand(InputClass* input, float timeDelta, Hand &hand);
	bool CheckSuper(Hand &hand);
	//Leap and possition
	int currentHand;
	Float3 leapToWorldScale, leapWorldOffset;
	Float3 rotationOffset;
	const Float3 restingPosition;
	//GamePlay
	float currentEnergey, currentHP;
	const float hpLossPerHit, energeyLossPerSecond, maxEnergey, maxHP;
	bool superActiveLastFrame;

	ShotManager* shotManager;

	//UI componet
	PlayerUI* playerUI;

	static PlayerControler* instance;
public:
	static PlayerControler* GetInstance();
};


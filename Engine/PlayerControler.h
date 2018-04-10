#pragma once
#include "Component.h"
#include "GameObject.h"
class PlayerControler :
	public Component
{
public:
	PlayerControler();
	~PlayerControler();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();
	bool virtual OnCollishon(const GameObject* other);

private:
	int currentHand;
	float currentEnergey, currentHP;
	//ShotSpawner
	//UI componets
	//score
};


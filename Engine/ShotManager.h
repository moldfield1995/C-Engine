#pragma once
#include "Component.h"
#include "GameObject.h"
#include "ShotComponet.h"
class ShotManager :
	public Component
{
public:
	ShotManager(GameObject* ShotPrefab);
	~ShotManager();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();

	static ShotManager* GetInstance();
private:

	void CreateShots(int amount);

	float timeToNextShot;
	const float shotInterval, superChargeTime;
	const Float3 shotOffset;
	GameObject* shotPrefab;

	std::vector<GameObject*> activeShots;
	std::vector<ShotComponet*> storedShots;

	static ShotManager* instance;
};


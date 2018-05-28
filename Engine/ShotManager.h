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

	void SetSuperState(bool value);

	void SetMultyShot(bool value);

private:

	void Shoot();
	void CreateShots(int amount);


	void SpawnShot(Float3 position, Float3 velocity);
	float timeToNextShot;
	const float shotInterval, superInterval;
	const float shotOffset, shotSpeed;
	GameObject* shotPrefab;
	bool superActive, multiShotActive;

	std::vector<GameObject*> activeShots;
	std::vector<ShotComponet*> storedShots;


	static ShotManager* instance;
public:
	static ShotManager* GetInstance();
};


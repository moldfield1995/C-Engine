#pragma once
#include "Component.h"
class PowerupManager :
	public Component
{
public:
	PowerupManager(GameObject* powerupPrefab);
	~PowerupManager();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();

	//calling has a chanse to spawn a power up, can be forced to spawn by setting forceSpawn = true
	void SpawnPowerup(Float3 position,Float3 velosity, bool forceSpawn = false);

private:
	GameObject *powerupPrefab, *healthModel, *powerModel, *scoreModel, *multishotModel, *negativeModel, *randomModel;

	const float spawnChanse;

	std::vector<GameObject*> GameObjects;

	static PowerupManager* instance;
public:
	static PowerupManager* GetInstance();
};


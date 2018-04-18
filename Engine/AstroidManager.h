#pragma once
#include "Component.h"
#include "Astroid.h"
class AstroidManager :
	public Component
{
public:
	AstroidManager(GameObject* prefab);
	~AstroidManager();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();

private:
	void CreateAstroids(int amount);
	void LaunchAstroid();

	const float minSpawnAstroid, maxSpawnAstroid;
	const Float3 minPosition, maxPosition, astroidVelosity;

	std::vector<AstroidComponet*> storedAstroids;
	std::vector<GameObject*> activeAstroids;
	GameObject* prefabAstroid;
	float nextAstroid;
};


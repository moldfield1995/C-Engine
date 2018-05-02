#pragma once
#include "Component.h"
class EnviromentAstroids :
	public Component
{
public:
	EnviromentAstroids(GameObject* prefab, float distanceBetween );
	~EnviromentAstroids();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();
private:
	const float m_MinZ, m_MaxZ, m_XOffset, m_SpawnSepiration, m_MovmentSpeed;
	std::vector<GameObject*> m_Astroids;
	GameObject* m_Prefab;
	int m_NextToCheck;
};


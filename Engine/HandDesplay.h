#pragma once
#include "Component.h"
#include "Leap.h"

//Created In Final Year
//Created By Matthew Oldfield
class HandDesplay :
	public Component
{
public:
	HandDesplay();
	~HandDesplay();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();

private:
	void createGameObjects(int amount);
	int currentActive;
	int64_t lastUpdate;
	std::vector<GameObject*> m_HandGameObjects;
	float3 leapToWorldScale, leapOffset;
};


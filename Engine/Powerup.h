#pragma once
#include "Component.h"
class Powerup :
	public Component
{
public:
	Powerup(GameObject* innerObject, Float3 Velosity);
	~Powerup();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();

	//Return True to stop other componets being called
	bool virtual OnCollishon(const CollisonData* other);

	void virtual Activate() = 0;

private:
	GameObject *innerObject;
	Float3 velosity;
};


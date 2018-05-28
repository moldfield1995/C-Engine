#pragma once
#include "Component.h"
class AstroidComponet :
	public Component
{
public:
	AstroidComponet();
	~AstroidComponet();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();
	bool virtual OnCollishon(const CollisonData* other);

	void Reset();
	void Launch(Float3 position, Float3 velosity);
private:
	const float zDeathPlain;
	Float3 rotation;
};


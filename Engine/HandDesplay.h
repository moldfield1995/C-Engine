#pragma once
#include "Component.h"
class HandDesplay :
	public Component
{
public:
	HandDesplay();
	~HandDesplay();
	void virtual Update() ;
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy() ;
};


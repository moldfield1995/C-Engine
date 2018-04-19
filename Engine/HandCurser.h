#pragma once
#include "Component.h"
#include "UIImage.h"
class HandCurser :
	public Component
{
public:
	HandCurser(char* cursorTexture);
	~HandCurser();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();
private:
	UIImage * curser;
};


#pragma once
#include "Component.h"
#include "timerclass.h"
class WarpSpeed :
	public Component
{
public:
	WarpSpeed();
	~WarpSpeed();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();

private:
	float *shaderData;
	Shader *shader;
	TimerClass *timerClass;
};


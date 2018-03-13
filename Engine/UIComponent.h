#pragma once
#include "d3dclass.h"
#include "Shader.h"
#include "float3.h"
class UIMannager;

///This class will be used for any object that would want to be on the UI.
///It works like a Gameobejct and componet together 
class UIComponent
{
	friend UIMannager;
public:
	UIComponent();
	~UIComponent() {};
	void virtual Initalize() = 0;
	void virtual Update() = 0;
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& baseViewMatrix, const XMMATRIX& orthoMatrix) = 0;
	void virtual Destroy() = 0;

	void virtual SetPosition(float3 value);
	void virtual SetRotation(float3 value);
	void virtual SetScale(float3 value);

	float3 virtual GetPosition();
	float3 virtual GetRotation();
	float3 virtual GetScale();

	bool virtual CheckCollition(float3 otherPos);

protected:
	float3 position, rotation, scale;
	bool renders, killComponet, active;
private:

};


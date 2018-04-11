#pragma once
#include "d3dclass.h"
#include "Shader.h"
#include "float3.h"
class UIMannager;

//Updated In Final Year
//Created By Matthew Oldfield

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

	void virtual SetPosition(Float3 value);
	void virtual SetRotation(Float3 value);
	void virtual SetScale(Float3 value);

	Float3 virtual GetPosition();
	Float3 virtual GetRotation();
	Float3 virtual GetScale();

	bool virtual CheckCollition(Float3 otherPos);

protected:
	Float3 position, rotation, scale;
	bool renders, killComponet, active;
private:

};


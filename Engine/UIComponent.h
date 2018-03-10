#pragma once
#include "d3dclass.h"
#include "ModelClass.h"
#include <vector>
#include "Shader.h"
#include "cameraclass.h"

class UIMannager;

enum PivotPoint
{
	topLeft,
	topRight,
	bottemLeft,
	bottemRight,
	center
};
///This class will be used for any object that would want to be on the UI.
///It works like a Gameobejct and componet together 
class UIComponent
{
	friend UIMannager;
public:
	UIComponent() {};
	~UIComponent() {};
	void virtual Initalize() = 0;
	void virtual Update() = 0;
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& baseViewMatrix, const XMMATRIX& orthoMatrix) = 0;
	void virtual Destroy() = 0;
protected:
	float3 position, rotation;
	PivotPoint pivotPoint;
	bool renders, killComponet, active;
private:

};


#pragma once
#include "Component.h"
#include "UIText.h"
#include "UIButton.h"
using namespace Leap;
//Created In Final Year
//Created By Matthew Oldfield
class DebugDesplay :
	public Component
{
public:
	DebugDesplay();
	~DebugDesplay();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();
private:
	void ButtonClicked();
	UIText** handText;
	UIButton* testButton;
	int textNum;
};


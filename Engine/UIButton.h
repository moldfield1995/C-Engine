#pragma once
#include "UIImage.h"

//Updated In Final Year
//Created By Matthew Oldfield

class UIButton :
	public UIImage
{
public:
	enum ButtonState
	{
		Default,
		Hover,
		Click
	};

	typedef void OnClick();
	__event OnClick onClickTrigger;
public:
	UIButton(char* textureFileName);
	~UIButton();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& baseViewMatrix, const XMMATRIX& orthoMatrix);
	void virtual Destroy();
	
	bool virtual CheckCollition(Float3 otherPos);
	void SetState(ButtonState value);
	ButtonState GetState();


	void virtual SetColour(XMFLOAT4 value);
	XMFLOAT4 GetHoverColour();
	void SetHoverColour(XMFLOAT4 value);
	XMFLOAT4 GetClickColour();
	void SetClickColour(XMFLOAT4 value);

	//void AddOnClick(OnClick deleget, void* source);
protected:
	XMFLOAT4 defaultColour,hoverColour, clickColour;
	ButtonState buttonState;
private:

};


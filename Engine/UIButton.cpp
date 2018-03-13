#include "UIButton.h"



UIButton::UIButton(char* textureFileName)
	: UIImage(textureFileName)
{
	defaultColour = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	hoverColour = XMFLOAT4(1.0f, 1.0f, 1.0f, 0.75f);
	clickColour = XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f);
}

UIButton::~UIButton()
{
}

void UIButton::Initalize()
{
}

void UIButton::Update()
{
	//Todo: check cursur/hand pos
}

void UIButton::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & baseViewMatrix, const XMMATRIX & orthoMatrix)
{
	UIImage::Render(deviceContext, worldMatrix, baseViewMatrix, orthoMatrix);
}

void UIButton::Destroy()
{
	UIImage::Destroy();
}

bool UIButton::CheckCollition(float3 otherPos)
{
	int height, width;
	//Todo: Coppys or refrences?
	float3 hitboxExstent = position;
	bitmapClass->GetTextureSize(height, width);
	hitboxExstent.X += width;
	hitboxExstent.Y += height;
	if ((otherPos.X >= position.X && otherPos.X <= hitboxExstent.X) && (otherPos.Y >= position.Y && otherPos.Y <= hitboxExstent.Y))
		return true;

	return false;
}

void UIButton::SetState(ButtonState value)
{
	buttonState = value;
}

UIButton::ButtonState UIButton::GetState()
{
	return buttonState;
}

void UIButton::SetColour(XMFLOAT4 value)
{
	defaultColour = value;
	if (buttonState == ButtonState::Default)
		colour = value;
}

XMFLOAT4 UIButton::GetHoverColour()
{
	return hoverColour;
}

void UIButton::SetHoverColour(XMFLOAT4 value)
{
	hoverColour = value;
}

XMFLOAT4 UIButton::GetClickColour()
{
	return clickColour;
}

void UIButton::SetClickColour(XMFLOAT4 value)
{
	clickColour = value;
}

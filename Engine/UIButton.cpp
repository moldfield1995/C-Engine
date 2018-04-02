#include "UIButton.h"
#include "inputclass.h"


UIButton::UIButton(char* textureFileName)
	: UIImage(textureFileName)
{
	defaultColour = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	hoverColour = XMFLOAT4(1.0f, 1.0f, 1.0f, 0.5f);
	clickColour = XMFLOAT4(0.5f, 0.5f, 0.5f, 1.0f);
	buttonState = ButtonState::Default;
}

UIButton::~UIButton()
{
}

void UIButton::Initalize()
{
	UIImage::Initalize();
}

void UIButton::Update()
{
	InputClass* instance = InputClass::GetInstance();
	//Todo: check cursur/hand pos
	if (CheckCollition(instance->GetLeapScreenPos()))
	{
		//check if a click has been made
		Leap::Frame frame = instance->GetLeapFrame();
		if (!frame.isValid())
			return;
		Leap::Hand hand = frame.hands()[0];
		if (!hand.isValid())
			return;
		Leap::FingerList fingers = frame.fingers();
		for each (Leap::Finger finger in fingers)
		{
			if (finger.type() == Leap::Finger::TYPE_THUMB && !finger.isExtended())
			{
				__raise this->onClickTrigger();
				this->colour = clickColour;
			}
		}

		if (buttonState == ButtonState::Default) {
			this->colour = hoverColour;
			buttonState = ButtonState::Hover;
		}
	}
	else if (buttonState != ButtonState::Default)
	{
		this->colour = defaultColour;
		buttonState = ButtonState::Default;
	}
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

//void UIButton::AddOnClick(OnClick value, void* source)
//{
//	__hook(&onClickTrigger, source, value);
//}

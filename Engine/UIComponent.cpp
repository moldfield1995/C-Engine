#include "UIComponent.h"

UIComponent::UIComponent(PivotPosition pivot)
{
	SetPivot(pivot);
	position = pivotOffset;
	rotation = Float3();
	scale = Float3(1.0f);
	renders = active = true;
	killComponet = false;
}

void UIComponent::SetPosition(Float3 value)
{
	position = value + pivotOffset;
}

void UIComponent::SetRotation(Float3 value)
{
	rotation = value;
}

void UIComponent::SetScale(Float3 value)
{
	scale = value;
}

void UIComponent::SetRender(bool value)
{
	renders = value;
}

void UIComponent::SetActive(bool value)
{
	active = value;
}

Float3 UIComponent::GetPosition()
{
	return position;
}

Float3 UIComponent::GetRotation()
{
	return rotation;
}

Float3 UIComponent::GetScale()
{
	return scale;
}

bool UIComponent::CheckCollition(Float3 otherPos)
{
	return false;
}

void UIComponent::SetPivot(PivotPosition pivot)
{
	int screenWidth, screenHight;
	D3DClass::GetInstance()->GetScreenReserlution(screenWidth, screenHight);
	switch (pivot)
	{
	case TopLeft:
		pivotOffset = Float3();
		break;
	case TopMiddle:
		pivotOffset = Float3(screenWidth / 2.0f, 0.0f);
		break;
	case TopRight:
		pivotOffset = Float3(screenWidth, 0.0f);
		break;
	case MiddleLeft:
		pivotOffset = Float3(0.0f, -screenHight / 2.0f);
		break;
	case Center:
		pivotOffset = Float3(screenWidth / 2.0f, -screenHight / 2.0f);
		break;
	case MiddleRight:
		pivotOffset = Float3(screenWidth, -screenHight / 2.0f);
		break;
	case BottemLeft:
		pivotOffset = Float3(0.0f, -screenHight);
		break;
	case BottemMiddle:
		pivotOffset = Float3(screenWidth / 2.0f, -screenHight);
		break;
	case BottemRight:
		pivotOffset = Float3(screenWidth, -screenHight);
		break;
	default:
		break;
	}
	this->pivot = pivot;
}

PivotPosition UIComponent::GetPivot()
{
	return pivot;
}

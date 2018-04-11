#include "UIComponent.h"

UIComponent::UIComponent()
{
	position = rotation = Float3();
	scale = Float3(1.0f);
	renders = active = true;
	killComponet = false;
}

void UIComponent::SetPosition(Float3 value)
{
	position = value;
}

void UIComponent::SetRotation(Float3 value)
{
	rotation = value;
}

void UIComponent::SetScale(Float3 value)
{
	scale = value;
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

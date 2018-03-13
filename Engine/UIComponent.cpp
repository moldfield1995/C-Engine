#include "UIComponent.h"

UIComponent::UIComponent()
{
	position = rotation = float3();
	scale = float3(1.0f);
	renders = active = true;
	killComponet = false;
}

void UIComponent::SetPosition(float3 value)
{
	position = value;
}

void UIComponent::SetRotation(float3 value)
{
	rotation = value;
}

void UIComponent::SetScale(float3 value)
{
	scale = value;
}

float3 UIComponent::GetPosition()
{
	return position;
}

float3 UIComponent::GetRotation()
{
	return rotation;
}

float3 UIComponent::GetScale()
{
	return scale;
}

bool UIComponent::CheckCollition(float3 otherPos)
{
	return false;
}

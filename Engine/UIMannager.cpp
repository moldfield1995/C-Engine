#include "UIMannager.h"

UIMannager* UIMannager::instance = 0;


UIMannager::UIMannager()
{
}


UIMannager::~UIMannager()
{
}

void UIMannager::Initalize(int screenX, int screenY)
{
	screenSize = float3(screenX, screenY);
	instance = this;
	active = true;
	componets = std::vector<UIComponent*>();
}

void UIMannager::Update()
{
	for each (UIComponent* var in componets)
	{
		var->Update();
	}
}

void UIMannager::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & baseViewMatrix, const XMMATRIX & orthoMatrix)
{
	for each (UIComponent* var in componets)
	{
		if (var->renders)
			var->Render(deviceContext, worldMatrix, baseViewMatrix, orthoMatrix);
	}
}


void UIMannager::AddComponet(UIComponent * componet)
{
	componet->Initalize();
	componets.push_back(componet);
}

void UIMannager::SetActive(bool value)
{
	active = value;
}

void UIMannager::Destroy()
{
	for each (UIComponent* var in componets)
	{
		var->Destroy();
		delete var;
	}
	componets.clear();
}

UIMannager * UIMannager::GetInstance()
{
	return instance;
}

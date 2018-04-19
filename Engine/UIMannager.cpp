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
	screenSize = Float3(screenX, screenY);
	instance = this;
	active = true;
	componets = std::vector<UIComponent*>();
}

void UIMannager::Update()
{
	for (int i = componets.size()-1; i >= 0; i--)
	{
		if (componets[i]->killComponet)
		{
			componets[i]->Destroy();
			delete componets[i];
			componets.erase(componets.begin() + i);
			i++;
		}
		else if(componets[i]->active)
			componets[i]->Update();
	}
}

void UIMannager::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & baseViewMatrix, const XMMATRIX & orthoMatrix)
{
	D3DClass* Direct3D = D3DClass::GetInstance();
	Direct3D->TurnZBufferOff();
	Direct3D->EnableAlphaBlending();
	for each (UIComponent* var in componets)
	{
		if (var->renders)
			var->Render(deviceContext, worldMatrix, baseViewMatrix, orthoMatrix);
	}
	Direct3D->TurnZBufferOn();
	Direct3D->DisableAlphaBlending();
	
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

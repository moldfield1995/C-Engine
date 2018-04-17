#include "PlayerUI.h"
#include "UIMannager.h"

PlayerUI::PlayerUI(float maxHp, float maxEnergey)
	: maxHp(maxHp)
	, maxEnergey(maxEnergey)
{
}


PlayerUI::~PlayerUI()
{
}

void PlayerUI::Initalize()
{
	UIMannager* uiManager = UIMannager::GetInstance();

	HpText = new UIText(XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f), "HP:", PivotPosition::BottemLeft);
	uiManager->AddComponet(HpText);
	HpText->SetPosition(Float3(0.0f), false, true);

	HpBar = new UISlider("../Engine/data/UI/EmptyHp.tga", "../Engine/data/UI/FillHp.tga", PivotPosition::BottemLeft);
	uiManager->AddComponet(HpBar);
	HpBar->SetPosition(Float3(30.0f,0.0f), false, true);

	EnergeyText = new UIText(XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f), "Power:", PivotPosition::BottemLeft);
	uiManager->AddComponet(EnergeyText);
	EnergeyText->SetPosition(Float3(210.0f,0.0f), false, true);

	EnergeyBar = new UISlider("../Engine/data/UI/EmptyEnergey.tga", "../Engine/data/UI/FillEnergey.tga", PivotPosition::BottemLeft);
	uiManager->AddComponet(EnergeyBar);
	EnergeyBar->SetPosition(Float3(270.0f, 0.0f), false, true);

}

void PlayerUI::Update()
{
}

void PlayerUI::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void PlayerUI::Destroy()
{
	if (HpText)
	{
		HpText->Destroy();
		HpText = 0;
	}

	if (HpBar)
	{
		HpBar->Destroy();
		HpBar = 0;
	}

	if (EnergeyText)
	{
		EnergeyText->Destroy();
		EnergeyText = 0;
	}

	if (EnergeyBar)
	{
		EnergeyBar->Destroy();
		EnergeyBar = 0;
	}
}

void PlayerUI::SetSliders(float currentHP, float currentEnergey)
{
	HpBar->SetUVClip(currentHP / maxHp);
	EnergeyBar->SetUVClip(currentEnergey / maxEnergey);
}

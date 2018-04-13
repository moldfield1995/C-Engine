#include "PlayerUI.h"
#include "UIText.h"


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
	UIImage *HPBackground, *EnergeyBackground;
	UIText *HPText, *EnergeyText;
	//TODO: UI shader that fills
}

void PlayerUI::Update()
{
}

void PlayerUI::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void PlayerUI::Destroy()
{
}

void PlayerUI::SetSliders(float currentHP, float currentEnergey)
{
}

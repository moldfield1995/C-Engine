#pragma once
#include "Component.h"
#include "UISlider.h"
#include "UIText.h"
class PlayerUI :
	public Component
{
public:
	PlayerUI(float maxHp,float maxEnergey);
	~PlayerUI();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix, FrustumClass* frustume, LightClass* light, CameraClass& camera);
	void virtual Destroy();

	void SetSliders(float currentHP, float currentEnergey);
private:
	const float maxHp, maxEnergey;
	UISlider *HpBar, *EnergeyBar;
	UIText *HpText, *EnergeyText;
};


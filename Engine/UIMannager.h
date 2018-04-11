#pragma once
#include "UIComponent.h"
#include <vector>

//Updated In Final Year
//Created By Matthew Oldfield

class UIMannager
{
public:
	UIMannager();
	~UIMannager();
	void Initalize(int screenX,int screenY);
	void Update();
	void Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& baseViewMatrix, const XMMATRIX& orthoMatrix);
	void AddComponet(UIComponent* componet);
	void SetActive(bool value);
	void Destroy();
protected:
	Float3 screenSize;
	bool active;
private:
	std::vector<UIComponent*> componets;

	static UIMannager* instance;
public:
	static UIMannager* GetInstance();
};


#pragma once
#include "UIComponent.h"
#include "bitmapclass.h"
#include "Shader.h"
#include <vector>

//Updated In Final Year
//Created By Matthew Oldfield

class UIImage:
	public UIComponent
{
public:
	UIImage(char* textureFileName, PivotPosition pivot = PivotPosition::TopLeft);
	~UIImage();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& baseViewMatrix, const XMMATRIX& orthoMatrix);
	void virtual Destroy();

	XMFLOAT4 GetColour();
	void virtual SetColour(XMFLOAT4 value);
	float GetWidth();
	float GetHight();
	//Exsposes the inherited SetPosition otherwise the compiler only sees SetPostion(Float3,bool,bool)
	using UIComponent::SetPosition;
	void SetPosition(Float3 value, bool centerX, bool centerY);
protected:
	XMFLOAT4 colour;
	BitmapClass *bitmapClass;
private:
	Shader *shader;
	std::vector<ID3D11ShaderResourceView*>* textures;
	char* textureFileName;
};


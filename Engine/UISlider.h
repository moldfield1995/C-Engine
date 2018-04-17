#pragma once
#include "UIImage.h"
#include "bitmapclass.h"
#include "slidershaderclass.h"
class UISlider :
	public UIImage
{
public:
	UISlider(char* backgroundFileName, char* sliderFileName, PivotPosition pivot = PivotPosition::TopLeft);
	~UISlider();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& baseViewMatrix, const XMMATRIX& orthoMatrix);
	void virtual Destroy();

	XMFLOAT4 GetSliderColour();
	void virtual SetSliderColour(XMFLOAT4 value);
	XMFLOAT2 GetUVClip();
	void virtual SetUVClip(float value);
protected:
	SliderShaderClass::SliderBuffer* sliderBuffer;
	BitmapClass *bitmapClass;
private:
	Shader * shader;
	std::vector<ID3D11ShaderResourceView*>* textures;
	char* textureFileName;
};


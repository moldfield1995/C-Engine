#include "UISlider.h"
#include "shadermanagerclass.h"


UISlider::UISlider(char* backgroundFileName, char* sliderFileName, PivotPosition pivot )
	: UIImage(backgroundFileName,pivot)
{
	this->textureFileName = sliderFileName;
	bitmapClass = 0;
	shader = 0;
	textures = 0;
	sliderBuffer = 0;
}


UISlider::~UISlider()
{
}

void UISlider::Initalize()
{
	UIImage::Initalize();
	D3DClass* instance = D3DClass::GetInstance();
	bitmapClass = new BitmapClass();
	if (!bitmapClass->Initialize(instance->GetDevice(), instance->GetDeviceContext(), textureFileName))
	{
		OutputDebugString(L"Failed to Initalize bitmapClass | Initalize | UIImage");
	}

	shader = ShaderManagerClass::GetInstance()->GetShader<SliderShaderClass>();
	textures = new std::vector<ID3D11ShaderResourceView*>();
	textures->push_back(bitmapClass->GetTexture());
	sliderBuffer = new SliderShaderClass::SliderBuffer{ XMFLOAT4(1.0f,1.0f,1.0f,1.0f), XMFLOAT2A(1.0f,1.0f)};

}

void UISlider::Update()
{
}

void UISlider::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & baseViewMatrix, const XMMATRIX & orthoMatrix)
{
	UIImage::Render(deviceContext, worldMatrix, baseViewMatrix, orthoMatrix);
	XMMATRIX renderMatrix, rotationMatrix, scaleMatrix;
	renderMatrix = XMMatrixTranslation(position.X, position.Y, position.Z);
	Float3 rotationInRadens = rotation * 0.0174532925f;
	rotationMatrix = XMMatrixRotationRollPitchYaw(rotationInRadens.X, rotationInRadens.Y, rotationInRadens.Z);
	scaleMatrix = XMMatrixScaling(scale.X, scale.Y, scale.Z);
	renderMatrix = XMMatrixMultiply(worldMatrix, renderMatrix);
	renderMatrix = XMMatrixMultiply(rotationMatrix, renderMatrix);
	renderMatrix = XMMatrixMultiply(scaleMatrix, renderMatrix);

	bitmapClass->Render(deviceContext);
	shader->Render(deviceContext, bitmapClass->GetIndexCount(), renderMatrix, baseViewMatrix, orthoMatrix, textures, 0, sliderBuffer);
	//UIImage::Render(deviceContext, worldMatrix, baseViewMatrix, orthoMatrix);
}

void UISlider::Destroy()
{
	UIImage::Destroy();
	if (bitmapClass)
	{
		bitmapClass->Shutdown();
		delete bitmapClass;
		bitmapClass = 0;
	}
	if (textures)
	{
		delete textures;
		textures = 0;
	}
	if (sliderBuffer)
	{
		delete sliderBuffer;
		sliderBuffer = 0;
	}

	shader = 0;
	killComponet = true;
}

XMFLOAT4 UISlider::GetSliderColour()
{
	return sliderBuffer->colour;
}

void UISlider::SetSliderColour(XMFLOAT4 value)
{
	sliderBuffer->colour = value;
}

XMFLOAT2 UISlider::GetUVClip()
{
	return sliderBuffer->UVClip;
}

void UISlider::SetUVClip(float value)
{
	sliderBuffer->UVClip.x = value;
}

#include "UIImage.h"
#include "shadermanagerclass.h"
#include "textureshaderclass.h"

UIImage::UIImage(char* textureFileName, PivotPosition pivot)
	: UIComponent(pivot)
{
	this->textureFileName = textureFileName;
	bitmapClass = 0;
	shader = 0;
	textures = 0;
	colour = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
}


UIImage::~UIImage()
{
}

void UIImage::Initalize()
{
	D3DClass* instance = D3DClass::GetInstance();
	bitmapClass = new BitmapClass();
	if (!bitmapClass->Initialize(instance->GetDevice(), instance->GetDeviceContext(), textureFileName))
	{
		OutputDebugString(L"Failed to Initalize bitmapClass | Initalize | UIImage");
	}
	shader = ShaderManagerClass::GetInstance()->GetShader<TextureShaderClass>();
	textures = new std::vector<ID3D11ShaderResourceView*>();
	textures->push_back(bitmapClass->GetTexture());
}

void UIImage::Update()
{
}

void UIImage::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & baseViewMatrix, const XMMATRIX & orthoMatrix)
{
	XMMATRIX renderMatrix, rotationMatrix, scaleMatrix;
	renderMatrix = XMMatrixTranslation(position.X, position.Y, position.Z);
	Float3 rotationInRadens = rotation * 0.0174532925f;
	rotationMatrix = XMMatrixRotationRollPitchYaw(rotationInRadens.X, rotationInRadens.Y, rotationInRadens.Z);
	scaleMatrix = XMMatrixScaling(scale.X, scale.Y, scale.Z);
	renderMatrix = XMMatrixMultiply(worldMatrix,renderMatrix);
	renderMatrix = XMMatrixMultiply(rotationMatrix, renderMatrix);
	renderMatrix = XMMatrixMultiply(scaleMatrix, renderMatrix);

	bitmapClass->Render(deviceContext);
	shader->Render(deviceContext, bitmapClass->GetIndexCount(), renderMatrix, baseViewMatrix, orthoMatrix, textures, 0, &colour);

}

void UIImage::Destroy()
{
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
	shader = 0;
	killComponet = true;
}

XMFLOAT4 UIImage::GetColour()
{
	return colour;
}

void UIImage::SetColour(XMFLOAT4 value)
{
	colour = value;
}

float UIImage::GetWidth()
{
	int height, width;
	bitmapClass->GetTextureSize(height, width);
	return (float)width * scale.X;
}

float UIImage::GetHight()
{
	int height, width;
	bitmapClass->GetTextureSize(height, width);
	return (float)height * scale.Y;
}

void UIImage::SetPosition(Float3 value, bool centerX, bool centerY)
{
	int height, width;
	bitmapClass->GetTextureSize(height, width);
	position = (value * relativeScreenSize) + pivotOffset;

	if (centerX)
		position.X -= width;
	if (centerY)
		position.Y += height;
}

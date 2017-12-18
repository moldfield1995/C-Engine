#include "ImageElement.h"

ImageElement::ImageElement()
{
	m_Image = 0;
}


ImageElement::~ImageElement()
{
}

bool ImageElement::Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext, int screenWidth, int screenHeight, int bitmapWidth, int bitmapHeight, char* textureFilename, int posX,int posY)
{
	bool result;
	m_Image = new BitmapClass;
	result = m_Image->Initialize(device, deviceContext, screenWidth, screenHeight, bitmapWidth,bitmapHeight, textureFilename);
	m_PosX = posX;
	m_PosY = posY;
	m_SizeX = bitmapWidth;
	m_SizeY = bitmapHeight;
	return result;
}

void ImageElement::Shutdown()
{
	if (m_Image)
	{
		m_Image->Shutdown();
		delete m_Image;
		m_Image = 0;
	}
}

bool ImageElement::Render(ID3D11DeviceContext* deviceContext)
{
	return m_Image->Render(deviceContext, m_PosX, m_PosY, m_SizeY, m_SizeX);
}

int ImageElement::GetIndexCount()
{
	return m_Image->GetIndexCount();
}

ID3D11ShaderResourceView * ImageElement::GetTexture()
{
	return m_Image->GetTexture();
}

void ImageElement::GetPosition(int & posX, int & posY)
{
	posX = m_PosX;
	posY = m_PosY;
}

void ImageElement::SetPosition(int posX, int posY)
{
	m_PosX = posX;
	m_PosY = posY;
}

void ImageElement::GetSize(int & sizeX, int & sizeY)
{
	sizeX = m_SizeX;
	sizeY = m_SizeY;
}

void ImageElement::SetSize(int sizeX, int sizeY)
{
	m_SizeX = sizeX;
	m_SizeY = sizeY;
}


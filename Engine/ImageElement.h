#pragma once
#include "bitmapclass.h"
class ImageElement
{
public:
	ImageElement();
	~ImageElement();

	bool Initialize(ID3D11Device*, ID3D11DeviceContext*, int, int, int, int, char*, int, int);
	void Shutdown();
	bool Render(ID3D11DeviceContext*);

	int GetIndexCount();
	ID3D11ShaderResourceView* GetTexture();

	void GetPosition(int&, int&);
	void SetPosition(int, int);
	void GetSize(int&, int&);
	void SetSize(int, int);
private:
	BitmapClass* m_Image;
	int m_PosX, m_PosY;
	int m_SizeX, m_SizeY;
};


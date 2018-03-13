////////////////////////////////////////////////////////////////////////////////
// Filename: fontclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _FONTCLASS_H_
#define _FONTCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <directxmath.h>
#include <fstream>
#include <vector>
using namespace DirectX;
using namespace std;


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "textureclass.h"


////////////////////////////////////////////////////////////////////////////////
// Class name: FontClass
////////////////////////////////////////////////////////////////////////////////
class FontClass
{
private:
	struct FontType
	{
		float left, right;
		int size;
	};

	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
	};

public:
	FontClass();
	FontClass(const FontClass&);
	~FontClass();

	bool Initialize(ID3D11Device*, ID3D11DeviceContext*, char*, char*, float, int);
	void Shutdown();
	//old
	ID3D11ShaderResourceView* GetTexture();
	//new
	std::vector< ID3D11ShaderResourceView*>* GetTextures();

	void BuildVertexArray(void*,const char*, float, float);
	int GetSentencePixelLength(char*);
	int GetFontHeight();

private:
	bool LoadFontData(char*);
	void ReleaseFontData();
	bool LoadTexture(ID3D11Device*, ID3D11DeviceContext*, char*);
	void ReleaseTexture();

private:
	FontType* m_Font;
	float m_fontHeight;
	int m_spaceSize;
	std::vector< ID3D11ShaderResourceView*> *textures;
	//TODO: Remove
	TextureClass* m_Texture;
};

#endif
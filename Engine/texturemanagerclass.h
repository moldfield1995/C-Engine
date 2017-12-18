////////////////////////////////////////////////////////////////////////////////
// Filename: texturemanagerclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _TEXTUREMANAGERCLASS_H_
#define _TEXTUREMANAGERCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "textureclass.h"
#include <map>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// Class name: TextureManagerClass
////////////////////////////////////////////////////////////////////////////////
class TextureManagerClass
{
public:
	TextureManagerClass();
	TextureManagerClass(const TextureManagerClass&);
	~TextureManagerClass();

	bool Initialize();
	void Shutdown();

	bool LoadTexture(ID3D11Device*, ID3D11DeviceContext*, char*, int);

	ID3D11ShaderResourceView* GetTexture(int);

	bool TextureLoaded(int id);
	std::vector<int> GetTextureList();
private:
	//TextureClass* m_TextureArray;
	//int m_textureCount;
	std::map<int, TextureClass*> textures;
	std::vector<int> storedTextures;
};

#endif
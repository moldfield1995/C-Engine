////////////////////////////////////////////////////////////////////////////////
// Filename: texturemanagerclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "texturemanagerclass.h"

TextureManagerClass* TextureManagerClass::instance = 0;

TextureManagerClass::TextureManagerClass()
{
	//m_TextureArray = 0;
}


TextureManagerClass::TextureManagerClass(const TextureManagerClass& other)
{
}


TextureManagerClass::~TextureManagerClass()
{
}


bool TextureManagerClass::Initialize()//int count)
{
	//m_textureCount = count;
	textures = std::map<int, TextureClass*>();
	storedTextures = std::vector<int>();
	instance = this;

	return true;
}


void TextureManagerClass::Shutdown()
{
	//int i;
	// Release the texture objects.
	//if(m_TextureArray)
	//{
	//	for(i=0; i<m_textureCount; i++)
	//	{
	//		m_TextureArray[i].Shutdown();
	//	}
	//	delete [] m_TextureArray;
	//	m_TextureArray = 0;
	//}

	for (std::map<int, TextureClass*>::iterator it = textures.begin(); it != textures.end(); ++it)
	{
		it->second->Shutdown();
		delete it->second;
	}
	textures.clear();
	return;
}


bool TextureManagerClass::LoadTexture(ID3D11Device* device, ID3D11DeviceContext* deviceContext, char* filename, int id)
{
	bool result;
	TextureClass* NewTexture = new TextureClass();
	result = NewTexture->Initialize(device, deviceContext, filename);
	textures[id] = NewTexture;
	storedTextures.push_back(id);
	return result;
	// Initialize the color texture object.
	//result = m_TextureArray[id].Initialize(device, deviceContext, filename);
	//if(!result)
	//{
	//	return false;
	//}

	//return true;
}


ID3D11ShaderResourceView* TextureManagerClass::GetTexture(int id)
{
	return textures[id]->GetTexture();
	//return m_TextureArray[id].GetTexture();
}

bool TextureManagerClass::TextureLoaded(int id)
{
	if (textures.find(id) != textures.end())
		return true;
	return false;
}
std::vector<int> TextureManagerClass::GetTextureList()
{
	return storedTextures;
}

TextureManagerClass * TextureManagerClass::GetInstance()
{
	return instance;
}

////////////////////////////////////////////////////////////////////////////////
// Filename: texturemanagerclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "texturemanagerclass.h"
#include "Utills.h"

TextureManagerClass* TextureManagerClass::instance = 0;

TextureManagerClass::TextureManagerClass()
{
}


TextureManagerClass::TextureManagerClass(const TextureManagerClass& other)
{
}


TextureManagerClass::~TextureManagerClass()
{
}


bool TextureManagerClass::Initialize()
{
	textures = std::map<int, TextureClass*>();
	storedTextures = std::vector<int>();
	instance = this;

	return true;
}


void TextureManagerClass::Shutdown()
{

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
	if (TextureLoaded(id))
	{
		OutputDebugString(L"Texture was allready loaded\n");
		return true; //return true as the texture allready exsits
	}
	TextureClass* NewTexture = new TextureClass();
	result = NewTexture->Initialize(device, deviceContext, filename);
	textures[id] = NewTexture;
	storedTextures.push_back(id);
	return result;
}

int TextureManagerClass::LoadTexture(ID3D11Device* device, ID3D11DeviceContext* deviceContext, char* filename)
{
	int id = Utills::ParsString(filename);
	if (TextureLoaded(id))
	{
		OutputDebugString(L"Texture was allready loaded\n");
		return id;
	}
	TextureClass* NewTexture = new TextureClass();
	if (!NewTexture->Initialize(device, deviceContext, filename))
	{
		std::string file =  "Texture Failed to load ";
		file.append(filename);
		Utills::DebugString(file.data());
	}
	textures[id] = NewTexture;
	storedTextures.push_back(id);
	return id;
}


ID3D11ShaderResourceView* TextureManagerClass::GetTexture(int id)
{
	return textures[id]->GetTexture();
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

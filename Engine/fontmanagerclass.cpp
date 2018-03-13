#include "fontmanagerclass.h"

FontManagerClass* FontManagerClass::instance = 0;

FontManagerClass::FontManagerClass()
{
}


FontManagerClass::FontManagerClass(const FontManagerClass& other)
{
}


FontManagerClass::~FontManagerClass()
{
}


bool FontManagerClass::Initialize()
{
	fonts = std::map<int, FontClass*>();
	storedFonts = std::vector<int>();
	instance = this;

	return true;
}


void FontManagerClass::Shutdown()
{

	for (std::map<int, FontClass*>::iterator it = fonts.begin(); it != fonts.end(); ++it)
	{
		it->second->Shutdown();
		delete it->second;
	}
	fonts.clear();
	return;
}


bool FontManagerClass::LoadFont(ID3D11Device* device, ID3D11DeviceContext* deviceContext, char* fontFileName,char*textureFileName,float fontHeight, int spaceSize, int id)
{
	bool result;
	if (FontLoaded(id))
	{
		OutputDebugString(L"Font was allready loaded");
		return true; //return true as the Font allready exsits
	}
	FontClass* NewFont = new FontClass();
	result = NewFont->Initialize(device, deviceContext, fontFileName, textureFileName, fontHeight, spaceSize);
	fonts[id] = NewFont;
	storedFonts.push_back(id);
	return result;
}


FontClass* FontManagerClass::GetFont(int id)
{
	return fonts[id];
}

bool FontManagerClass::FontLoaded(int id)
{
	if (fonts.find(id) != fonts.end())
		return true;
	return false;
}
std::vector<int> FontManagerClass::GetFontList()
{
	return storedFonts;
}

FontManagerClass * FontManagerClass::GetInstance()
{
	return instance;
}

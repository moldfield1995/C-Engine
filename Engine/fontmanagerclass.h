#include "fontclass.h"
#include <map>
#include <vector>

class FontManagerClass
{
public:
	FontManagerClass();
	FontManagerClass(const FontManagerClass&);
	~FontManagerClass();
	bool Initialize();
	void Shutdown();

	bool LoadFont(ID3D11Device*, ID3D11DeviceContext*, char*,char*,float,int, int);

	FontClass* GetFont(int);

	bool FontLoaded(int id);
	std::vector<int> GetFontList();
private:
	static FontManagerClass* instance;
	std::map<int, FontClass*> fonts;
	std::vector<int> storedFonts;
public:
	static FontManagerClass* GetInstance();
};

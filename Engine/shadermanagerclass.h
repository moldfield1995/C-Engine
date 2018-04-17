////////////////////////////////////////////////////////////////////////////////
// Filename: shadermanagerclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _SHADERMANAGERCLASS_H_
#define _SHADERMANAGERCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "d3dclass.h"
#include <vector>
#include <typeinfo>
#include "Shader.h"

//Updated In Final Year
//Created By RasterTeck
//Updated By Matthew Oldfield

////////////////////////////////////////////////////////////////////////////////
// Class name: ShaderManagerClass
////////////////////////////////////////////////////////////////////////////////
class ShaderManagerClass
{
public:
	ShaderManagerClass();
	ShaderManagerClass(const ShaderManagerClass&);
	~ShaderManagerClass();


	bool Initialize(ID3D11Device*, HWND);
	void Shutdown();

	template<class T>
	Shader* GetShader()
	{
		for each (Shader* shader in m_shaders)
		{
			T* castedShader = dynamic_cast<T*>(shader);
			if (castedShader != NULL)
				return shader;
		}
		return nullptr;
	}
private:
	bool CreateShader(Shader* shader, ID3D11Device* device, HWND hwnd);
	std::vector<Shader*> m_shaders;
	static ShaderManagerClass* instance;
public:
	static ShaderManagerClass* GetInstance();
};

#endif


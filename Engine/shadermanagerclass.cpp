////////////////////////////////////////////////////////////////////////////////
// Filename: shadermanagerclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "shadermanagerclass.h"
#include "colorshaderclass.h"
#include "textureshaderclass.h"
#include "lightshaderclass.h"
#include "fontshaderclass.h"
#include "skydomeshaderclass.h"
#include "lightshader.h"
#include "bumpmapshaderclass.h"
#include "slidershaderclass.h"
#include "warpspeedshaderclass.h"
#include "maskedTextureshaderclass.h"

ShaderManagerClass* ShaderManagerClass::instance = 0;

ShaderManagerClass::ShaderManagerClass()
{
	
}


ShaderManagerClass::ShaderManagerClass(const ShaderManagerClass& other)
{
}


ShaderManagerClass::~ShaderManagerClass()
{
}


bool ShaderManagerClass::Initialize(ID3D11Device* device, HWND hwnd)
{
	m_shaders = vector<Shader*>();
	CreateShader(new ColorShaderClass, device, hwnd);
	CreateShader(new TextureShaderClass, device, hwnd);
	CreateShader(new LightShaderClass, device, hwnd);
	CreateShader(new FontShaderClass, device, hwnd);
	CreateShader(new LightShader, device, hwnd);
	CreateShader(new BumpMapShaderClass, device, hwnd);
	CreateShader(new SkyDomeShaderClass, device, hwnd);
	CreateShader(new SliderShaderClass, device, hwnd);
	CreateShader(new WarpSpeedShaderClass, device, hwnd);
	CreateShader(new MaskedTextureshaderclass, device, hwnd);
	instance = this;

	return true;
}


void ShaderManagerClass::Shutdown()
{
	for each (Shader* shader in m_shaders)
	{
		shader->Shutdown();
		delete shader;
		shader = 0;
	}

	return;
}

bool ShaderManagerClass::CreateShader(Shader * shader, ID3D11Device* device, HWND hwnd)
{
	if (!shader)
		return false;
	if (!shader->Initialize(device,hwnd))
		return false;
	m_shaders.push_back(shader);
	return true;
}

ShaderManagerClass * ShaderManagerClass::GetInstance()
{
	return instance;
}


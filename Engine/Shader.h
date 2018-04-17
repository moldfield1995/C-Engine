#pragma once
#include "lightclass.h"
#include <vector>

//Updated In Final Year
//Created By Matthew Oldfield

class Shader
{
public:
	Shader() {};
	~Shader() {};
	virtual bool Initialize(ID3D11Device*, HWND) = 0;
	virtual void Shutdown() = 0;
	virtual bool Render(ID3D11DeviceContext* context,int indexCount,const XMMATRIX&, const XMMATRIX&, const XMMATRIX&,std::vector< ID3D11ShaderResourceView*>* textures,LightClass* light = 0,void* shaderData = 0 ) = 0;
};


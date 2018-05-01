#pragma once
#include "Shader.h"
#include "ModelClass.h"
#include "textureclass.h"
#include <vector>

class SkyBoxRender
{
public:
	SkyBoxRender();
	~SkyBoxRender();
	void Initalize(ModelClass* model, ID3D11ShaderResourceView* texture, Shader* shader);
	void Destroy();
	void Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix);
private:
	ModelClass * m_modle;
	std::vector<ID3D11ShaderResourceView*>* m_textures;
	Shader* m_shader;

};


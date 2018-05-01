#include "SkyBoxRender.h"
#include "d3dclass.h"


SkyBoxRender::SkyBoxRender()
{
	m_modle = 0;
	m_shader = 0;
	m_textures = 0;
}


SkyBoxRender::~SkyBoxRender()
{
}

void SkyBoxRender::Initalize(ModelClass* model, ID3D11ShaderResourceView* texture, Shader* shader)
{
	m_modle = model;
	m_shader = shader;
	m_textures = new std::vector<ID3D11ShaderResourceView*>();
	m_textures->push_back(texture);
}

void SkyBoxRender::Destroy()
{
	m_modle = 0;
	if (m_textures)
	{
		m_textures->clear();
		delete m_textures;
		m_textures = 0;
	}
	m_shader = 0;

}

void SkyBoxRender::Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, const XMMATRIX& projectionMatrix)
{
	D3DClass* D3DInstance = D3DClass::GetInstance();
	D3DInstance->TurnZBufferOff();
	m_modle->Render(deviceContext);
	m_shader->Render(deviceContext, m_modle->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, m_textures);
	D3DInstance->TurnZBufferOn();
}

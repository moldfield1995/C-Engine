////////////////////////////////////////////////////////////////////////////////
// Filename: shadermanagerclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "shadermanagerclass.h"
ShaderManagerClass* ShaderManagerClass::instance = 0;

ShaderManagerClass::ShaderManagerClass()
{
	m_ColorShader = 0;
	m_TextureShader = 0;
	m_LightShader = 0;
	m_FontShader = 0;
	m_SkyDomeShader = 0;
	m_TerrainShader = 0;
	m_LightShader = 0;
	m_LightShading = 0;
	
}


ShaderManagerClass::ShaderManagerClass(const ShaderManagerClass& other)
{
}


ShaderManagerClass::~ShaderManagerClass()
{
}


bool ShaderManagerClass::Initialize(ID3D11Device* device, HWND hwnd)
{
	bool result;
	m_shaders = vector<Shader*>();
	CreateShader(new ColorShaderClass, device, hwnd);
	CreateShader(new TextureShaderClass, device, hwnd);
	CreateShader(new LightShaderClass, device, hwnd);
	CreateShader(new FontShaderClass, device, hwnd);
	CreateShader(new TerrainShaderClass, device, hwnd);
	CreateShader(new LightShader, device, hwnd);
	CreateShader(new BumpMapShaderClass, device, hwnd);
	CreateShader(new SkyDomeShaderClass, device, hwnd);
	instance = this;
	// Create the color shader object.
	m_ColorShader = new ColorShaderClass;
	if(!m_ColorShader)
	{
		return false;
	}

	// Initialize the color shader object.
	result = m_ColorShader->Initialize(device, hwnd);
	if(!m_ColorShader)
	{
		return false;
	}

	// Create the texture shader object.
	m_TextureShader = new TextureShaderClass;
	if(!m_TextureShader)
	{
		return false;
	}

	// Initialize the texture shader object.
	result = m_TextureShader->Initialize(device, hwnd);
	if(!result)
	{
		return false;
	}

	// Create the light shader object.
	m_LightShader = new LightShaderClass;
	if(!m_LightShader)
	{
		return false;
	}

	// Initialize the light shader object.
	result = m_LightShader->Initialize(device, hwnd);
	if(!result)
	{
		return false;
	}

	// Create the font shader object.
	m_FontShader = new FontShaderClass;
	if(!m_FontShader)
	{
		return false;
	}

	// Initialize the font shader object.
	result = m_FontShader->Initialize(device, hwnd);
	if(!result)
	{
		return false;
	}

	// Create the sky dome shader object.
	m_SkyDomeShader = new SkyDomeShaderClass;
	if(!m_SkyDomeShader)
	{
		return false;
	}

	// Initialize the sky dome shader object.
	result = m_SkyDomeShader->Initialize(device, hwnd);
	if(!result)
	{
		return false;
	}

	// Create the terrain shader object.
	m_TerrainShader = new TerrainShaderClass;
	if (!m_TerrainShader)
	{
		return false;
	}

	// Initialize the terrain shader object.
	result = m_TerrainShader->Initialize(device, hwnd);
	if (!result)
	{
		return false;
	}
	m_LightShading = new LightShader;
	result = m_LightShading->Initialize(device, hwnd);
	if (!result)
	{
		return false;
	}
	m_bumpmapShader = new BumpMapShaderClass;
	result = m_bumpmapShader->Initialize(device, hwnd);
	if (!result)
	{
		return false;
	}

	return true;
}


void ShaderManagerClass::Shutdown()
{
	// Release the terrain shader object.
	if (m_TerrainShader)
	{
		m_TerrainShader->Shutdown();
		delete m_TerrainShader;
		m_TerrainShader = 0;
	}

	// Release the sky dome shader object.
	if (m_SkyDomeShader)
	{
		m_SkyDomeShader->Shutdown();
		delete m_SkyDomeShader;
		m_SkyDomeShader = 0;
	}

	// Release the font shader object.
	if(m_FontShader)
	{
		m_FontShader->Shutdown();
		delete m_FontShader;
		m_FontShader = 0;
	}

	// Release the light shader object.
	if(m_LightShader)
	{
		m_LightShader->Shutdown();
		delete m_LightShader;
		m_LightShader = 0;
	}

	// Release the texture shader object.
	if(m_TextureShader)
	{
		m_TextureShader->Shutdown();
		delete m_TextureShader;
		m_TextureShader = 0;
	}

	// Release the color shader object.
	if(m_ColorShader)
	{
		m_ColorShader->Shutdown();
		delete m_ColorShader;
		m_ColorShader = 0;
	}

	if (m_LightShading)
	{
		m_LightShading->Shutdown();
		delete m_LightShading;
		m_LightShading = 0;
	}

	return;
}


bool ShaderManagerClass::RenderColorShader(ID3D11DeviceContext* deviceContext, int indexCount, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, 
										   const XMMATRIX& projectionMatrix)
{
	return m_ColorShader->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix);
}


bool ShaderManagerClass::RenderTextureShader(ID3D11DeviceContext* deviceContext, int indexCount, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, 
											 const XMMATRIX& projectionMatrix, ID3D11ShaderResourceView* texture)
{
	return m_TextureShader->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix, texture,0);
}


bool ShaderManagerClass::RenderLightShader(ID3D11DeviceContext* deviceContext, int indexCount, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix,
										   const XMMATRIX& projectionMatrix, ID3D11ShaderResourceView* texture, XMFLOAT3 lightDirection, 
										   XMFLOAT4 diffuseColor)
{
	return m_LightShader->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix, texture, lightDirection, diffuseColor);
}


bool ShaderManagerClass::RenderFontShader(ID3D11DeviceContext* deviceContext, int indexCount, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, 
										  const XMMATRIX& projectionMatrix, ID3D11ShaderResourceView* texture, XMFLOAT4 color)
{
	return m_FontShader->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix, texture, color);
}


bool ShaderManagerClass::RenderSkyDomeShader(ID3D11DeviceContext* deviceContext, int indexCount, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, 
											 const XMMATRIX& projectionMatrix, XMFLOAT4 apexColor, XMFLOAT4 centerColor)
{
	return m_SkyDomeShader->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix, apexColor, centerColor);
}


bool ShaderManagerClass::RenderTerrainShader(ID3D11DeviceContext* deviceContext, int indexCount, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix,
											 const XMMATRIX& projectionMatrix, ID3D11ShaderResourceView* texture, ID3D11ShaderResourceView* normalMap,
											 ID3D11ShaderResourceView* normalMap2, ID3D11ShaderResourceView* normalMap3, 
											 XMFLOAT3 lightDirection, XMFLOAT4 diffuseColor)
{
	return m_TerrainShader->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix, texture, normalMap, normalMap2, normalMap3,
								   lightDirection, diffuseColor);
}

bool ShaderManagerClass::RenderLightShading(ID3D11DeviceContext* deviceContext, int indexCount, const XMMATRIX &worldMatrix, const XMMATRIX &viewMatrix,
	const XMMATRIX &projectionMatrix, ID3D11ShaderResourceView* texture, XMFLOAT3 lightDirection, XMFLOAT4 ambientColor,
	XMFLOAT4 diffuseColor, XMFLOAT3 cameraPosition, XMFLOAT4 specularColor, float specularPower)
{
	bool result;
	result = m_LightShading->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix, texture, lightDirection, ambientColor, diffuseColor, cameraPosition, specularColor, specularPower);
	return result;
}

bool ShaderManagerClass::RenderBumpMapShader(ID3D11DeviceContext* deviceContext, int indexCount, const XMMATRIX &worldMatrix, const XMMATRIX &viewMatrix,
	const XMMATRIX &projectionMatrix, ID3D11ShaderResourceView* colorTexture, ID3D11ShaderResourceView* normalMapTexture,
	XMFLOAT3 lightDirection, XMFLOAT4 diffuseColor, XMFLOAT4 ambientColor)
{
	bool result;
	result = m_bumpmapShader->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix, colorTexture, normalMapTexture, lightDirection, diffuseColor, ambientColor);
	return result;
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


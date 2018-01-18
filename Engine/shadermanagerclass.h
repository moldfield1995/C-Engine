////////////////////////////////////////////////////////////////////////////////
// Filename: shadermanagerclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _SHADERMANAGERCLASS_H_
#define _SHADERMANAGERCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "d3dclass.h"
#include "colorshaderclass.h"
#include "textureshaderclass.h"
#include "lightshaderclass.h"
#include "fontshaderclass.h"
#include "skydomeshaderclass.h"
#include "terrainshaderclass.h"
#include "lightshader.h"
#include "bumpmapshaderclass.h"
#include <vector>
#include <typeinfo>
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

	bool RenderColorShader(ID3D11DeviceContext*, int, const XMMATRIX&, const XMMATRIX&, const XMMATRIX&);
	bool RenderTextureShader(ID3D11DeviceContext*, int, const XMMATRIX&, const XMMATRIX&, const XMMATRIX&, ID3D11ShaderResourceView*);
	bool RenderLightShader(ID3D11DeviceContext*, int, const XMMATRIX&, const XMMATRIX&, const XMMATRIX&, ID3D11ShaderResourceView*, XMFLOAT3, XMFLOAT4);
	bool RenderFontShader(ID3D11DeviceContext*, int, const XMMATRIX&, const XMMATRIX&, const XMMATRIX&, ID3D11ShaderResourceView*, XMFLOAT4);
	bool RenderSkyDomeShader(ID3D11DeviceContext*, int, const XMMATRIX&, const XMMATRIX&, const XMMATRIX&, XMFLOAT4, XMFLOAT4);
	bool RenderTerrainShader(ID3D11DeviceContext*, int, const XMMATRIX&, const XMMATRIX&, const XMMATRIX&, ID3D11ShaderResourceView*, ID3D11ShaderResourceView*,
		ID3D11ShaderResourceView*, ID3D11ShaderResourceView*, XMFLOAT3, XMFLOAT4);
	bool RenderLightShading(ID3D11DeviceContext* deviceContext, int indexCount, const XMMATRIX &worldMatrix, const XMMATRIX &viewMatrix,
		const XMMATRIX &projectionMatrix, ID3D11ShaderResourceView* texture, XMFLOAT3 lightDirection, XMFLOAT4 ambientColor,
		XMFLOAT4 diffuseColor, XMFLOAT3 cameraPosition, XMFLOAT4 specularColor, float specularPower);
	bool RenderBumpMapShader(ID3D11DeviceContext* deviceContext, int indexCount, const XMMATRIX &worldMatrix, const XMMATRIX &viewMatrix,
		const XMMATRIX &projectionMatrix, ID3D11ShaderResourceView* colorTexture, ID3D11ShaderResourceView* normalMapTexture,
		XMFLOAT3 lightDirection, XMFLOAT4 diffuseColor, XMFLOAT4 ambinetColor);

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

	ColorShaderClass* m_ColorShader;
	TextureShaderClass* m_TextureShader;
	LightShaderClass* m_LightShader;
	FontShaderClass* m_FontShader;
	SkyDomeShaderClass* m_SkyDomeShader;
	TerrainShaderClass* m_TerrainShader;
	LightShader* m_LightShading;
	BumpMapShaderClass* m_bumpmapShader;
	std::vector<Shader*> m_shaders;
	static ShaderManagerClass* instance;
public:
	static ShaderManagerClass* GetInstance();
};

#endif


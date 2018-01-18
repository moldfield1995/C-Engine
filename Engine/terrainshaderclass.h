////////////////////////////////////////////////////////////////////////////////
// Filename: terrainshaderclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _TERRAINSHADERCLASS_H_
#define _TERRAINSHADERCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include <fstream>
#include "Shader.h"
using namespace DirectX;
using namespace std;


////////////////////////////////////////////////////////////////////////////////
// Class name: TerrainShaderClass
////////////////////////////////////////////////////////////////////////////////
class TerrainShaderClass:public Shader
{
private:
	struct MatrixBufferType
	{
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX projection;
	};

	struct LightBufferType
	{
		XMFLOAT4 diffuseColor;
		XMFLOAT3 lightDirection;
		float padding;
	};

public:
	TerrainShaderClass();
	TerrainShaderClass(const TerrainShaderClass&);
	~TerrainShaderClass();

	bool Initialize(ID3D11Device*, HWND);
	void Shutdown();
	//New
	bool Render(ID3D11DeviceContext * context, int indexCount, const XMMATRIX &worldMatrix, const XMMATRIX &viewMatrix, const XMMATRIX &projectionMatrix, std::vector< ID3D11ShaderResourceView*>* textures, LightClass * light = 0, XMFLOAT4* colour = 0);
	//Old
	bool Render(ID3D11DeviceContext*, int, const XMMATRIX&, const XMMATRIX&, const XMMATRIX&, ID3D11ShaderResourceView*, ID3D11ShaderResourceView*,
				ID3D11ShaderResourceView*, ID3D11ShaderResourceView*, XMFLOAT3, XMFLOAT4);

private:
	bool InitializeShader(ID3D11Device*, HWND, WCHAR*, WCHAR*);
	void ShutdownShader();
	void OutputShaderErrorMessage(ID3D10Blob*, HWND, WCHAR*);
	//New
	bool SetShaderParameters(ID3D11DeviceContext*, const XMMATRIX&, const XMMATRIX&, const XMMATRIX&, ID3D11ShaderResourceView*, XMFLOAT3, XMFLOAT4);
	//Old
	bool SetShaderParameters(ID3D11DeviceContext*, const XMMATRIX&, const XMMATRIX&, const XMMATRIX&, ID3D11ShaderResourceView*, ID3D11ShaderResourceView*,
							 ID3D11ShaderResourceView*, ID3D11ShaderResourceView*, XMFLOAT3, XMFLOAT4);
	void RenderShader(ID3D11DeviceContext*, int);

private:
	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11InputLayout* m_layout;
	ID3D11Buffer* m_matrixBuffer;
	ID3D11SamplerState* m_sampleState;
	ID3D11Buffer* m_lightBuffer;
};

#endif
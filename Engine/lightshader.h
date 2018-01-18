////////////////////////////////////////////////////////////////////////////////
// Filename: lightshaderclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _LIGHTSHADER_H_
#define _LIGHTSHADER_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <DirectXMath.h> 
#include "Shader.h"
using namespace DirectX;
#include <fstream>
using namespace std;


////////////////////////////////////////////////////////////////////////////////
// Class name: LightShaderClass
////////////////////////////////////////////////////////////////////////////////
class LightShader:public Shader
{
private:
	struct MatrixBufferType
	{
		XMMATRIX  world;
		XMMATRIX  view;
		XMMATRIX  projection;
	};

	struct CameraBufferType
	{
		XMFLOAT3  cameraPosition;
		float padding;
	};

	struct LightBufferType
	{
		XMFLOAT4  ambientColor;
		XMFLOAT4  diffuseColor;
		XMFLOAT3  lightDirection;
		float specularPower;
		XMFLOAT4  specularColor;
	};

public:
	LightShader();
	LightShader(const LightShader&);
	~LightShader();

	bool Initialize(ID3D11Device*, HWND);
	void Shutdown();
	//New
	bool Render(ID3D11DeviceContext * context, int indexCount, const XMMATRIX &worldMatrix, const XMMATRIX &viewMatrix, const XMMATRIX &projectionMatrix, ID3D11ShaderResourceView * textures, LightClass * light = 0, XMFLOAT4* colour = 0);
	//Old
	bool Render(ID3D11DeviceContext*, int, const XMMATRIX&, const XMMATRIX&, const XMMATRIX&, ID3D11ShaderResourceView*, XMFLOAT3, XMFLOAT4, XMFLOAT4,
		XMFLOAT3, XMFLOAT4, float);

private:
	bool InitializeShader(ID3D11Device*, HWND, WCHAR*, WCHAR*);
	void ShutdownShader();
	void OutputShaderErrorMessage(ID3D10Blob*, HWND, WCHAR*);

	bool SetShaderParameters(ID3D11DeviceContext*, const XMMATRIX&, const XMMATRIX&, const XMMATRIX&, ID3D11ShaderResourceView*, XMFLOAT3, XMFLOAT4, XMFLOAT4,
		XMFLOAT3, XMFLOAT4, float);
	void RenderShader(ID3D11DeviceContext*, int);

private:
	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11InputLayout* m_layout;
	ID3D11SamplerState* m_sampleState;
	ID3D11Buffer* m_matrixBuffer;
	ID3D11Buffer* m_cameraBuffer;
	ID3D11Buffer* m_lightBuffer;
};

#endif
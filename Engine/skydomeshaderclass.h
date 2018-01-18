////////////////////////////////////////////////////////////////////////////////
// Filename: skydomeshaderclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _SKYDOMESHADERCLASS_H_
#define _SKYDOMESHADERCLASS_H_


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
// Class name: SkyDomeShaderClass
////////////////////////////////////////////////////////////////////////////////
class SkyDomeShaderClass:public Shader
{
private:
	struct MatrixBufferType
	{
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX projection;
	};

	struct ColorBufferType
	{
		XMFLOAT4 apexColor;
		XMFLOAT4 centerColor;
	};

public:
	SkyDomeShaderClass();
	SkyDomeShaderClass(const SkyDomeShaderClass&);
	~SkyDomeShaderClass();

	bool Initialize(ID3D11Device*, HWND);
	void Shutdown();
	//New
	bool Render(ID3D11DeviceContext * context, int indexCount, const XMMATRIX &worldMatrix, const XMMATRIX &viewMatrix, const XMMATRIX &projectionMatrix, std::vector< ID3D11ShaderResourceView*>* textures, LightClass * light = 0, XMFLOAT4* colour = 0);
	//Old
	bool Render(ID3D11DeviceContext*, int, const XMMATRIX&, const XMMATRIX&, const XMMATRIX&, XMFLOAT4, XMFLOAT4);

private:
	bool InitializeShader(ID3D11Device*, HWND, WCHAR*, WCHAR*);
	void ShutdownShader();
	void OutputShaderErrorMessage(ID3D10Blob*, HWND, WCHAR*);

	bool SetShaderParameters(ID3D11DeviceContext*, const XMMATRIX&, const XMMATRIX&, const XMMATRIX&, XMFLOAT4, XMFLOAT4);
	void RenderShader(ID3D11DeviceContext*, int);

private:
	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11InputLayout* m_layout;
	ID3D11Buffer* m_matrixBuffer;
	ID3D11Buffer* m_colorBuffer;
};

#endif


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

//Created By RasterTeck
//Updated By Matthew Oldfield

////////////////////////////////////////////////////////////////////////////////
// Class name: SliderShaderClass
////////////////////////////////////////////////////////////////////////////////
class SliderShaderClass:public Shader
{
private:
	struct MatrixBufferType
	{
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX projection;
	};
public:
	struct SliderBuffer
	{
		XMFLOAT4 colour;
		XMFLOAT2A UVClip;
		
	};

public:
	SliderShaderClass();
	SliderShaderClass(const SliderShaderClass&);
	~SliderShaderClass();

	bool Initialize(ID3D11Device*, HWND);
	void Shutdown();
	bool Render(ID3D11DeviceContext * context, int indexCount, const XMMATRIX &worldMatrix, const XMMATRIX &viewMatrix, const XMMATRIX &projectionMatrix, std::vector< ID3D11ShaderResourceView*>* Sliders, LightClass * light = 0, void* shaderData = 0);


private:
	bool InitializeShader(ID3D11Device*, HWND, WCHAR*, WCHAR*);
	void ShutdownShader();
	void OutputShaderErrorMessage(ID3D10Blob*, HWND, WCHAR*);

	bool SetShaderParameters(ID3D11DeviceContext*, const XMMATRIX&, const XMMATRIX&, const XMMATRIX&, ID3D11ShaderResourceView*, SliderBuffer*);
	void RenderShader(ID3D11DeviceContext*, int);

private:
	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11InputLayout* m_layout;
	ID3D11Buffer* m_matrixBuffer;
	ID3D11SamplerState* m_sampleState;

	ID3D11Buffer* m_sliderBuffer;
};

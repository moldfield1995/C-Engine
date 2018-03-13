#pragma once
#include "UIComponent.h"
#include "bitmapclass.h"
#include "Shader.h"
#include <vector>

class UIImage:
	public UIComponent
{
public:
	UIImage(char* textureFileName);
	~UIImage();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& baseViewMatrix, const XMMATRIX& orthoMatrix);
	void virtual Destroy();

	XMFLOAT4 GetColour();
	void virtual SetColour(XMFLOAT4 value);
protected:
	XMFLOAT4 colour;
	BitmapClass *bitmapClass;
private:
	Shader *shader;
	std::vector<ID3D11ShaderResourceView*>* textures;
	char* textureFileName;
};


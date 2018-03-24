#pragma once
#include "UIComponent.h"
#include "fontclass.h"

using namespace std;

//Updated In Final Year
//Created By Matthew Oldfield

class UIText :
	public UIComponent
{
private:

	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
	};

public:
	UIText(XMFLOAT4 colour, string initalText);
	~UIText();
	void virtual Initalize();
	void virtual Update();
	void virtual Render(ID3D11DeviceContext* deviceContext, const XMMATRIX& worldMatrix, const XMMATRIX& baseViewMatrix, const XMMATRIX& orthoMatrix) ;
	void virtual Destroy();
	void UpdateString(string text);
	void SetShadowColour(XMFLOAT4 colour);
protected:
	XMFLOAT4 pixleColour, shadowColour;
	XMMATRIX shadowOffset;
	string currentText;
private:
	ID3D11Buffer* vertexBuffer, *indexBuffer;
	int vertexCount, indexCount, activeIndexs;
	Shader* shader;
	FontClass* font;
	VertexType* vertices;
	unsigned int stride;
};


#include "UIText.h"
#include "fontshaderclass.h"
#include "shadermanagerclass.h"
#include "fontmanagerclass.h"
int UIText::screenHeight = 0;
int UIText::screenWidth = 0;
UIText::UIText(XMFLOAT4 colour, string initalText, PivotPosition pivot)
	:UIComponent(pivot)
{
	active = false;
	killComponet = false;
	renders = true;
	scale = Float3(1.0f);
	pixleColour = colour;
	currentText = initalText;
	shadowColour = XMFLOAT4(0.0f, 0.0f, 0.0f, 0.0f);
	indexBuffer = vertexBuffer = 0;
	stride = sizeof(VertexType);
	shadowOffset = XMMatrixTranslation(2.0f,-2.0f,0.0f);
	shader = 0;
	font = 0;
	vertices = 0;
}


UIText::~UIText()
{
}

void UIText::Initalize()
{
	unsigned long* indices;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT result;
	int i;
	ID3D11Device* device = D3DClass::GetInstance()->GetDevice();
	//checks if staic varibles have been set
	if (screenWidth == 0 || screenHeight == 0)
		D3DClass::GetInstance()->GetScreenReserlution(screenWidth, screenHeight);

	// Max carictor length is 128
	vertexCount = 6 * 128;
	indexCount = 6 * 128;

	// Create the vertex array.
	vertices = new VertexType[vertexCount];

	// Create the index array.
	indices = new unsigned long[indexCount];


	// Initialize vertex array to zeros at first.
	memset(vertices, 0, (sizeof(VertexType) * vertexCount));

	// Initialize the index array.
	for (i = 0; i<indexCount; i++)
	{
		indices[i] = i;
	}

	// Set up the description of the dynamic vertex buffer.
	vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the vertex data.
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Create the vertex buffer.
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &vertexBuffer);
	if (FAILED(result))
	{
		OutputDebugString(L"Failed to create vertex buffer | Inialize | UIText");
	}

	// Set up the description of the static index buffer.
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * indexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the index data.
	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// Create the index buffer.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &indexBuffer);
	if (FAILED(result))
	{
		OutputDebugString(L"Failed to Create index buffer | Initalize | UIText");
	}

	// Release the index array as it is no longer needed.
	delete[] indices;
	indices = 0;
	//End of D3DBuffet creation

	shader = ShaderManagerClass::GetInstance()->GetShader<FontShaderClass>();
	
	font = FontManagerClass::GetInstance()->GetFont(0);
	UpdateString(currentText);
}

void UIText::Update()
{
}

void UIText::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & baseViewMatrix, const XMMATRIX & orthoMatrix)
{
	XMMATRIX renderMatrix, rotationMatrix, scaleMatrix, positionMatrix;
	Float3 rotationInRadens = rotation * 0.0174532925f;
	rotationMatrix = XMMatrixRotationRollPitchYaw(rotationInRadens.X, rotationInRadens.Y, rotationInRadens.Z);
	scaleMatrix = XMMatrixScaling(scale.X, scale.Y, scale.Z);
	positionMatrix = XMMatrixTranslation(position.X, position.Y, position.Z);
	unsigned int offset = 0;
	//check if the shadow alpha is grater than 0
	if (shadowColour.z > 0.0f)
	{
		renderMatrix = XMMatrixMultiply(positionMatrix, shadowOffset);
		renderMatrix = XMMatrixMultiply(worldMatrix, renderMatrix);
		renderMatrix = XMMatrixMultiply(scaleMatrix, renderMatrix);
		renderMatrix = XMMatrixMultiply(rotationMatrix, renderMatrix);
		deviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
		deviceContext->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);
		deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		shader->Render(deviceContext, activeIndexs, renderMatrix, baseViewMatrix, orthoMatrix, font->GetTextures(),0,&pixleColour);
	}
	renderMatrix = XMMatrixMultiply(worldMatrix, positionMatrix);
	renderMatrix = XMMatrixMultiply(rotationMatrix, renderMatrix);
	renderMatrix = XMMatrixMultiply(scaleMatrix, renderMatrix);
	deviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
	deviceContext->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	shader->Render(deviceContext, activeIndexs, renderMatrix, baseViewMatrix, orthoMatrix, font->GetTextures(), 0, &pixleColour);
}

void UIText::Destroy()
{
	if (indexBuffer != 0)
	{
		indexBuffer->Release();
		delete indexBuffer;
		indexBuffer = 0;
	}
	if (vertexBuffer != 0)
	{
		vertexBuffer->Release();
		delete vertexBuffer;
		vertexBuffer = 0;
	}
	shader = 0;
	font = 0;
	delete[] vertices;
	vertices = 0;
	killComponet = true;
}

void UIText::UpdateString(string text)
{
	int numLetters;
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	void* verticesPtr;
	HRESULT result;
	ID3D11DeviceContext* deviceContext;
	// Get the number of letters in the sentence.
	numLetters = text.length();

	// Check for possible buffer overflow.
	if (numLetters > vertexCount/6)
	{
		OutputDebugString(L"Buffer Overflow Redusing chars | UpdateString | UIText");
		text.erase(text.begin() + vertexCount / 6, text.end());
		numLetters = text.length();
	}

	// Use the font class to build the vertex array from the sentence text and sentence draw location.
	activeIndexs = font->BuildVertexArray((void*)vertices, text.data(), -screenWidth / 2, screenHeight / 2);
	deviceContext = D3DClass::GetInstance()->GetDeviceContext();
	// Lock the vertex buffer.
	result = deviceContext->Map(vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(result))
	{
		OutputDebugString(L"Failed to Map Data | UpdateString | UIText");
	}

	// Get a pointer to the mapped resource data pointer.
	verticesPtr = (void*)mappedResource.pData;

	// Copy ACTIVE vertexs into the vertex buffer.
	memcpy(verticesPtr, (void*)vertices, (sizeof(VertexType) * activeIndexs ));

	// Unlock the vertex buffer.
	deviceContext->Unmap(vertexBuffer, 0);

}

void UIText::SetShadowColour(XMFLOAT4 colour)
{
	shadowColour = colour;
}

void UIText::SetPosition(Float3 value, bool centerX, bool centerY)
{
	position = value + pivotOffset;
	if (centerX)
		position.X -= font->GetFontWidth();
	if (centerY)
		position.Y += font->GetFontHeight();
}

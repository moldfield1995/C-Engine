#include "UIText.h"





UIText::UIText(XMFLOAT4 colour, string initalText)
{
	pixleColour = colour;
	currentText = initalText;
	shadowColour = XMFLOAT4(0.0f, 0.0f, 0.0f, 0.0f);
	indexBuffer = vertexBuffer = 0;
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
		
	}

	// Release the index array as it is no longer needed.
	delete[] indices;
	indices = 0;


}

void UIText::Update()
{
}

void UIText::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & baseViewMatrix, const XMMATRIX & orthoMatrix)
{
}

void UIText::Destroy()
{
}

void UIText::UpdateString(string text)
{
	int numLetters;
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	void* verticesPtr;
	HRESULT result;
	ID3D11DeviceContext* deviceContext;
	const char* charText = text.data();
	// Get the number of letters in the sentence.
	numLetters = text.length();

	// Check for possible buffer overflow.
	if (numLetters > vertexCount/6)
	{
		
	}
	activeIndexs = numLetters * 6;
	// Use the font class to build the vertex array from the sentence text and sentence draw location.
	font->BuildVertexArray((void*)vertices, charText, position.X, position.Y);
	deviceContext = D3DClass::GetInstance()->GetDeviceContext();
	// Lock the vertex buffer.
	result = deviceContext->Map(vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(result))
	{
		
	}

	// Get a pointer to the mapped resource data pointer.
	verticesPtr = (void*)mappedResource.pData;

	// Copy the vertex array into the vertex buffer.
	memcpy(verticesPtr, (void*)vertices, (sizeof(VertexType) * vertexCount));

	// Unlock the vertex buffer.
	deviceContext->Unmap(vertexBuffer, 0);

}

void UIText::SetShadowColour(XMFLOAT4 colour)
{
}

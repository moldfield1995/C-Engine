#include "ModelClass.h"


ModelClass::ModelClass()
{
}


ModelClass::~ModelClass()
{
}

bool ModelClass::Initialize(ID3D11Device* device, char* modelFilename)
{
	bool result;
	m_fileLoaction = modelFilename;
	std::string fileName = modelFilename;
	if (fileName.substr(fileName.find_last_of('.') + 1) == "obj")
		result = LoadObjModel(modelFilename);
	else
		result = LoadModel(modelFilename);
	if (!result)
		return false;
	if (!InitializeBuffers(device))
		return false;
	return true;
}

void ModelClass::ShutDown()
{
	// Shutdown the vertex and index buffers.
	ShutdownBuffers();

	// Release the model data.
	ReleaseModel();
}

void ModelClass::Render(ID3D11DeviceContext* deviceContext)
{
	RenderBuffers(deviceContext);
}

int ModelClass::GetIndexCount()
{
	return m_indexCount;
}

const ModelClass::ModelType* ModelClass::GetModelData()
{
	return m_model;
}

const char * ModelClass::GetFileName()
{
	return m_fileLoaction;
}



bool ModelClass::LoadModel(char* modelFilename)
{
	std::ifstream fin;
	char input;
	int i;
	// Open the model file.
	fin.open(modelFilename);

	// If it could not open the file then exit.
	if (fin.fail())
	{
		fin.close();
		return false;
	}

	// Read up to the value of vertex count.
	fin.get(input);
	while (input != ':')
	{
		fin.get(input);
	}

	// Read in the vertex count.
	fin >> m_vertexCount;
	// Set the number of indices to be the same as the vertex count.
	m_indexCount = m_vertexCount;

	// Create the model using the vertex count that was read in.
	m_model = new ModelType[m_vertexCount];
	if (!m_model)
	{
		fin.close();
		return false;
	}

	// Read up to the beginning of the data.
	fin.get(input);
	while (input != ':')
	{
		fin.get(input);
	}
	fin.get(input);
	fin.get(input);

	// Read in the vertex data.
	for (i = 0; i < m_vertexCount; i++)
	{
		fin >> m_model[i].x >> m_model[i].y >> m_model[i].z;
		fin >> m_model[i].tu >> m_model[i].tv;
		fin >> m_model[i].nx >> m_model[i].ny >> m_model[i].nz;
	}

	// Close the model file.
	fin.close();

	return true;
}

bool ModelClass::LoadObjModel(char * modelFileName)
{
	int vertexCount, textureCount, normalCount, faceCount, maxCount;
	int vertexIndex, texcoordIndex, normalIndex, faceIndex, vIndex, tIndex, nIndex;
	char input, temp;
	std::ifstream fin;
	//Setup all the arrays and Indexs
	vertexIndex = texcoordIndex = normalIndex = faceIndex = 0;
	if (!ReadCounts(modelFileName, vertexCount, textureCount, normalCount, faceCount))
		return false;
	//Get the max count to initalize an array of modelInput
	maxCount = vertexCount > textureCount ? vertexCount : textureCount;
	maxCount = maxCount > normalCount ? maxCount : normalCount;
	ModelType *modelInput = new ModelType[maxCount];
	FaceType *faceInput = new FaceType[faceCount];

	fin.open(modelFileName);
	if (fin.fail())
		return false;

	// Read in the vertices, texture coordinates, and normals into the data structures.
	// Important: Also convert to left hand coordinate system since Maya uses right hand coordinate system.
	fin.get(input);
	while (!fin.eof())
	{
		if (input == 'v')
		{
			fin.get(input);

			// Read in the vertices.
			if (input == ' ')
			{
				fin >> modelInput[vertexIndex].x >> modelInput[vertexIndex].y >> modelInput[vertexIndex].z;

				// Invert the Z vertex to change to left hand system.
				modelInput[vertexIndex].z = modelInput[vertexIndex].z * -1.0f;
				vertexIndex++;
			}

			// Read in the texture uv coordinates.
			if (input == 't')
			{
				fin >> modelInput[texcoordIndex].tu >> modelInput[texcoordIndex].tv;

				// Invert the V texture coordinates to left hand system.
				modelInput[texcoordIndex].tv = 1.0f - modelInput[texcoordIndex].tv;
				texcoordIndex++;
			}

			// Read in the normals.
			if (input == 'n')
			{
				fin >> modelInput[normalIndex].nx >> modelInput[normalIndex].ny >> modelInput[normalIndex].nz;

				// Invert the Z normal to change to left hand system.
				modelInput[normalIndex].nz = modelInput[normalIndex].nz * -1.0f;
				normalIndex++;
			}
		}

		// Read in the faces.
		if (input == 'f')
		{
			fin.get(input);
			if (input == ' ')
			{
				// Read the face data in backwards to convert it to a left hand system from right hand system.
				fin >> faceInput[faceIndex].vIndex3 >> temp >> faceInput[faceIndex].tIndex3 >> temp >> faceInput[faceIndex].nIndex3
					>> faceInput[faceIndex].vIndex2 >> temp >> faceInput[faceIndex].tIndex2 >> temp >> faceInput[faceIndex].nIndex2
					>> faceInput[faceIndex].vIndex1 >> temp >> faceInput[faceIndex].tIndex1 >> temp >> faceInput[faceIndex].nIndex1;
				faceIndex++;
			}
		}

		// Read in the remainder of the line.
		while (input != '\n')
		{
			fin.get(input);
		}

		// Start reading the beginning of the next line.
		fin.get(input);
	}

	// Close the file.
	fin.close();

	//Initalize Model Varibles
	m_vertexCount = m_indexCount = faceCount * 3;
	m_model = new ModelType[m_vertexCount];
	int vertItt = 0;
	// Now loop through all the faces 
	for (int i = 0; i < faceIndex; i++)
	{
		vIndex = faceInput[i].vIndex1 - 1;
		tIndex = faceInput[i].tIndex1 - 1;
		nIndex = faceInput[i].nIndex1 - 1;

		m_model[vertItt].x = modelInput[vIndex].x; m_model[vertItt].y = modelInput[vIndex].y;  m_model[vertItt].z = modelInput[vIndex].z;
		m_model[vertItt].tu = modelInput[tIndex].tu; m_model[vertItt].tv = modelInput[tIndex].tv;
		m_model[vertItt].nx = modelInput[nIndex].nx; m_model[vertItt].nx = modelInput[nIndex].ny; m_model[vertItt].nx = modelInput[nIndex].nz;
		vertItt++;

		vIndex = faceInput[i].vIndex2 - 1;
		tIndex = faceInput[i].tIndex2 - 1;
		nIndex = faceInput[i].nIndex2 - 1;

		m_model[vertItt].x = modelInput[vIndex].x; m_model[vertItt].y = modelInput[vIndex].y;  m_model[vertItt].z = modelInput[vIndex].z;
		m_model[vertItt].tu = modelInput[tIndex].tu; m_model[vertItt].tv = modelInput[tIndex].tv;
		m_model[vertItt].nx = modelInput[nIndex].nx; m_model[vertItt].nx = modelInput[nIndex].ny; m_model[vertItt].nx = modelInput[nIndex].nz;
		vertItt++;

		vIndex = faceInput[i].vIndex3 - 1;
		tIndex = faceInput[i].tIndex3 - 1;
		nIndex = faceInput[i].nIndex3 - 1;

		m_model[vertItt].x = modelInput[vIndex].x; m_model[vertItt].y = modelInput[vIndex].y;  m_model[vertItt].z = modelInput[vIndex].z;
		m_model[vertItt].tu = modelInput[tIndex].tu; m_model[vertItt].tv = modelInput[tIndex].tv;
		m_model[vertItt].nx = modelInput[nIndex].nx; m_model[vertItt].nx = modelInput[nIndex].ny; m_model[vertItt].nx = modelInput[nIndex].nz;
		vertItt++;
	}

	//cleanup
	delete[] modelInput;
	delete[] faceInput;

	return true;
}
//Rasterteck model to text parser
bool ModelClass::ReadCounts(char * filename, int & vertexCount, int & textureCount, int & normalCount, int & faceCount)
{
	std::ifstream fin;
	char input;


	// Initialize the counts.
	vertexCount = 0;
	textureCount = 0;
	normalCount = 0;
	faceCount = 0;

	// Open the file.
	fin.open(filename);

	// Check if it was successful in opening the file.
	if (fin.fail() == true)
	{
		return false;
	}

	// Read from the file and continue to read until the end of the file is reached.
	fin.get(input);
	while (!fin.eof())
	{
		// If the line starts with 'v' then count either the vertex, the texture coordinates, or the normal vector.
		if (input == 'v')
		{
			fin.get(input);
			if (input == ' ') { vertexCount++; }
			if (input == 't') { textureCount++; }
			if (input == 'n') { normalCount++; }
		}

		// If the line starts with 'f' then increment the face count.
		if (input == 'f')
		{
			fin.get(input);
			if (input == ' ') { faceCount++; }
		}

		// Otherwise read in the remainder of the line.
		while (input != '\n')
		{
			fin.get(input);
		}

		// Start reading the beginning of the next line.
		fin.get(input);
	}

	// Close the file.
	fin.close();
	return true;
}

void ModelClass::ReleaseModel()
{
	if (m_model)
	{
		delete[] m_model;
		m_model = 0;
	}

	return;
}



bool ModelClass::InitializeBuffers(ID3D11Device* device)
{
	VertexType* vertices;
	unsigned long* indices;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT result;
	int i;


	// Create the vertex array.
	vertices = new VertexType[m_vertexCount];
	if (!vertices)
	{
		return false;
	}

	// Create the index array.
	indices = new unsigned long[m_indexCount];
	if (!indices)
	{
		return false;
	}
	float xsize, ysize, zsize;
	xsize = m_model[0].x;
	ysize = m_model[0].y;
	zsize = m_model[0].z;
	// Load the vertex array and index array with data.
	for (i = 0; i < m_vertexCount; i++)
	{
		if (xsize < m_model[i].x)
			xsize = m_model[i].x;
		if (ysize < m_model[i].y)
			ysize = m_model[i].y;
		if (zsize < m_model[i].z)
			zsize = m_model[i].z;
		vertices[i].position = XMFLOAT3(m_model[i].x, m_model[i].y, m_model[i].z);
		vertices[i].texture = XMFLOAT2(m_model[i].tu, m_model[i].tv);
		vertices[i].normal = XMFLOAT3(m_model[i].nx, m_model[i].ny, m_model[i].nz);

		indices[i] = i;
	}
	// Set up the description of the static vertex buffer.
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * m_vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the vertex data.
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Now create the vertex buffer.
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	// Set up the description of the static index buffer.
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * m_indexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the index data.
	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// Create the index buffer.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	// Release the arrays now that the vertex and index buffers have been created and loaded.
	delete[] vertices;
	vertices = 0;

	delete[] indices;
	indices = 0;

	return true;
}

void ModelClass::ShutdownBuffers()
{
	// Release the index buffer.
	if (m_indexBuffer)
	{
		m_indexBuffer->Release();
		m_indexBuffer = 0;
	}

	// Release the vertex buffer.
	if (m_vertexBuffer)
	{
		m_vertexBuffer->Release();
		m_vertexBuffer = 0;
	}

	return;
}

void ModelClass::RenderBuffers(ID3D11DeviceContext* deviceContext)
{
	unsigned int stride;
	unsigned int offset;


	// Set vertex buffer stride and offset.
	stride = sizeof(VertexType);
	offset = 0;

	// Set the vertex buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);

	// Set the index buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

	// Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	return;
}

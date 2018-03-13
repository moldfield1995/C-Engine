///////////////////////////////////////////////////////////////////////////////
// Filename: userinterfaceclass.cpp
///////////////////////////////////////////////////////////////////////////////
#include "userinterfaceclass.h"


UserInterfaceClass::UserInterfaceClass()
{
	m_Font1 = 0;
	m_FpsString = 0;
	//m_MiniMap = 0;
	m_SpawnType = 0;
}


UserInterfaceClass::UserInterfaceClass(const UserInterfaceClass& other)
{
}


UserInterfaceClass::~UserInterfaceClass()
{
}


bool UserInterfaceClass::Initialize(D3DClass* Direct3D, int screenHeight, int screenWidth)
{
	bool result;


	// Create the first font object.
	m_Font1 = new FontClass;
	if (!m_Font1)
	{
		return false;
	}

	// Initialize the first font object.
	result = m_Font1->Initialize(Direct3D->GetDevice(), Direct3D->GetDeviceContext(), "../Engine/data/font/font01.txt", 
								 "../Engine/data/font/font01.tga", 32.0f, 3);
	if (!result)
	{
		return false;
	}

	// Create the text object for the fps string.
	m_FpsString = new TextClass;
	if (!m_FpsString)
	{
		return false;
	}

	// Initialize the fps text string.
	result = m_FpsString->Initialize(Direct3D->GetDevice(), Direct3D->GetDeviceContext(), screenWidth, screenHeight, 16, false, m_Font1, 
									 "Fps: 0", 10, 70, 0.0f, 1.0f, 0.0f);
	if (!result)
	{
		return false;
	}
	m_SpawnType = new TextClass;
	if (!m_SpawnType)
	{
		return false;
	}

	result = m_SpawnType->Initialize(Direct3D->GetDevice(), Direct3D->GetDeviceContext(), screenWidth, screenHeight, 30, false, m_Font1,
		"Object Edit: Possition", 10, 55, 0.0f, 1.0f, 0.0f);
	if (!result)
	{
		return false;
	}
	// Initial the previous frame fps.
	m_previousFps = -1;

	// Create the mini-map object.
	//m_MiniMap = new MiniMapClass;
	//if(!m_MiniMap)
	//{
	//	return false;
	//}

	//// Initialize the mini-map object.
	//result = m_MiniMap->Initialize(Direct3D->GetDevice(), Direct3D->GetDeviceContext(), screenWidth, screenHeight, 1025, 1025);
	//if(!m_MiniMap)
	//{
	//	return false;
	//}

	return true;
}


void UserInterfaceClass::Shutdown()
{
	//// Release the mini-map object.
	//if(m_MiniMap)
	//{
	//	m_MiniMap->Shutdown();
	//	delete m_MiniMap;
	//	m_MiniMap = 0;
	//}



	// Release the fps text string.
	if(m_FpsString)
	{
		m_FpsString->Shutdown();
		delete m_FpsString;
		m_FpsString = 0;
	}

	// Release the font object.
	if(m_Font1)
	{
		m_Font1->Shutdown();
		delete m_Font1;
		m_Font1 = 0;
	}

	return;
}


bool UserInterfaceClass::Frame(ID3D11DeviceContext* deviceContext, int fps,float posX,float posZ, bool objectSpawned, SpawnState state)
{
	bool result;


	// Update the fps string.
	result = UpdateFpsString(deviceContext, fps);
	if(!result)
	{
		return false;
	}

	if (objectSpawned)
	{
		char finalString[30];
		char tempString[16];
		strcpy_s(finalString, "Object Edit: ");
		switch (state)
		{
		case SpawnState::position:
			strcpy_s(tempString, "Position");
			break;
		case SpawnState::rotation:
			strcpy_s(tempString, "Rotation");
			break;
		case SpawnState::scale:
			strcpy_s(tempString, "Scale");
			break;
		case SpawnState::model:
			strcpy_s(tempString, "Model");
			break;
		case SpawnState::texture:
			strcpy_s(tempString, "Texture");
			break;
		case SpawnState::shader:
			strcpy_s(tempString, "Shader");
			break;
		case SpawnState::bumpMap:
			strcpy_s(tempString, "BumpMap");
			break;
		default:
			break;
		}
		strcat_s(finalString, tempString);
		m_SpawnType->UpdateSentence(deviceContext, m_Font1, finalString, 10, 55, 0.0f, 1.0f, 0.0f);
	}
	else
	{
		char finalString[2];
		strcpy_s(finalString, "");
		m_SpawnType->UpdateSentence(deviceContext, m_Font1, finalString, 10, 55, 0.0f, 1.0f, 0.0f);
	}

	// Update the mini-map position indicator.
	//m_MiniMap->PositionUpdate(posX, posZ);

	return true;
}


bool UserInterfaceClass::Render(D3DClass* Direct3D, ShaderManagerClass* ShaderManager, const XMMATRIX& worldMatrix, const XMMATRIX& viewMatrix, 
								const XMMATRIX& orthoMatrix)
{
	bool result;


	// Turn off the Z buffer and enable alpha blending to begin 2D rendering.
	Direct3D->TurnZBufferOff();
	Direct3D->EnableAlphaBlending();

	// Render the fps string.
	m_FpsString->Render(Direct3D->GetDeviceContext(), ShaderManager, worldMatrix, viewMatrix, orthoMatrix, m_Font1->GetTexture());

	// Render the video card strings.
	//m_VideoStrings[0].Render(Direct3D->GetDeviceContext(), ShaderManager, worldMatrix, viewMatrix, orthoMatrix, m_Font1->GetTexture());
	m_SpawnType->Render(Direct3D->GetDeviceContext(), ShaderManager, worldMatrix, viewMatrix, orthoMatrix, m_Font1->GetTexture());

	// Turn off alpha blending now that the text has been rendered.
	Direct3D->DisableAlphaBlending();

	// Render the mini-map.
	//result = m_MiniMap->Render(Direct3D->GetDeviceContext(), ShaderManager, worldMatrix, viewMatrix, orthoMatrix);
	//if(!result)
	//{
	//	return false;
	//}

	// Turn the Z buffer back on now that the 2D rendering has completed.
	Direct3D->TurnZBufferOn();

	return true;
}


bool UserInterfaceClass::UpdateFpsString(ID3D11DeviceContext* deviceContext, int fps)
{
	char tempString[16];
	char finalString[16];
	float red, green, blue;
	bool result;


	// Check if the fps from the previous frame was the same, if so don't need to update the text string.
	if(m_previousFps == fps)
	{
		return true;
	}

	// Store the fps for checking next frame.
	m_previousFps = fps;

	// Truncate the fps to below 100,000.
	if(fps > 99999)
	{
		fps = 99999;
	}

	// Convert the fps integer to string format.
	_itoa_s(fps, tempString, 10);

	// Setup the fps string.
	strcpy_s(finalString, "Fps: ");
	strcat_s(finalString, tempString);

	// If fps is 60 or above set the fps color to green.
	if(fps >= 60)
	{
		red = 0.0f;
		green = 1.0f;
		blue = 0.0f;
	}

	// If fps is below 60 set the fps color to yellow.
	if(fps < 60)
	{
		red = 1.0f;
		green = 1.0f;
		blue = 0.0f;
	}

	// If fps is below 30 set the fps color to red.
	if(fps < 30)
	{
		red = 1.0f;
		green = 0.0f;
		blue = 0.0f;
	}

	// Update the sentence vertex buffer with the new string information.
	result = m_FpsString->UpdateSentence(deviceContext, m_Font1, finalString, 10, 70, red, green, blue);
	if(!result)
	{
		return false;
	}

	return true;
}


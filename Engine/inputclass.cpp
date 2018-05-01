////////////////////////////////////////////////////////////////////////////////
// Filename: inputclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "inputclass.h"
#include <algorithm>
#include "d3dclass.h"
#include "cameraclass.h"
InputClass* InputClass::instance = 0;

InputClass::InputClass()
{
	m_directInput = 0;
	m_keyboard = 0;
	m_mouse = 0;
	m_leapToWorldScale = Float3(.04f, .04f, -.04f);
	m_leapOffset = Float3(0.0f, -7.0f, 0.0f);
}


InputClass::InputClass(const InputClass& other)
{
}


InputClass::~InputClass()
{
}


bool InputClass::Initialize(HINSTANCE hinstance, HWND hwnd, int screenWidth, int screenHeight)
{
	HRESULT result;


	// Store the screen size which will be used for positioning the mouse cursor.
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;

	// Initialize the location of the mouse on the screen.
	m_mouseX = 0;
	m_mouseY = 0;
	currentX = 0;
	currentY = 0;
	// Initialize the main direct input interface.
	result = DirectInput8Create(hinstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_directInput, NULL);
	if (FAILED(result))
	{
		return false;
	}

	// Initialize the direct input interface for the keyboard.
	result = m_directInput->CreateDevice(GUID_SysKeyboard, &m_keyboard, NULL);
	if (FAILED(result))
	{
		return false;
	}

	// Set the data format.  In this case since it is a keyboard we can use the predefined data format.
	result = m_keyboard->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(result))
	{
		return false;
	}

	// Set the cooperative level of the keyboard to share with other programs.
	result = m_keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(result))
	{
		return false;
	}

	// Now acquire the keyboard.
	result = m_keyboard->Acquire();
	if (FAILED(result))
	{
		return false;
	}

	// Initialize the direct input interface for the mouse.
	result = m_directInput->CreateDevice(GUID_SysMouse, &m_mouse, NULL);
	if (FAILED(result))
	{
		return false;
	}

	// Set the data format for the mouse using the pre-defined mouse data format.
	result = m_mouse->SetDataFormat(&c_dfDIMouse);
	if (FAILED(result))
	{
		return false;
	}

	// Set the cooperative level of the mouse to share with other programs.
	result = m_mouse->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(result))
	{
		return false;
	}

	// Acquire the mouse.
	result = m_mouse->Acquire();
	if (FAILED(result))
	{
		return false;
	}

	m_LeapControler = Controller();

	instance = this;
	return true;
}


void InputClass::Shutdown()
{
	// Release the mouse.
	if (m_mouse)
	{
		m_mouse->Unacquire();
		m_mouse->Release();
		m_mouse = 0;
	}

	// Release the keyboard.
	if (m_keyboard)
	{
		m_keyboard->Unacquire();
		m_keyboard->Release();
		m_keyboard = 0;
	}

	// Release the main interface to direct input.
	if (m_directInput)
	{
		m_directInput->Release();
		m_directInput = 0;
	}

	return;
}


bool InputClass::Frame()
{
	bool result;


	// Read the current state of the keyboard.
	result = ReadKeyboard();
	if (!result)
	{
		return false;
	}

	// Read the current state of the mouse.
	result = ReadMouse();
	if (!result)
	{
		return false;
	}

	ReadLeap();

	// Process the changes in the mouse and keyboard.
	ProcessInput();

	return true;
}


bool InputClass::ReadKeyboard()
{
	HRESULT result;

	std::copy(std::begin(m_keyboardState), std::end(m_keyboardState), m_OldKeyboardState);
	// Read the keyboard device.
	result = m_keyboard->GetDeviceState(sizeof(m_keyboardState), (LPVOID)&m_keyboardState);
	if (FAILED(result))
	{
		// If the keyboard lost focus or was not acquired then try to get control back.
		if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
		{
			m_keyboard->Acquire();
		}
		else
		{
			return false;
		}
	}

	return true;
}


bool InputClass::ReadMouse()
{
	HRESULT result;

	m_OldMouseState = m_mouseState;
	// Read the mouse device.
	result = m_mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&m_mouseState);
	
	if (FAILED(result))
	{
		// If the mouse lost focus or was not acquired then try to get control back.
		if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
		{
			m_mouse->Acquire();
		}
		else
		{
			return false;
		}
	}

	return true;
}

void InputClass::ReadLeap()
{
	if (m_LeapControler.isConnected())
	{
		m_LeapFrame = m_LeapControler.frame();

		if (CameraClass::GetActiveCamera() && D3DClass::GetInstance() && m_LeapFrame.isValid() && m_LeapFrame.hands()[0].isValid())
		{
			D3DClass* directInstance;
			CameraClass* activeCamera;
			XMMATRIX projectionMatirx, viewMatrix, worldMatrix;
			int screenHight, screenWidth;
			float screenDepth, screenNear;
			directInstance = D3DClass::GetInstance();
			activeCamera = CameraClass::GetActiveCamera();

			directInstance->GetScreenReserlution(screenWidth, screenHight);
			directInstance->GetScreenDepth(screenNear, screenDepth);
			directInstance->GetProjectionMatrix(projectionMatirx);
			directInstance->GetWorldMatrix(worldMatrix);
			activeCamera->GetViewMatrix(viewMatrix);

			Float3 handpos = (Float3(m_LeapFrame.hands()[0].palmPosition())* m_leapToWorldScale) + m_leapOffset;
			XMVECTOR posvector = XMVectorSet(handpos.X, handpos.Y, handpos.Z, 1.0f);
			XMVECTOR screenspace = XMVector3Project(posvector, 0.0f, 0.0f, screenWidth, screenHight, screenNear, screenDepth, projectionMatirx, viewMatrix, worldMatrix);
			m_leapScreenPosition.X = screenspace.m128_f32[0];
			m_leapScreenPosition.Y = -screenspace.m128_f32[1];
		}
	}
}


void InputClass::ProcessInput()
{
	// Update the location of the mouse cursor based on the change of the mouse location during the frame.
	if (m_mouseState.lX != m_OldMouseState.lX || m_mouseState.lY != m_OldMouseState.lY)
	{
		int oldX, oldY;
		oldX = m_mouseX;
		oldY = m_mouseY;
		m_mouseX += m_mouseState.lX;
		m_mouseY += m_mouseState.lY;
		m_mouseX = m_mouseX - oldX;
		m_mouseY = m_mouseY - oldY;
		
		currentX += m_mouseState.lX;
		currentY += m_mouseState.lY;
	}

	return;
}

InputClass* InputClass::GetInstance()
{
	return instance;
}


void InputClass::GetMouseLocation(int& mouseX, int& mouseY)
{
	mouseX = m_mouseX;
	mouseY = m_mouseY;
	return;
}

void InputClass::GetMouseRaw(int &mouseX, int &mouseY)
{
	mouseX = currentX;
	mouseY = currentY;
}
//Returns if the key was pressed down this frame
bool InputClass::KeyDown(unsigned short int key)
{
	return (m_keyboardState[key] & 0x80) && !(m_OldKeyboardState[key] & 0x80);
}
//Returns if the key was releced this frame
bool InputClass::KeyUp(unsigned short int key)
{
	return !(m_keyboardState[key] & 0x80) && (m_OldKeyboardState[key] & 0x80);
}
//Returns if the key is down
bool InputClass::Key(unsigned short int key)
{
	return m_keyboardState[key] & 0x80;
}

char InputClass::TypeCheck()
{
	for (unsigned short int i = 0; i < 256; i++)
	{
		if (m_keyboardState[i] & 0x80 && !m_OldKeyboardState[i] & 0x80)
		{
			return i;
		}
	}
	return 0;
}

bool InputClass::MouseButton(int button)
{
	if (m_mouseState.rgbButtons[button] & 0x80)
		return true;
	return false;
}

bool InputClass::LeapConnected()
{
	return m_LeapControler.isConnected();
}

const Leap::Frame InputClass::GetLeapFrame()
{
	return m_LeapFrame;
}

const Float3 InputClass::GetLeapToWorldScale()
{
	return m_leapToWorldScale;
}

const Float3 InputClass::GetLeapOffset()
{
	return m_leapOffset;
}

Float3 InputClass::GetLeapScreenPos()
{
	return m_leapScreenPosition;
}


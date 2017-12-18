////////////////////////////////////////////////////////////////////////////////
// Filename: inputclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "inputclass.h"


InputClass::InputClass()
{
	m_directInput = 0;
	m_keyboard = 0;
	m_mouse = 0;
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

	m_F1_released = true;
	m_F2_released = true;
	m_F3_released = true;
	m_F4_released = true;
	m_F5_released = true;
	m_MinusToggle = false;
	m_PlusToggle = false;
	m_AToggle = false;
	m_ZToggle = false;
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

	// Process the changes in the mouse and keyboard.
	ProcessInput();

	return true;
}


bool InputClass::ReadKeyboard()
{
	HRESULT result;


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


bool InputClass::IsEscapePressed()
{
	// Do a bitwise and on the keyboard state to check if the escape key is currently being pressed.
	if (m_keyboardState[DIK_ESCAPE] & 0x80)
	{
		return true;
	}

	return false;
}


bool InputClass::IsLeftPressed()
{
	// Do a bitwise and on the keyboard state to check if the key is currently being pressed.
	if (m_keyboardState[DIK_LEFT] & 0x80)
	{
		return true;
	}

	return false;
}


bool InputClass::IsRightPressed()
{
	// Do a bitwise and on the keyboard state to check if the key is currently being pressed.
	if (m_keyboardState[DIK_RIGHT] & 0x80)
	{
		return true;
	}

	return false;
}


bool InputClass::IsUpPressed()
{
	// Do a bitwise and on the keyboard state to check if the key is currently being pressed.
	if (m_keyboardState[DIK_UP] & 0x80)
	{
		return true;
	}

	return false;
}


bool InputClass::IsDownPressed()
{
	// Do a bitwise and on the keyboard state to check if the key is currently being pressed.
	if (m_keyboardState[DIK_DOWN] & 0x80)
	{
		return true;
	}

	return false;
}


bool InputClass::IsAPressed()
{
	// Do a bitwise and on the keyboard state to check if the key is currently being pressed.
	if (m_keyboardState[DIK_A] & 0x80)
	{
		return true;
	}

	return false;
}


bool InputClass::IsZPressed()
{
	// Do a bitwise and on the keyboard state to check if the key is currently being pressed.
	if (m_keyboardState[DIK_Z] & 0x80)
	{
		return true;
	}

	return false;
}

bool InputClass::IsAToggled()
{
	if (m_keyboardState[DIK_A] & 0x80 )
	{
		if (m_AToggle)
			return false;
		m_AToggle = true;
		return true;
	}
	m_AToggle = false;
	return false;
}

bool InputClass::IsZToggled()
{
	if (m_keyboardState[DIK_Z] & 0x80)
	{
		if (m_ZToggle)
			return false;
		m_ZToggle = true;
		return true;
	}
	m_ZToggle = false;
	return false;
}

bool InputClass::IsSPressed()
{
	if (m_keyboardState[DIK_S] & 0x80)
	{
		return true;
	}

	return false;
}

bool InputClass::IsXPressed()
{
	if (m_keyboardState[DIK_X] & 0x80)
	{
		return true;
	}

	return false;
}

bool InputClass::IsDPressed()
{
	if (m_keyboardState[DIK_D] & 0x80)
	{
		return true;
	}

	return false;
}

bool InputClass::IsCPressed()
{
	if (m_keyboardState[DIK_C] & 0x80)
	{
		return true;
	}

	return false;
}


bool InputClass::IsPgUpPressed()
{
	// Do a bitwise and on the keyboard state to check if the key is currently being pressed.
	if (m_keyboardState[DIK_PGUP] & 0x80)
	{
		return true;
	}

	return false;
}


bool InputClass::IsPgDownPressed()
{
	// Do a bitwise and on the keyboard state to check if the key is currently being pressed.
	if (m_keyboardState[DIK_PGDN] & 0x80)
	{
		return true;
	}

	return false;
}

bool InputClass::IsPlusPressed()
{
	if (m_keyboardState[DIK_ADD] & 0x80 || m_keyboardState[DIK_NUMPADPLUS] & 0x80)
	{
		if (m_PlusToggle)
			return false;
		m_PlusToggle = true;
		return true;
	}
	m_PlusToggle = false;
	return false;
}

bool InputClass::IsMinusPressed()
{
	if (m_keyboardState[DIK_MINUS] & 0x80 || m_keyboardState[DIK_NUMPADMINUS] & 0x80)
	{
		if (m_MinusToggle)
			return false;
		m_MinusToggle = true;
		return true;
	}
	m_MinusToggle = false;
	return false;
}


bool InputClass::IsF1Toggled()
{
	// Do a bitwise and on the keyboard state to check if the key is currently being pressed.
	if(m_keyboardState[DIK_F1] & 0x80)
	{
		if(m_F1_released)
		{
			m_F1_released = false;
			return true;
		}
	}
	else
	{
		m_F1_released = true;
	}

	return false;
}


bool InputClass::IsF2Toggled()
{
	// Do a bitwise and on the keyboard state to check if the key is currently being pressed.
	if(m_keyboardState[DIK_F2] & 0x80)
	{
		if(m_F2_released)
		{
			m_F2_released = false;
			return true;
		}
	}
	else
	{
		m_F2_released = true;
	}

	return false;
}


bool InputClass::IsF3Toggled()
{
	// Do a bitwise and on the keyboard state to check if the key is currently being pressed.
	if(m_keyboardState[DIK_F3] & 0x80)
	{
		if (m_F3_released)
		{
			m_F3_released = false;
			return true;
		}
	}
	else
	{
		m_F3_released = true;
	}

	return false;
}


bool InputClass::IsF4Toggled()
{
	// Do a bitwise and on the keyboard state to check if the key is currently being pressed.
	if(m_keyboardState[DIK_F4] & 0x80)
	{
		if (m_F4_released)
		{
			m_F4_released = false;
			return true;
		}
	}
	else
	{
		m_F4_released = true;
	}

	return false;
}


bool InputClass::IsF5Toggled()
{
	// Do a bitwise and on the keyboard state to check if the key is currently being pressed.
	if (m_keyboardState[DIK_F5] & 0x80)
	{
		if (m_F5_released)
		{
			m_F5_released = false;
			return true;
		}
	}
	else
	{
		m_F5_released = true;
	}

	return false;
}

bool InputClass::KeyDown(unsigned short int key)
{
	if (m_keyboardState[key] & 0x80)
	{
		return true;
	}
	return false;
}

char InputClass::TypeCheck()
{
	for (unsigned short int i = 0; i < 256; i++)
	{
		if (m_keyboardState[i] & 0x80)
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


////////////////////////////////////////////////////////////////////////////////
// Filename: inputclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _INPUTCLASS_H_
#define _INPUTCLASS_H_


///////////////////////////////
// PRE-PROCESSING DIRECTIVES //
///////////////////////////////
#define DIRECTINPUT_VERSION 0x0800


/////////////
// LINKING //
/////////////
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")


//////////////
// INCLUDES //
//////////////
#include <dinput.h>
#include <Xinput.h>

////////////////////////////////////////////////////////////////////////////////
// Class name: InputClass
////////////////////////////////////////////////////////////////////////////////
class InputClass
{
public:
	InputClass();
	InputClass(const InputClass&);
	~InputClass();

	bool Initialize(HINSTANCE, HWND, int, int);
	void Shutdown();
	bool Frame();

	bool IsEscapePressed();
	void GetMouseLocation(int&, int&);
	void GetMouseRaw(int&, int&);
	bool IsLeftPressed();
	bool IsRightPressed();
	bool IsUpPressed();
	bool IsDownPressed();
	bool IsAPressed();
	bool IsZPressed();
	bool IsAToggled();
	bool IsZToggled();
	bool IsSPressed();
	bool IsXPressed();
	bool IsDPressed();
	bool IsCPressed();
	bool IsPgUpPressed();
	bool IsPgDownPressed();
	bool IsPlusPressed();
	bool IsMinusPressed();
	bool IsF1Toggled();
	bool IsF2Toggled();
	bool IsF3Toggled();
	bool IsF4Toggled();
	bool IsF5Toggled();

	bool KeyDown(unsigned short int key);
	char TypeCheck();
	bool MouseButton(int button);
private:
	bool ReadKeyboard();
	bool ReadMouse();
	void ProcessInput();

private:
	IDirectInput8* m_directInput;
	IDirectInputDevice8* m_keyboard;
	IDirectInputDevice8* m_mouse;
	
	unsigned char m_keyboardState[256];
	DIMOUSESTATE m_mouseState;
	DIMOUSESTATE m_OldMouseState;
	

	int m_screenWidth, m_screenHeight;
	int m_mouseX, m_mouseY;
	int currentX, currentY;
	bool m_F1_released;
	bool m_F2_released;
	bool m_F3_released;
	bool m_F4_released;
	bool m_F5_released;
	bool m_PlusToggle;
	bool m_MinusToggle;
	bool m_AToggle;
	bool m_ZToggle;
};

#endif
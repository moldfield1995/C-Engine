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
#include "Leap.h"
#include "float3.h"

//Updated In Final Year
//Created By RasterTeck
//Updated By Matthew Oldfield

using namespace Leap;
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

	void GetMouseLocation(int&, int&);
	void GetMouseRaw(int&, int&);

	bool KeyDown(unsigned short int key);
	bool KeyUp(unsigned short int key);
	bool Key(unsigned short int key);
	char TypeCheck();
	bool MouseButton(int button);

	bool LeapConnected();
	const Leap::Frame GetLeapFrame();

	const Float3 GetLeapToWorldScale();
	const Float3 GetLeapOffset();
	Float3 GetLeapScreenPos();
private:
	bool ReadKeyboard();
	bool ReadMouse();
	void ReadLeap();
	void ProcessInput();
private:
	static InputClass* instance;

	IDirectInput8* m_directInput;
	IDirectInputDevice8* m_keyboard;
	IDirectInputDevice8* m_mouse;
	
	unsigned char m_keyboardState[256];
	unsigned char m_OldKeyboardState[256];
	DIMOUSESTATE m_mouseState;
	DIMOUSESTATE m_OldMouseState;

	int m_screenWidth, m_screenHeight;
	int m_mouseX, m_mouseY;
	int currentX, currentY;

	Controller m_LeapControler;
	Leap::Frame m_LeapFrame;
	Float3 m_leapToWorldScale, m_leapOffset;

	Float3 m_leapScreenPosition;
public:
	static InputClass* GetInstance();
};

#endif
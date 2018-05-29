///////////////////////////////////////////////////////////////////////////////
// Filename: applicationclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _APPLICATIONCLASS_H_
#define _APPLICATIONCLASS_H_
#define _BuildState_ 0

/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = true;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1500.0f;
const float SCREEN_NEAR = 0.1f;


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "inputclass.h"
#include "d3dclass.h"
#include "shadermanagerclass.h"
#include "texturemanagerclass.h"
#include "timerclass.h"
#include "fpsclass.h"
#include "ModelManager.h"
#include "GameState.h"
#include "AudioManager.h"
#include "fontmanagerclass.h"
#include "..\TrueAxis\Physics\Physics.h"

////////////////////////////////////////////////////////////////////////////////
// Class name: ApplicationClass
////////////////////////////////////////////////////////////////////////////////
enum class CurrentState
{
	SplashScreen,
	MainMenu,
	Level,
};
class ApplicationClass
{
public:
	ApplicationClass();
	ApplicationClass(const ApplicationClass&);
	~ApplicationClass();

	bool Initialize(HINSTANCE, HWND, int, int);
	void Shutdown();
	bool Frame();

private:
	//bool ProcessColltion(TA::PreCollision & collision);
	//Collition Triggers
	bool static TA_CALL_BACK ProcessColltion(TA::PreCollision& collition);

	void CreateNextScene(GameState* newBuffer);

	InputClass* m_Input;
	D3DClass* m_Direct3D;
	ShaderManagerClass* m_ShaderManager;
	TextureManagerClass* m_TextureManager;
	TimerClass* m_Timer;
	FpsClass* m_Fps;
	GameState* m_FrountBuffer;
	ModelManager* m_ModelManager;
	FontManagerClass* m_FontManager;
	int m_ScreenHeight, m_ScreenWidth;
	CurrentState m_currentState;
	AudioManager* m_AudioManager;
	TA::Physics* m_taPhysics;
};

#endif
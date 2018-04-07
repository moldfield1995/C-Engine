///////////////////////////////////////////////////////////////////////////////
// Filename: applicationclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _APPLICATIONCLASS_H_
#define _APPLICATIONCLASS_H_
#define _BuildState_ 1

/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
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
#include "LoadingScreen.h"
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
	PauseScreen,
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
	//Loading and Scene settup
	void loadMainMenu();
	void loadMainLevel();
	void shutDownFrountBuffer();
	void shutDownBackBuffer();

	static void InitaliseLevel(D3DClass* Direct3D, int screenWidth, int screenHeight, float screenDepth, TextureManagerClass* textureManager, ModelManager* modelManager, GameState* frountBuffer,AudioManager* AudioManager);
	static void RunLoadingScreen(D3DClass* Direct3D, InputClass* Input, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager,
		ModelManager* modelManager, float frameTime, int fps, LoadingScreen* loadingScreen, GameState* level, AudioManager* audioManager);

	InputClass* m_Input;
	D3DClass* m_Direct3D;
	ShaderManagerClass* m_ShaderManager;
	TextureManagerClass* m_TextureManager;
	TimerClass* m_Timer;
	FpsClass* m_Fps;
	GameState* m_FrountBuffer;
	GameState* m_BackBuffer;
	ModelManager* m_ModelManager;
	FontManagerClass* m_FontManager;
	int m_ScreenHeight, m_ScreenWidth;
	CurrentState m_currentState;
	bool m_activeThread;
	AudioManager* m_AudioManager;
	TA::Physics* m_taPhysics;
};

#endif
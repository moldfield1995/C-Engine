////////////////////////////////////////////////////////////////////////////////
// Filename: applicationclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "applicationclass.h"
#include <thread>
#include "MainMenu.h"
#include "zoneclass.h"
#include "SplashScreen.h"

ApplicationClass::ApplicationClass()
{
	m_Input = 0;
	m_Direct3D = 0;
	m_Timer = 0;
	m_Fps = 0;
	m_ShaderManager = 0;
	m_TextureManager = 0;
	m_FrountBuffer = 0;
	m_BackBuffer = 0;
	m_ModelManager = 0;
	m_AudioManager = 0;
}


ApplicationClass::ApplicationClass(const ApplicationClass& other)
{
}


ApplicationClass::~ApplicationClass()
{
}


bool ApplicationClass::Initialize(HINSTANCE hinstance, HWND hwnd, int screenWidth, int screenHeight)
{
	bool result;

	
	// Create the input object.
	m_Input = new InputClass;
	if (!m_Input)
	{
		return false;
	}

	// Initialize the input object.
	result = m_Input->Initialize(hinstance, hwnd, screenWidth, screenHeight);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the input object.", L"Error", MB_OK);
		return false;
	}

	// Create the Direct3D object.
	m_Direct3D = new D3DClass;
	if(!m_Direct3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_Direct3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D.", L"Error", MB_OK);
		return false;
	}

	// Create the shader manager object.
	m_ShaderManager = new ShaderManagerClass;
	if(!m_ShaderManager)
	{
		return false;
	}

	// Initialize the shader manager object.
	result = m_ShaderManager->Initialize(m_Direct3D->GetDevice(), hwnd);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the shader manager object.", L"Error", MB_OK);
		return false;
	}

	// Create the texture manager object.
	m_TextureManager = new TextureManagerClass;
	if(!m_TextureManager)
	{
		return false;
	}

	// Initialize the texture manager object.
	result = m_TextureManager->Initialize();
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the texture manager object.", L"Error", MB_OK);
		return false;
	}


	// Create the timer object.
	m_Timer = new TimerClass;
	if(!m_Timer)
	{
		return false;
	}

	// Initialize the timer object.
	result = m_Timer->Initialize();
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the timer object.", L"Error", MB_OK);
		return false;
	}

	// Create the fps object.
	m_Fps = new FpsClass;
	if(!m_Fps)
	{
		return false;
	}

	// Initialize the fps object.
	m_Fps->Initialize();

	m_ModelManager = new ModelManager();
	m_ModelManager->Initalize();

	m_AudioManager = new AudioManager();
	m_AudioManager->Initialise(hinstance);
	int au = m_AudioManager->AddAudio("../Engine/data/Music/1.wav");
	m_AudioManager->Play(au, true);
	// Create the zone object.
	m_FrountBuffer = new SplashScreen();
	if(!m_FrountBuffer)
	{
		return false;
	}
	m_currentState = CurrentState::SplashScreen;
	// Initialize the zone object.
	result = m_FrountBuffer->Initialize(m_Direct3D, screenWidth, screenHeight, SCREEN_DEPTH, m_TextureManager, m_ModelManager, m_AudioManager);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the zone object.", L"Error", MB_OK);
		return false;
	}

	m_ScreenWidth = screenWidth;
	m_ScreenHeight = screenHeight;
	m_activeThread = true;
	return true;
}


void ApplicationClass::Shutdown()
{
	// Release the zone object.
	shutDownFrountBuffer();
	shutDownBackBuffer();
	
	// Release the fps object.
	if(m_Fps)
	{
		delete m_Fps;
		m_Fps = 0;
	}

	// Release the timer object.
	if(m_Timer)
	{
		delete m_Timer;
		m_Timer = 0;
	}

	// Release the texture manager object.
	if(m_TextureManager)
	{
		m_TextureManager->Shutdown();
		delete m_TextureManager;
		m_TextureManager = 0;
	}

	// Release the shader manager object.
	if(m_ShaderManager)
	{
		m_ShaderManager->Shutdown();
		delete m_ShaderManager;
		m_ShaderManager = 0;
	}

	// Release the Direct3D object.
	if(m_Direct3D)
	{
		m_Direct3D->Shutdown();
		delete m_Direct3D;
		m_Direct3D = 0;
	}

	// Release the input object.
	if(m_Input)
	{
		m_Input->Shutdown();
		delete m_Input;
		m_Input = 0;
	}
	if (m_ModelManager)
	{
		m_ModelManager->ShutDown();
		delete m_ModelManager;
		m_ModelManager = 0;
	}

	return;
}

void ApplicationClass::shutDownFrountBuffer()
{
	if (m_FrountBuffer)
	{
		m_FrountBuffer->Shutdown();
		delete m_FrountBuffer;
		m_FrountBuffer = 0;
	}
}
void ApplicationClass::shutDownBackBuffer()
{
	if (m_BackBuffer)
	{
		m_BackBuffer->Shutdown();
		delete m_BackBuffer;
		m_BackBuffer = 0;
	}
}

bool ApplicationClass::Frame()
{
	bool result;


	// Update the system stats.
	m_Fps->Frame();
	m_Timer->Frame();

	// Do the input frame processing.
	result = m_Input->Frame();
	if(!result)
	{
		return false;
	}

	// Check if the user pressed escape and wants to exit the application.
	if(m_Input->IsEscapePressed() == true)
	{
		return false;
	}


	// Do the zone frame processing.
	if(m_activeThread)
	result = m_FrountBuffer->Frame(m_Direct3D, m_Input, m_ShaderManager, m_TextureManager,m_ModelManager, m_Timer->GetTime(), m_Fps->GetFps(),m_AudioManager);
	else
		result = m_BackBuffer->Frame(m_Direct3D, m_Input, m_ShaderManager, m_TextureManager, m_ModelManager, m_Timer->GetTime(), m_Fps->GetFps(), m_AudioManager);
	if(!result)
	{
		return false;
	}

	if (m_FrountBuffer->SwitchState() == StateSwich::Next)
	{
		switch (m_currentState)
		{
		case CurrentState::SplashScreen:
			loadMainMenu();
			m_currentState = CurrentState::MainMenu;
			break;
		case CurrentState::Level:
			m_activeThread = false;
			m_currentState = CurrentState::PauseScreen;
			break;
		case CurrentState::MainMenu:
			loadMainLevel();
			m_currentState = CurrentState::Level;
			break;
		case CurrentState::PauseScreen:
			m_activeThread = true;
			m_currentState = CurrentState::Level;
			break;
		default:
			break;
		}
	}
	else if (m_FrountBuffer->SwitchState() == StateSwich::Quit)
		return false;
	return result;
}

void ApplicationClass::loadMainLevel()
{
	LoadingScreen* m_loadingScreen = new LoadingScreen();
	m_loadingScreen->Initialize(m_Direct3D, m_ScreenWidth, m_ScreenHeight, SCREEN_DEPTH, m_TextureManager, m_ModelManager, m_AudioManager);
	m_BackBuffer = m_FrountBuffer; // Put the menu on the backBuffer
	m_FrountBuffer = new ZoneClass();
	//thread lodingScreenFrame (RunLoadingScreen,m_Direct3D,m_Input,m_ShaderManager,m_TextureManager,m_ModelManager, m_Timer->GetTime(), m_Fps->GetFps(), m_loadingScreen, m_FrountBuffer, m_AudioManager); // this starts when you construct it
	thread InitilizeLevel(InitaliseLevel,m_Direct3D, m_ScreenWidth, m_ScreenHeight, SCREEN_DEPTH, m_TextureManager, m_ModelManager, m_FrountBuffer, m_AudioManager);
	InitilizeLevel.join();
	m_loadingScreen->SetRunning(false);//notify lodingscreen to stop
	//lodingScreenFrame.join();
	m_loadingScreen->Shutdown();
}

void ApplicationClass::loadMainMenu()
{
	shutDownFrountBuffer();
	shutDownBackBuffer();
	m_FrountBuffer = new MainMenu();
	m_FrountBuffer->Initialize(m_Direct3D, m_ScreenWidth, m_ScreenHeight, SCREEN_DEPTH, m_TextureManager, m_ModelManager, m_AudioManager);
}

void ApplicationClass::InitaliseLevel(D3DClass* Direct3D, int screenWidth, int screenHeight, float screenDepth, TextureManagerClass* textureManager, ModelManager* modelManager, GameState* frountBuffer, AudioManager* audioManager)
{
	frountBuffer->Initialize(Direct3D, screenWidth, screenHeight, screenDepth, textureManager, modelManager,audioManager);
}

void ApplicationClass::RunLoadingScreen(D3DClass* Direct3D, InputClass* Input, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager,
	ModelManager* modelManager, float frameTime, int fps, LoadingScreen* loadingScreen, GameState* level, AudioManager* audioManager)
{
	loadingScreen->SetLevel(level);
	loadingScreen->Frame(Direct3D, Input, ShaderManager, TextureManager, modelManager, frameTime, fps,audioManager);
}

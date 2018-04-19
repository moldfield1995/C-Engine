////////////////////////////////////////////////////////////////////////////////
// Filename: applicationclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "applicationclass.h"
#include <thread>
#include "LeapTestScene.h"
#include "Utills.h"
#include "Collider.h"
#include "GamePlayScene.h"

ApplicationClass::ApplicationClass()
{
	m_Input = 0;
	m_Direct3D = 0;
	m_Timer = 0;
	m_Fps = 0;
	m_ShaderManager = 0;
	m_TextureManager = 0;
	m_FrountBuffer = 0;
	m_ModelManager = 0;
	m_AudioManager = 0;
	m_FontManager = 0;
	m_taPhysics = 0;
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
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the input object.", L"Error", MB_OK);
		return false;
	}

	// Create the Direct3D object.
	m_Direct3D = new D3DClass;
	if (!m_Direct3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_Direct3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D.", L"Error", MB_OK);
		return false;
	}

	// Create the shader manager object.
	m_ShaderManager = new ShaderManagerClass;
	if (!m_ShaderManager)
	{
		return false;
	}

	// Initialize the shader manager object.
	result = m_ShaderManager->Initialize(m_Direct3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the shader manager object.", L"Error", MB_OK);
		return false;
	}

	// Create the texture manager object.
	m_TextureManager = new TextureManagerClass;
	if (!m_TextureManager)
	{
		return false;
	}

	// Initialize the texture manager object.
	result = m_TextureManager->Initialize();
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the texture manager object.", L"Error", MB_OK);
		return false;
	}
	//Load Default Texture
	result = m_TextureManager->LoadTexture(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), "../Engine/data/textures/debug.tga", 404);
	if (!result)
	{
		return false;
	}
	//create Font Class
	m_FontManager = new FontManagerClass;
	if (!m_FontManager)
		return false;
	result = m_FontManager->Initialize();
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the font manager object.", L"Error", MB_OK);
		return false;
	}
	//Load Default Font
	result = m_FontManager->LoadFont(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), "../Engine/data/font/font01.txt",
		"../Engine/data/font/font01.tga", 32.0f, 3, 0);

	// Create the timer object.
	m_Timer = new TimerClass;
	if (!m_Timer)
	{
		return false;
	}

	// Initialize the timer object.
	result = m_Timer->Initialize();
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the timer object.", L"Error", MB_OK);
		return false;
	}

	// Create the fps object.
	m_Fps = new FpsClass;
	if (!m_Fps)
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



	TA::Physics::CreateInstance();
	m_taPhysics = &TA::Physics::GetInstance();
	TA::AABB worldExstence;
	worldExstence.Initialise(TA::Vec3(0.0f, 0.0f, 900.0f), TA::Vec3(1000.0f, 1000.0f, 1000.0f));
	m_taPhysics->SetWorldDimensions(worldExstence);
	//We are in space, no graverty
	m_taPhysics->SetGravity(TA::Vec3(0.0f, 0.0f, 0.0f));
	m_taPhysics->SetupSimulation();
	m_taPhysics->SetPreProcessCollisionCallBack(ApplicationClass::ProcessColltion);
#if _BuildState_  ==0
	m_AudioManager->Play(au, true);
	// Create the zone object.
	m_FrountBuffer = new SplashScreen();
	if (!m_FrountBuffer)
	{
		return false;
	}
	m_currentState = CurrentState::SplashScreen;
	// Initialize the zone object.
	result = m_FrountBuffer->Initialize(m_Direct3D, screenWidth, screenHeight, SCREEN_DEPTH, m_TextureManager, m_ModelManager, m_AudioManager);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the zone object.", L"Error", MB_OK);
		return false;
	}
#endif
#if _BuildState_ == 1
	m_FrountBuffer = new LeapTestScene();
	if (!m_FrountBuffer)
	{
		return false;
	}
	m_currentState = CurrentState::Level;
	// Initialize the zone object.
	result = m_FrountBuffer->Initialize(m_Direct3D, screenWidth, screenHeight, SCREEN_DEPTH, m_TextureManager, m_ModelManager, m_AudioManager);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the zone object.", L"Error", MB_OK);
		return false;
	}
#endif
#if _BuildState_ == 2
	m_FrountBuffer = new GamePlayScene();
	if (!m_FrountBuffer)
	{
		return false;
	}
	m_currentState = CurrentState::Level;
	// Initialize the zone object.
	result = m_FrountBuffer->Initialize();
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the zone object.", L"Error", MB_OK);
		return false;
	}
#endif

	m_ScreenWidth = screenWidth;
	m_ScreenHeight = screenHeight;
	return true;
}


void ApplicationClass::Shutdown()
{


	// Release the fps object.
	if (m_Fps)
	{
		delete m_Fps;
		m_Fps = 0;
	}

	// Release the timer object.
	if (m_Timer)
	{
		delete m_Timer;
		m_Timer = 0;
	}

	// Release the texture manager object.
	if (m_TextureManager)
	{
		m_TextureManager->Shutdown();
		delete m_TextureManager;
		m_TextureManager = 0;
	}

	// Release the shader manager object.
	if (m_ShaderManager)
	{
		m_ShaderManager->Shutdown();
		delete m_ShaderManager;
		m_ShaderManager = 0;
	}

	// Release the Direct3D object.
	if (m_Direct3D)
	{
		m_Direct3D->Shutdown();
		delete m_Direct3D;
		m_Direct3D = 0;
	}

	// Release the input object.
	if (m_Input)
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


bool ApplicationClass::Frame()
{
	bool result;


	// Update the system stats.
	m_Fps->Frame();
	m_Timer->Frame();

	// Do the input frame processing.
	result = m_Input->Frame();
	if (!result)
	{
		return false;
	}

	m_taPhysics->Update(m_Timer->GetFrameTime());

	// Check if the user pressed escape and wants to exit the application.
	if (m_Input->KeyDown(DIK_ESCAPE))
	{
		return false;
	}

	result = m_FrountBuffer->Frame();
	if (!result)
	{
		return false;
	}

	if (m_FrountBuffer->SwitchState() == StateSwich::Next)
	{
		switch (m_currentState)
		{
		case CurrentState::SplashScreen:
			m_currentState = CurrentState::MainMenu;
			//CreateNextScene(new)
			break;
		case CurrentState::Level:
			m_currentState = CurrentState::MainMenu;

			break;
		case CurrentState::MainMenu:
			m_currentState = CurrentState::Level;
			CreateNextScene(new GamePlayScene);
			break;
		default:
			break;
		}
	}
	else if (m_FrountBuffer->SwitchState() == StateSwich::Quit)
		return false;
	return result;
}
//Called before the collion is processed, Returns if the collison should be ignored
bool TA_CALL_BACK ApplicationClass::ProcessColltion(TA::PreCollision& collision) {

	CollisonData *col1, *col2;
	col1 = (CollisonData*)collision.GetObjectA()->GetUserData();
	col2 = (CollisonData*)collision.GetObjectB()->GetUserData();
	if (!col1 || !col2)
	{
		Utills::DebugString("Collition Happened where one of the Userdata did not contain a gameobject: ProcessColltion : ApplicationClass ");
		return false;
	}
	col1->Object->OnCollishon(col2);
	col2->Object->OnCollishon(col1);
	return true;
}

void ApplicationClass::CreateNextScene(GameState * newBuffer)
{
	m_FrountBuffer->Shutdown();
	delete m_FrountBuffer;
	m_FrountBuffer = newBuffer;
	m_FrountBuffer->Initialize();
}


//Needs to be fixed as there is a thread collison when loading assets (setting buffers on GPU) and rendering



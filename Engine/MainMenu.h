#pragma once
#include "GameState.h"
#include "cameraclass.h"
#include "frustumclass.h"
#include "lightclass.h"
#include "UIMannager.h"
#include "GameObject.h"
class MainMenu :
	public GameState
{
public:
	MainMenu();
	~MainMenu();

	virtual bool Initialize();
	virtual void Shutdown();
	virtual bool Frame();

protected:
	virtual bool Render();
private:

	CameraClass * m_Camera;
	FrustumClass* m_Frustum;
	LightClass* m_Light;
	UIMannager* m_UIMannager;
	std::vector<GameObject*> m_GameObjects;
};


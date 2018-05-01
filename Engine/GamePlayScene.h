#pragma once
#include "GameState.h"
#include "cameraclass.h"
#include "lightclass.h"
#include "frustumclass.h"
#include "GameObject.h"
#include "UIMannager.h"
#include <vector>
#include "SkyBoxRender.h"

class GamePlayScene :
	public GameState
{
public:
	GamePlayScene();
	~GamePlayScene();

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
	SkyBoxRender* m_Skybox;
};


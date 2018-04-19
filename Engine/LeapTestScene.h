#pragma once
#include "GameState.h"
#include "cameraclass.h"
#include "lightclass.h"
#include "frustumclass.h"
#include "GameObject.h"
#include "UIMannager.h"
#include <vector>

//Created In Final Year
//Created By Matthew Oldfield

class LeapTestScene :
	public GameState
{
public:
	LeapTestScene();
	~LeapTestScene();

	virtual bool Initialize() ;
	virtual void Shutdown() ;
	virtual bool Frame() ;

protected:
	virtual bool Render();

private:
	CameraClass* m_Camera;
	FrustumClass* m_Frustum;
	LightClass* m_Light;
	UIMannager* m_UIMannager;
	std::vector<GameObject*> m_GameObjects;

};


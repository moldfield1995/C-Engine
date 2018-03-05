#pragma once
#include "GameState.h"
#include "cameraclass.h"
#include "lightclass.h"
#include "frustumclass.h"
#include "GameObject.h"
#include <vector>
class LeapTestScene :
	public GameState
{
public:
	LeapTestScene();
	~LeapTestScene();

	virtual bool Initialize(D3DClass*, int, int, float, TextureManagerClass*, ModelManager*, AudioManager*) ;
	virtual void Shutdown() ;
	virtual bool Frame(D3DClass*, InputClass*, ShaderManagerClass*, TextureManagerClass*, ModelManager*, float, int, AudioManager*) ;

protected:
	virtual void HandleMovementInput(InputClass*, float);
	virtual bool Render(D3DClass*, ShaderManagerClass*, TextureManagerClass*, ModelManager*);

private:
	CameraClass* m_Camera;
	FrustumClass* m_Frustum;
	LightClass* m_Light;
	std::vector<GameObject*> m_GameObjects;

};

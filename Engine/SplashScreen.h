#pragma once
#include "GameState.h"
#include "d3dclass.h"
#include "texturemanagerclass.h"
#include "ModelManager.h"
#include "shadermanagerclass.h"
#include "inputclass.h"
#include "bitmapclass.h"
#include "cameraclass.h"
class SplashScreen : public  GameState
{
public:
	SplashScreen();
	SplashScreen(const SplashScreen&);
	~SplashScreen();

	bool Initialize(D3DClass*, int, int, float, TextureManagerClass*, ModelManager*, AudioManager*);
	void Shutdown();
	bool Frame(D3DClass*, InputClass*, ShaderManagerClass*, TextureManagerClass*, ModelManager*, float, int, AudioManager*);
protected:
	void HandleMovementInput(InputClass*, float);
	bool Render(D3DClass*, ShaderManagerClass*, TextureManagerClass*, ModelManager*);
private:
	int m_ScreenHight, m_ScreenWidth;
	CameraClass* m_Camera;
};


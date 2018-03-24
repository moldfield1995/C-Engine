#pragma once
#include "GameState.h"
#include "d3dclass.h"
#include "texturemanagerclass.h"
#include "ModelManager.h"
#include "shadermanagerclass.h"
#include "inputclass.h"
#include "bitmapclass.h"
#include "cameraclass.h"

//Created By Matthew Oldfield

class LoadingScreen : public GameState
{
public:
	LoadingScreen();
	LoadingScreen(const LoadingScreen&);
	~LoadingScreen();
	bool Initialize(D3DClass*, int, int, float, TextureManagerClass*, ModelManager*, AudioManager*);
	void Shutdown();
	bool Frame(D3DClass*, InputClass*, ShaderManagerClass*, TextureManagerClass*, ModelManager*, float, int, AudioManager*);
	void SetRunning(bool);
	void SetLevel(GameState* level);
protected:
	void HandleMovementInput(InputClass*, float);
	bool Render(D3DClass*, ShaderManagerClass*, TextureManagerClass*, ModelManager*);
private:
	CameraClass* m_Camera;
	bool m_running;
	GameState* m_level;
	float m_scaleX;
};


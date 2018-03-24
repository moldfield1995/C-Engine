#pragma once
#include "d3dclass.h"
#include "inputclass.h"
#include "shadermanagerclass.h"
#include "texturemanagerclass.h"
#include "ModelManager.h"
#include "AudioManager.h"

//Updated In Final Year
//Created By Matthew Oldfield

enum class StateSwich{
	Next,
	Quit,
	Continue,
};
class GameState
{
public:
	GameState();
	GameState(const GameState& other) {};
	~GameState() {};

	virtual bool Initialize(D3DClass*, int, int, float, TextureManagerClass*, ModelManager*, AudioManager*) = 0;
	virtual void Shutdown() = 0;
	virtual bool Frame(D3DClass*, InputClass*, ShaderManagerClass*, TextureManagerClass*, ModelManager*, float, int,AudioManager*) = 0;
	StateSwich SwitchState();
	int GetLoadingLevel();
protected:
	virtual void HandleMovementInput(InputClass*, float) = 0;
	virtual bool Render(D3DClass*, ShaderManagerClass*, TextureManagerClass*, ModelManager*) = 0;
	StateSwich m_currentState;
	void SetLoadingLevel(int level);
private:
	bool m_concurentAccsess;
	int m_loadingLevel;
	
};


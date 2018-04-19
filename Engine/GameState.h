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
	Reset,
	Continue,
};
class GameState
{
public:
	GameState();
	GameState(const GameState& other) {};
	~GameState() {};

	virtual bool Initialize() = 0;
	virtual void Shutdown() = 0;
	virtual bool Frame() = 0;
	StateSwich SwitchState();
	void SetSwitchState(StateSwich value);
protected:
	virtual bool Render() = 0;
	StateSwich m_currentState;
private:
	bool m_concurentAccsess;
	int m_loadingLevel;
	
};


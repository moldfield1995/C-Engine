#include "GameState.h"
//stored in system class for debug.


GameState::GameState()
{
	m_currentState = StateSwich::Continue;
	m_concurentAccsess = false;
	m_loadingLevel = 0;
}

GameState::GameState(const GameState & other)
{
}


GameState::~GameState()
{
}

bool GameState::Initialize(D3DClass *, int, int, float, TextureManagerClass *, ModelManager *, AudioManager*)
{
	return false;
}

void GameState::Shutdown()
{
}

bool GameState::Frame(D3DClass *, InputClass *, ShaderManagerClass *, TextureManagerClass *, ModelManager *, float, int, AudioManager*)
{
	return false;
}

void GameState::HandleMovementInput(InputClass *, float)
{
}

bool GameState::Render(D3DClass *, ShaderManagerClass *, TextureManagerClass *, ModelManager *)
{
	return false;
}

void GameState::setLoadingLevel(int level)
{
	m_concurentAccsess = true;
	m_loadingLevel = level;
	m_concurentAccsess = false;
}

StateSwich GameState::SwitchState()
{
	return m_currentState;
}

int GameState::GetLoadingLevel()
{
	if (!m_concurentAccsess)
		return m_loadingLevel;
	else
		return -1;
}

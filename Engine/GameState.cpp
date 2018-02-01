#include "GameState.h"


GameState::GameState()
{
	m_currentState = StateSwich::Continue;
	m_concurentAccsess = false;
	m_loadingLevel = 0;
}


void GameState::SetLoadingLevel(int level)
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

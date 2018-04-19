#include "GameState.h"


GameState::GameState()
{
	m_currentState = StateSwich::Continue;
	m_concurentAccsess = false;
	m_loadingLevel = 0;
}




StateSwich GameState::SwitchState()
{
	return m_currentState;
}

void GameState::SetSwitchState(StateSwich value)
{
	m_currentState = value;
}


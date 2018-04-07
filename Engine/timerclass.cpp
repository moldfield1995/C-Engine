///////////////////////////////////////////////////////////////////////////////
// Filename: timerclass.cpp
///////////////////////////////////////////////////////////////////////////////
#include "timerclass.h"

TimerClass* TimerClass::instance = 0;


TimerClass::TimerClass()
{
	m_appAliveTime = 0.0f;
}


TimerClass::TimerClass(const TimerClass& other)
{
}


TimerClass::~TimerClass()
{
}


bool TimerClass::Initialize()
{
	INT64 frequency;


	// Get the cycles per second speed for this system.
	QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
	if(frequency == 0)
	{
		return false;
	}
	
	// Store it in floating point.
	m_frequency = (float)frequency;

	// Get the initial start time.
	QueryPerformanceCounter((LARGE_INTEGER*)&m_startTime);

	instance = this;

	return true;
}


void TimerClass::Frame()
{
	INT64 currentTime;
	INT64 elapsedTicks;


	// Query the current time.
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);

	// Calculate the difference in time since the last time we queried for the current time.
	elapsedTicks = currentTime - m_startTime;

	// Calculate the frame time.
	m_frameTime = (float)elapsedTicks / m_frequency;
	m_appAliveTime += m_frameTime;

	// Restart the timer.
	m_startTime = currentTime;

	return;
}


float TimerClass::GetFrameTime()
{
	return m_frameTime;
}

float TimerClass::GetTime()
{
	return m_appAliveTime;
}


void TimerClass::StartTimer()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&m_beginTime);
	return;
}


void TimerClass::StopTimer()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&m_endTime);
	return;
}


int TimerClass::GetTimerTime()
{
	float elapsedTicks;
	INT64 frequency;
	float milliseconds;


	// Get the elapsed ticks between the two times.
	elapsedTicks = (float)(m_endTime - m_beginTime);

	// Get the ticks per second speed of the timer.
	QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);

	// Calculate the elapsed time in milliseconds.
	milliseconds = (elapsedTicks / (float)frequency) * 1000.0f;

	return (int)milliseconds;
}

TimerClass * TimerClass::GetInstance()
{
	return instance;
}

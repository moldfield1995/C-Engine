////////////////////////////////////////////////////////////////////////////////
// Filename: timerclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _TIMERCLASS_H_
#define _TIMERCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <windows.h>


////////////////////////////////////////////////////////////////////////////////
// Class name: TimerClass
////////////////////////////////////////////////////////////////////////////////
class TimerClass
{
public:
	TimerClass();
	TimerClass(const TimerClass&);
	~TimerClass();

	bool Initialize();
	void Frame();

	float GetFrameTime();
	float GetTime();

	//For Performance monitoring
	void StartTimer();
	void StopTimer();
	int GetTimerTime();

private:
	static TimerClass *instance;

	float m_frequency;
	INT64 m_startTime;
	float m_frameTime;
	INT64 m_beginTime, m_endTime;

	float m_appAliveTime;
public:
	static TimerClass* GetInstance();

};

#endif
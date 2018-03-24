#pragma once
#include "fpsclass.h"
#include "cpuclass.h"
#include "timerclass.h"

//Created By Matthew Oldfield

class PeformanceMonerting
{
public:
	PeformanceMonerting();
	PeformanceMonerting(const PeformanceMonerting&);
	~PeformanceMonerting();
	bool Initialize();
	void Shutdown();
	void Frame();
	int GetCpuPercentage();
	int GetFps();
	float GetTrueTime();
	float GetTime();
	void IncreseTimeScale();
	void ReduceTimeScale();
private:
	FpsClass* m_Fps;
	CpuClass* m_Cpu;
	TimerClass* m_Timer;
	float m_timeScale = 1.0f;
};


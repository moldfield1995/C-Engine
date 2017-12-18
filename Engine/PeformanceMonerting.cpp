#include "PeformanceMonerting.h"


PeformanceMonerting::PeformanceMonerting()
{
	m_Cpu = 0;
	m_Fps = 0;
	m_Timer = 0;
}
PeformanceMonerting::PeformanceMonerting(const PeformanceMonerting&)
{
}

PeformanceMonerting::~PeformanceMonerting()
{
}
bool PeformanceMonerting::Initialize()
{
	m_Fps = new FpsClass;
	m_Cpu = new CpuClass;
	m_Timer = new TimerClass;
	if (!m_Fps || !m_Cpu || !m_Timer)
	{
		return false;
	}
	m_Fps->Initialize();
	m_Cpu->Initialize();
	if (!m_Timer->Initialize())
		return false;
	return true;
}

void PeformanceMonerting::Shutdown()
{
	if (m_Fps)
	{
		delete m_Fps;
		m_Fps = 0;
	}
	if (m_Cpu)
	{
		delete m_Cpu;
		m_Cpu = 0;
	}
	if (m_Timer)
	{
		delete m_Timer;
		m_Timer = 0;
	}
}

void PeformanceMonerting::Frame()
{
	m_Cpu->Frame();
	m_Fps->Frame();
	m_Timer->Frame();
}

int PeformanceMonerting::GetCpuPercentage(){ return m_Cpu->GetCpuPercentage(); }
int PeformanceMonerting::GetFps(){ return m_Fps->GetFps(); }
float PeformanceMonerting::GetTrueTime(){ return m_Timer->GetTime(); }
float PeformanceMonerting::GetTime(){ return m_Timer->GetTime() * m_timeScale; }
void PeformanceMonerting::IncreseTimeScale(){ m_timeScale += 0.01f * m_Timer->GetTime(); }
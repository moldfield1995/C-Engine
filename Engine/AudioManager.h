#pragma once
#include <Windows.h>
#include <vector>
#include "AudioElement.h"
class AudioManager
{
public:
	AudioManager();
	~AudioManager();
	bool Initialise(HINSTANCE hinstance);
	void Shutdown();
	void Play( int unsigned index, bool loop);
	void Remove(int unsigned index);
	int AddAudio(char* fileLocation);
private:
	HINSTANCE m_hinstance;
	std::vector<AudioElement*> m_AudioElements;
};


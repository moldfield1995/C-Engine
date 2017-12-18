#include "AudioManager.h"
#include <mmsystem.h>

AudioManager::AudioManager()
{
}


AudioManager::~AudioManager()
{
}

bool AudioManager::Initialise(HINSTANCE hinstance)
{
	m_hinstance = hinstance;
	m_AudioElements = std::vector<AudioElement*>();
	return true;
}

void AudioManager::Shutdown()
{
	PlaySoundA(NULL, 0, 0); // Stop Audio Player
	int vectorSize = m_AudioElements.size();
	for (int i = 0; i < vectorSize; i++)
	{
		if (m_AudioElements[i] != NULL)
		{
			m_AudioElements[i]->ShutDown();
			delete m_AudioElements[i];
			m_AudioElements[i] = NULL;
		}
	}
	m_AudioElements.clear();
}

void AudioManager::Play(int unsigned index, bool loop)
{
	if (index < m_AudioElements.size())
		if(loop)
			PlaySoundA(m_AudioElements[index]->GetAudioClip(), m_hinstance, SND_MEMORY | SND_ASYNC| SND_LOOP);
		else
			PlaySoundA(m_AudioElements[index]->GetAudioClip(), m_hinstance, SND_MEMORY | SND_ASYNC);
}

void AudioManager::Remove(int unsigned index)
{
	PlaySoundA(NULL, 0, 0); // Stop Audio Player
	if (index < m_AudioElements.size())
		if (m_AudioElements[index] != NULL)
		{
			m_AudioElements[index]->ShutDown();
			delete m_AudioElements[index];
			m_AudioElements[index] = NULL;
			m_AudioElements.erase(m_AudioElements.begin() +index);
		}
}

int AudioManager::AddAudio(char * fileLocation)
{
	AudioElement* newAudio = new AudioElement();
	if (newAudio->Initalise(fileLocation))
	{
		m_AudioElements.push_back(newAudio);
		return m_AudioElements.size() - 1;
	}
	return -2;
}

#include "AudioElement.h"
#include <Windows.h>
#include <mmsystem.h>


AudioElement::AudioElement()
{
	data = 0;
}


AudioElement::~AudioElement()
{
}

bool AudioElement::Initalise(char * fileLocation)
{
	std::ifstream file(fileLocation, std::ios::binary);
	if (!file)
	{
		return false;
	}
	try
	{
		file.seekg(0, std::ios::end);
		int flength = file.tellg();
		data = new char[flength];
		file.seekg(0, std::ios::beg);
		file.read(data, flength);
	}
	catch(std::exception e)
	{

	}
	file.close();
	return true;
}

void AudioElement::ShutDown()
{
	if (data)
	{
		delete data;
		data = 0;
	}
}

char* AudioElement::GetAudioClip()
{
	return data;
}

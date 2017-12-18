#pragma once
#include <iostream>
#include <fstream>
class AudioElement
{
public:
	AudioElement();
	~AudioElement();
	bool Initalise(char* fileLocation);
	void ShutDown();
	char* GetAudioClip();
private:
	char* data;

};


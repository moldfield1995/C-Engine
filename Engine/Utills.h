#pragma once

//Created by Matthew Oldfield
//Created in Final Year


class Utills
{
public:
	Utills() {};
	~Utills() {};
	//Basic Hash for string with basic hash collishon removal
	static int ParsString(char *fileLocation);
	//Debugs to Visual studio Debugger cleanly
	static void DebugString(const char* debugOutput);
	//Checks if a file Exsits
	static bool FileExsits(const char* filelocation);
	//Creates a randomFloat 0-1
	static float RandomFloat();
	//lerps between a and b by t
	static float Lerp(float a, float b, float t);
};


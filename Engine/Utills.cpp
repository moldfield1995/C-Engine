#include "Utills.h"
#include <string>
#include <windows.h>

int Utills::ParsString(char *fileLocation)
{
	std::string local = fileLocation;
	int id = 0;
	for (int itt = local.length()-1; itt >= 0; itt--)
	{
		id += local[itt];
	}
	return id * local.length();
}

void Utills::DebugString(const char * debugOutput)
{
	int stringlen = strlen(debugOutput)+1;
	wchar_t *wtext = new wchar_t[stringlen];
	mbstowcs(wtext, debugOutput, stringlen);
	OutputDebugString(wtext);
	//Required to force a new line
	OutputDebugString(L"\r\n");
	delete[] wtext;
}

bool Utills::FileExsits(const char * filelocation)
{
	int stringlen = strlen(filelocation) + 1;
	wchar_t *wtext = new wchar_t[stringlen];
	mbstowcs(wtext, filelocation, stringlen);

	return _waccess(wtext, 6) != -1;
	delete[] wtext;
}

////////////////////////////////////////////////////////////////////////////////
// Filename: userinterfaceclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _USERINTERFACECLASS_H_
#define _USERINTERFACECLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "textclass.h"
#include "GameObject.h"

////////////////////////////////////////////////////////////////////////////////
// Class name: UserInterfaceClass
////////////////////////////////////////////////////////////////////////////////
class UserInterfaceClass
{
public:
	UserInterfaceClass();
	UserInterfaceClass(const UserInterfaceClass&);
	~UserInterfaceClass();

	bool Initialize(D3DClass*, int, int);
	void Shutdown();

	bool Frame(ID3D11DeviceContext*, int,float ,float, bool, SpawnState );
	bool Render(D3DClass*, ShaderManagerClass*, const XMMATRIX&, const XMMATRIX&, const XMMATRIX&);


private:
	bool UpdateFpsString(ID3D11DeviceContext*, int);

private:
	FontClass* m_Font1;
	TextClass *m_FpsString, *m_SpawnType;
	int m_previousFps;
	int m_previousPosition[6];
};

#endif
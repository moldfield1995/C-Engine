////////////////////////////////////////////////////////////////////////////////
// Filename: zoneclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _ZONECLASS_H_
#define _ZONECLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "d3dclass.h"
#include "inputclass.h"
#include "shadermanagerclass.h"
#include "texturemanagerclass.h"
#include "timerclass.h"
#include "userinterfaceclass.h"
#include "cameraclass.h"
#include "lightclass.h"
#include "positionclass.h"
#include "frustumclass.h"
#include "skydomeclass.h"
#include "terrainclass.h"
#include "ModelManager.h"
#include "GameState.h"
#include "GameObject.h"
#include <vector>

//Updated In Final Year
//Created By RasterTeck
//Updated By Matthew Oldfield

////////////////////////////////////////////////////////////////////////////////
// Class name: ZoneClass
////////////////////////////////////////////////////////////////////////////////
class ZoneClass : public GameState
{
public:
	ZoneClass();
	ZoneClass(const ZoneClass&);
	~ZoneClass();

	bool Initialize(D3DClass*, int, int, float, TextureManagerClass*, ModelManager*, AudioManager*);
	void Shutdown();
	bool Frame(D3DClass*, InputClass*, ShaderManagerClass*, TextureManagerClass*,ModelManager*, float, int, AudioManager*);

protected:
	void HandleMovementInput(InputClass*, float);
	bool Render(D3DClass*, ShaderManagerClass*, TextureManagerClass*, ModelManager*);

private:
	void HandleInput(InputClass*, float, TextureManagerClass*, ModelManager*);
	bool CheckHitboxs(ModelManager*);
	UserInterfaceClass* m_UserInterface;
	CameraClass* m_Camera;
	LightClass* m_Light;
	PositionClass* m_Position;
	FrustumClass* m_Frustum;
	SkyDomeClass* m_SkyDome;
	TerrainClass* m_Terrain;
	bool m_displayUI, m_wireFrame, m_cellLines, m_heightLocked, m_DebugHitbox,m_ObjectSpawn;
	float m_xmod, m_ymod, m_zmod;
	int m_textID, m_modelID, m_bumpID;
	std::vector<GameObject*> m_GameObjects;
};

#endif
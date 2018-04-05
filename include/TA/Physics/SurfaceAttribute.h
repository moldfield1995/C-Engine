//---------------------------------------------------------------------------------
// File Name: SurfaceAttribute.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_SURFACEATTRIBUTE_H
#define TA_SURFACEATTRIBUTE_H

#ifndef TA_TYPES_H
#include "../Common/Types.h"
#endif 

#ifndef TA_MATHS_H
#include "../Common/Maths.h"
#endif 

#ifndef lOlOllllOll
#include "../Physics/zpta012.h"
#endif 



namespace TA
{

class lOlOlllllOO SurfaceAttribute
{
public:
	
	SurfaceAttribute();
	SurfaceAttribute(const SurfaceAttribute& that);
	~SurfaceAttribute() {}

	void Clear();

	void SetCollisionFriction(float fCollisionFriction);
	float GetCollisionFriction() const;

	void SetRestitution(float fRestitution);
	float GetRestitution() const;

	void SetTireFriction(float fTireFriction);
	float GetTireFriction() const;

	void SetTireFrictionFallOff(float fTireFrictionFallOff);
	float GetTireFrictionFallOff() const;

	void SetUserData(u32 nUserData);
	u32 GetUserData() const;
	

private:
	float lllOOOlOllOl;
	float lOOllOlOOOOO;
	float lllOOOlOlllO;
	float lllOOOlOllll;
	u32 llOllOlOOOl;
};

inline void SurfaceAttribute::SetCollisionFriction(float lllOOOllOOOO) { lllOOOlOllOl = lllOOOllOOOO; }
inline float SurfaceAttribute::GetCollisionFriction() const { return lllOOOlOllOl; }
inline void SurfaceAttribute::SetRestitution(float lOllOOlOlOl) { lOOllOlOOOOO = lOllOOlOlOl; Clamp(lOOllOlOOOOO, -1.0f, 1.0f); }
inline float SurfaceAttribute::GetRestitution() const { return lOOllOlOOOOO; }
inline void SurfaceAttribute::SetTireFriction(float lllOOOllOOOl) { lllOOOlOlllO = lllOOOllOOOl; }
inline float SurfaceAttribute::GetTireFriction() const { return lllOOOlOlllO; }
inline void SurfaceAttribute::SetTireFrictionFallOff(float lllOOOllOOlO) { lllOOOlOllll = lllOOOllOOlO; }
inline float SurfaceAttribute::GetTireFrictionFallOff() const { return lllOOOlOllll; }
inline void SurfaceAttribute::SetUserData(u32 llOllOlOOlO) { llOllOlOOOl = llOllOlOOlO; }
inline u32 SurfaceAttribute::GetUserData() const { return llOllOlOOOl; }

}

#endif 

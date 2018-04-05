//---------------------------------------------------------------------------------
// File Name: CollisionObjectLineList.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_COLLISIONOBJECTLINELIST_H
#define TA_COLLISIONOBJECTLINELIST_H

#ifndef lOOllOllll
#include "../Common/zcta001.h"
#endif 

#ifndef TA_COLLISIONOBJECTSIMPLE_H
#include "CollisionObjectSimple.h"
#endif 

#ifndef TA_COLLISION_H
#include "Collision.h"
#endif 



namespace TA
{

struct MFrame;
class CollisionObjectCachedPolyData;

class lOlOlllllOO CollisionObjectLineList : public CollisionObjectSimple
{
public:
	
	void Initialise(const Vec3* v3PointList, int nNumLines);
	void Finalise();
	
	
	#ifndef TA_WRAPPER	
	void Serialise(Serialiser& serialiser, const Version& version);
	#endif 
	
	bool Serialisable() const { return true; }
	
	AABB CalculateBoundingBox() const;
	void CalculateMass(float fDensity, float& fMass, Vec3& v3CenterOfMass, Mat33& m33Inertia) const;
		
	virtual void Render(const MFrame& mFrame);

	virtual bool TestLineForCollision(
		const Vec3& v3Start,
		const Vec3& v3Normal,
		float fLength,
		Collision& collision) const { return false; }
	int GetNumLines() const;
	
	static CollisionObjectLineList* TAC_CALL CreateNew();

	

#ifndef DOXYGEN
	lOlllOOOllO(llllOOlllll)

	lOlllOOOlOO(llllOOllOOO)
	lOlllOOOlOO(llllOOllOOl)
	lOlllOOOlOO(llllOOOOOOO)	
	lOlllOOOlOO(llllOOlOlOl)

#endif 

private:
	struct lOlOllllOl
	{
		Vec3 lOOlOlOlll;
		Vec3 lOOlOllOOl;
	};
	lOOOOlOllO<lOlOllllOl, false> llllOOOOOll;

	CollisionObjectLineList();
	~CollisionObjectLineList();

	virtual const char* llOllOOlOlO() const { return "TAColObjLines"; }
};

inline int CollisionObjectLineList::GetNumLines() const { return llllOOOOOll.lOOOlllOOl(); }

#ifndef DOXYGEN

lOlllOOOlOl(llllOOlllll)

#endif 

}

#endif 

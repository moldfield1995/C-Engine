//---------------------------------------------------------------------------------
// File Name: CollisionObjectCapsule.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_COLLISIONOBJECTCAPSULE_H
#define TA_COLLISIONOBJECTCAPSULE_H

#ifndef TA_COLLISION_H
#include "Collision.h"
#endif 

#ifndef TA_COLLISIONOBJECTSIMPLE_H
#include "CollisionObjectSimple.h"
#endif 



namespace TA
{

struct MFrame;
class CollisionObjectCachedPolyData;

class lOlOlllllOO CollisionObjectCapsule : public CollisionObjectSimple
{
public:
	
	void Initialise(
		const Vec3& v3PointA,
		const Vec3& v3PointB,
		float fRadius);
	void Finalise();
	
	
#ifndef TA_WRAPPER	
	void Serialise(Serialiser& serialiser, const Version& version);
#endif 
	
	bool Serialisable() const { return true; }

	void Render(const MFrame& mFrame);
	AABB CalculateBoundingBox() const;
	void CalculateMass(float fDensity, float& fMass, Vec3& v3CenterOfMass, Mat33& m33Inertia) const;

	const Vec3& GetPointA() const;
	const Vec3& GetPointB() const;
	float GetRadius() const;
	
	virtual bool TestLineForCollision(
		const Vec3& v3Start,
		const Vec3& v3Normal,
		float fLength,
		Collision& collision) const;

	static CollisionObjectCapsule* TAC_CALL CreateNew();
	

#ifndef DOXYGEN
	lOlllOOOlOO(lllOllOllOl)
	lOlllOOOlOO(llllOOOOlOO)	
	lOlllOOOlOO(lllOllllOOl)
	lOlllOOOlOO(llllOOOOlOl)
	lOlllOOOlOO(llllOOOOOOO)

	lOlllOOOllO(lllOlllllOl)
#endif 


private:
	float lOlOlOOlOlO;
	Vec3 lllOlOlOOlO;
	Vec3 lllOlOlOOll;

	CollisionObjectCapsule();
	~CollisionObjectCapsule();
	virtual const char* llOllOOlOlO() const { return "TAColObjCapsule"; }
};

inline const Vec3& CollisionObjectCapsule::GetPointA() const { return lllOlOlOOlO; }
inline const Vec3& CollisionObjectCapsule::GetPointB() const { return lllOlOlOOll; }
inline float CollisionObjectCapsule::GetRadius() const { return lOlOlOOlOlO; }

#ifndef DOXYGEN
lOllOllllll(lllOllOllOl)
lOllOllllll(lllOllllOOl)
lOllOllllll(llllOOOOOOO)

lOlllOOOlOl(lllOlllllOl)
#endif 

};

#endif 

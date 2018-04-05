//---------------------------------------------------------------------------------
// File Name: CollisionObjectSphere.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_COLLISIONOBJECTSPHERE_H
#define TA_COLLISIONOBJECTSPHERE_H

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

class lOlOlllllOO CollisionObjectSphere : public CollisionObjectSimple
{
public:
	
	void Initialise(
		const Vec3& v3Center,
		float fRadius);
	void Finalise();
	
	
	#ifndef TA_WRAPPER	
	void Serialise(Serialiser& serialiser, const Version& version);
	#endif 
	
	bool Serialisable() const { return true; }

	void Render(const MFrame& mFrame);
	AABB CalculateBoundingBox() const;
	void CalculateMass(float fDensity, float& fMass, Vec3& v3CenterOfMass, Mat33& m33Inertia) const;

	const Vec3& GetPoint() const;
	float GetRadius() const;
	
	virtual bool TestLineForCollision(
		const Vec3& v3Start,
		const Vec3& v3Normal,
		float fLength,
		Collision& collision) const;

	static CollisionObjectSphere* TAC_CALL CreateNew();

	

#ifndef DOXYGEN
	lOlllOOOlOO(llllOOllOlO)
	lOlllOOOlOO(llllOOlOllO)
	lOlllOOOlOO(lllOllllOOl)
	lOlllOOOlOO(llllOOllOll)
	lOlllOOOlOO(llllOOllOOO)

	lOlllOOOllO(llllOlOOOOO)
#endif 

private:
	float lOlOlOOlOlO;
	Vec3 lllOOOOllOO;

	CollisionObjectSphere();
	~CollisionObjectSphere();
	
	virtual const char* llOllOOlOlO() const { return "TAColObjSphere"; }
};

inline const Vec3& CollisionObjectSphere::GetPoint() const { return lllOOOOllOO; }
inline float CollisionObjectSphere::GetRadius() const { return lOlOlOOlOlO; }

#ifndef DOXYGEN
lOllOllllll(llllOOllOlO)
lOllOllllll(llllOOllOOO)

lOlllOOOlOl(llllOlOOOOO)
#endif 

}


#endif 

//---------------------------------------------------------------------------------
// File Name: CollisionObjectCylinder.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_COLLISIONOBJECTCYLINDER_H
#define TA_COLLISIONOBJECTCYLINDER_H

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

class lOlOlllllOO CollisionObjectCylinder : public CollisionObjectSimple
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

	static CollisionObjectCylinder* TAC_CALL CreateNew();

	

#ifndef DOXYGEN
	friend void TAC_CALL llllOOlllOO(
		const CollisionObjectSimple& lOOOllllOllO,
		const MFrame& lOlllOOOOOl,
		const MFrame& lOlllOOOOlO,
		bool lOllOlllOll,
		const CollisionObjectSimple& lOOOllllOlll,
		lOllOlllOOO* lOlllOOOOll);

	lOlllOOOlOO(llllOOlllOO)
	lOlllOOOlOO(llllOOlOlll)
	lOlllOOOlOO(llllOOllOll)
	lOlllOOOlOO(llllOOOOlOl)

	lOlllOOOllO(llllOlOOOOl)

	lOlllOOOlOO(llllOOllOOl)
	
#endif 

private:
	float lOlOlOOlOlO;
	Vec3 lllOlOlOOlO;
	Vec3 lllOlOlOOll;

	CollisionObjectCylinder();
	~CollisionObjectCylinder();
	virtual const char* llOllOOlOlO() const { return "TAColObjCylinder"; }
};

inline const Vec3& CollisionObjectCylinder::GetPointA() const { return lllOlOlOOlO; }
inline const Vec3& CollisionObjectCylinder::GetPointB() const { return lllOlOlOOll; }
inline float CollisionObjectCylinder::GetRadius() const { return lOlOlOOlOlO; }

#ifndef DOXYGEN
lOllOllllll(llllOOlllOO)
lOllOllllll(llllOOllOll)
lOllOllllll(llllOOOOlOl)

lOlllOOOlOl(llllOlOOOOl)

lOllOllllll(llllOOllOOl)
#endif 

}


#endif 

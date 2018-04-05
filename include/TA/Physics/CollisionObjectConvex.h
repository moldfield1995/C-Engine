//---------------------------------------------------------------------------------
// File Name: CollisionObjectConvex.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_COLLISIONOBJECTCONVEX_H
#define TA_COLLISIONOBJECTCONVEX_H

#ifndef TA_REFCOUNT_H
#include "../Common/RefCount.h"
#endif 

#ifndef TA_AABB_H
#include "../Common/AABB.h"
#endif 

#ifndef TA_COLLISION_H
#include "Collision.h"
#endif 

#ifndef TA_COLLISIONOBJECTSIMPLE_H
#include "CollisionObjectSimple.h"
#endif 



namespace TA
{


struct MFrame;
struct AABB;
class ConvexHull;
class CollisionObjectCachedPolyData;

class lOlOlllllOO CollisionObjectConvex : public CollisionObjectSimple
{
public:
	struct Data;
	struct lllllOlOlll;
	struct Polygon;
	struct lllllOllOOl;
	struct Vertex;

	
	void Initialise();
	void InitialiseAsABox(float fSizeX, float fSizeY, float fSizeZ);
	void InitialiseAsABox(const AABB& aabb);
	void InitialiseAsAnOrientedBox(const AABB& aabb, const MFrame& mFrame);
	bool InitialiseFromPointList(const Vec3* pv3PointList, int nNumPoints);
	void InitialiseFromPlaneList(
		const Vec3* pv3PlaneNormalList, 
		const Vec3* pv3PlanePointList, 
		int nNumPlanes);
	void InitialiseFromConvexHull(ConvexHull& convexHull);
	void Finalise();
	
	
	#ifndef TA_WRAPPER	
	void Serialise(Serialiser& serialiser, const Version& version);
	#endif 
	
	bool Serialisable() const { return true; }

	AABB CalculateBoundingBox() const;
	void CalculateMass(float fDensity, float& fMass, Vec3& v3CenterOfMass, Mat33& m33Inertia) const;

	void Transform(const MFrame& frame);
	void Render(const MFrame& mFrame);

	virtual bool TestLineForCollision(
		const Vec3& v3Start,
		const Vec3& v3Normal,
		float fLength,
		Collision& collision) const;

	static CollisionObjectConvex* TAC_CALL CreateNew();

	

#ifndef DOXYGEN
	lOlllOOOlOO(llllOOlOlOO)
	lOlllOOOlOO(llllOOOOlOO)
	lOlllOOOlOO(llllOOlOlll)
	lOlllOOOlOO(llllOOlOllO)	
	lOlllOOOlOO(llllOOlOlOl)

	lOlllOOOllO(lllOlOOlllO)

	const Data* GetData() const { return lOlOOlOllO; }
#endif 



private:
	Data* lOlOOlOllO;
#ifdef lOOOOOOOlllO
	mutable Polygon* lOOOOOOOllll;
#endif 

	CollisionObjectConvex();
	~CollisionObjectConvex();
	void InitialiseCommon();
	void llllllOOllO(const AABB& lOOOOOOlll, const MFrame* lOOOOOOlOlOO);

	virtual const char* llOllOOlOlO() const { return "TAColObjConvex"; }
	
	void llllllOlllO();
	void llllllOllOO();
	
	void lOOOOOOllllO(
		int lOOOOOOlllll, 
		const Vec3* lOOOOOOOOlll,
		int& lOOOOOlOOOOO,
		int& lOOOOOlOOOOl,
		float& lOOOOOlOOOlO) const;
	
	void lOOOOOlOOlOl(
		int lOOOOOOlllll,
		const Vec3* lOOOOOlOOllO,
		const Vec3* lOOOOOlOOlll,
		Polygon& lOllOOOlOl,
		lOllOlllOOO* lOlllOOOOll,
		const MFrame& lOOOOOOOOl,
		float lOOOOOlOlOOO) const;
	
	float lOOOOOlOlOOl(		
		const Vec3* lOOOOOlOlOlO,
		const CollisionObjectConvex& lllOllOllll,
		int& lOOOOOlOlOll,
		int& lOOOOOlOllOO) const;

	int lOOOOOllOOll(	
		int lOOOOOlOOOOl, 
		const Vec3& lOOOOOllOlOO) const;

	int lOOOOOlllOOO(const Vec3& lOOOOOllOlOO) const;
};

#ifndef DOXYGEN
lOllOllllll(llllOOlOlOO)
lOllOllllll(llllOOOOlOO)
lOllOllllll(llllOOlOlll)
lOllOllllll(lOOOlOOOlOOl)
lOllOllllll(llllOOlOlOl)
#endif 

}

#endif 

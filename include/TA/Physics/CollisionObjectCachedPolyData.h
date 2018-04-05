//---------------------------------------------------------------------------------
// File Name: CollisionObjectCachedPolyData.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_COLLISIONOBJECTCACHEDPOLYDATA_H
#define TA_COLLISIONOBJECTCACHEDPOLYDATA_H

#ifndef lOOllOllll
#include "../Common/zcta001.h"
#endif 

#ifndef lOOllOlllO
#include "../Common/zcta000.h" 
#endif 

#ifndef llOOllOOOOl
#include "../Physics/zpta001.h"
#endif 

#ifndef TA_COLLISION_H
#include "Collision.h"
#endif 

#ifndef TA_COLLISIONOBJECT_H
#include "CollisionObject.h"
#endif 



namespace TA
{

struct AABB;
class CollisionObjectSimple;

class CollisionObjectCachedPolyData : public CollisionObject
{
public:
	
	struct Vertex
	{
		const Vec3& GetPosition();
		void SetPosition(const Vec3& v3Position);
		const Vec3& GetEdgeNormal();
		void SetEdgeNormal(const Vec3& v3EdgeNormal);
		
#ifndef lOllOllOOlO
	private:
#endif 
		Vec3 lOOOOlllll;
		Vec3 lOlllOlOlll;
	};
	
	struct Polygon 
	{
		const Vec3& GetNormal();
		void SetNormal(const Vec3& v3Normal);
		int GetAttribute() const;
		void SetAttribute(int nAttribute);
		int GetNumVertices() const;
		void SetCollisionID(u32 nCollisionID);
		u32 GetCollisionID() const;
		
		Vertex& GetVertex(int nIndex);
		const Vertex& GetVertex(int nIndex) const;
		void GenerateEdgeNormals();
		
#ifndef lOllOllOOlO
	private:
#endif 
		Vec3 lOOOlOOOOO;
		int llOlllOlOOO;
		int lOllOlllOl;
		u32 llOlllOlllO;
		u32 lllOlOOlOOO;
		Vertex llOllllOlO[lOlllOOlOll];
	};

	void Initialise();
	void Finalise();

	
	void Clear();
	Polygon* GetNewPolygon(int nNumVertices);
	
	

#ifndef DOXYGEN
	const u8* GetData() const { return &lOOOllOOlOO[0]; }
	const u8* lllOlOOlOOl(int lOOOlOOlll) const { return &lOOOllOOlOO[lOOOlOOlll]; }
	int lllOlOOlOlO() const { return lOOOllOOlOO.lOOOlllOOl(); }
	static int TAC_CALL lllOOllOOOl(int lOllOlllOl) { return sizeof (Vec3) + sizeof (int) * 4 + sizeof (Vertex) * lOllOlllOl; }
#endif 

#ifndef DOXYGEN
	virtual bool TestLineForCollision(
		const Vec3& lOOlOlOlll,
		const Vec3& lOOOlOOOOO,
		float lOOlOllOOO,
		Collision& llOllllOlll) const { return false; }

	CollisionObject* lllOlOOlOll() { return lllOOlOllll; }
	void lllOlOOllOO(CollisionObject* lllOlOOllOl) { lllOOlOllll = lllOlOOllOl; }

	lOlllOOOllO(lllOlOOlllO)		

#endif 

	static CollisionObjectCachedPolyData* TAC_CALL CreateNew();

protected:
	CollisionObjectCachedPolyData();
	~CollisionObjectCachedPolyData();	

private:
	lOOOOlOllO<u8, false> lOOOllOOlOO;

	virtual const AABB& GetAABB() const { return NoGetAABB(); }

	static void TAC_CALL lllOlOOllll(lOOOOllOll::lOOllOOOOO* lOOlllOOOl, void* lOOlllOOOO);
	CollisionObject* lllOOlOllll;
};

inline const Vec3& CollisionObjectCachedPolyData::Vertex::GetPosition() { return lOOOOlllll; }
inline void CollisionObjectCachedPolyData::Vertex::SetPosition(const Vec3& lOOOOlllll) { this->lOOOOlllll = lOOOOlllll; }
inline const Vec3& CollisionObjectCachedPolyData::Vertex::GetEdgeNormal() { return lOlllOlOlll; }
inline void CollisionObjectCachedPolyData::Vertex::SetEdgeNormal(const Vec3& lOlllOlOlll) { this->lOlllOlOlll = lOlllOlOlll; }
inline const Vec3& CollisionObjectCachedPolyData::Polygon::GetNormal() { return lOOOlOOOOO; }
inline void CollisionObjectCachedPolyData::Polygon::SetNormal(const Vec3& lOOOlOOOOO) { this->lOOOlOOOOO = lOOOlOOOOO; }
inline int CollisionObjectCachedPolyData::Polygon::GetAttribute() const { return llOlllOlOOO; }
inline void CollisionObjectCachedPolyData::Polygon::SetCollisionID(u32 llOlllOlllO) { this->llOlllOlllO = llOlllOlllO; }
inline u32 CollisionObjectCachedPolyData::Polygon::GetCollisionID() const { return llOlllOlllO; }
inline void CollisionObjectCachedPolyData::Polygon::SetAttribute(int llOlllOlOOO) { this->llOlllOlOOO = llOlllOlOOO; }
inline int CollisionObjectCachedPolyData::Polygon::GetNumVertices() const { return lOllOlllOl; }
inline CollisionObjectCachedPolyData::Vertex& CollisionObjectCachedPolyData::Polygon::GetVertex(int lOOOlOOlll) { TA_ASSERT(lOOOlOOlll >= 0); TA_ASSERT(lOOOlOOlll < lOllOlllOl); return llOllllOlO[lOOOlOOlll]; }
inline const CollisionObjectCachedPolyData::Vertex& CollisionObjectCachedPolyData::Polygon::GetVertex(int lOOOlOOlll) const { return llOllllOlO[lOOOlOOlll]; }
inline void CollisionObjectCachedPolyData::Clear() { lOOOllOOlOO.Clear(); }

#ifndef DOXYGEN

void TAC_CALL lllOOllOOlO();

void TAC_CALL lllOOllOOll(lOllOlllOOO* lOlllOOOOll);

void TAC_CALL lllOOlllOlO(
	float lllOlllllO,
	float lOllOOlOOll,
	const CollisionObjectCachedPolyData::Polygon* llOOOlOlOO,
	int lOlllOlOOl,
	bool lllOOlllOll,
	const Vec3& lllOOOlllOO,
	const Vec3& lllOOllllOO,
	const Vec3& lOOOlOOOOO);

void TAC_CALL lllOlOOOOOO(
	const Vec3& lllOlOOOlOl,
	const Vec3& lllOOOlllll);

enum 
{ 
	lllOlOOOOOl = 0,
	lllOlOOOlOO,
};

void TAC_CALL lllOlOOOOOO(
	const Vec3& lllOlOOOlOl,
	int lOllOlOlOlO);

void TAC_CALL lllOlOOOllO(
	float lllOlllllO,
	float lOllOOlOOll,
	u32 llOlllOlOOO,
	const Vec3& lOllllOOllO,
	const Vec3& lOlllOllOlO,
	const Vec3& lllOOllllOO,
	const Vec3& lOOOlOOOOO,
	int lOllOlOlOlO);

void TAC_CALL lllOlOOOlll(
	const Vec3& lOllllOOllO,
	const Vec3& lOlllOllOlO,
	int lOllOlOlOlO);

#endif 

};


#endif 

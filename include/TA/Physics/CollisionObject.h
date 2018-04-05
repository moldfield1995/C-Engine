//---------------------------------------------------------------------------------
// File Name: CollisionObject.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_COLLISIONOBJECT_H
#define TA_COLLISIONOBJECT_H

#ifndef TA_AABB_H
#include "../Common/AABB.h"
#endif 

#ifndef TA_REFCOUNT_H
#include "../Common/RefCount.h"
#endif 

#ifndef lOlOllllOll
#include "../Physics/zpta012.h"
#endif 



namespace TA
{

struct MFrame;
class Serialiser;
struct Version;
class lllOlOOOlO;
class Collision;

class lOlOlllllOO CollisionObject : public RefCount
{
public:
	
	enum Type
	{
		
		
		
		TYPE_CONVEX = 0,
		TYPE_LINE_LIST,
		TYPE_CAPSULE,
		TYPE_SPHERE,
		TYPE_CYLINDER,

		
		TYPE_COMPLEX,

		
		TYPE_CACHED_POLY_DATA,
		TYPE_COMBO,

		NUM_TYPES
	};
	
	virtual ~CollisionObject() {}

	bool InitialiseFromFile(const Char* szFileName);
	bool SaveToFile(const Char* szFileName);
	bool InitialiseFromFileInMemory(void* pFileData, int nSizeInBytes);
	bool SaveToFileInMemory(void* pFileData, int nSizeInBytes);
	int CalculateFileSize();

	
	
	
	virtual void Serialise(Serialiser& lOOOlOllOl, const Version& lllOlOOlOO) { TA_ASSERT(0); }
	
	
	virtual bool Serialisable() const { return false; }

	virtual void Render(const MFrame& mFrame) {};

	virtual const AABB& GetAABB() const = 0;
	
	virtual bool TestLineForCollision(
		const Vec3& v3Start,
		const Vec3& v3Normal,
		float fLength,
		Collision& collision) const = 0;

	int GetCollisionObjectType() const;
	void SetUserData(u32 nUserData);
	u32 GetUserData() const;
	

protected:
	AABB lOOlOllOlO;

	CollisionObject(int lOllOlOlOlO) : llOllOlOOOO(lOllOlOlOlO), llOllOlOOOl(0) {}
	const AABB& NoGetAABB() const { lOOOOOOllO(0, "GetAABB Not Implemented on this class"); return lOOlOllOlO; }

private:
	const int llOllOlOOOO;
	int llOllOlOOOl;

	virtual const Char* llOllOOlOlO() const { return 0; }
};

inline int CollisionObject::GetCollisionObjectType() const { return llOllOlOOOO; }
inline void CollisionObject::SetUserData(u32 llOllOlOOlO) { llOllOlOOOl = llOllOlOOlO; }
inline u32 CollisionObject::GetUserData() const { return llOllOlOOOl; }

}

#endif 

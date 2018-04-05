//---------------------------------------------------------------------------------
// File Name: StaticObject.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_STATICOBJECT_H
#define TA_STATICOBJECT_H

#ifndef TA_DYNAMICOBJECT_H
#include "DynamicObject.h"
#endif 



namespace TA
{

class CollisionObjectComplex;

class lOlOlllllOO StaticObject : public PhysicsObject
{
public:
	//pl.BeginExportClass(StaticObject)

	
	void Initialise(CollisionObjectComplex* pCollisionObjectComplex);
	void Finalise();

	const MFrame& GetFrame() const;
	void SetFrame(const MFrame& frame);
	const MFrame& GetNextFrame() const;
	void SetNextFrame(const MFrame& nextFrame);

	CollisionObjectComplex& GetCollisionObject();
	const AABB& GetWorldAABB() const;

	void TestLineForCollision(
		const Vec3& v3Start,
		const Vec3& v3Normal,
		float fLength,
		Collision& collision);

	DynamicObject* GetDynamicObject();

	static StaticObject* TAC_CALL CreateNew();

	//pl.Release()

		
	void SetUserData(void* pData);
	void* GetUserData();
	

	//pl.EndExportClass(DynamicObject)

protected:
	StaticObject();
	~StaticObject();
	

private:
	DynamicObject* lOlOlllOOOOO;
};

inline const MFrame& StaticObject::GetFrame() const { return lOlOlllOOOOO->GetFrame(); }
inline const MFrame& StaticObject::GetNextFrame() const { return lOlOlllOOOOO->GetNextFrame(); }
inline CollisionObjectComplex& StaticObject::GetCollisionObject() { TA_ASSERT(lOlOlllOOOOO); TA_ASSERT(lOlOlllOOOOO->GetCollisionObjectComplex()); return *lOlOlllOOOOO->GetCollisionObjectComplex(); }
inline const AABB& StaticObject::GetWorldAABB() const { return lOlOlllOOOOO->GetWorldAABB(); }
inline DynamicObject* StaticObject::GetDynamicObject() { return lOlOlllOOOOO; }
inline void StaticObject::SetUserData(void* lOOlllOOOO) { lOlOlllOOOOO->SetUserData(lOOlllOOOO); }
inline void* StaticObject::GetUserData() { return lOlOlllOOOOO->GetUserData(); }

}

#endif 

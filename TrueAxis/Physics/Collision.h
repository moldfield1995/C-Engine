//---------------------------------------------------------------------------------
// File Name: Collision.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_COLLISION_H
#define TA_COLLISION_H

#ifndef TA_MFRAME_H
#include "../Common/MFrame.h"
#endif 



namespace TA
{

class DynamicObject;
class StaticObject;
class CollisionObject;
class PhysicsJoint;
	
class Collision
{
public:
#ifndef DOXYGEN
	enum Type
	{
		lOllOlOOOOO =							 0x100000,
		lOllOlOOOOl =							 0x200000,
		lOllOlOOOlO =						 0x300000,
		TYPE_ROTATION_CONSTRAINT =				 0x400000,
		lOllOlOOOll =	 0x500000,
		lOllOlOOlOO =				 0x600000,
		lOllOlOOlOl =								 0x700000,
		lOllOlOOllO =								 0x700000,
	};
#endif 

	
	//pl.BeginExportClass(Collision)

	enum Flag
	{
		FLAG_CONSTRAIN_IN_BOTH_DIRECTIONS =		0x1,
		FLAG_FRICTION =							0x2,
		FLAG_FRICTION_GENERATING_IMPULSE =		0x4,
		FLAG_NO_FRICTION =						0x8,
		FLAG_JOINT =							0x10,
		FLAG_JOINT_LIMIT =						0x20,
		FLAG_COLLISION_OCCURRED =				0x40,
		FLAG_DISABLE_PUSHOUT =					0x80,
		FLAG_FRICTION_GENERATING_IMPULSE2 =		0x100,
		FLAG_MARKED =							0x200,
		FLAG_RESTITUTION_CALCULATED =			0x400,
		FLAG_OBJECTA_SOLID = 					0x1000,
		FLAG_OBJECTB_SOLID = 					0x2000,
		FLAG_NEW_COLLISION = 					0x4000,
		FLAG_ROTATION_CONSTRAINT =				0x8000,
		FLAG_OBJECTB_INFINITE_MASS =			0x10000,
		FLAG_DEPTH_CALCULATED_FROM_TIME =		0x20000,
		FLAG_USE_PUSH_OUT_MODIFIER =			0x40000,
#ifndef DOXYGEN
		FLAG_OBJECTA_SOLID_INTERNAL = 			0x80000,
		FLAG_OBJECTB_SOLID_INTERNAL = 			0x100000,
#endif 
	};

#ifndef TA_WRAPPER	
	Collision();
#endif 
	void Clear();
	void Initialise(
		DynamicObject* pNewObjectA,
		DynamicObject* pNewObjectB,
		float fNewTime,
		float fNewIntersectingDepth,
		const Vec3& v3NewPosition,
		const Vec3& v3NewNormal);
	
#ifndef DOXYGEN
#ifndef TA_WRAPPER
	inline void Initialise(
		Type eNewType,
		float fNewTime,
		float fNewIntersectingDepth,
		const Vec3& v3NewPosition,
		const Vec3& v3NewNormal,
		PhysicsJoint* pJoint = 0);
#endif 
#endif 

	const Vec3& GetPosition() const;
	void SetPosition(const Vec3& v3Position);
	const Vec3& GetNormal() const;
	void SetNormal(const Vec3& v3Normal);
	
	DynamicObject* GetObjectA() const;
	DynamicObject* GetObjectB() const;
	void SetObjectA(DynamicObject* pDynamicObject);
	void SetObjectB(DynamicObject* pDynamicObject);

	CollisionObject* GetCollisionObjectA();
	CollisionObject* GetCollisionObjectB();
	const CollisionObject* GetCollisionObjectA() const;
	const CollisionObject* GetCollisionObjectB() const;
	void SetCollisionObjectA(CollisionObject* pCollisionObjectA);
	void SetCollisionObjectB(CollisionObject* pCollisionObjectB);

	int GetFlags() const;
	void SetFlags(u32 nFlags);
	u32& Flags();
	float GetRestitution() const;
	void SetRestitution(float fRestitution);
	float GetImpulse() const;
	void SetImpulse(float fImpulse);
	float GetFrictionCoefficient() const;
	void SetFrictionCoefficient(float fFrictionCoefficient);
	float GetTime() const;
	void SetTime(float fTime);
	float GetIntersectingDepth() const;
	void SetIntersectingDepth(float fIntersectingDepth);
	u32 GetCollisionIdA() const;
	void SetCollisionIdA(u32 nCollisionIdA);
	u32 GetCollisionIdB() const;
	void SetCollisionIdB(u32 nCollisionIdB);
	u32 GetAttributeA() const;
	void SetAttributeA(u32 nAttributeA);
	u32 GetAttributeB() const;
	void SetAttributeB(u32 nAttributeB);

	
	PhysicsJoint* GetJoint();
	const PhysicsJoint* GetJoint() const;

	bool CollisionOccurred() const;
	Collision* GetNext();

	//pl.EndExportClass(Collision)
	
	

#ifdef TA_PHYSICS_INTERNAL

	void lOllOlOOlll(Collision* lOllOlOlOOO) { lOOOOOlOOOl = lOllOlOlOOO; }

	u32 GetType() { return lOlOllOOll & lOllOlOOllO; }
	void lOllOlOlOOl(u32 lOllOlOlOlO) { lOlOllOOll &= ~lOllOlOOllO; lOlOllOOll |= (lOllOlOlOlO & lOllOlOOllO); }

	
	
	DynamicObject* Collision::lOllOlOlOll() 
	{ 
		if ((lOlOllOOll & (FLAG_OBJECTB_SOLID_INTERNAL | FLAG_OBJECTB_INFINITE_MASS)) == 0)
			return lOllOOOlllO;
		else
			return 0;
	}

	
	
	inline void Collision::lOllOlOllOO()
	{
		TA_ASSERT(lOllOlOlOll());
		Swap(lOllOOOllOl, lOllOOOlllO);
		lOOOlOOOOO = -lOOOlOOOOO;
		Swap(lOllOOlOOOl, lOllOOlOOlO);
		Swap(lOllOOOllll, lOllOOlOOOO);

	#ifdef _DEBUG
		int lOllOlOllOl = lOlOllOOll;
	#endif
		
		TA_ASSERT((FLAG_OBJECTB_SOLID >> 1) == FLAG_OBJECTA_SOLID);
		TA_ASSERT((FLAG_OBJECTB_SOLID_INTERNAL >> 1) == FLAG_OBJECTA_SOLID_INTERNAL);
		const int lOllOlOlllO = (FLAG_OBJECTA_SOLID | FLAG_OBJECTB_SOLID | FLAG_OBJECTA_SOLID_INTERNAL | FLAG_OBJECTB_SOLID_INTERNAL);
		int lOllOlOllll = lOlOllOOll & lOllOlOlllO;
		lOllOlOllll = (((lOllOlOllll << 2) + lOllOlOllll) >> 1) & lOllOlOlllO;
		lOlOllOOll &= ~lOllOlOlllO;
		lOlOllOOll |= lOllOlOllll;

		lOllOOllOOO.Clear();
		lOllOOllOOl.Clear();
		
	#ifdef _DEBUG
		TA_ASSERT(
			((lOllOlOllOl & FLAG_OBJECTB_SOLID) && (lOlOllOOll & FLAG_OBJECTA_SOLID)) ||
			((!(lOllOlOllOl & FLAG_OBJECTB_SOLID)) && (!(lOlOllOOll & FLAG_OBJECTA_SOLID))));
		TA_ASSERT(
			((lOllOlOllOl & FLAG_OBJECTB_SOLID) && (lOlOllOOll & FLAG_OBJECTA_SOLID)) ||
			((!(lOllOlOllOl & FLAG_OBJECTB_SOLID)) && (!(lOlOllOOll & FLAG_OBJECTA_SOLID))));
		TA_ASSERT(
			((lOllOlOllOl & FLAG_OBJECTB_SOLID_INTERNAL) && (lOlOllOOll & FLAG_OBJECTA_SOLID_INTERNAL)) ||
			((!(lOllOlOllOl & FLAG_OBJECTB_SOLID_INTERNAL)) && (!(lOlOllOOll & FLAG_OBJECTA_SOLID_INTERNAL))));
		TA_ASSERT(
			((lOllOlOllOl & FLAG_OBJECTB_SOLID_INTERNAL) && (lOlOllOOll & FLAG_OBJECTA_SOLID_INTERNAL)) ||
			((!(lOllOlOllOl & FLAG_OBJECTB_SOLID_INTERNAL)) && (!(lOlOllOOll & FLAG_OBJECTA_SOLID_INTERNAL))));
	#endif
	}
#endif 



	
	friend void lOllOllOOOO(Collision* lOllOllOOOl, Collision* lOOOOOlOOOl);

#ifndef lOllOllOOlO
private:
#endif 

	friend class PreCollision;
	friend class PostCollision;

	Vec3 lOOOOlllll;
	Vec3 lOOOlOOOOO;
	
	Vec4 lOllOOllOOO;
	Vec4 lOllOOllOOl;

	u32 lOlOllOOll;
	DynamicObject* lOllOOOllOl;
	DynamicObject* lOllOOOlllO;
	Collision* lOOOOOlOOOl;

	float lOllOOlOlOl;
	float lOllOOlOlll;
	float lOllOOlOlOO;
	float lOllOOlOllO;

	float lllOlllllO;
	float lOllOOlOOll;
	u32 lOllOllOOll;
	u32 lOllOllOlOO;
	
	CollisionObject* lOllOOOllll;
	CollisionObject* lOllOOlOOOO;
	u32 lOllOOlOOOl;
	u32 lOllOOlOOlO;
	

	Collision* lOllOllOlOl() const { return (Collision*)this; }
};

#ifndef DOXYGEN
typedef bool (TAC_CALL *lOllOllOllO)(Collision& lOllOllOlll, void* lOOlllOOOO);
struct lOllOlllOOO
{
	
	
	lOllOllOllO lOllOlllOOl;
	void* lOllOlllOlO;
	bool lOllOlllOll;
	bool lOllOllllOO;
	u32 lOllOllllOl;
	CollisionObject* lOllOOOllll;
	CollisionObject* lOllOOlOOOO;
	MFrame lOllOlllllO;
};
#endif 

#define lOllOllllll(lOlllOOOOOO)			\
	void TAC_CALL lOlllOOOOOO(										\
		const MFrame& lOlllOOOOOl,									\
		const MFrame& lOlllOOOOlO,									\
		lOllOlllOOO* lOlllOOOOll);

#define lOlllOOOlOO(lOlllOOOOOO)	\
	friend lOllOllllll(lOlllOOOOOO)

#define lOlllOOOlOl(lOlllOOOOOO)			\
	void TAC_CALL lOlllOOOOOO(										\
		const MFrame& lOlllOOOOOl,									\
		const MFrame& lOlllOOOOlO,									\
		lOllOlllOOO* lOlllOOOOll);

#define lOlllOOOllO(lOlllOOOOOO)	\
	friend lOllOllllll(lOlllOOOOOO)


class PreCollision
{
public:
	const DynamicObject* GetObjectA() const;
	const DynamicObject* GetObjectB() const;
	const CollisionObject* GetCollisionObjectA() const;
	const CollisionObject* GetCollisionObjectB() const;
	const PhysicsJoint* GetJoint() const;

	PreCollision* GetNext();

	const Vec3& GetPosition() const;
	void SetPosition(const Vec3& v3Position);
	const Vec3& GetNormal() const;
	void SetNormal(const Vec3& v3Normal);

	u32 GetFlags() const;
	void SetFlags(u32 nFlags);
	
	float GetRestitution() const;
	void SetRestitution(float fRestitution);
	float GetFrictionCoefficient() const;
	void SetFrictionCoefficient(float fFrictionCoefficient);

	float GetTime() const;
	void SetTime(float fTime);
	float GetIntersectingDepth() const;
	void SetIntersectingDepth(float fIntersectingDepth);

	u32 GetAttributeA() const;
	u32 GetAttributeB() const;

	u32 GetCollisionIdA() const;
	u32 GetCollisionIdB() const;

	
private:
	friend class Physics;
	Collision lOlllOOOlll;
	PreCollision() {};
	PreCollision(const PreCollision&) {};
};


class PostCollision
{
public:
	DynamicObject* GetObjectA();
	DynamicObject* GetObjectB();
	CollisionObject* GetCollisionObjectA();
	CollisionObject* GetCollisionObjectB();
	PhysicsJoint* GetJoint();


	PostCollision* GetNext();

	const Vec3& GetPosition() const;
	const Vec3& GetNormal() const;

	u32 GetFlags() const;

	float GetImpulse() const;
	float GetTime() const;
	float GetIntersectingDepth() const;

	u32 GetAttributeA() const;
	u32 GetAttributeB() const;

	u32 GetCollisionIdA() const;
	u32 GetCollisionIdB() const;

	

private:
	friend class Physics;
	Collision lOlllOOOlll;
	PostCollision() {};
	PostCollision(const PostCollision&) {};

};

}

#include "../Physics/zpta001.inl"

#endif 

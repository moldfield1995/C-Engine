//---------------------------------------------------------------------------------
// File Name: Physics.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_PHYSICS_H
#define TA_PHYSICS_H

#ifndef TA_DEBUG_H
#include "../Common/Debug.h"
#endif 

#ifndef lOOOOOOllll
#include "../Common/zcta008.h"
#endif 

#ifndef lOlOlOllOO
#include "../Common/zcta009.h"
#endif 

#ifndef TA_VECTOR_H
#include "../Common/Vector.h"
#endif 

#ifndef lOlOllllOll
#include "../Physics/zpta012.h"
#endif 

#ifndef TA_DYNAMICOBJECT_H
#include "DynamicObject.h"
#endif 

#ifndef TA_STATICOBJECT_H
#include "StaticObject.h"
#endif 

#ifndef TA_SURFACEATTRIBUTE_H
#include "SurfaceAttribute.h"
#endif 



namespace TA
{

class Collision;
class llOOlOllOOl;
class SpaceDivisionObject;
class CollisionObjectCachedPolyData;
class lOllOlOlOOll;
class SurfaceAttribute;
class lOllOlOlllOO;
class lOlOllllOOOO;
struct lOlOOOOOOlll;
struct llllOllOllO;

class lOlOlllllOO Physics
{
public:
	//pl.BeginExportClass(Physics)
	

	enum Flags
	{
		FLAG_DYNAMIC_OBJECTS =			0x1,
		FLAG_STATIC_OBJECTS	=			0x2,

		FLAG_ALL_OBJECTS = FLAG_DYNAMIC_OBJECTS | FLAG_STATIC_OBJECTS, //pl. pascal($1 + $2;)
		FLAG_ALL_NON_DYNAMIC_OBJECTS = FLAG_STATIC_OBJECTS, //pl. pascal($2;)

		FLAG_GHOST_OBJECTS =			0x8,

		FLAG_SPACIAL_DIVISION_MASK =	0x20 + 0x40 + 0x80 + 0x100, 
		FLAG_XY_COLLISION_GRID =		0x20,
		FLAG_XZ_COLLISION_GRID =		0x40,
		FLAG_YZ_COLLISION_GRID =		0x60,
		FLAG_DYNAMIC_OCTREE =			0x80,
		FLAG_CTREE =					0x100
	};

	enum SpacialDivisionType
	{
		SPACIAL_DIVISION_TYPE_DYNAMIC_OCTREE = 0,
		SPACIAL_DIVISION_TYPE_CTREE = 1,
		SPACIAL_DIVISION_TYPE_XY_COLLISION_GRID = 2,
		SPACIAL_DIVISION_TYPE_XZ_COLLISION_GRID = 3,
		SPACIAL_DIVISION_TYPE_YZ_COLLISION_GRID = 4,
	};

	enum SetMovingPriority
	{
		SET_MOVING_PRIORITY_LOW = 0,
		SET_MOVING_PRIORITY_HIGH = 1
	};
	
#ifndef TA_WRAPPER	
	typedef bool (TA_CALL_BACK *DynamicVsDynamicCollisionTestCallBack)(DynamicObject& objectA, DynamicObject& objectB);
	typedef bool (TA_CALL_BACK *PreProcessCollisionCallBack)(PreCollision& collision);
	typedef void (TA_CALL_BACK *PostProcessCollisionCallBack)(PostCollision& collision);
	typedef void (TA_CALL_BACK *OnBrokenJointCallBack)(PhysicsJoint& joint);
	typedef bool (TA_CALL_BACK *CollisionCallBack)(const Collision& collision, void* pUserData);
	typedef bool (TA_CALL_BACK *CollisionCallBack)(const Collision& collision, void* pUserData);
	typedef bool (TA_CALL_BACK *IntersectingObjectCallBack)(DynamicObject& object, void* pCallBackData);
	typedef void (TA_CALL_BACK *OnMovingCallBack)(const DynamicObject& object, void* pCallBackData);
	typedef void (TA_CALL_BACK *OnRestingCallBack)(const DynamicObject& object, void* pCallBackData);
#endif 

	
	
	static void TAC_CALL CreateInstance();
	static void TAC_CALL DestroyInstance();
	static Physics& TAC_CALL GetInstance();
	void SetupSimulation();
	

	
	
	
	void Update(float fDt);
	void Render();
	

	
	
	
	
	void AddStaticObject(StaticObject* pStaticObject);
	void RemoveStaticObject(StaticObject* pStaticObject);
	

	
	
	int AddSurfaceAttribute(SurfaceAttribute* pSurfaceAttribute);
	int AddSurfaceAttribute();
	void RemoveSurfaceAttribute(int nIndex);
	SurfaceAttribute& GetSurfaceAttribute(int nIndex);
	int GetNumSurfaceAttributes();
	void SetDefaultSurfaceAttribute(SurfaceAttribute* pSurfaceAttribute);
	const SurfaceAttribute& GetDefaultSurfaceAttribute();
	

	
	
	void AddDynamicObject(DynamicObject* pDynamicObject, bool bInitiallyMoving = true);
	void RemoveDynamicObject(DynamicObject* pDynamicObject);

	void SetDynamicObjectIsMoving(DynamicObject* pDynamicObject, int nPriority = SET_MOVING_PRIORITY_LOW);
	void SetDynamicObjectAtRest(DynamicObject* pDynamicObject);
	

	
	
	void TestLineForCollision(
		const Vec3& v3Start,
		const Vec3& v3Normal,
		float fLength,
		Collision& collision,
		u32 nFlags);

	void TestLineForCollision(
		const Vec3& v3Start,
		const Vec3& v3End,
		Collision& collision,
		u32 nFlags = FLAG_ALL_OBJECTS);

#ifndef TA_WRAPPER	
	Collision TestLineForCollision(
		const Vec3& v3Start,
		const Vec3& v3Normal,
		float fLength,
		u32 nFlags);

	Collision TestLineForCollision(
		const Vec3& v3Start,
		const Vec3& v3End,
		u32 nFlags = FLAG_ALL_OBJECTS);
#endif 

	
	
	void ForAllIntersectingObjects(const AABB& aabb, IntersectingObjectCallBack pfnCallBack, void* pCallBackData);
	void WakeUpAllIntersectingObjects(const AABB& aabb);
	

	
	
	const Vec3& GetGravity() const;
	void SetGravity(const Vec3& v3Gravity);
	void SetRenderCollisionsEnabled(bool bValue);
	bool IsRenderCollisionsEnabled() const;
	void SetMovementPropagationEnabled(bool bValue);
	bool IsMovementPropagationEnabled() const;
	

	
	
	void SetWorldDimensions(const AABB& worldAABB);	
	const AABB& GetWorldDimensions();	
	void SetMaxNumCollisions(int nMaxNumCollisions);
	int GetMaxNumCollisions();
	void SetMaxNumMovingObjects(int nMaxNumMovingObjects);
	int GetMaxNumMovingObjects();
	void SetSlowSolverMaxNumCollisions(int nSlowSolverMaxNumCollisions);
	int GetSlowSolverMaxNumCollisions();
	void SetSlowSolverMaxNumObjects(int nSlowSolverMaxNumObjects);
	int GetSlowSolverMaxNumObjects();
	void SetMaxNumObjectPairs(int nMaxNumObjectPairs);
	int GetMaxNumObjectPairs();
#ifdef TA_WRAPPER	
	void SetSpacialDivisionType(int eSpacialDivisionType);
	int GetSpacialDivisionType();
#endif
#ifndef TA_WRAPPER	
	void SetSpacialDivisionType(SpacialDivisionType eSpacialDivisionType);
	SpacialDivisionType GetSpacialDivisionType();
#ifndef DOXYGEN
	void SetSpacialDivisionType(int nSpacialDivisionType);
#endif
#endif
	void SetSpacialDivisionMinSize(float fSpacialDivisionMinSize);
	float GetSpacialDivisionMinSize();
	void SetSpacialDivisionMaxMemory(int nSpacialDivisionMaxMemory);
	int GetSpacialDivisionMaxMemory();
	

	
	
	DynamicVsDynamicCollisionTestCallBack GetDynamicVsDynamicCollisionTestCallBack() const;
	void SetDynamicVsDynamicCollisionTestCallBack(DynamicVsDynamicCollisionTestCallBack pfnDynamicVsDynamicCollisionTest);
	PreProcessCollisionCallBack GetPreProcessCollisionCallBack() const;
	void SetPreProcessCollisionCallBack(PreProcessCollisionCallBack pfnPreProcessCollision);
	PostProcessCollisionCallBack GetPostProcessCollisionCallBack() const;
	void SetPostProcessCollisionCallBack(PostProcessCollisionCallBack pfnPostProcessCollision);
	

	
	
#ifndef TA_WRAPPER	
	OnBrokenJointCallBack GetOnBrokenJointCallBack() const;
	void SetOnBrokenJointCallBack(OnBrokenJointCallBack pfnOnBrokenJoint);
	OnMovingCallBack GetOnMovingCallBack() const;
	void SetOnMovingCallBack(OnMovingCallBack pfnOnMoving, void* pCallBackData);
	OnRestingCallBack GetOnRestingCallBack() const;
	void SetOnRestingCallBack(OnRestingCallBack pfnOnResting, void* pCallBackData);
#endif 
	

#ifdef TA_PHYSICS_INTERNAL	
	
	void lOOlllOOllOl(DynamicObject* lOlllOOlOOO, int lOOlllOOllOO = SET_MOVING_PRIORITY_LOW);
	CollisionObjectCachedPolyData& lllllOOOlll() { TA_ASSERT(lOlllOOOlllO); return *lOlllOOOlllO; }
	void lOOlllOOOOlO(DynamicObject* lOlllOOlOOO);
	lOllOlOlllOO& lOlOOOOlOOOO() { TA_ASSERT(lOllOlOllOll); return *lOllOlOllOll; }
	lOllOlOlllOO* llOOlOlOOlOO() { return lOllOlOllOll; }
	llllOllOllO& lOlOOllOOOOl() { TA_ASSERT(lOOllOllllOO); return *lOOllOllllOO; }
	bool llOOlOOOlOll();
	float llOOlOlOOlOl() const { return lOlllOOlOOOO; }
	void llOOlOOOllOO(DynamicObject* lOllOOOllOl, DynamicObject* lOllOOOlllO, const MFrame& lOOlllOlllOO, const MFrame& lOOlllOlllOl, float lOOlllOOllll);
	
#endif 

#ifndef TA_REMOVE_DEPRECATED
	
	
	static void TAC_CALL CreateInstance(
		const AABB& worldAABB,
		const Vec3& v3Gravity = Vec3(0.0f, -9.81f, 0.0f),
		u32 nFlags = FLAG_XZ_COLLISION_GRID,
		float fMinSpacialDivision = 10.0f,
		int nSpacialDivisionMemory = 0x40000);
	
#endif 

	//pl.EndExportClass(DynamicObject)


	
private:	
	enum llOOlOlOOllO
	{
		llOOlOlOOlll =			0x10000,
		lOllllOOllOO =		0x20000,
		lOlllOOlOllO =		0x40000,
		lOllOlOOllOl =		0x80000,
		lOllOlOOlllO =				0x100000,
		lOlllOlOlOll =		0x200000,
		lOlllOOlOlll =			0x400000,
		llOOOOlllllO =			0x800000,
	};
	struct lOllOlOOOlll;

	struct llOOlOlOlOOO
	{
		AABB lOllOlOOlOOl;
		int lOlOllllOlOO;
		int lOlOllllOOll;
		int lOlOllllOlll;
		int lOllOlOlOOOl;
		int lOllOllOOlOl;
		SpacialDivisionType lOllOlOlOlOl;
		float lOllOlOlOllO;
		int lOllOlOlOlll;
	};

	typedef List<StaticObject*>::Iterator lOlllOlOOOll;
	typedef List<DynamicObject*>::Iterator lOllOlOllOOO;
	typedef lOlOlllOlO<DynamicObject*>::lOOlOOlOOOl::Iterator lOlllOlOllOO;

	Vec3 lOlllOOOllll;
	float lOlllOOlOOOO;	
	float lOlllOOlOOOl;
	u32 lllOllOOOO;
	u32 lOllOllOOllO;

	llllOllOllO* lOOllOllllOO;
	lOllOlOlOOll* lOllOlOOllll;
	llOOlOllOOl* lOllOlOlOlOO;
	lOllOlOlllOO* lOllOlOllOll;
	DynamicObject* lOlllOOOlOll;
	DynamicObject* lOlllOOOllOO;
	DynamicObject* lOlllOOOllOl;
	List<DynamicObject*> lOllOlOllOOl;
	List<StaticObject*> lOlllOlOOlOl;
	lOlOlllOlO<DynamicObject*> lOllOlOlllOl;
	lOlOlllOlO<DynamicObject*>::lOOlOOlOOOl lOllOlOllllO;
	CollisionObjectCachedPolyData* lOlllOOOlllO;
	SurfaceAttribute lOlllOlOOOOO;
	lOOOOlOllO<SurfaceAttribute> lOlllOlOOOOl;
	DynamicVsDynamicCollisionTestCallBack lOlllOOllOlO;
	PreProcessCollisionCallBack lOlllOOllOll;
	PostProcessCollisionCallBack lOlllOOlllOO;
	OnBrokenJointCallBack lOlllOOlllOl;
	OnMovingCallBack lOlllOOllllO;
	void* lOlllOOlllll;
	OnRestingCallBack lOllOllOOOll;
	void* lOllOllOOlOO;
	llOOlOlOlOOO lOllOlOlOOOO;
	llOOlOlOlOOO lOllOlOlOOlO;
	
	void (TAC_CALL *lOlllOOlOOlO)(float lOOlOllOllll, Collision& llOllllOlll);
	void (TAC_CALL *lOlllOOlOOll)(float lOOlOllOllll, float llOlllOOOl, float lOlOOOllllll, Collision& llOllllOlll);
	bool (TAC_CALL *lOlllOOlOlOO)(float lOllOOlOlOO, Collision& llOllllOlll);
	void (TAC_CALL *lOlllOOlOlOl)(float lOOlOllOllll, float llOlllOOOl, Collision& llOllllOlll);
	float (TAC_CALL *lOlllOOllOOl)(float lOOlllOOllll, Collision& llOllllOlll);

	static Physics* lOllOlOOOOll;
	
	Physics();
	~Physics();

	void Initialise();
	void Initialise(
		const AABB& lOllOlOOlOOl,
		const Vec3& lOllOlOOlOlO,
		u32 lOlOllOOll,
		float lOllOlOOlOll,
		int lOllOlOOllOO);
	void Finalise();

	void lOlllOlOOlll();

	void lOllOllOlOOO(float lOOlllOOllll);
	void lOllOllOlOlO(float lOOlllOOllll, int lOllOllOlOOl);
	void lOllllOlOlOl(DynamicObject& lOllllOllOOl);
	void lOllllOllOll(PhysicsJoint& lOOlllOOOOll);
	void lOllOlllOOOO(lOlOllllOOOO& lOllOllOllOO);
	void llOOOOlOOlll(float lOOlllOOllll, Collision& llOllllOlll);
	void lOllOlllOOOl(float lOOlllOOllll, lOlOllllOOOO& lOllOllOllOO, int lOllOllOlOOl);
	float lOlOOlOOOOlO(float lOOlllOOllll, Collision& llOllllOlll) { TA_ASSERT(lOlllOOllOOl); return lOlllOOllOOl(lOOlllOOllll, llOllllOlll); }
	bool lOllOlllOOlO();
	void llOOOOlOllOl();
	bool lOllOlllOOll(lOlOllllOOOO& lOllOllOllOO);
	void lOllOlllOlOO(lOlOllllOOOO& lOllOllOllOO);
	void lOllOlllllll(float lOOlllOOllll, lOlOllllOOOO& lOllOllOllOO);
	void lOlllOOOlOOO(float lOOlllOOllll, bool llOOOlOOOllO, lOlOllllOOOO& lOllOllOllOO);
	void llOOOlOllOlO(PhysicsJoint& lOOlllllOOlO, bool llOOOlOlOOOl, float llOOOlOllOOl);
	void lOlllOOOlOOl(float lOOlllOOllll, bool llOOOlOOOllO);

	void lOlllOOOOlOl(lOlOllllOOOO&, lOllOlOOOlll*, int);
	void lOllOlllllOl(lOlOllllOOOO&, DynamicObject**, int&, int, Collision**, int&, int);
	void lOlllOOOOOOl(DynamicObject**, int, Collision**,int);
	void lOlllOOOOOlO(lOlOllllOOOO&, DynamicObject**, int, Collision**, int);	
	void lOlllOOOOllO(lOllOlOOOlll*, int, int, const Vec3&);
	void lOlllOOOOlll(lOllOlOOOlll*, int, int, const Vec3&);
	void lOllOllllllO(lOlOllllOOOO&, DynamicObject**, int, Collision**, int);	
	void llOOlOOOOOOl(lOllOlOOOlll*, int, int, const Vec3&);
	void lOlllOOOlOlO();
	
	void lOlOOOllllOl(float lOOlOllOllll, Collision& llOllllOlll) { TA_ASSERT(lOlllOOlOOlO); lOlllOOlOOlO(lOOlOllOllll, llOllllOlll); }
	void TAC_CALL lOlOOOlllllO(float lOOlOllOllll, float llOlllOOOl, float lOlOOOllllll, Collision& llOllllOlll) { TA_ASSERT(lOlllOOlOOll); lOlllOOlOOll(lOOlOllOllll, llOlllOOOl, lOlOOOllllll, llOllllOlll); }
	bool TAC_CALL lOlOOlOOOOOO(float lOllOOlOlOO, Collision& llOllllOlll) { TA_ASSERT(lOlllOOlOlOO); return lOlllOOlOlOO(lOllOOlOlOO, llOllllOlll); }
	void TAC_CALL lOlOOlOOOOOl(float lOOlOllOllll, float llOlllOOOl, Collision& llOllllOlll) { TA_ASSERT(lOlllOOlOlOl); lOlllOOlOlOl(lOOlOllOllll, llOlllOOOl, llOllllOlll); }

	bool llOOlOOOOlOO(DynamicObject* lOlllOOlOOO);

	void lOllOllOOlll();
	void llOOOOOOOllO();
	
	static bool TAC_CALL lOlllllOOlll(Collision& lOllOllOlll, void* lOOlllOOOO);
	static void TAC_CALL lOllllOlOOll(SpaceDivisionObject& llOOOOOOOOO, void* lOOlllOOOO);
	void lOllllOOlOll(lOlOOOOOOlll& lOlOOOOlllOO);
	static void TAC_CALL lOlllOlOllOl(SpaceDivisionObject& llOOOOOOOOO, void* lOOlllOOOO);
	static void TAC_CALL lOlllOlOlllO(SpaceDivisionObject& llOOOOOOOOO, void* lOOlllOOOO);
};

inline Physics& TAC_CALL Physics::GetInstance() { lOOOOOOllO(lOllOlOOOOll, "Physics::GetInstance. Instance not created."); return *lOllOlOOOOll; }
inline const Vec3& Physics::GetGravity() const { return lOlllOOOllll; }
inline void Physics::SetRenderCollisionsEnabled(bool lllOllOOlO) { if (lllOllOOlO) lllOllOOOO |= llOOOOlllllO; else lllOllOOOO &= ~llOOOOlllllO; }
inline bool Physics::IsRenderCollisionsEnabled() const { return (lllOllOOOO & llOOOOlllllO) != 0; }
inline void Physics::SetMovementPropagationEnabled(bool lllOllOOlO) { if (lllOllOOlO) lllOllOOOO |= lOlllOOlOlll; else lllOllOOOO &= ~lOlllOOlOlll; }
inline bool Physics::IsMovementPropagationEnabled() const { return (lllOllOOOO & lOlllOOlOlll) != 0; }
inline Physics::DynamicVsDynamicCollisionTestCallBack Physics::GetDynamicVsDynamicCollisionTestCallBack() const { return lOlllOOllOlO; }
inline void Physics::SetDynamicVsDynamicCollisionTestCallBack(DynamicVsDynamicCollisionTestCallBack llOOlOlOlOOl) { lOlllOOllOlO= llOOlOlOlOOl; }
inline Physics::PreProcessCollisionCallBack Physics::GetPreProcessCollisionCallBack() const { return lOlllOOllOll; }
inline void Physics::SetPreProcessCollisionCallBack(PreProcessCollisionCallBack llOOlOlOlOlO) { lOlllOOllOll = llOOlOlOlOlO; }
inline Physics::PostProcessCollisionCallBack Physics::GetPostProcessCollisionCallBack() const { return lOlllOOlllOO; }
inline void Physics::SetPostProcessCollisionCallBack(PostProcessCollisionCallBack llOOlOlOlOll) { lOlllOOlllOO = llOOlOlOlOll; }
inline Physics::OnBrokenJointCallBack Physics::GetOnBrokenJointCallBack() const { return lOlllOOlllOl; }
inline void Physics::SetOnBrokenJointCallBack(OnBrokenJointCallBack llOOlOlOllOO) { lOlllOOlllOl = llOOlOlOllOO; }
inline Physics::OnMovingCallBack Physics::GetOnMovingCallBack() const { return lOlllOOllllO; }
inline void Physics::SetOnMovingCallBack(OnMovingCallBack llOOlOlOllOl, void* lOOOOllllO) { lOlllOOllllO = llOOlOlOllOl; lOlllOOlllll = lOOOOllllO; }
inline Physics::OnRestingCallBack Physics::GetOnRestingCallBack() const { return lOllOllOOOll; }
inline void Physics::SetOnRestingCallBack(OnRestingCallBack llOOlOlOlllO, void* lOOOOllllO) { lOllOllOOOll = llOOlOlOlllO; lOllOllOOlOO = lOOOOllllO; }
inline void Physics::SetSpacialDivisionType(int llOOlOlOllll) { SetSpacialDivisionType((SpacialDivisionType)llOOlOlOllll); }

void TAC_CALL lOllOlOOlOOO(
	const AABB& lOllOlOOlOOl,
	const Vec3& lOllOlOOlOlO = Vec3(0.0f, -9.81f, 0.0f),
	u32 lOlOllOOll = Physics::FLAG_XZ_COLLISION_GRID,
	float lOllOlOOlOll = 10.0f,
	int lOllOlOOllOO = 0x40000);

}

#endif 

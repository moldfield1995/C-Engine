//---------------------------------------------------------------------------------
// File Name: DynamicObject.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_DYNAMICOBJECT_H
#define TA_DYNAMICOBJECT_H

#ifndef TA_MFRAME_H
#include "../Common/MFrame.h"
#endif 

#ifndef TA_AABB_H
#include "../Common/AABB.h"
#endif 

#ifndef lOOllOllll
#include "../Common/zcta001.h"
#endif 

#ifndef lOOOOOOllll
#include "../Common/zcta008.h"
#endif 

#ifndef lOlOlOllOO
#include "../Common/zcta009.h"
#endif 

#ifndef lllOlOlllO
#include "../Common/zcta005.h"
#endif 

#ifndef TA_PHYSICSOBJECT_H
#include "PhysicsObject.h"
#endif 

#ifndef lOlOOOlllOOl
#include "../Physics/zpta016.h"
#endif 

#ifndef TA_PHYSICSJOINT_H
#include "PhysicsJoint.h"
#endif 

#ifndef TA_COLLISIONOBJECT_H
#include "CollisionObject.h"
#endif 

#ifndef TA_COLLISION_H
#include "Collision.h"
#endif 

#ifndef TA_DYNAMICOBJECTCOLLISIONITERATOR_H
#include "DynamicObjectCollisionIterator.h"
#endif 



namespace TA
{

class CollisionObjectCombo;
class CollisionObjectComplex;
class DynamicObjectGroup;
struct EulerAngles;
struct llllOllOllO;


const float JOINT_LIMIT_DISABLED = k_fMaxFloat;



#ifdef TA_PHYSICS_INTERNAL
	


#define lOlOOOlllOlO(lOlOOOlllOll, lOlOOOllllOO) \
namespace lOlOOOllllOO \
{ \
	lOlOOOlllOll void TAC_CALL lOlOOOllllOl(float lOOlOllOllll, Collision& llOllllOlll); \
	lOlOOOlllOll void TAC_CALL lOlOOOlllllO(float lOOlOllOllll, float llOlllOOOl, float lOlOOOllllll, Collision& llOllllOlll); \
	lOlOOOlllOll bool TAC_CALL lOlOOlOOOOOO(float lOllOOlOlOO, Collision& llOllllOlll); \
	lOlOOOlllOll void TAC_CALL lOlOOlOOOOOl(float lOOlOllOllll, float llOlllOOOl, Collision& llOllllOlll); \
	lOlOOOlllOll float TAC_CALL lOlOOlOOOOlO(float lOOlllOOllll, Collision& llOllllOlll); \
}

lOlOOOlllOlO(extern, lOlOOlOOOOll)
lOlOOOlllOlO(extern, lOlOOlOOOlOO)

#endif 

class lOlOlllllOO DynamicObject : public PhysicsObject, public SpaceDivisionObject
{
public:	
	
	struct LineIntersection
	{
		float GetIntersectionDepth() const;
		DynamicObject* GetDynamicObject() const;
		CollisionObject* GetCollisionObject() const;
		int GetAttribute() const;
		const Vec3& GetPosition() const;
		const Vec3& GetNormal() const;
		

	private:
		friend class DynamicObject;
		friend class DynamicObjectCar;
		float lOllOOlOOll;
		DynamicObject* lOlllOOlOOO;
		CollisionObject* lOlOllOOOll;
		int llOlllOlOOO;
		Vec3 lOOOOlllll;
		Vec3 lOOOlOOOOO;
	};
	


	typedef List<PhysicsJoint>::Iterator JointIterator;
	typedef DynamicObjectCollisionIterator CollisionIterator;

	const static float JOINT_LIMIT_DISABLED;

	//pl.BeginExportClass(DynamicObject)

	enum ReinitFlags
	{
		REINIT_FLAG_UPDATE_MASS = 0x1,
		REINIT_FLAG_UPDATE_INERTIA_TENSOR = 0x2,
		REINIT_FLAG_UPDATE_CENTER_OFFSET = 0x4,
	};

	enum SetMovingPriority
	{
		SET_MOVING_PRIORITY_LOW = 0,
		SET_MOVING_PRIORITY_HIGH = 1
	};

	
	
	void InitialiseFromFile(const Char* szFileName);
	void InitialiseAsABox(const AABB& aabb);
	void InitialiseAsAnOrientedBox(const AABB& aabb, const MFrame& mFrame);
	void InitialiseAsACapsule(const Vec3& v3Start, const Vec3& v3End, float fRadius);
	void InitialiseAsASphere(const Vec3& v3Center, float fRadius);
	void InitialiseAsACylinder(const Vec3& v3Start, const Vec3& v3End, float fRadius);	
	void InitialiseFromPointList(const Vec3* pv3PointList, int nNumPoints);
	void Initialise(CollisionObjectCombo* pCollisionObjectCombo);
	void Initialise(CollisionObjectComplex* pCollisionObjectComplex);
#ifdef TA_PHYSICS_INTERNAL
	void InitialiseAsWorldObject();
#endif 
	void Finalise();
	

	
	
	const MFrame& GetFrame() const;
	void SetFrame(const MFrame& frame);
	const MFrame& GetNextFrame() const;
	const MFrame& GetPreviousFrame() const;
	const MFrame& GetGraphicsFrame() const;
	const Vec3& GetPosition() const;
	void SetPosition(const Vec3& v3Position);
	const Vec3& GetCenterOfMass() const;
	const Vec3& GetNextCenterOfMass() const;
	const Vec3& GetCenterOffset() const;
	void SetCenterOffset(const Vec3& v3CenterOffset);
	
	
	void SetFrameDirect(const MFrame& frame);
	

	
	
	float GetMass() const;
	float GetInverseMass() const;
	void SetMass(float fMass);
	const Mat33& GetInertia() const;
	void SetInertiaFromBox(const AABB& aabb);
	void SetInertiaFromBox(float fX, float fY, float fZ);
	const Mat33& GetInverseInertia() const;
	const Mat33& GetWorldSpaceInertia() const;
	const Mat33& GetWorldSpaceInverseInertia() const;
	

	
	
	void SetFriction(float fFriction);
	float GetFriction() const;
	void SetRestitution(float fRestitution);
	float GetRestitution() const;
	void SetGravityMult(float fGravityMult);
	float GetGravityMult() const;
	void SetRotationDisabled(bool bValue);
	bool RotationDisabled() const;
	void SetMovementDisabled(bool bValue);
	bool MovementDisabled() const;
	void SetForceFastSolverEnabled(bool bValue);
	bool IsForceFastSolverEnabled() const;
	void SetAllDampingDisabled(bool bValue);
	bool IsAllDampingDisabled() const;
	void SetExtraStability(bool bValue);
	bool ExtraStability() const;
	void SetRigidFrictionDisabled(bool bValue);
	bool RigidFrictionDisabled() const;
	void SetCollisionDisabled(bool bValue);
	bool CollisionDisabled() const;
	void SetUpdateDisabled(bool bValue);
	bool UpdateDisabled() const;
	void SetGhost(bool bValue);
	bool Ghost() const;
	void SetInfiniteMass(bool bValue);
	bool InfiniteMass() const;
	void SetFindVelocityFromNextFrame(bool bValue);
	bool GetFindVelocityFromNextFrame() const;
	bool IsWorldObject() const;
	void SetRestTimeMultiplier(float fRestTimeMultiplier);
	float GetRestTimeMultiplier() const;
	void SetID(int nID); 
	int GetID() const;
	Physics* GetPhysics();
	

	
	
	bool IsInMovingList() const;
	void SetToMoving(int nPriority = SET_MOVING_PRIORITY_LOW);
	void SetToResting();
	

	
	
	
	
#ifdef TA_PHYSICS_INTERNAL
	float lOlOOlOOOlOl() const { return lOOllOlOOOOl; }
	void lOlOOlOOOllO(float lllOlllllO) { lOOllOlOOOOl = lllOlllllO; }
	void lOlOOlOOOlll(float lOOlllOOllll) { lOOllOlOOOOl += lOOlllOOllll * lOOllOlOOOlO; lOOlllOOlOlO(false); }
	void lOOlllOOlllO() { lOOllOlOOOOl = 0.0f; lOOlllOOlOlO(false); }
	void lOOlllOOlOlO(bool lllOllOOlO) { lllOlOllll(lllOllOOOO, lOlOOOlllOOO, lllOllOOlO); }
	bool lOlOOOlOOOOO() const { return lllOllOOll(lllOllOOOO, lOlOOOlllOOO); }
	void lOOllOOlllOO(bool lllOllOOlO) { lllOlOllll(lllOllOOOO, lOlOOlOOlOOO, lllOllOOlO); }

	
	int lOlOOlOOlOOl() const { return lOOllOlOOOll; }
	void lOlOOlOOlOlO() { lOOllOlOOOll++; }
	void lOlOOlOOlOll() { lOOllOlOOOll = 0; }	

	
	void lOlOOlOOllOO(void* lOlOOlOOllOl) { lOOllOlOlOll = lOlOOlOOllOl; lllOlOllll(lllOllOOOO, lOlOOlOOlllO, lOOllOlOlOll != 0); lllOlOllll(lllOllOOOO, lOlOOOlllOOO, lOOllOlOlOll == 0); lllOlOllll(lllOllOOOO, lOlOOlOOllll, lOOllOlOlOll == 0); }
	void* lOlOOlOlOOOO() { return lOOllOlOlOll; }

	void lOlOOlOlOOOl(bool lllOllOOlO) { lllOlOllll(lllOllOOOO, lOlOOlOOllll, lllOllOOlO); }
	bool lOlOOOlOOOOl() const { return lllOllOOll(lllOllOOOO, lOlOOlOOllll); }

	
	void lOlOOlOlOOlO(bool lllOllOOlO) { lllOlOllll(lllOllOOOO, lOlOOlOlOOll, lllOllOOlO); }
	bool lOlOOlOlOlOO() const { return lllOllOOll(lllOllOOOO, lOlOOlOlOOll); }
	void lOlOOlOlOlOl(bool lllOllOOlO) { lllOlOllll(lllOllOOOO, lOlOOlOlOllO, lllOllOOlO); }
	bool lOlOOlOlOlll() const { return lllOllOOll(lllOllOOOO, lOlOOlOlOllO); }
	void lOlOOlOllOOO(bool lllOllOOlO) { lllOlOllll(lllOllOOOO, lOlOOlOllOOl, lllOllOOlO); }
	bool lOlOOlOllOlO() const { return lllOllOOll(lllOllOOOO, lOlOOlOllOOl); }
	void lOlOOlOllOll(bool lllOllOOlO) { lllOlOllll(lllOllOOOO, lOlOOlOlllOO, lllOllOOlO); }
	bool lOOlOOOllOl() const { return lllOllOOll(lllOllOOOO, lOlOOlOlllOO); }	
	void lOlOOlOlllOl(bool lllOllOOlO) { lllOlOllll(lllOllOOOO, lOlOOlOllllO, lllOllOOlO); }
	bool lOlOOlOlllll() const { return lllOllOOll(lllOllOOOO, lOlOOlOllllO); }	
	u32& lOlOOllOOOOO() { return lllOllOOOO; }
	u32 GetFlags() const { return lllOllOOOO; }
	
	llllOllOllO* lOlOOllOOOOl() { return lOOllOllllOO; }
	void lOlOOllOOOlO(llllOllOllO* lOlOOllOOOll) { lOOllOllllOO = lOlOOllOOOll; }

#define lOlOOllOOlOO(lOlOOOlllOll, lOlOOOllllOO) \
	lOlOOOlllOll void TAC_CALL lOlOOOllllOO::lOlOOOllllOl(float lOOlOllOllll, Collision& llOllllOlll); \
	lOlOOOlllOll void TAC_CALL lOlOOOllllOO::lOlOOOlllllO(float lOOlOllOllll, float llOlllOOOl, float lOlOOOllllll, Collision& llOllllOlll); \
	lOlOOOlllOll bool TAC_CALL lOlOOOllllOO::lOlOOlOOOOOO(float lOllOOlOlOO, Collision& llOllllOlll); \
	lOlOOOlllOll void TAC_CALL lOlOOOllllOO::lOlOOlOOOOOl(float lOOlOllOllll, float llOlllOOOl, Collision& llOllllOlll);
	
	lOlOOllOOlOO(friend, lOlOOlOOOOll)
	lOlOOllOOlOO(friend, lOlOOlOOOlOO)



#endif 
	
	
	
	
	
	const Vec3& GetLinearVelocity() const;
	void SetLinearVelocity(const Vec3& v3LinearVelocity);
	const Vec3& GetAngularVelocity() const;
	void SetAngularVelocity(const Vec3& v3AngularVelocity);
	void SetVelocitiesToMoveToFrame(const MFrame& mFrame, float fDt);
	Vec3 GetVelocityAtWorldPosition(const Vec3& v3Position) const;
	void ApplyImpulse(const Vec3& v3WorldImpulse, const Vec3& v3WorldPosition);
	void ApplyLinearImpulse(const Vec3& v3WorldLinearImpulse);
	void ApplyAngularImpulse(const Vec3& v3WorldAngularImpulse);
	

	
	
	void AssertForceAndTorqueCleared() const;
	void AccumulateGravity();	
	void AccumulateForceAndTorque(const Vec3& v3WorldForce, const Vec3& v3WorldPosition);
	void AccumulateLinearForce(const Vec3& v3WorldForce);
	void ApplyForceAndTorqueToVelocities(float fDt);
	void ClearForceAndTorque();
	

	
	
	void Clear();
	void UpdateWorldSpaceInertialTensor();
	virtual void Update(float fDt);
	virtual void UpdateGraphics(float fDt, float fInterpolant);
	void Extrapolate(
		const MFrame& frameA,
		const MFrame& frameB,
		const Vec3& v3VelocityA,
		const Vec3& v3VelocityB,
		float fDt,
		float fExtrapolation);
	virtual void ApplyVelocityToNextFrame(float fDt);
	void ApplyNextFrame();
	

	
	
	void Render();
	

	
	
	
	
#ifdef TA_PHYSICS_INTERNAL
	void lOlOOllOOlOl(void* lOlOOllOOllO) { lOOllOlOllOO = lOlOOllOOllO; }
	void* lOlOOllOOlll() { return lOOllOlOllOO; }
#endif 
	
	

	
	
	void CalculateWorldAABB();
	const AABB& GetWorldAABB();
#ifndef TA_WRAPPER	
	CollisionObject& GetCollisionObject();
#endif 
	CollisionObjectCombo* GetCollisionObjectCombo();
	CollisionObjectComplex* GetCollisionObjectComplex();
	void SetCollisionObject(
		CollisionObjectCombo* pCollisionObjectCombo, 
		int nFlags = (REINIT_FLAG_UPDATE_MASS | REINIT_FLAG_UPDATE_INERTIA_TENSOR | REINIT_FLAG_UPDATE_CENTER_OFFSET));
	void SetCollisionObjectChanged(
		int nFlags = (REINIT_FLAG_UPDATE_MASS | REINIT_FLAG_UPDATE_INERTIA_TENSOR | REINIT_FLAG_UPDATE_CENTER_OFFSET));
	void ReinitCollisionAsABox(
		const AABB& aabb, 
		int nFlags = (REINIT_FLAG_UPDATE_MASS | REINIT_FLAG_UPDATE_INERTIA_TENSOR | REINIT_FLAG_UPDATE_CENTER_OFFSET));
	void ReinitCollisionAsAnOrientedBox(
		const AABB& aabb, 
		const MFrame& mFrame, 
		int nFlags = (REINIT_FLAG_UPDATE_MASS | REINIT_FLAG_UPDATE_INERTIA_TENSOR | REINIT_FLAG_UPDATE_CENTER_OFFSET));
	void ReinitCollisionAsACapsule(
		const Vec3& v3Start, 
		const Vec3& v3End, 
		float fRadius, 
		int nFlags = (REINIT_FLAG_UPDATE_MASS | REINIT_FLAG_UPDATE_INERTIA_TENSOR | REINIT_FLAG_UPDATE_CENTER_OFFSET));
	void ReinitCollisionAsASphere(
		const Vec3& v3Center, 
		float fRadius, 
		int nFlags = (REINIT_FLAG_UPDATE_MASS | REINIT_FLAG_UPDATE_INERTIA_TENSOR | REINIT_FLAG_UPDATE_CENTER_OFFSET));
	void ReinitCollisionAsACylinder(
		const Vec3& v3Start, 
		const Vec3& v3End, 
		float fRadius, 
		int nFlags = (REINIT_FLAG_UPDATE_MASS | REINIT_FLAG_UPDATE_INERTIA_TENSOR | REINIT_FLAG_UPDATE_CENTER_OFFSET));
	
#ifndef TA_WRAPPER
	CollisionIterator GetCollisionIterator();
#ifndef TA_REMOVE_DEPRECATED
	void SetCollisionListEnabled(bool bValue);
	bool CollisionListEnabled() const;
#endif
#endif 
	bool TestLineForCollision(
		const Vec3& v3Start,
		const Vec3& v3Normal,
		float fLength,
		Collision& collision) const;
	

	
	
	
#ifdef TA_PHYSICS_INTERNAL
	void lOOllllOlllO(
		int lOOllllOllll,
		DynamicObject* lOlllOOlOOO,
		CollisionObject* lOlOllOOOll,
		u32 llOlllOlOOO,
		float lOllOOlOOll,
		const Vec3& lOOOOlllll,
		const Vec3& lOOOlOOOOO);
#endif 
	
	

	
	
	int GetNumLineCollisions();
	const LineIntersection& GetLineCollision(int nIndex) const;
	

	
	
	PhysicsJoint& AddJoint(
		DynamicObject* pOtherObject);
	
	
	void RemoveAllJoints(); 	
	void RemoveJoint(PhysicsJoint& joint);
	void RemoveJointsToObject(DynamicObject* pDynamicObject);
	

	
	
#ifndef TA_REMOVE_DEPRECATED
	PhysicsJoint& AddJoint(
		DynamicObject* pOtherObject, 
		const Vec3& v3LocalPos, 
		const Vec3& v3LocalPosOnOtherObject,
		const Mat33& m33DefaultRotationOfOtherObject,
		const EulerAngles& minAngles,
		const EulerAngles& maxAngles);
	PhysicsJoint& AddJointTypeHinge(
		DynamicObject* pOtherObject, 
		const Vec3& v3LocalPos,
		const Vec3& v3LocalPosOnOtherObject,
		const Vec3& v3LocalHingeAxis, 
		const Vec3& v3LocalHingeNormal, 
		float fMinAngle,
		float fMaxAngle);
	PhysicsJoint& AddJointTypeSocket(
		DynamicObject* pOtherObject, 
		const Vec3& v3LocalPos, 
		const Vec3& v3LocalPosOnOtherObject,
		const Vec3& v3LimitCenterNormal,
		const Vec3& v3LimitCenterNormalOnOtherObject,
		float fMaxAngle);
	PhysicsJoint& AddJointTypeLimitedSocket(
		DynamicObject* pOtherObject, 
		const Vec3& v3LocalPos, 
		const Vec3& v3LocalPosOnOtherObject,
		const Mat33& m33DefaultRotationOfOtherObject,
		float fMaxAngleY,
		float fMaxAngleXZ);
	PhysicsJoint& AddJointTypeSquareSocket(
		DynamicObject* pOtherObject, 
		const Vec3& v3LocalPos, 
		const Vec3& v3LocalPosOnOtherObject,
		const Mat33& m33DefaultRotationOfOtherObject,
		float fMinX,
		float fMaxX,
		float fMinY,
		float fMaxY,
		float fMinZ,
		float fMaxZ);
	PhysicsJoint& AddJointTypeSlider(
		DynamicObject* pOtherObject, 
		const Vec3& v3LocalPos,
		const Vec3& v3StartPosOnOtherObject,
		const Vec3& v3EndPosPosOnOtherObject);
	PhysicsJoint& AddRotationConstraint(
		DynamicObject* pOtherObject, 
		const Mat33& m33DefaultRotationOfOtherObject,
		const EulerAngles& minAngles,
		const EulerAngles& maxAngles);
	PhysicsJoint& AddVectorConstraint(
		DynamicObject* pOtherObject,
		const Vec3& v3LimitCenterNormal,
		const Vec3& v3LimitCenterNormalOnOtherObject,
		float fMaxAngle);
#endif 
#ifndef TA_WRAPPER
	
#ifdef TA_DYNAMIC_OBJECT_GROUP_ENABLED
	DynamicObjectGroup* GetDynamicObjectGroup() { return m_pDynamicObjectGroup; }
#endif 
#endif 
	
	
#ifndef TA_WRAPPER
	JointIterator GetJointIterator();
#endif 
	

	
	
	
#ifdef TA_PHYSICS_INTERNAL
	List<PhysicsJoint*>::Iterator lOlOOllOlOOO() { return lOOllOlllOlO.lOlOOOOlOO(); }
	void lOOllOlllOll();
	lOlOOOOOOlll* lOlOOOOOlOOO(DynamicObject* llOOlOOlOll, bool lOlOOOOOlOOl);
	lOlOOOOOOlll* lOlOOOOOllll(DynamicObject* llOOlOOlOll);
	lOlOOOOOlOlO* lOlOOllOlOOl() { return lOOllOllOlOO; }
	int lOlOOllOlOlO() const { return lOOllOllOllO; }
	void lOlOOOOllOOO(int lOlOOOOlOlll) { lOOllOllOllO = lOlOOOOlOlll; }
	int lOlOOllOlOll() const { return lOOllOllOlll; }
	void lOlOOllOllOO(int lOlOOllOllOl) { lOOllOllOlll = lOlOOllOllOl; }
	void lOlOOOOlOllO(int lOlOOOOlOlll);
	void lOlOOOOllOOl(int lOlOOOOlOlll);
	void lOlOOOOllOlO(void (TAC_CALL *lOlOOOOllOll)(lOlOOOOOOlll& lOlOOOOlllOO, void* lOOlllOOOO), void* lOOlllOOOO);
	void lOlOOOOlllOl();
	void lOlOOOOlllll();
	void lOlOOOlOOOll();
	void lOlOOOlOOlOO(lOlOOOOOOlll& lOlOOOOlllOO);
	void lOlOOllOlllO(int lOlOOllOllll) { lOOllOlOOlOO = lOlOOllOllll; }
	int lOlOOlllOOOO() const { return lOOllOlOOlOO; }
	void lOlOOOlOOlOl();
	void lOlOOOlOOllO();
	void lOlOOlllOOOl(float lOOOOOlllO) { lOlOOlllOOlO = lOOOOOlllO; }
	void lOOlOlllllll(float lOOOOOlllO) { lOlOOlllOOlO += lOOOOOlllO; }
	float lOlOOlllOOll() const { return lOlOOlllOOlO; }
	const Vec3& lOlOOlllOlOO() const { return lOOllOlOlOOl; }
	const Vec3& lOlOOlllOlOl() const { return lOOllOlOlOlO; }	
	const void SetNextFrame(const MFrame& lOllOlllllO) { lOOllOlOlOOO = lOllOlllllO; lOOllOlOOllO = lOOllOlOOlOl * lOllOlllllO; }
	void lOlOOOlOOlll(float lOOlllOOllll, float lOlOOOlOlOOO);
	const Vec3& lOlOOlllOllO() const { return lOOlllOllOOO; }
	const Vec3& lOlOOlllOlll() const { return lOOlllOllOOl; }
	void lOlOOOlOlOOl();
	float lOOllOOOOlOO() const { return lOOllOOllOlO; }	
	float lOlOOllllOOO() const { return lOOllOOllOll; }	
	void lOlOOllllOOl(float lOlOOOlOllOO) { lOOllOOllOll = lOlOOOlOllOO; }	
	bool lOlOOllllOlO() const { return (lllOllOOOO & (lOOlllOOlOll | lOOlllOOlOOl | lOlOOlOOlllO)) == lOlOOlOOlllO; }
	void lOlOOOlOlOlO();
	void lOlOOllllOll(DynamicObject* lOlllOOlOOO) { lOOllOllOOlO = lOlllOOlOOO; }
	DynamicObject* lOlOOlllllOO() { return lOOllOllOOlO; }
	void lOlOOOlOlOll(DynamicObject* llOOlOOlOll);
	void lOlOOOlOllOl(float lOlOOOlOlllO, float lOlOOOlOllll);
	void lOlOOOllOOOO(); 
	void lOlOOOllOOlO(); 
	void lOOlllOOOOOl();
	
#endif 
	
	
	
	
	
	bool IsAllowedToCollideWith(const DynamicObject& otherObject) const;
	void SetUserGroup(int nUserGroupId);
	int GetUserGroup() const;
	void SetUserGroupItemId(int nUserGroupItemId);
	int GetUserGroupItemId() const;
	void DisallowCollisionWithUserGroupItemId(int nUserGroupItemId);
	void AllowCollisionWithUserGroupItemId(int nUserGroupItemId);
#ifndef TA_REMOVE_DEPRECATED
	void SetCollisionUserData(void* pData);
	void* GetCollisionUserData() const;
#endif 
	void SetUserData(void* pData);
	void* GetUserData() const;
	
	
	
	static int TAC_CALL CreateUserGroup();
	

	static DynamicObject* TAC_CALL CreateNew();
	//pl.Release()
	
	//pl.EndExportClass(DynamicObject)
		

protected:	
	DynamicObject();
	virtual ~DynamicObject();
	void InitialiseCommon();
	void ClearLineIntersections();
	

private:
	
#ifdef TA_PHYSICS_INTERNAL
public:
#endif 
	enum Flags
	{
		lOlOOlOOlllO =					0x1,
		lOlOOlOOllll =				0x2,
		lOlOOlllllOl =					0x4,
		lOOlllOOlOOO =					0x8,
		lOlOOllllllO =					0x10,
		lOlOOlllllll =					0x20,
		lOlOlOOOOOOO =								0x40,
		lOlOlOOOOOOl =					0x80,
		lOOlllOOlOOl =					0x100,
		lOlOOlOlOOll =		0x400,
		lOlOlOOOOOlO =			0x800,
		lOOlllOOlOll =						0x1000,
		lOlOOOlllOOO =					0x2000,
		lOlOOlOlOllO =							0x4000,
		lOlOOlOllOOl =							0x8000,
		lOlOlOOOOOll =		0x10000,
		lOlOOlOOlOOO =						0x20000,
		lOlOOlOlllOO =							0x40000,
		lOlOOlOllllO =			0x80000,
		lOlOlOOOOlOO =					0x100000,
		lOlOlOOOOlOl =				0x200000,
	};	
#ifdef TA_PHYSICS_INTERNAL
private:
#endif 
	float lOlOlOlOlOO;
	float lOOlOlllllOO;
	float lOOllOOlllll;
	float lOOllOlOOOOO;
	float lOOllOlOOOOl;
	float lOOllOlOOOlO;
	float lOOlllOlOlOl;
	float lOlOOlllOOlO;
	float lOOllOOllOlO;
	float lOOllOOllOll;
	int lOOllOlOOOll;
	u32 lllOllOOOO;
	int lOOllOlOOlOO;
	int lOlOOOllOlll;
	void* lOOllOlOlOll;
	void* lOOllOlOllOO;
	int lOOllOlOlllO;
	u32 lOOllOlOllll; 
	u32 lOOllOllOOOO;			
	CollisionObject* lOOllOOlOllO;
	DynamicObjectGroup* lOOllOllOOOl;
	DynamicObject* lOOllOllOOlO; 
	void* lOOllOllOOll;
	lOlOOOOOlOlO* lOOllOllOlOO;
	int lOOllOllOlOl;
	int lOOllOllOllO;
	int lOOllOllOlll;
	llllOllOllO* lOOllOllllOO;
	lOOOOlOllO<LineIntersection, false> lOOllOlllOOO;
	List<PhysicsJoint> lOOllOlllOOl;	
	List<PhysicsJoint*> lOOllOlllOlO;	
	Mat33 lOOllOOllOOO; 
	Mat33 lOOllOOllOOl;
	Mat33 lOOllOOlllOl; 
	Mat33 lOOllOOllllO;
	MFrame lOOllOlOOlll;
	MFrame lOOllOlOlOOO;
	MFrame lOOllOlllllO;
	MFrame lOOllOllllll;
	MFrame lOOlllOOOOOO;
	Vec3 lOOllOlOOlOl;
	Vec3 lOOlOllllOll;
	Vec3 lOOlOlllllOl;
	Vec3 lOOllOlOOllO;
	Vec3 lOOlOlllOlOl;
	Vec3 lOOllOlOlOOl;
	Vec3 lOOllOlOlOlO;
	Vec3 lOOlllOlOlOO;
	Vec3 lOOlllOlOlll;
	Vec3 lOOlllOllOOO;
	Vec3 lOOlllOllOOl;
	AABB lOOllOlOllOl;
#ifndef lOlOlOOOOllO
	enum { lOlOOOllOOOl = 10 * sizeof (uSize) + 5 * sizeof (u32) + 2 * sizeof (uSize) + 5 * sizeof (u32) };
	
	u8* lOOllOllllOl;
#endif 
	
	bool lOOlllOlOOll() const { return (lllOllOOOO & (lOOlllOOlOll | lOOlllOOlOOl | lOlOOlOOlllO)) == lOlOOlOOlllO; }

	
	virtual const Vec3& GetCollisionGridWorldPos() const { return lOOllOlOllOl.v3Center; }
	virtual const AABB& GetCollisionGridWorldAABB() const { return lOOllOlOllOl; }
	virtual const AABB& GetCollisionGridGetLocalAABB() const { return lOOllOOlOllO->GetAABB(); }
#ifdef lOlOlOOOOllO
	virtual void* GetSpaceDivisionNodeMemory() { return 0; }
	virtual int GetSpaceDivisionNodeMemorySize() { return 0; }
#else
	virtual void* GetSpaceDivisionNodeMemory() { return lOOllOllllOl; }
	virtual int GetSpaceDivisionNodeMemorySize() { return lOlOOOllOOOl; }
#endif

};

}

#include "../Physics/zpta006.inl"

#endif 

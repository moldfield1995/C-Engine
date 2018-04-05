//---------------------------------------------------------------------------------
// File Name: CarTemplate.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------



#ifndef TA_CARTEMPLATE_H
#define TA_CARTEMPLATE_H

#ifndef TA_REFCOUNT_H
#include "../Common/RefCount.h"
#endif 

#ifndef TA_VECTOR_H
#include "../Common/Vector.h"
#endif 

#ifndef lOOOOOOllll
#include "../Common/zcta008.h"
#endif 

#ifndef lOOllOllll
#include "../Common/zcta001.h"
#endif 

#ifndef lOlOllllOll
#include "../Physics/zpta012.h"
#endif 



namespace TA
{

class CollisionObjectConvex;
class CollisionObjectCapsule;
class CollisionObjectCylinder;
class CollisionObjectSphere;
class CollisionObjectCombo;
class DynamicObjectCar;
class SurfaceAttribute;

class lOlOlllllOO CarTemplate : public RefCount
{
public:
	

	typedef float (TAC_CALL *FnTorqueCurve)(float fRadsPerSec);
	typedef float (TAC_CALL *FnSlipRatioToNormalisedTraction)(float fSlipRatio, const SurfaceAttribute& surfaceAttribute);
	typedef float (TAC_CALL *FnSlipAngleToLateralForce)(float fSlipAngle, float fLongitudinalSlipRatio, const SurfaceAttribute& surfaceAttribute);

	struct Wheel
	{
	public:
		Wheel();
		void Clear();

		void SetSuspensionTop(const Vec3& v3SuspensionTop);
		const Vec3& GetSuspensionTop() const;

		void SetSuspensionBottom(const Vec3& v3SuspensionBottom);
		const Vec3& GetSuspensionBottom() const;

		void SetRadius(float fRadius);
		float GetRadius() const;

		void SetInertia(float fInertia);
		float GetInertia() const;

		void SetBrakeTorque(float fBrakeTorque);
		float GetBrakeTorque() const;

		void SetRollResistance(float fRollResistance);
		float GetRollResistance() const;

		void SetSuspensionSpringConstant(float fSuspensionSpringConstant);
		float GetSuspensionSpringConstant() const;

		void SetSuspensionDampingConstant(float fSuspensionDampingConstant);
		float GetSuspensionDampingConstant() const;
		
		void SetSlipRatioToNormalisedTractionCallBack(FnSlipRatioToNormalisedTraction pCallBack);
		FnSlipRatioToNormalisedTraction GetSlipRatioToNormalisedTractionCallBack() const;
	
		void SetSlipAngleToLateralForceCallBack(FnSlipAngleToLateralForce pCallBack);
		FnSlipAngleToLateralForce GetSlipAngleToLateralForceCallBack() const;

		void SetSteeringFlag(bool bSteering);
		bool GetSteeringFlag() const;

		void SetDrivingFlag(bool bDriving);
		bool GetDrivingFlag() const;

		void SetHandBrakeFlag(bool bHandBrake);
		bool GetHandBrakeFlag() const;

		
	private:

		Vec3 lOlOlOOlOOO;
		Vec3 lOlOlOOlOOl;
		float lOlOlOOlOlO;
		float lOlOlOOlOll;
		float lOlOlOOllOO;
		float lOlOlOOllOl;
		float lOlOlOOlllO;
		float lOlOlOOllll;
		FnSlipRatioToNormalisedTraction lOlOlOlOOOO;
		FnSlipAngleToLateralForce lOlOlOlOOOl;
		struct
		{
			bool lOlOlOOOlOl		: 1;
			bool lOlOlOOOllO		: 1;
			bool lOlOlOOOlll		: 1;
		} lOlOlOOOlOO;
	};
	

	void BeginInitialise();
	void EndInitialise();
	void Finalise();

	void AddCollisionObject(CollisionObjectConvex* pCollisionObject);
	void AddCollisionObject(CollisionObjectCapsule* pCollisionObject);
	void AddCollisionObject(CollisionObjectCylinder* pCollisionObject);
	void AddCollisionObject(CollisionObjectSphere* pCollisionObject);

	void AddWheel(const Wheel& wheel);

	void SetOrientation(const Vec3& v3Forward, const Vec3& v3Up);
	const Vec3& GetForward() const;
	const Vec3& GetUp() const;

	int GetNumGears() const;
	void SetNumGears(int nNumGears);
	void SetGearRatio(int nIndex, float fGearRatio);
	float GetGearRatio(int nIndex) const;

	void SetDifferentialRatio(float fDifferentialRatio);
	float GetDifferentialRatio() const;

	void SetMass(float fMass);
	float GetMass() const;

	void SetTransmissionEfficiency(float fTransmissionEfficiency);
	float GetTransmissionEfficiency() const;

	void SetTorqueMultiplier(float fTorqueMultiplier);
	float GetTorqueMultiplier() const;
	void SetTorqueCurve(FnTorqueCurve pFnTorqueCurve);

	void SetAirResistance(float fAirResistance);
	float GetAirResistance() const;

	void SetDownForce(float fDownForce);
	float GetDownForce() const;

	void SetAntiRollFudge(float fAntiRollFudge);
	float GetAntiRollFudge() const;

	static CarTemplate* TAC_CALL CreateNew();
	static float TAC_CALL StandardTorqueCurve(float fRadsPerSec);
	static float TAC_CALL StandardSlipRatioToNormalisedTraction(float fSlipRatio, const SurfaceAttribute& surfaceAttribute);
	static float TAC_CALL StandardSlipAngleToLateralForce(float fSlipAngle, float fLongitudinalSlipRatio, const SurfaceAttribute& surfaceAttribute);


protected:
	CarTemplate();
	~CarTemplate();

	

private:
	friend class DynamicObjectCar;

	bool lOlOlOlOOll;
	CollisionObjectCombo* lOlOlOlOOlO;
	float lOlOlOllOOl;
	float lOlOlOlOlOO;
	float lOlOlOlOlll;
	float lOlOlOlOlOl;
	FnTorqueCurve lOlOlOlOllO;
	float lOlOlOllOlO;
	float lOlOlOllOll;
	float lOlOlOlllOO;
	List<Wheel> lOlOlOllllO;
	lOOOOlOllO<float> lOlOlOllOOO;
	Vec3 lOlOllOOllO;
	Vec3 lOlOllOOlll;

	void lOlOllOOOlO();
};

}

#include "../Physics/zpta000.inl"

#endif 

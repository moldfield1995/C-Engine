//---------------------------------------------------------------------------------
// File Name: DynamicObjectCar.h
//
// Copyright (C) 2004 - 2006 True Axis Pty Ltd, Australia.
// All Rights Reserved.
//
//---------------------------------------------------------------------------------


#ifndef TA_DYNAMICOBJECTCAR_H
#define TA_DYNAMICOBJECTCAR_H

#ifndef TA_DYNAMICOBJECT_H
#include "DynamicObject.h"
#endif 



namespace TA
{

class CollisionObjectCombo;
class CarTemplate;
class SurfaceAttribute;

class lOlOlllllOO DynamicObjectCar : public DynamicObject
{
public:
	enum lOlOllOllOOO
	{
		lOlOlOOlOllO =				0x1,
		lOlOlOOlOlll =				0x2,
		lOlOlOOllOOO =	0x4,
		lOlOlOllOOll =			0x8,
	};
	
	struct Wheel
	{
	public:
		typedef float (TAC_CALL *FnSlipRatioToNormalisedTraction)(float fSlipRatio, const SurfaceAttribute& surfaceAttribute);
		typedef float (TAC_CALL *FnSlipAngleToLateralForce)(float fSlipAngle, float fLongitudinalSlipRatio, const SurfaceAttribute& surfaceAttribute);

		const MFrame& GetLocalGraphicsFrame() const;
		
		void SetRadius(float fRadius);
		float GetRadius() const;

		void SetInvInertia(float fInvInertia);
		float GetInvInertia() const;

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

		void SetYaw(float fYaw);
		float GetYaw() const;

		void SetPitch(float fPitch);
		float GetPitch() const;

		void SetPitchVelocity(float fPitchVelocity);
        float GetPitchVelocity() const;

		void SetCamberAngle(float fCamberAngle);
		float GetCamberAngle() const;

		

	private:
		friend class DynamicObjectCar;

		MFrame lOlOlOOllOOl;
		Mat33 lOlOlOOllOlO;
		Mat33 lOlOlOOllOll;		
		Vec3 lOlOlOllOOlO;
		float lOlOlOOlOlO;
		float lOlOlOOlllOO;
		float lOlOlOOlllOl;
		float lOlOlOOllllO;
		float lOlOlOOlllll;
		float lOlOlOlOOOOO;
		float lOlOlOOllOl;
		float lOlOlOOllOO;
		float lOlOlOlOOOOl;
		float lOlOlOOlllO;
		float lOlOlOOllll;
		float (TAC_CALL *lOlOlOlOOOO)(float lOlOllOllOO, const SurfaceAttribute& lOlOllOllOl);
		float (TAC_CALL *lOlOlOlOOOl)(float lOlOllllOOO, float lOlOllllOOl, const SurfaceAttribute& lOlOllOllOl);
		u32 lllOllOOOO;
	};

	
	
	
	void Initialise(CarTemplate* pCarTemplate);
	void Initialise(const Char* szFileName);
	void Finalise();
	

	
	
	virtual void Update(float fDt);

	void ClearControls();
	void UpdateControls(
		float fSteeringAngle,
		float fAccelerator,
		float fBrake,
		float fHandBrake,
		float fSteeringHelp,
		float fTractionControl,
		int nGear = -1);
	


	
	
	float GetRPM() const;
	int GetGear() const;
	int GetNumGears() const;
	float GetCarSpeedFromWheels();
	
	void SetTorqueMultiplier(float fTorqueMultiplier);
	float GetTorqueMultiplier() const;

	void SetAntiRollFudge(float fAntiRollFudge);
	float GetAntiRollFudge() const;
	const Wheel& GetWheel(int nIndex) const;
	Wheel& GetWheel(int nIndex);
	int GetNumWheels() const;

	void SetOrientation(const Vec3& v3Forward, const Vec3& v3Up);
	const Vec3& GetForward() const;
	const Vec3& GetUp() const;
	

	static DynamicObjectCar* TAC_CALL CreateNew();

protected:
	DynamicObjectCar();
	~DynamicObjectCar();

	

private:
	struct lOlOllOllOOl
	{
		float lOlOlOllOOOO;
		float lOlOlOllllll;
		float lOlOlOlllllO;
		float lOlOllOlOllO;
		float lOlOlOlOllll;
		float lOlOllOOllOO;
		int lOlOlOlOOlOO;
	};

	lOlOllOllOOl lOlOlOlOlllO;
	Vec3 lOlOllOOllO;
	Vec3 lOlOllOOlll;
	lOOOOlOllO<Wheel, false> lOlOlOOlOOll;

	int lOlOlOlllOOO;

	float lOlOlOlOOlOl;
	float lOlOlOlOOllO;

	lOOOOlOllO<float, false> lOlOlOlOOOll;
	float lOlOlOllOOl;
	float lOlOlOlOlll;
	float lOlOlOlOlOl;
	float lOlOlOlllOO;
	float (TAC_CALL *lOlOlOlOllO)(float lOlOllOlOlO);

	float lOlOlOllOlO;
	float lOlOlOllOll;

	void InitialiseCommon();
	void lOlOlOlOOOlO(Wheel& lOlOllOOOOO);
};

}

#include "../Physics/zpta007.inl"

#endif 

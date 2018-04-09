#pragma once
#include "Leap.h"
#include "..\TrueAxis\Common\Vec3.h"
#include "..\TrueAxis\Common\EulerAngles.h"
//Updated In Final Year
//Created By Matthew Oldfield

class float3
{
public:
	float3();
	~float3();
	float3(float xyz);
	float3(float x, float y);
	float3(float x, float y, float z);
	float3(Leap::Vector vector);
	//Static Maths
	static float3 Lerp(float3 a, float3 b, float t);

	//Usefull operators
	void Set(float x, float y, float z);
	float3 Normalize();
	float Lenght();
	float3 operator* (float3 other);
	float3 operator+ (float3 other);
	float3 operator- (float3 other);
	float3 operator/ (float3 other);
	float3 operator- ();
	//Convertions from float3 to other libary equivlents
	std::string ToString();
	TA::Vec3 ToVec3();
	TA::EulerAngles ToEuler();

	float X, Y, Z;

};


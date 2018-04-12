#pragma once
#include "Leap.h"
#include "..\TrueAxis\Common\Vec3.h"
#include "..\TrueAxis\Common\EulerAngles.h"
//Updated In Final Year
//Created By Matthew Oldfield

class Float3
{
public:
	Float3();
	~Float3();
	Float3(float xyz);
	Float3(float x, float y);
	Float3(float x, float y, float z);
	Float3(Leap::Vector vector);
	Float3(const TA::Vec3& vector);

	//Static Maths
	static Float3 Lerp(Float3 a, Float3 b, float t);
	static Float3 Cross(Float3 a, Float3 b);
	//Usefull operators
	void Set(float x, float y, float z);
	Float3 Normalize();
	float Lenght();
	Float3 operator* (Float3 other);
	Float3 operator+ (Float3 other);
	Float3 operator- (Float3 other);
	Float3 operator/ (Float3 other);
	Float3 operator- ();
	//Convertions from Float3 to other libary equivlents
	std::string ToString();
	TA::Vec3 ToVec3();
	TA::EulerAngles ToEuler();

	float X, Y, Z;

};


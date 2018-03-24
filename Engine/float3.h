#pragma once
#include "Leap.h"

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

	void Set(float x, float y, float z);
	float3 Normalize();
	float Lenght();
	float3 operator* (float3 other);
	float3 operator+ (float3 other);
	float3 operator- (float3 other);
	float3 operator/ (float3 other);
	std::string ToString();
	//float3 operator= (Leap::Vector vector);
	float X, Y, Z;

private:
	//float m_x, m_y, m_z;
};


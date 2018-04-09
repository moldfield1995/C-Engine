#include "float3.h"



float3::float3()
{
	X = Y = Z = 0.0f;
}

float3::~float3()
{
}

float3::float3(float xyz)
{
	X = xyz;
	Y = xyz;
	Z = xyz;
}

float3::float3(float x, float y)
{
	X = x;
	Y = y;
	Z = 0.0f;
}

float3::float3(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;
}

float3::float3(Leap::Vector vector)
{
	X = vector.x;
	Y = vector.y;
	Z = vector.z;
}


void float3::Set(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;
}

float3 float3::Normalize()
{
	float lenght = Lenght();
	return float3(X / lenght,Y/lenght,Z/lenght);
}

float3 float3::Lerp(float3 a, float3 b, float t)
{
	float3 value = float3();
	value.X = a.X + t * (b.X - a.X);
	value.Y = a.Y + t * (b.Y - a.Y);
	value.Z = a.Z + t * (b.Z - a.Z);
	return value;
}

float float3::Lenght()
{
	float lenght = 0.0f;
	lenght += X >= 0.0f ? X : -X;
	lenght += Y >= 0.0f ? Y : -Y;
	lenght += Z >= 0.0f ? Z : -Z;
	return lenght;
}

float3 float3::operator*(float3 other)
{
	return float3(X*other.X,Y*other.Y,Z*other.Z);
}

float3 float3::operator+(float3 other)
{
	return float3(X+other.X, Y+other.Y, Z+other.Z);
}

float3 float3::operator-(float3 other)
{
	return float3(X-other.X, Y-other.Y, Z-other.Z);
}

float3 float3::operator/(float3 other)
{
	return float3(X/other.X, Y/other.Y, Z/other.Z);
}

float3 float3::operator-()
{
	return float3(-X,-Y,-Z);
}

std::string float3::ToString()
{
	return "X: "+std::to_string(X) + " Y: " + std::to_string(Y) + " Z: " + std::to_string(Z) ;
}

TA::Vec3 float3::ToVec3()
{
	return TA::Vec3(X,Y,Z);
}

TA::EulerAngles float3::ToEuler()
{
	return TA::EulerAngles(X,Y,Z);
}





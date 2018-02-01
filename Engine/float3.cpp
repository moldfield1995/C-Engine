#include "float3.h"



float3::float3()
{
	X = Y = Z = 0.0f;
}

float3::~float3()
{
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

float float3::Lenght()
{
	return X + Y + Z;
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





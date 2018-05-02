#include "float3.h"



Float3::Float3()
{
	X = Y = Z = 0.0f;
}

Float3::~Float3()
{
}

Float3::Float3(float xyz)
{
	X = xyz;
	Y = xyz;
	Z = xyz;
}

Float3::Float3(float x, float y)
{
	X = x;
	Y = y;
	Z = 0.0f;
}

Float3::Float3(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;
}

Float3::Float3(Leap::Vector vector)
{
	X = vector.x;
	Y = vector.y;
	Z = vector.z;
}

Float3::Float3(const TA::Vec3 & vector)
{
	X = vector.x;
	Y = vector.y;
	Z = vector.z;
}



void Float3::Set(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;
}

void Float3::Traslate(Float3 other)
{
	X += other.X;
	Y += other.Y;
	Z += other.Z;
}

Float3 Float3::Normalize()
{
	float lenght = Lenght();
	return Float3(X / lenght, Y / lenght, Z / lenght);
}

Float3 Float3::Lerp(Float3 a, Float3 b, float t)
{
	Float3 value = Float3();
	value.X = a.X + t * (b.X - a.X);
	value.Y = a.Y + t * (b.Y - a.Y);
	value.Z = a.Z + t * (b.Z - a.Z);
	return value;
}

Float3 Float3::Cross(Float3 a, Float3 b)
{
	return Float3(a.Y*b.Z - a.Z*b.Y, a.Z*b.X - a.X*b.Z,a.X*b.Y - a.Y*b.X);
}

float Float3::Lenght()
{
	float lenght = 0.0f;
	lenght += X >= 0.0f ? X : -X;
	lenght += Y >= 0.0f ? Y : -Y;
	lenght += Z >= 0.0f ? Z : -Z;
	return lenght;
}

Float3 Float3::operator*(Float3 other)
{
	return Float3(X*other.X, Y*other.Y, Z*other.Z);
}

Float3 Float3::operator+(Float3 other)
{
	return Float3(X + other.X, Y + other.Y, Z + other.Z);
}

Float3 Float3::operator-(Float3 other)
{
	return Float3(X - other.X, Y - other.Y, Z - other.Z);
}

Float3 Float3::operator/(Float3 other)
{
	return Float3(X / other.X, Y / other.Y, Z / other.Z);
}

Float3 Float3::operator-()
{
	return Float3(-X, -Y, -Z);
}

std::string Float3::ToString()
{
	return "X: " + std::to_string(X) + " Y: " + std::to_string(Y) + " Z: " + std::to_string(Z);
}

TA::Vec3 Float3::ToVec3()
{
	return TA::Vec3(X, Y, Z);
}

TA::EulerAngles Float3::ToEuler()
{
	return TA::EulerAngles(X, Y, Z);
}





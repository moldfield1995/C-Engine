#pragma once
class float3
{
public:
	float3();
	~float3();
	float3(float x, float y, float z);
	float X();
	float Y();
	float Z();
	void X(float x);
	void Y(float y);
	void Z(float z);
	void Set(float x, float y, float z);
private:
	float m_x, m_y, m_z;
};


#include "float3.h"



float3::float3()
{
	m_x = m_y = m_z = 0.0f;
}

float3::~float3()
{
}

float3::float3(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

float float3::X()
{
	return m_x;
}

float float3::Y()
{
	return m_y;
}

float float3::Z()
{
	return m_z;
}

void float3::X(float x)
{
	m_x = x;
}

void float3::Y(float y)
{
	m_y = y;
}

void float3::Z(float z)
{
	m_z = z;
}

void float3::Set(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}



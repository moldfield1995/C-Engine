////////////////////////////////////////////////////////////////////////////////
// Filename: positionclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _POSITIONCLASS_H_
#define _POSITIONCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <math.h>
#include <directxmath.h>
#include "float3.h"
using namespace DirectX;
////////////////////////////////////////////////////////////////////////////////
// Class name: PositionClass
////////////////////////////////////////////////////////////////////////////////
class PositionClass
{
public:
	PositionClass();
	PositionClass(const PositionClass&);
	~PositionClass();

	void SetPosition(float, float, float);
	void SetRotation(float, float, float);

	void SetOrigin(float posX, float posY, float posZ,float rotX, float rotY, float radius);
	void SetOrigin(float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float offsetX, float offsetY, float offsetZ , bool focused);

	void GetPosition(float&, float&, float&);
	float3 GetPosition();
	void GetRotation(float&, float&, float&);
	void SetFrameTime(float);

	void RotateX(float X);
	void RotateY(float Y);
	bool ApplyInput(bool forward, bool back, bool left, bool right);
	void SetMoveSpeed(float movespeed);
	void Frame(bool hit);
	void Sethitbox(float3 hitbox);
	float3 Gethitbox();
private:
	float m_positionX, m_positionY, m_positionZ;
	float m_rotationX, m_rotationY, m_rotationZ;
	float m_oldPosX, m_oldPosY, m_oldPosZ;
	bool m_focused;

	float m_frameTime;
	float m_moveSpeed;
	float3 m_hitbox;
};

#endif
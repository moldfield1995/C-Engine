////////////////////////////////////////////////////////////////////////////////
// Filename: positionclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "positionclass.h"


PositionClass::PositionClass()
{
	m_positionX = 0.0f;
	m_positionY = 0.0f;
	m_positionZ = 0.0f;

	m_rotationX = 0.0f;
	m_rotationY = 0.0f;
	m_rotationZ = 0.0f;
	m_oldPosX = m_oldPosY = m_oldPosZ = 0.0f;
	m_frameTime = 0.0f;
	m_moveSpeed = 10.0f;
	m_focused = false;
	m_hitbox = Float3();
}


PositionClass::PositionClass(const PositionClass& other)
{
}


PositionClass::~PositionClass()
{
}

void PositionClass::SetMoveSpeed(float moveSpeed)
{
	m_moveSpeed = moveSpeed;
}

void PositionClass::Frame(bool hit)
{
	if (hit)
	{
		m_positionX = m_oldPosX;
		m_positionY = m_oldPosY;
		m_positionZ = m_oldPosZ;
	}
}

void PositionClass::Sethitbox(Float3 hitbox)
{
	m_hitbox = hitbox;
}

Float3 PositionClass::Gethitbox()
{
	return m_hitbox;
}


void PositionClass::SetPosition(float x, float y, float z)
{
	m_positionX = x;
	m_positionY = y;
	m_positionZ = z;
	return;
}


void PositionClass::SetRotation(float x, float y, float z)
{
	m_rotationX = x;
	m_rotationY = y;
	m_rotationZ = z;
	return;
}


void PositionClass::GetPosition(float& x, float& y, float& z)
{
	x = m_positionX;
	y = m_positionY;
	z = m_positionZ;
	return;
}

Float3 PositionClass::GetPosition()
{
	return Float3(m_positionX,m_positionY,m_positionZ);
}


void PositionClass::GetRotation(float& x, float& y, float& z)
{
	x = m_rotationX;
	y = m_rotationY;
	z = m_rotationZ;
	return;
}


void PositionClass::SetFrameTime(float time)
{
	m_frameTime = time;
	return;
}

void PositionClass::RotateX(float x)
{
	m_rotationX += x;
	if (m_rotationX > 90.0f)
	{
		m_rotationX = 90.0f;
	}
	else if (m_rotationX < -90.0f)
	{
		m_rotationX = -90.0f;
	}
}
void PositionClass::RotateY(float y)
{
	m_rotationY += y;
	if (m_rotationY < 0.0f)
	{
		m_rotationY += 360.0f;
	}
	else if (m_rotationY > 360.0f)
	{
		m_rotationY -= 360.0f;
	}
}

bool PositionClass::ApplyInput(bool forward, bool back, bool left, bool right)
{
	m_oldPosX = m_positionX;
	m_oldPosY = m_positionY;
	m_oldPosZ = m_positionZ;
	float forwardBack = 0.0f, leftRight = 0.0f;
	if (forward)
		forwardBack += 1.0f;
	if (back)
		forwardBack -= 1.0f;
	if (right)
		leftRight += 1.0f;
	if (left)
		leftRight -= 1.0f;

	forwardBack = forwardBack * m_moveSpeed * m_frameTime;
	leftRight = leftRight* m_moveSpeed * m_frameTime;

	float radiansY = m_rotationY * 0.0174532925f;
	float sideRadians = (m_rotationY + 90.0f) * 0.0174532925f;
	float radiansX = (m_rotationX + 90.0f) * 0.0174532925f;
	// Update the position.
	m_positionX += sinf(radiansY) * forwardBack;
	m_positionZ += cosf(radiansY) * forwardBack;
	m_positionY += cosf(radiansX) * forwardBack;

	m_positionX += sinf(sideRadians) * leftRight;
	m_positionZ += cosf(sideRadians) * leftRight;



	if (forward || back || left || right)
		return true;
	return false;

}
void PositionClass::SetOrigin(float posX, float posY, float posZ,float rotX, float rotY, float radius)
{
	m_positionX = posX - radius*cosf(rotX*0.0174532925f)*sinf(rotY*0.0174532925f);
	//m_positionY = posY - 2.0f*sinf(rotX*0.0174532925f)*sinf(rotY*0.0174532925f);
	m_positionZ = posZ - radius*cosf(rotY*0.0174532925f);
}
void PositionClass::SetOrigin(float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float offsetX, float offsetY, float offsetZ, bool focused)
{
	XMMATRIX originMartix, localMatrix, transformMatrix, rotationMatrix;
	transformMatrix = XMMatrixTranslation(posX, posY, posZ);
	rotationMatrix = XMMatrixRotationRollPitchYaw(rotX, rotY, rotZ);
	originMartix = XMMatrixMultiply(rotationMatrix, transformMatrix); 
}

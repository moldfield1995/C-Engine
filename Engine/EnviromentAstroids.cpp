#include "EnviromentAstroids.h"
#include "GameObject.h"
#include "timerclass.h"

EnviromentAstroids::EnviromentAstroids(GameObject* prefab, float distanceBetween)
	: m_MinZ(-distanceBetween)
	, m_MaxZ(1000.0f)
	, m_XOffset(80.0f)
	, m_SpawnSepiration(distanceBetween)
	, m_MovmentSpeed(-20.0f)
{
	m_Prefab = prefab;
	m_NextToCheck = 0;
}


EnviromentAstroids::~EnviromentAstroids()
{
}

void EnviromentAstroids::Initalize()
{
	float currentZ = 0.0f;
	int arrayLength = (std::roundf(m_MaxZ / m_SpawnSepiration) * 2);
	m_Astroids = std::vector<GameObject*>(arrayLength);
	GameObject* temp = 0;

	for (int itt = 0; itt < arrayLength; itt++)
	{//Spawns astriods on both sides of the player
		currentZ = m_MaxZ - (m_SpawnSepiration * (arrayLength - itt) / 2);
		//Right side
		temp = new GameObject(m_Prefab);
		temp->SetPosition(Float3(m_XOffset, 0.0f, currentZ));
		m_Astroids[itt] = temp;
		itt++;
		//Left Side
		temp = new GameObject(m_Prefab);
		temp->SetPosition(Float3(-m_XOffset, 0.0f, currentZ));
		m_Astroids[itt] = temp;
	}

}

void EnviromentAstroids::Update()
{
	//check current closet astroids
	if (m_Astroids[m_NextToCheck]->GetPosition().Z <= m_MinZ)
	{
		m_Astroids[m_NextToCheck]->SetPosition(Float3(m_XOffset, 0.0f, m_MaxZ));
		m_Astroids[m_NextToCheck+1]->SetPosition(Float3(-m_XOffset, 0.0f, m_MaxZ));
		m_NextToCheck += 2;
		if (m_NextToCheck >= m_Astroids.size())
			m_NextToCheck = 0;
	}
	TimerClass* timer = TimerClass::GetInstance();
	Float3 zMovment(0.0f,0.0f, m_MovmentSpeed * timer->GetFrameTime());
	for each (GameObject* go in m_Astroids)
	{
		go->SetPosition(go->GetPosition()+zMovment);
	}
}

void EnviromentAstroids::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
	for each (GameObject* go in m_Astroids)
	{
		go->Render(deviceContext, worldMatrix, viewMatrix, projectionMatrix, frustume, light, camera);
	}
}

void EnviromentAstroids::Destroy()
{
	for each (GameObject* go in m_Astroids)
	{
		go->Destroy();
		delete go;
		go = 0;
	}
	m_Astroids.clear();

	if (m_Prefab)
	{
		m_Prefab->Destroy();
		delete m_Prefab;
		m_Prefab = 0;
	}
}

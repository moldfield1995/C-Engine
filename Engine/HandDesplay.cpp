#include "HandDesplay.h"
#include "GameObject.h"
#include "inputclass.h"

HandDesplay::HandDesplay()
{
	lastUpdate = 0;
	m_HandGameObjects = std::vector<GameObject*>();
	currentCashedHands = 0;
}


HandDesplay::~HandDesplay()
{
}

void HandDesplay::Update()
{
	InputClass* instance = InputClass::GetInstance();
	if (!instance->LeapConnected())
		return;
	Leap::Frame frame = instance->GetLeapFrame();
	if (frame.id() == lastUpdate || !frame.isValid())
		return;
	Leap::HandList hands = frame.hands();
	int handCount = hands.count();
	if (currentCashedHands < handCount)
	{
		for (int i = currentCashedHands; i < handCount; i++)
			createGameObjects(hands[currentCashedHands]);
	}
	int currentGOIndex = 0;

	for (int i = 0; i < handCount; i++)
	{
		Leap::Hand hand = hands[i];
		GameObject* Go = m_HandGameObjects[i];
		Go->SetPosition(hand.palmPosition());
		Go->SetRotation(hand.direction());
	}

}

void HandDesplay::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
	for each (GameObject* gameObject in m_HandGameObjects)
	{
		gameObject->Render(deviceContext, worldMatrix, viewMatrix, projectionMatrix, frustume, light, camera);
	}
}

void HandDesplay::Destroy()
{

}

void HandDesplay::createGameObjects(Leap::Hand hand)
{
	//createObject for palm
	//createObject for each finger
}

void HandDesplay::createGameObjects(int amount)
{
}

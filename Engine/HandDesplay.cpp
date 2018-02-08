#include "HandDesplay.h"
#include "GameObject.h"
#include "inputclass.h"

using namespace Leap;

HandDesplay::HandDesplay()
{
	lastUpdate = 0;
	m_HandGameObjects = std::vector<GameObject*>();
	currentActive = 0;
	leapToWorldScale = float3(.02f,.02f,-.02f);
	handOffset = float3(0.0f, -5.0f, 0.0f);
}


HandDesplay::~HandDesplay()
{
}

void HandDesplay::Initalize()
{
	//createGameObjects(10);
	this->SetOwnersRender(false);
}

void HandDesplay::Update()
{
	InputClass* instance = InputClass::GetInstance();
	if (!instance->LeapConnected())
		return;
	Frame frame = instance->GetLeapFrame();
	if (frame.id() == lastUpdate || !frame.isValid())
		return;
	HandList hands = frame.hands();
	int handCount = hands.count();
	//reset to 0 incase render was not called
	currentActive = 0;
	GameObject* workGo = 0;
	for each (Leap::Hand hand in hands)
	{
		if (currentActive >= m_HandGameObjects.size())
			createGameObjects(1);
		workGo = m_HandGameObjects[currentActive];
		workGo->SetPosition(float3(hand.palmPosition())*leapToWorldScale + handOffset);
		workGo->SetRotation(hand.direction());
		//Itterate the gameobject index to update
		currentActive++;
		//Itterate throgh fingers
		FingerList fingers = hand.fingers();
		//Fingers Multiplyed by 4 for each bone that will be rendered (-1 for thumb as it only had 3 render io
		if (currentActive +(fingers.count())*4 >= m_HandGameObjects.size())
			createGameObjects((currentActive + fingers.count()*4) - m_HandGameObjects.size());
		for each (Finger finger in fingers)
		{
			for (int i = 1; i <= 4; i++)
			{
				Bone bone = finger.bone(static_cast<Bone::Type>(i));
				if (bone.isValid()) {
					workGo = m_HandGameObjects[currentActive];
					workGo->SetPosition(float3(bone.prevJoint())*leapToWorldScale + handOffset);
					workGo->SetRotation(bone.direction()); //Default float 3 = 0,0,0
					//itterate the gameobject index to update
					currentActive++;
				}
			}
		}
	}


	//Trims off the last game object that was never set
	currentActive--;
}

void HandDesplay::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
	for (; currentActive >= 0; currentActive--)
	{
		m_HandGameObjects[currentActive]->Render(deviceContext, worldMatrix, viewMatrix, projectionMatrix, frustume, light, camera);
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
	for (; amount > 0; amount--)
		m_HandGameObjects.push_back(new GameObject(owner));
}

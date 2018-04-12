#include "HandDesplay.h"
#include "GameObject.h"
#include "inputclass.h"

using namespace Leap;

HandDesplay::HandDesplay()
{
	lastUpdate = 0;
	m_HandGameObjects = std::vector<GameObject*>();
	currentActive = -1;
}


HandDesplay::~HandDesplay()
{
}

void HandDesplay::Initalize()
{
	InputClass* instance = InputClass::GetInstance();
	leapToWorldScale = instance->GetLeapToWorldScale();
	leapOffset = instance->GetLeapOffset();
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
		workGo->SetPosition(Float3(hand.palmPosition())*leapToWorldScale + leapOffset);
		workGo->SetRotation((Float3(hand.palmNormal())+Float3(1.0f)) * (90.0f / PI));//* (180.0f/PI));
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
					workGo->SetPosition(Float3(bone.prevJoint())*leapToWorldScale + leapOffset);
					workGo->SetRotation((Float3(hand.palmNormal()) + Float3(1.0f)) * (90.0f/PI));
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


void HandDesplay::createGameObjects(int amount)
{
	for (; amount > 0; amount--)
		m_HandGameObjects.push_back(new GameObject(owner));
}

#include "DebugDesplay.h"
#include "UIMannager.h"
#include "inputclass.h"
#include "timerclass.h"

DebugDesplay::DebugDesplay()
{
	handText = 0;
	renders = false;
}


DebugDesplay::~DebugDesplay()
{
}

void DebugDesplay::Initalize()
{
	int screenHeight, screenWidth;
	UIMannager* instance = UIMannager::GetInstance();
	D3DClass::GetInstance()->GetScreenReserlution(screenWidth, screenHeight);
	textNum = 5;
	handText = new UIText*[textNum];
	handText[0] = new UIText(XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f), "Hands: 0 PosX: 0.0 PosY: 0.0 PosZ: 0.0");
	handText[1] = new UIText(XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f), "Raw leap X: 0.0 Y: 0.0 Z: 0.0");
	handText[2] = new UIText(XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f), "Rot X: 0.0 Y: 0.0 Z: 0.0");
	handText[3] = new UIText(XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f), "ScreenPos X: 0.0 Y: 0.0");
	handText[4] = new UIText(XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f), "");
	for (int i = textNum-1; i >= 0; i--)
	{
		handText[i]->SetPosition(float3(0.0f, - (i * 35.0f)));
		instance->AddComponet(handText[i]);
	}
	

	testButton = new UIButton("../Engine/data/textures/Button.tga");
	testButton->SetPosition(float3(screenWidth/2, 0.0f));
	__hook(&UIButton::onClickTrigger, testButton, &DebugDesplay::ButtonClicked);
	instance->AddComponet(testButton);
}

void DebugDesplay::Update()
{
	InputClass *instance = InputClass::GetInstance();
	float frameTime = TimerClass::GetInstance()->GetTime();
	Frame frame = instance->GetLeapFrame();
	if (frame.isValid())
	{
		Hand hand = frame.hands()[0];
		float3 handPos = hand.palmPosition();
		handText[1]->UpdateString("Raw leap " + handPos.ToString());

		handPos = handPos * instance->GetLeapToWorldScale() + instance->GetLeapOffset();
		handText[0]->UpdateString("Hands: " + std::to_string(frame.hands().count()) + " Pos " + handPos.ToString());
		
		handText[2]->UpdateString("Rot " + hand.palmNormal().toString());

		handText[3]->UpdateString("ScreenPos " + instance->GetLeapScreenPos().ToString());
	}
	else
	{
		handText[0]->UpdateString("Invalid Frame");
	}
	//float3 input = float3();
	//if (instance->Key(DIK_UPARROW))
	//	input.Y += 100.0f * frameTime;
	//if (instance->Key(DIK_DOWNARROW))
	//	input.Y -= 100.0f * frameTime;
	//if (instance->Key(DIK_RIGHTARROW))
	//	input.X += 100.0f * frameTime;
	//if (instance->Key(DIK_LEFTARROW))
	//	input.X -= 100.0f * frameTime;
	//handText->SetPosition(handText->GetPosition() + input);
	
}

void DebugDesplay::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{

}

void DebugDesplay::Destroy()
{
	for (int i = textNum-1; i >= 0; i--)
		handText[i]->Destroy();
	delete[] handText;
	__unhook(&UIButton::onClickTrigger, testButton, &DebugDesplay::ButtonClicked);
	testButton->Destroy();
	delete testButton;
}

void DebugDesplay::ButtonClicked()
{
	handText[4]->UpdateString("Button Clicked");
}

#include "HandCurser.h"
#include "UIMannager.h"
#include "inputclass.h"

HandCurser::HandCurser(char* cursorDefault)
{
	curser = new UIImage(cursorDefault);
}


HandCurser::~HandCurser()
{
}

void HandCurser::Initalize()
{
	UIMannager::GetInstance()->AddComponet(curser);
}

void HandCurser::Update()
{
	Leap::Frame frame = InputClass::GetInstance()->GetLeapFrame();
	if (frame.isValid() && frame.hands().count() > 0)
	{
		curser->SetRender(true);
		curser->SetPosition(InputClass::GetInstance()->GetLeapScreenPos());
	}
	else
	{
		curser->SetRender(false);
	}
}

void HandCurser::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
}

void HandCurser::Destroy()
{
	if (curser)
	{
		curser->Destroy();
		curser = 0;
	}
}

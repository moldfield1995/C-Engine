#include "WarpSpeed.h"
#include "GameObject.h"
#include "warpspeedshaderclass.h"
#include "shadermanagerclass.h"
#include "DifficultyHandler.h"

WarpSpeed::WarpSpeed()
{
}


WarpSpeed::~WarpSpeed()
{
}

void WarpSpeed::Initalize()
{
	timerClass = TimerClass::GetInstance();
	shaderData = new float[7];
	shaderData[0] = timerClass->GetTime();//Time
	shaderData[1] = 1.0f;//Speed
	shaderData[2] = 0.1f;//Fade
	shaderData[3] = 10.0f;//Regularity
	//Colour
	shaderData[4] = 0.541f;//R
	shaderData[5] = 0.776f;//G
	shaderData[6] = 0.988f;//B

	shader = ShaderManagerClass::GetInstance()->GetShader<WarpSpeedShaderClass>();
	SetOwnersRender(false);
}

void WarpSpeed::Update()
{
	shaderData[0] = timerClass->GetTime();
	shaderData[1] = 0.75f + (0.25f * DifficultyHandler::GetDifficulty());
	shaderData[2] = (0.1f * DifficultyHandler::GetDifficulty());
}

void WarpSpeed::Render(ID3D11DeviceContext * deviceContext, const XMMATRIX & worldMatrix, const XMMATRIX & viewMatrix, const XMMATRIX & projectionMatrix, FrustumClass * frustume, LightClass * light, CameraClass & camera)
{
	XMMATRIX renderMatrix, transformMatrix, rotationMatrix, scaleMatrix;
	Float3 position, rotation, scale;
	ModelClass *model = GetModel();
	position = owner->GetPosition();
	rotation = owner->GetRotation();
	scale = owner->GetScale();
	rotation = rotation * 0.0174532925f;

	transformMatrix = XMMatrixTranslation(position.X, position.Y, position.Z);
	scaleMatrix = XMMatrixScaling(scale.X, scale.Y, scale.Z);
	rotationMatrix = XMMatrixRotationRollPitchYaw(rotation.X, rotation.Y, rotation.Z);
	
	renderMatrix = XMMatrixMultiply(worldMatrix, transformMatrix);
	renderMatrix = XMMatrixMultiply(rotationMatrix, renderMatrix);
	renderMatrix = XMMatrixMultiply(scaleMatrix, renderMatrix);
	D3DClass::GetInstance()->TurnZBufferOff();
	D3DClass::GetInstance()->EnableAlphaBlending();
	model->Render(deviceContext);
	shader->Render(deviceContext, model->GetIndexCount(), renderMatrix, viewMatrix, projectionMatrix, nullptr, light, shaderData);
	D3DClass::GetInstance()->TurnZBufferOn();
	D3DClass::GetInstance()->DisableAlphaBlending();
}

void WarpSpeed::Destroy()
{
	if (shaderData)
	{
		delete(shaderData);
		shaderData = 0;
	}
	shader = 0;
	timerClass = 0;
}

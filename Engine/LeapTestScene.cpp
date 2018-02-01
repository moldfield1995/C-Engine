#include "LeapTestScene.h"
#include "HandDesplay.h"


LeapTestScene::LeapTestScene()
{
}


LeapTestScene::~LeapTestScene()
{
}

bool LeapTestScene::Initialize(D3DClass* Direct3D, int screenWidth, int screenHeight, float screenDepth, TextureManagerClass* textureManager, ModelManager* modelManager, AudioManager* audioManager)
{
	ID3D11Device* device = Direct3D->GetDevice();
	bool result;
	if(!textureManager->TextureLoaded(404))
		result = textureManager->LoadTexture(device, Direct3D->GetDeviceContext(), "../Engine/data/textures/debug.tga", 404);
	if(!result)
		return false;
	if (!modelManager->ModelLoaded(ModelManager::parsString("../Engine/data/T1Assets/cubeS.txt")))
		modelManager->AddModle(device, "../Engine/data/T1Assets/cubeS.txt", ModelManager::parsString("../Engine/data/T1Assets/cubeS.txt"), HitBoxType::Point, float3());
	Shader* shader = ShaderManagerClass::GetInstance()->GetShader<TextureShaderClass>();

	GameObject* gameObject = new GameObject();
	gameObject->Initalize(float3(), float3(), modelManager->GetModel(ModelManager::parsString("../Engine/data/T1Assets/cubeS.txt")), textureManager->GetTexture(404), shader);
	gameObject->AddComponet(new HandDesplay());



	return true;
}

void LeapTestScene::Shutdown()
{
}

bool LeapTestScene::Frame(D3DClass* Direct3D, InputClass* Input, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager,
	ModelManager* modelManager, float frameTime, int fps, AudioManager* audioManager)
{


	return false;
}

void LeapTestScene::HandleMovementInput(InputClass* Input, float frameTime)
{
}

bool LeapTestScene::Render(D3DClass* Direct3D, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager, ModelManager* modelManager)
{


	return false;
}

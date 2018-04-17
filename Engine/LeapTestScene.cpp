#include "LeapTestScene.h"
#include "HandDesplay.h"
#include "DebugDesplay.h"
#include "Utills.h"
#include "RotateObject.h"
#include "HitBoxTest.h"
#include "BasicMeshHitbox.h"
#include "textureshaderclass.h"
#include "bumpmapshaderclass.h"

LeapTestScene::LeapTestScene()
{
	m_Camera = 0;
	m_Frustum = 0;
	m_GameObjects = std::vector<GameObject*>();
	m_Light = 0;
	m_UIMannager = 0;
}


LeapTestScene::~LeapTestScene()
{
}

bool LeapTestScene::Initialize(D3DClass* Direct3D, int screenWidth, int screenHeight, float screenDepth, TextureManagerClass* textureManager, ModelManager* modelManager, AudioManager* audioManager)
{
	ID3D11Device* device = Direct3D->GetDevice();
	ID3D11DeviceContext* deviceContex = Direct3D->GetDeviceContext();
	bool result = true;
	int defaultNormal, modelId, textureID;
	// Create the camera object.
	m_Camera = new CameraClass;
	if (!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera and build the matrices needed for rendering.
	m_Camera->SetPosition(0.0f, 0.0f, -10.0f);
	m_Camera->Render();
	m_Camera->RenderBaseViewMatrix();
	m_Camera->SetActiveCamera();
	// Create the light object.
	m_Light = new LightClass;
	if (!m_Light)
	{
		return false;
	}

	// Initialize the light object.
	m_Light->SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetAmbientColor(0.1f, 0.1f, 0.1f, 0.1f);
	m_Light->SetSpecularColor(0.1f, 0.1f, 0.1f, 0.1f);
	m_Light->SetDirection(0.5f, -1.0f, -0.5f);

	// Create the frustum object.
	m_Frustum = new FrustumClass;
	if (!m_Frustum)
	{
		return false;
	}

	// Initialize the frustum object.
	m_Frustum->Initialize(screenDepth);

	m_UIMannager = new UIMannager();
	m_UIMannager->Initalize(screenWidth, screenHeight);

	textureID = textureManager->LoadTexture(device, deviceContex, "../Engine/data/textures/StupidShipUV.tga");

	result = textureManager->LoadTexture(device, deviceContex, "../Engine/data/textures/debug.tga", 404);
	if (!result)
		return false;
	modelManager->AddModle(device, "../Engine/data/T1Assets/cubeS.txt", Utills::ParsString("../Engine/data/T1Assets/cubeS.txt"));
	modelManager->AddModle(device, "../Engine/data/Models/Capsule.obj", Utills::ParsString("../Engine/data/Models/Capsule.obj"));
	modelId = modelManager->AddModle(device, "../Engine/data/Models/StupidShip.obj");

	Shader* shader = ShaderManagerClass::GetInstance()->GetShader<TextureShaderClass>();

	GameObject* gameObject = new GameObject();
	gameObject->Initalize(Float3(), Float3(), modelManager->GetModel(Utills::ParsString("../Engine/data/T1Assets/cubeS.txt")), textureManager->GetTexture(404), shader);

	gameObject->AddComponet(new HandDesplay());
	gameObject->AddComponet(new DebugDesplay());
	m_GameObjects.push_back(gameObject);

	//gameObject = new GameObject();
	//gameObject->Initalize(Float3(0.0f, -10.0f, 5.0f), Float3(), modelManager->GetModel(Utills::ParsString("../Engine/data/Capsule.obj")), textureManager->GetTexture(404), shader);
	//m_GameObjects.push_back(gameObject);

	Shader* bumpShader = ShaderManagerClass::GetInstance()->GetShader<BumpMapShaderClass>();
	defaultNormal = textureManager->LoadTexture(device, deviceContex, "../Engine/data/textures/DefaultNornal.tga");

	gameObject = new GameObject();
	gameObject->Initalize(Float3(0.0f, 0.0f, 5.0f), Float3(), modelManager->GetModel(modelId), textureManager->GetTexture(textureID), bumpShader);
	gameObject->AddTexture(textureManager->GetTexture(defaultNormal));
	gameObject->AddComponet(new RotateObject(Float3(50.0f, 50.0f, 50.0f)));
	m_GameObjects.push_back(gameObject);

	modelId = modelManager->AddModle(device, "../Engine/data/GooglePoly/Asteroids.obj");
	textureID = textureManager->LoadTexture(device, deviceContex, "../Engine/data/GooglePoly/Asteroids_BaseColor.tga");

	gameObject = new GameObject();
	gameObject->Initalize(Float3(0.0f, -5.0f, 15.0f), Float3(), modelManager->GetModel(modelId), textureManager->GetTexture(textureID), shader);
	m_GameObjects.push_back(gameObject);

	modelId = modelManager->AddModle(device, "../Engine/data/LizReddington/Planet1.obj");
	textureID = textureManager->LoadTexture(device, deviceContex, "../Engine/data/LizReddington/Planet1.tga");

	gameObject = new GameObject();
	gameObject->Initalize(Float3(5.0f, -5.0f, 15.0f), Float3(), modelManager->GetModel(modelId), textureManager->GetTexture(textureID), shader);
	gameObject->SetScale(Float3(0.01f,0.01f,0.01f));
	m_GameObjects.push_back(gameObject);

	modelId = modelManager->AddModle(device, "../Engine/data/LizReddington/Ship1.obj");
	textureID = textureManager->LoadTexture(device, deviceContex, "../Engine/data/LizReddington/Ship1Uved.tga");

	gameObject = new GameObject();
	gameObject->Initalize(Float3(0.0f, 0.0f, 0.0f), Float3(), modelManager->GetModel(modelId), textureManager->GetTexture(textureID), shader);
	gameObject->SetScale(Float3(0.01f, 0.01f, 0.01f));
	BasicMeshHitbox *basicMeshHitbox = new BasicMeshHitbox();
	gameObject->AddComponet(basicMeshHitbox);
	m_GameObjects.push_back(gameObject);

	modelId = modelManager->AddModle(device, "../Engine/data/T1Assets/cube.txt");

	gameObject = new GameObject();
	gameObject->Initalize(Float3(0.0f, 0.0f, 0.0f), Float3(), modelManager->GetModel(modelId), textureManager->GetTexture(404), shader);
	Component* hitbox = new HitBoxTest(Float3(), Float3(-6.0f, 0.0f, 0.0f), Float3(0.0f, 0.0f, 0.0f));
	gameObject->AddComponet(hitbox);
	m_GameObjects.push_back(gameObject);

	gameObject = new GameObject();
	gameObject->Initalize(Float3(0.0f, 0.0f, 0.0f), Float3(40.0f,29.0f,68.0f), modelManager->GetModel(modelId), textureManager->GetTexture(404), shader);
	hitbox = new HitBoxTest(Float3(), Float3(6.0f, 0.0f, 0.0f), Float3(0.0f, 0.0f, 0.0f));
	gameObject->AddComponet(hitbox);
	m_GameObjects.push_back(gameObject);

	return true;
}

void LeapTestScene::Shutdown()
{
	if (m_Camera)
	{
		delete(m_Camera);
		m_Camera = 0;
	}
	if (m_Frustum)
	{
		delete m_Frustum;
		m_Frustum = 0;
	}
	for each (GameObject* var in m_GameObjects)
	{
		var->Destroy();
		delete var;
		var = 0;
	}

	m_Light = 0;
	m_UIMannager = 0;
}

bool LeapTestScene::Frame(D3DClass* Direct3D, InputClass* Input, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager,
	ModelManager* modelManager, float frameTime, int fps, AudioManager* audioManager)
{
	for each (GameObject* gameobject in m_GameObjects)
	{
		gameobject->Update();
	}
	m_UIMannager->Update();
	Render(Direct3D, ShaderManager, TextureManager, modelManager);
	return true;
}

void LeapTestScene::HandleMovementInput(InputClass* Input, float frameTime)
{
}

bool LeapTestScene::Render(D3DClass* Direct3D, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager, ModelManager* modelManager)
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix, baceViewMatrix, orthoMatrix;
	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	Direct3D->GetWorldMatrix(worldMatrix);
	m_Camera->GetViewMatrix(viewMatrix);
	Direct3D->GetProjectionMatrix(projectionMatrix);
	m_Camera->GetBaseViewMatrix(baceViewMatrix);
	Direct3D->GetOrthoMatrix(orthoMatrix);

	// Construct the frustum.
	m_Frustum->ConstructFrustum(projectionMatrix, viewMatrix);

	// Clear the buffers to begin the scene.
	Direct3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);
	ID3D11DeviceContext* context = Direct3D->GetDeviceContext();
	for each (GameObject* gameobject in m_GameObjects)
	{
		gameobject->Render(context, worldMatrix, viewMatrix, projectionMatrix, m_Frustum, m_Light, *m_Camera);
	}

	m_UIMannager->Render(context, worldMatrix, baceViewMatrix, orthoMatrix);

	//End Render
	Direct3D->EndScene();
	return true;
}

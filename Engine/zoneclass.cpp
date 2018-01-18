////////////////////////////////////////////////////////////////////////////////
// Filename: zoneclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "zoneclass.h"
#include "lightshader.h"
#include "bumpmapshaderclass.h"
ZoneClass::ZoneClass()
{
	m_UserInterface = 0;
	m_Camera = 0;
	m_Light = 0;
	m_Position = 0;
	m_Frustum = 0;
	m_SkyDome = 0;
	m_Terrain = 0;
}


ZoneClass::ZoneClass(const ZoneClass& other)
{
}


ZoneClass::~ZoneClass()
{
}


bool ZoneClass::Initialize(D3DClass* Direct3D, int screenWidth, int screenHeight, float screenDepth, TextureManagerClass* textureManager, ModelManager* modelManager, AudioManager* audioManager)
{
	bool result;
	int loadAmount = 0;
	ID3D11Device* device = Direct3D->GetDevice();
	result = textureManager->LoadTexture(device, Direct3D->GetDeviceContext(), "../Engine/data/textures/rock01d.tga", 0);
	if (!result)
	{
		return false;
	}

	result = textureManager->LoadTexture(device, Direct3D->GetDeviceContext(), "../Engine/data/textures/rock01n.tga", 1);
	if (!result)
	{
		return false;
	}

	result = textureManager->LoadTexture(device, Direct3D->GetDeviceContext(), "../Engine/data/textures/snow01n.tga", 2);
	if (!result)
	{
		return false;
	}

	result = textureManager->LoadTexture(device, Direct3D->GetDeviceContext(), "../Engine/data/textures/distance01n.tga", 3);
	if (!result)
	{
		return false;
	}
	result = textureManager->LoadTexture(device, Direct3D->GetDeviceContext(), "../Engine/data/textures/debug.tga", 404);
	if (!result)
	{
		return false;
	}
	loadAmount += 5;
	setLoadingLevel(loadAmount);
	m_textID = m_modelID = 0;
	// Create the user interface object.
	m_UserInterface = new UserInterfaceClass;
	if (!m_UserInterface)
	{
		return false;
	}

	// Initialize the user interface object.
	result = m_UserInterface->Initialize(Direct3D, screenHeight, screenWidth);
	if (!result)
	{
		return false;
	}

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
	m_Light->SetDirection(-0.5f, -1.0f, -0.5f);

	// Create the position object.
	m_Position = new PositionClass;
	if (!m_Position)
	{
		return false;
	}

	// Set the initial position and rotation.
	m_Position->SetPosition(560.0f, 8.0f, 260.0f);
	m_Position->SetRotation(0.0f, 0.0f, 0.0f);
	m_Position->Sethitbox(float3(1.0f, 3.0f, 1.0f));
	// Create the frustum object.
	m_Frustum = new FrustumClass;
	if (!m_Frustum)
	{
		return false;
	}

	// Initialize the frustum object.
	m_Frustum->Initialize(screenDepth);

	// Create the sky dome object.
	m_SkyDome = new SkyDomeClass;
	if (!m_SkyDome)
	{
		return false;
	}

	// Initialize the sky dome object.
	result = m_SkyDome->Initialize(device);
	if (!result)
	{
		return false;
	}
	loadAmount += 5;
	setLoadingLevel(loadAmount);
	// Create the terrain object.
	m_Terrain = new TerrainClass;
	if (!m_Terrain)
	{
		return false;
	}

	// Initialize the terrain object.
	result = m_Terrain->Initialize(device, "../Engine/data/setup.txt");
	if (!result)
	{
		return false;
	}

	loadAmount += 10;
	setLoadingLevel(loadAmount);
	// Set the UI to display by default.
	m_displayUI = true;

	// Set wire frame rendering initially to disabled.
	m_wireFrame = false;

	// Set the rendering of cell lines initially to disabled.
	m_cellLines = false;

	// Set the user locked to the terrain height for movement.
	m_heightLocked = true;
	result = textureManager->LoadTexture(device, Direct3D->GetDeviceContext(), "../Engine/data/T1Assets/Su-35_SuperFlanker_P01.tga", ModelManager::parsString("../Engine/data/T1Assets/Su-35_SuperFlanker_P01.tga"));
	if (!result)
	{
		return false;
	}
	result = textureManager->LoadTexture(device, Direct3D->GetDeviceContext(), "../Engine/data/New Models/OldHouce.tga", ModelManager::parsString("../Engine/data/New Models/OldHouce.tga"));
	if (!result)
	{
		return false;
	}
	result = textureManager->LoadTexture(device, Direct3D->GetDeviceContext(), "../Engine/data/New Models/hutTex.tga", ModelManager::parsString("../Engine/data/New Models/hutTex.tga"));
	if (!result)
	{
		return false;
	}
	result = textureManager->LoadTexture(device, Direct3D->GetDeviceContext(), "../Engine/data/New Models/FancyHouceTex.tga", ModelManager::parsString("../Engine/data/New Models/FancyHouceTex.tga"));
	if (!result)
	{
		return false;
	}
	result = textureManager->LoadTexture(device, Direct3D->GetDeviceContext(), "../Engine/data/New Models/SimpleHouce.tga", ModelManager::parsString("../Engine/data/New Models/SimpleHouce.tga"));
	if (!result)
	{
		return false;
	}
	result = textureManager->LoadTexture(device, Direct3D->GetDeviceContext(), "../Engine/data/New Models/FancyHouceBump.tga", ModelManager::parsString("../Engine/data/New Models/FancyHouceBump.tga"));
	if (!result)
	{
		return false;
	}
	result = textureManager->LoadTexture(device, Direct3D->GetDeviceContext(), "../Engine/data/New Models/hutBump.tga", ModelManager::parsString("../Engine/data/New Models/hutBump.tga"));
	if (!result)
	{
		return false;
	}
	loadAmount += 5;
	setLoadingLevel(loadAmount);
	m_DebugHitbox = true;
	m_ObjectSpawn = false;
	modelManager->AddModle(device, "../Engine/data/T2Assets/Cat.txt", ModelManager::parsString("../Engine/data/T2Assets/Cat.txt"), HitBoxType::Rectangle, float3(1.0f, 0.0f, 0.0f));
	loadAmount += 10;
	setLoadingLevel(loadAmount);
	modelManager->AddModle(device, "../Engine/data/T1Assets/Su-35_SuperFlanker.txt", ModelManager::parsString("../Engine/data/T1Assets/Su-35_SuperFlanker.txt"), HitBoxType::Rectangle, float3(8.0f, 13.0f, 1.0f));
	loadAmount += 10;
	setLoadingLevel(loadAmount);
	modelManager->AddModle(device, "../Engine/data/New Models/OldHouce.txt", ModelManager::parsString("../Engine/data/New Models/OldHouce.txt"), HitBoxType::Rectangle, float3(3.0f, 2.0f, 4.0f));
	loadAmount += 20;
	setLoadingLevel(loadAmount);
	modelManager->AddModle(device, "../Engine/data/New Models/SimpleHouce.txt", ModelManager::parsString("../Engine/data/New Models/SimpleHouce.txt"), HitBoxType::Rectangle, float3(7.0f, 0.0f, 0.0f));
	loadAmount += 10;
	setLoadingLevel(loadAmount);
	modelManager->AddModle(device, "../Engine/data/New Models/hut.txt", ModelManager::parsString("../Engine/data/New Models/hut.txt"), HitBoxType::Rectangle, float3());
	loadAmount += 5;
	setLoadingLevel(loadAmount);
	modelManager->AddModle(device, "../Engine/data/New Models/FancyHouce.txt", ModelManager::parsString("../Engine/data/New Models/FancyHouce.txt"), HitBoxType::Rectangle, float3());
	loadAmount += 5;
	setLoadingLevel(loadAmount);
	modelManager->AddModle(device, "../Engine/data/T1Assets/cubeS.txt", ModelManager::parsString("../Engine/data/T1Assets/cubeS.txt"), HitBoxType::Point, float3());
	ShaderManagerClass* shaderManager = ShaderManagerClass::GetInstance();
	m_GameObjects = std::vector<GameObject*>();
	GameObject* gameObject = new GameObject();
	gameObject->Initalize(float3(0.0f, 0.0f, 0.0f), float3(0.0f, 0.0f, 0.0f), modelManager->GetModel(ModelManager::parsString("../Engine/data/T1Assets/cubeS.txt")), textureManager->GetTexture(404), shaderManager->GetShader<LightShader>());
	m_GameObjects.push_back(gameObject);

	gameObject = new GameObject();
	gameObject->Initalize(float3(560.0f, 30.0f, 260.0f), float3(0.0f, 0.0f, 0.0f), modelManager->GetModel(ModelManager::parsString("../Engine/data/T1Assets/Su-35_SuperFlanker.txt")), textureManager->GetTexture(ModelManager::parsString("../Engine/data/T1Assets/Su-35_SuperFlanker_P01.tga")), shaderManager->GetShader<LightShader>());
	m_GameObjects.push_back(gameObject);

	gameObject = new GameObject();
	gameObject->Initalize(float3(565.0f, 7.8f, 260.0f), float3(0.0f, 0.0f, 0.0f), modelManager->GetModel(ModelManager::parsString("../Engine/data/T2Assets/Cat.txt")), textureManager->GetTexture(404), shaderManager->GetShader<LightShader>());
	m_GameObjects.push_back(gameObject);

	gameObject = new GameObject();
	gameObject->Initalize(float3(560.0f, 8.0f, 270.0f), float3(0.0f, 0.0f, 0.0f), modelManager->GetModel(ModelManager::parsString("../Engine/data/New Models/OldHouce.txt")), textureManager->GetTexture(ModelManager::parsString("../Engine/data/New Models/OldHouce.tga")), shaderManager->GetShader<LightShader>());
	m_GameObjects.push_back(gameObject);
	{
		gameObject = new GameObject();
		ID3D11ShaderResourceView* textures[2] = { textureManager->GetTexture(ModelManager::parsString("../Engine/data/New Models/hutTex.tga")),textureManager->GetTexture(ModelManager::parsString("../Engine/data/New Models/hutBump.tga")) };
		gameObject->Initalize(float3(540.0f, 8.0f, 260.0f), float3(0.0f, 0.0f, 0.0f), modelManager->GetModel(ModelManager::parsString("../Engine/data/New Models/hut.txt")), *textures, shaderManager->GetShader<BumpMapShaderClass>());
		gameObject->SetScale(float3(0.08f, 0.08f, 0.08f));
		m_GameObjects.push_back(gameObject);
	}
	{
		gameObject = new GameObject();

		ID3D11ShaderResourceView* textures[2] = { textureManager->GetTexture(ModelManager::parsString("../Engine/data/New Models/FancyHouceTex.tga")),textureManager->GetTexture(ModelManager::parsString("../Engine/data/New Models/FancyHouceBump.tga")) };
		gameObject->Initalize(float3(580.0f, 8.0f, 260.0f), float3(0.0f, 0.0f, 0.0f), modelManager->GetModel(ModelManager::parsString("../Engine/data/New Models/FancyHouce.txt")), *textures, shaderManager->GetShader<BumpMapShaderClass>());
		gameObject->SetScale(float3(0.05f, 0.05f, 0.05f));
		m_GameObjects.push_back(gameObject);
	}
	gameObject = new GameObject();
	gameObject->Initalize(float3(560.0f, 8.0f, 240.0f), float3(0.0f, 0.0f, 0.0f), modelManager->GetModel(ModelManager::parsString("../Engine/data/New Models/SimpleHouce.txt")), textureManager->GetTexture(ModelManager::parsString("../Engine/data/New Models/SimpleHouce.tga")), shaderManager->GetShader<LightShader>());
	m_GameObjects.push_back(gameObject);
	m_Camera->SetActiveCamera();
	return true;
}


void ZoneClass::Shutdown()
{
	// Release the terrain object.
	if (m_Terrain)
	{
		m_Terrain->Shutdown();
		delete m_Terrain;
		m_Terrain = 0;
	}
	// Release the sky dome object.
	if (m_SkyDome)
	{
		m_SkyDome->Shutdown();
		delete m_SkyDome;
		m_SkyDome = 0;
	}

	// Release the frustum object.
	if (m_Frustum)
	{
		delete m_Frustum;
		m_Frustum = 0;
	}

	// Release the position object.
	if (m_Position)
	{
		delete m_Position;
		m_Position = 0;
	}

	// Release the light object.
	if (m_Light)
	{
		delete m_Light;
		m_Light = 0;
	}

	// Release the camera object.
	if (m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	// Release the user interface object.
	if (m_UserInterface)
	{
		m_UserInterface->Shutdown();
		delete m_UserInterface;
		m_UserInterface = 0;
	}


	return;
}

//Make most of these Instance Classes
bool ZoneClass::Frame(D3DClass* Direct3D, InputClass* Input, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager,
	ModelManager* modelManager, float frameTime, int fps, AudioManager* audioManager)
{
	bool result;
	float posX, posY, posZ, rotX, rotY, rotZ;


	// Do the frame input processing.
	HandleMovementInput(Input, frameTime);
	HandleInput(Input, frameTime, TextureManager, modelManager);
	// Get the view point position/rotation.
	m_Position->GetPosition(posX, posY, posZ);
	m_Position->GetRotation(rotX, rotY, rotZ);
	m_Camera->SetRotation(rotX, rotY, rotZ);
	// Do the frame processing for the user interface.
	result = m_UserInterface->Frame(Direct3D->GetDeviceContext(), fps, posX, posZ, m_ObjectSpawn, m_spawnState);
	if (!result)
	{
		return false;
	}

	// Do the terrain frame processing.
	m_Terrain->Frame();
	if (CheckHitboxs(modelManager))
	{
		m_Position->Frame(true);
		m_Position->GetPosition(posX, posY, posZ);
		m_Camera->SetPosition(posX, posY + 2.0f, posZ);
	}
	// Render the graphics.
	result = Render(Direct3D, ShaderManager, TextureManager, modelManager);
	if (!result)
	{
		return false;
	}
	return true;
}


void ZoneClass::HandleMovementInput(InputClass* Input, float frameTime)
{
	bool result;
	float posX, posY, posZ, height = 0.0f;
	int mouseX = 0, mouseY = 0;
	//int newCS;
	m_Position->SetFrameTime(frameTime);
	Input->GetMouseLocation(mouseX, mouseY);
	m_Position->RotateX(mouseY);
	m_Position->RotateY(mouseX);
	result = m_Position->ApplyInput(Input->IsUpPressed(), Input->IsDownPressed(), Input->IsLeftPressed(), Input->IsRightPressed());
	m_Position->GetPosition(posX, posY, posZ);
	m_Camera->SetPosition(posX, posY + 2.0f, posZ);
	if (result)
	{
		if (m_heightLocked)
		{
			// Get the height of the triangle that is directly underneath the given camera position.
			bool foundHeight = m_Terrain->GetHeightAtPosition(posX, posZ, height);
			if (foundHeight)
			{
				// If there was a triangle under the camera then position the camera just above it by one meter.
				posY = height;
				m_Position->SetPosition(posX, posY + 1.0f, posZ);
				m_Camera->SetPosition(posX, posY + 3.0f, posZ);
			}
		}
	}
	if (Input->IsF2Toggled())
		m_DebugHitbox = !m_DebugHitbox;

	return;
}

void ZoneClass::HandleInput(InputClass *Input, float frameTime, TextureManagerClass * TextureManager, ModelManager * Models)
{
	float posX, posY, posZ, rotX, rotY, rotZ;
	float3 position, rotation, scale;
	if (m_ObjectSpawn)
	{
		m_Position->GetPosition(posX, posY, posZ);
		m_Position->GetRotation(rotX, rotY, rotZ);
		GameObject* go = m_GameObjects.back();
		go->SetOrigin(posX, posY + m_ymod, posZ, rotX, rotY, 10.0f + m_zmod);
		position = go->GetPosition();
		rotation = go->GetRotation();
		scale = go->GetScale();
		//int shader = go->GetShader();
		if (Input->MouseButton(1))
			m_ObjectSpawn = false;
		else
		{
			switch (m_spawnState)
			{
			case SpawnState::position:
				if (Input->IsPlusPressed())
					m_spawnState = SpawnState::rotation;
				else if (Input->IsMinusPressed())
					m_spawnState = SpawnState::bumpMap;
				else
				{
					if (Input->IsAPressed())
						m_xmod += 1 * frameTime;
					else if (Input->IsZPressed())
						m_xmod -= 1 * frameTime;
					if (Input->IsSPressed())
						m_ymod += 1 * frameTime;
					else if (Input->IsXPressed())
						m_ymod -= 1 * frameTime;
					if (Input->IsDPressed())
						m_zmod += 1 * frameTime;
					else if (Input->IsCPressed())
						m_zmod -= 1 * frameTime;
				}
				break;
			case SpawnState::rotation:
				if (Input->IsPlusPressed())
					m_spawnState = SpawnState::scale;
				else if (Input->IsMinusPressed())
					m_spawnState = SpawnState::position;
				if (Input->IsAPressed())
					rotation.X(rotation.X() + 10 * frameTime);
				else if (Input->IsZPressed())
					rotation.X(rotation.X() - 10 * frameTime);
				if (Input->IsSPressed())
					rotation.Y(rotation.Y() + 10 * frameTime);
				else if (Input->IsXPressed())
					rotation.Y(rotation.Y() - 10 * frameTime);
				if (Input->IsDPressed())
					rotation.Z(rotation.Z() + 10 * frameTime);
				else if (Input->IsCPressed())
					rotation.Z(rotation.Z() - 10 * frameTime);
				go->SetRotation(rotation);
				break;
			case SpawnState::scale:
				if (Input->IsPlusPressed())
					m_spawnState = SpawnState::model;
				else if (Input->IsMinusPressed())
					m_spawnState = SpawnState::rotation;
				if (Input->IsAPressed())
					scale.X(scale.X() + frameTime);
				else if (Input->IsZPressed() && scale.X() > 0.1f)
					scale.X(scale.X() - frameTime);
				if (Input->IsSPressed())
					scale.Y(scale.Y() + frameTime);
				else if (Input->IsXPressed() && scale.Y() > 0.1f)
					scale.Y(scale.Y() - frameTime);
				if (Input->IsDPressed())
					scale.Z(scale.Z() + frameTime);
				else if (Input->IsCPressed() && scale.Z() > 0.1f)
					scale.Z(scale.Z() - frameTime);
				go->SetScale(scale);
				break;
/*			case SpawnState::model:
				if (Input->IsPlusPressed())
					m_spawnState = SpawnState::texture;
				else if (Input->IsMinusPressed())
					m_spawnState = SpawnState::scale;
				if (Input->IsAToggled())
				{
					m_modelID++;
					if (Models->GetModdelList().size() == m_modelID)
						m_modelID = 0;
					go->SetModel(Models->GetModdelList()[m_modelID]);
				}
				else if (Input->IsZToggled())
				{
					m_modelID--;
					if (m_modelID < 0)
						m_modelID = Models->GetModdelList().size() - 1;
					go->SetModel(Models->GetModdelList()[m_modelID]);
				}
				break;
			case SpawnState::texture:
				if (Input->IsPlusPressed())
					m_spawnState = SpawnState::shader;
				else if (Input->IsMinusPressed())
					m_spawnState = SpawnState::model;
				if (Input->IsAToggled())
				{
					m_textID++;
					if (TextureManager->GetTextureList().size() == m_textID)
						m_textID = 0;
					go->SetTexture(TextureManager->GetTextureList()[m_textID]);
				}
				else if (Input->IsZToggled())
				{
					m_textID--;
					if (m_textID < 0)
						m_textID = TextureManager->GetTextureList().size() - 1;
					go->SetTexture(TextureManager->GetTextureList()[m_textID]);
				}
				break;
			case SpawnState::shader:
				if (Input->IsPlusPressed())
					m_spawnState = SpawnState::bumpMap;
				else if (Input->IsMinusPressed())
					m_spawnState = SpawnState::texture;
				if (Input->IsAToggled())
				{
					shader++;
					if (shader > 2)
						shader = 0;
					go->SetShader(shader);
				}
				else if (Input->IsZToggled())
				{
					shader--;
					if (shader < 0)
						shader = 2;
					go->SetShader(shader);
				}
				break;
			case SpawnState::bumpMap:
				if (Input->IsPlusPressed())
					m_spawnState = SpawnState::position;
				else if (Input->IsMinusPressed())
					m_spawnState = SpawnState::shader;
				if (Input->IsAToggled())
				{
					m_bumpID++;
					if (TextureManager->GetTextureList().size() == m_bumpID)
						m_bumpID = 0;
					go->SetBump(TextureManager->GetTextureList()[m_bumpID]);
				}
				else if (Input->IsZToggled())
				{
					m_bumpID--;
					if (m_bumpID < 0)
						m_bumpID = TextureManager->GetTextureList().size() - 1;
					go->SetBump(TextureManager->GetTextureList()[m_bumpID]);
				}
				break;//*/
			default:
				break;
			}
		}
	}
	else
	{
		if (Input->MouseButton(0))
		{
			m_Position->GetPosition(posX, posY, posZ);
			m_Position->GetRotation(rotX, rotY, rotZ);
			m_ObjectSpawn = true;
			m_textID = m_modelID = m_bumpID = 0;
			GameObject* go = new GameObject();
			go->Initalize(Models->GetModdelList()[0], TextureManager->GetTextureList()[0], float3(), float3());
			go->SetOrigin(posX, posY, posZ, rotX, rotY, 10.0f);
			m_GameObjects.push_back(go);
			m_xmod = m_ymod = m_zmod = 0.0f;
			m_spawnState = SpawnState::position;
		}
	}
}

bool ZoneClass::CheckHitboxs(ModelManager* modelManager)
{
	bool result = false;
	float3 gPossition, gScale, gHitbox, pHitbox, pPosition;
	HitBoxType hitboxType;
	pPosition = m_Position->GetPosition();
	pHitbox = m_Position->Gethitbox();

	int vectorLegth = m_GameObjects.size();
	if (m_ObjectSpawn)
		vectorLegth -= 1;
	for (int i = 1; i < vectorLegth; i++)
	{
		if (i == vectorLegth&&m_ObjectSpawn)
			return false;
		if (m_GameObjects[i] != NULL)
		{
			gHitbox = m_GameObjects[i]->GetHitbox();
			hitboxType = m_GameObjects[i]->GetHitboxType();
			gPossition = m_GameObjects[i]->GetPosition();
			gScale = m_GameObjects[i]->GetScale();
			gHitbox.X(gHitbox.X() * gScale.X());
			gHitbox.Y(gHitbox.Y() * gScale.Y());
			gHitbox.Z(gHitbox.Z() * gScale.Z());
			switch (hitboxType)
			{
			case HitBoxType::Sphere:
				result;
				break;
			case HitBoxType::Cube:
				result;
				break;
			case HitBoxType::Rectangle:
				result = (pPosition.X() - pHitbox.X() <= gPossition.X() + gHitbox.X() && pPosition.X() + pHitbox.X() >= gPossition.X() - gHitbox.X())
					&& (pPosition.Y() - pHitbox.Y() <= gPossition.Y() + gHitbox.Y() && pPosition.Y() + pHitbox.Y() >= gPossition.Y() - gHitbox.Y())
					&& (pPosition.Z() - pHitbox.Z() <= gPossition.Z() + gHitbox.Z() && pPosition.Z() + pHitbox.Z() >= gPossition.Z() - gHitbox.Z());
				break;
			case HitBoxType::Point:
				result = false;
				break;
			default:
				result = false;
				break;
			}
			if (result)
				return result;
		}
	}
	return false;
}

bool ZoneClass::Render(D3DClass* Direct3D, ShaderManagerClass* ShaderManager, TextureManagerClass* TextureManager, ModelManager* modelManager)
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix, baseViewMatrix, orthoMatrix, transformationMartix, rotationMatrix, scaleMatrix;
	bool result;
	XMFLOAT3 cameraPosition;
	int i;
	float3 possition, rotaion, scale, hitbox;
	HitBoxType hitboxType;
	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	Direct3D->GetWorldMatrix(worldMatrix);
	m_Camera->GetViewMatrix(viewMatrix);
	Direct3D->GetProjectionMatrix(projectionMatrix);
	//UI
	m_Camera->GetBaseViewMatrix(baseViewMatrix);
	Direct3D->GetOrthoMatrix(orthoMatrix);

	// Get the position of the camera.
	cameraPosition = m_Camera->GetPosition();

	// Construct the frustum.
	m_Frustum->ConstructFrustum(projectionMatrix, viewMatrix);

	// Clear the buffers to begin the scene.
	Direct3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Turn off back face culling and turn off the Z buffer.
	Direct3D->TurnOffCulling();
	Direct3D->TurnZBufferOff();

	// Translate the sky dome to be centered around the camera position.
	worldMatrix = XMMatrixTranslation(cameraPosition.x, cameraPosition.y, cameraPosition.z);
	scaleMatrix = XMMatrixScaling(0.1f, 0.1f, 0.1f);
	// Render the sky dome using the sky dome shader.
	m_SkyDome->Render(Direct3D->GetDeviceContext());
	result = ShaderManager->RenderSkyDomeShader(Direct3D->GetDeviceContext(), m_SkyDome->GetIndexCount(), worldMatrix, viewMatrix,
		projectionMatrix, m_SkyDome->GetApexColor(), m_SkyDome->GetCenterColor());
	if (!result)
	{
		return false;
	}

	// Reset the world matrix.
	Direct3D->GetWorldMatrix(worldMatrix);

	// Turn the Z buffer back and back face culling on.
	Direct3D->TurnZBufferOn();
	Direct3D->TurnOnCulling();

	// Turn on wire frame rendering of the terrain if needed.
	if (m_wireFrame)
	{
		Direct3D->EnableWireframe();
	}

	// Render the terrain cells (and cell lines if needed).
	for (i = 0; i < m_Terrain->GetCellCount(); i++)
	{
		// Render each terrain cell if it is visible only.
		result = m_Terrain->RenderCell(Direct3D->GetDeviceContext(), i, m_Frustum);
		if (result)
		{
			// Render the cell buffers using the hgih quality terrain shader.
			result = ShaderManager->RenderTerrainShader(Direct3D->GetDeviceContext(), m_Terrain->GetCellIndexCount(i), worldMatrix, viewMatrix,
				projectionMatrix, TextureManager->GetTexture(0), TextureManager->GetTexture(1),
				TextureManager->GetTexture(2), TextureManager->GetTexture(3),
				m_Light->GetDirection(), m_Light->GetDiffuseColor());
			if (!result)
			{
				return false;
			}
		}
	}
	ID3D11DeviceContext* context = Direct3D->GetDeviceContext();
	int vectorLegth = m_GameObjects.size();
	for (int i = 1; i < vectorLegth; i++)
	{
		if (m_GameObjects[i] != NULL)
		{
			m_GameObjects[i]->Render(context, worldMatrix, viewMatrix, projectionMatrix, m_Frustum, m_Light, *m_Camera);
			/*
			hitbox = modelManager->GetHitbox(m_GameObjects[i]->GetModel());
			hitboxType = modelManager->GetHitBoxType(m_GameObjects[i]->GetModel());
			possition = m_GameObjects[i]->GetPosition();
			scale = m_GameObjects[i]->GetScale();
			hitbox.X(hitbox.X() * scale.X());
			hitbox.Y(hitbox.Y() * scale.Y());
			hitbox.Z(hitbox.Z() * scale.Z());
			switch (hitboxType)
			{
			case HitBoxType::Sphere:
				result = m_Frustum->CheckSphere(possition.X(), possition.Y(), possition.Z(), hitbox.X());
				break;
			case HitBoxType::Cube:
				result = m_Frustum->CheckCube(possition.X(), possition.Y(), possition.Z(), hitbox.X());
				break;
			case HitBoxType::Rectangle:
				result = m_Frustum->CheckRectangle(possition.X(), possition.Y(), possition.Z(), hitbox.X(), hitbox.Y(), hitbox.Z());
				break;
			case HitBoxType::Point:
				result = true;
				break;
			default:
				result = false;
				break;
			}
			if (result)
			{
				rotaion = m_GameObjects[i]->GetRotation();
				Direct3D->GetWorldMatrix(worldMatrix);
				modelManager->Render(Direct3D->GetDeviceContext(), m_GameObjects[i]->GetModel());
				transformationMartix = XMMatrixTranslation(possition.X(), possition.Y(), possition.Z());
				rotationMatrix = XMMatrixRotationRollPitchYaw(rotaion.X()* 0.0174532925f, rotaion.Y()* 0.0174532925f, rotaion.Z()* 0.0174532925f);
				scaleMatrix = XMMatrixScaling(scale.X(), scale.Y(), scale.Z());
				worldMatrix = XMMatrixMultiply(worldMatrix, transformationMartix);
				worldMatrix = XMMatrixMultiply(rotationMatrix, worldMatrix);
				worldMatrix = XMMatrixMultiply(scaleMatrix, worldMatrix);
				if (m_GameObjects[i]->GetShader() == 0)
					ShaderManager->RenderLightShading(Direct3D->GetDeviceContext(), modelManager->IndexCount(m_GameObjects[i]->GetModel()), worldMatrix, viewMatrix, projectionMatrix,
						TextureManager->GetTexture(m_GameObjects[i]->GetTexture()), m_Light->GetDirection(), m_Light->GetDiffuseColor(), m_Light->GetAmbientColor(), m_Camera->GetPosition(), m_Light->GetSpecularColor(), 100.0f);
				else if (m_GameObjects[i]->GetShader() == 1)
					ShaderManager->RenderTextureShader(Direct3D->GetDeviceContext(), modelManager->IndexCount(m_GameObjects[i]->GetModel()), worldMatrix, viewMatrix, projectionMatrix,
						TextureManager->GetTexture(m_GameObjects[i]->GetTexture()));
				else
					ShaderManager->RenderBumpMapShader(Direct3D->GetDeviceContext(), modelManager->IndexCount(m_GameObjects[i]->GetModel()), worldMatrix, viewMatrix, projectionMatrix,
						TextureManager->GetTexture(m_GameObjects[i]->GetTexture()), TextureManager->GetTexture(m_GameObjects[i]->GetBump()), m_Light->GetDirection(), m_Light->GetDiffuseColor(), m_Light->GetAmbientColor());
				if (m_DebugHitbox)
				{
					if (hitboxType == HitBoxType::Cube)
					{
						float x = 1.0f, y = 1.0f, z = 1.0f;
						for (int i = 1; i <= 8; i++)
						{
							Direct3D->GetWorldMatrix(worldMatrix);
							modelManager->Render(Direct3D->GetDeviceContext(), m_GameObjects[0]->GetModel());
							transformationMartix = XMMatrixTranslation(possition.X() + (hitbox.X() * x), possition.Y() + (hitbox.X() * y), possition.Z() + (hitbox.X() * z));
							worldMatrix = XMMatrixMultiply(worldMatrix, transformationMartix);
							ShaderManager->RenderTextureShader(Direct3D->GetDeviceContext(), modelManager->IndexCount(m_GameObjects[0]->GetModel()), worldMatrix, viewMatrix, projectionMatrix, TextureManager->GetTexture(m_GameObjects[0]->GetTexture()));
							if (i % 2 == 0)
								x *= -1.0f;
							else
								z *= -1.0f;
							if (i % 4 == 0)
								y *= -1.0f;
						}
					}
					else if (hitboxType == HitBoxType::Rectangle)
					{
						float x = 1.0f, y = 1.0f, z = 1.0f;

						for (int i = 1; i <= 8; i++)
						{
							Direct3D->GetWorldMatrix(worldMatrix);
							modelManager->Render(Direct3D->GetDeviceContext(), m_GameObjects[0]->GetModel());
							transformationMartix = XMMatrixTranslation(possition.X() + (hitbox.X() * x), possition.Y() + (hitbox.Y() * y), possition.Z() + (hitbox.Z() * z));
							worldMatrix = XMMatrixMultiply(worldMatrix, transformationMartix);
							ShaderManager->RenderTextureShader(Direct3D->GetDeviceContext(), modelManager->IndexCount(m_GameObjects[0]->GetModel()), worldMatrix, viewMatrix, projectionMatrix, TextureManager->GetTexture(m_GameObjects[0]->GetTexture()));
							if (i % 2 == 0)
								x *= -1.0f;
							else
								z *= -1.0f;
							if (i % 4 == 0)
								y *= -1.0f;
						}
					}
				}
			}
			//*/
		}
	}
	/*
	if (m_DebugHitbox)
	{
		Direct3D->GetWorldMatrix(worldMatrix);
		float x = 1.0f, y = 1.0f, z = 1.0f;
		hitbox = m_Position->Gethitbox();
		possition = m_Position->GetPosition();
		for (int i = 1; i <= 8; i++)
		{
			Direct3D->GetWorldMatrix(worldMatrix);
			modelManager->Render(Direct3D->GetDeviceContext(), m_GameObjects[0]->GetModel());
			transformationMartix = XMMatrixTranslation(possition.X() + (hitbox.X() * x), possition.Y() + (hitbox.Y() * y), possition.Z() + (hitbox.Z() * z));
			worldMatrix = XMMatrixMultiply(worldMatrix, transformationMartix);
			ShaderManager->RenderTextureShader(Direct3D->GetDeviceContext(), modelManager->IndexCount(m_GameObjects[0]->GetModel()), worldMatrix, viewMatrix, projectionMatrix, TextureManager->GetTexture(m_GameObjects[0]->GetTexture()));
			if (i % 2 == 0)
				x *= -1.0f;
			else
				z *= -1.0f;
			if (i % 4 == 0)
				y *= -1.0f;
		}

	}
	//*/
	Direct3D->GetWorldMatrix(worldMatrix);
	// Turn off wire frame rendering of the terrain if it was on.
	if (m_wireFrame)
	{
		Direct3D->DisableWireframe();
	}

	// Render the user interface.
	if (m_displayUI)
	{
		result = m_UserInterface->Render(Direct3D, ShaderManager, worldMatrix, baseViewMatrix, orthoMatrix);
		if (!result)
		{
			return false;
		}
	}

	// Present the rendered scene to the screen.
	Direct3D->EndScene();

	return true;
}





#include "ModelManager.h"

ModelManager* ModelManager::instance = 0;

ModelManager::ModelManager()
{
}


ModelManager::~ModelManager()
{
}

void ModelManager::ShutDown()
{
	for (std::map<int, ModelClass*>::iterator it = models.begin(); it != models.end(); ++it)
	{
		it->second->ShutDown();
		delete it->second;
	}
	models.clear();
}

void ModelManager::Initalize()
{
	models = std::map<int, ModelClass*>();
	storedModdels = std::vector<int>();
	instance = this;
}

void ModelManager::Render(ID3D11DeviceContext* deviceContex, int id)
{
	models[id]->Render(deviceContex);
}

void ModelManager::AddModle(ID3D11Device* device, char* filePath, int id,HitBoxType hitboxType,float3 hitboxSize)
{
	ModelClass* NewModel = new ModelClass();
	NewModel->Initialize(device, filePath,hitboxType,hitboxSize);
	models[id] = NewModel;
	storedModdels.push_back(id);
}

ModelClass * ModelManager::GetModel(int id)
{
	if (models.find(id) != models.end())
		return models[id];
	return nullptr;
}

bool ModelManager::ModelLoaded(int id)
{
	if (models.find(id) != models.end())
		return true;
	else
		return false;
}

int ModelManager::parsString(char* fileLocation)
{
	std::string local = fileLocation;
	int id = 0;
	for (int itt = 0, length = local.length(); itt < length; itt++)
	{
		id += local[itt];
	}
	return id * local.length();
}

int ModelManager::IndexCount(int id)
{
	return models[id]->GetIndexCount();
}

std::vector<int> ModelManager::GetModdelList()
{
	return storedModdels;
}
float3 ModelManager::GetHitbox(int id)
{
	return models[id]->GetHitbox();
}

HitBoxType ModelManager::GetHitBoxType(int id)
{
	return models[id]->GetHitBoxType();
}

ModelManager * ModelManager::GetInstance()
{
	return instance;
}

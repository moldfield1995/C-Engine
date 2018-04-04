#include "ModelManager.h"
#include "Utills.h"

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

void ModelManager::AddModle(ID3D11Device* device, char* filePath, int id)
{
	if (ModelLoaded(id))
		return;
	ModelClass* NewModel = new ModelClass();
	if (!NewModel->Initialize(device, filePath))
	{
		std::string file = "Modle Failed to load ";
		file.append(filePath);
		Utills::DebugString(file.data());
		
	}
	models[id] = NewModel;
	storedModdels.push_back(id);
}

int ModelManager::AddModle(ID3D11Device * device , char * filePath)
{
	int id = Utills::ParsString(filePath);
	if (ModelLoaded(id))
		return id;
	ModelClass* NewModel = new ModelClass();
	if (!NewModel->Initialize(device, filePath))
	{
		std::string file = "Modle Failed to load ";
		file.append(filePath);
		Utills::DebugString(file.data());
	}
	models[id] = NewModel;
	storedModdels.push_back(id);
	return id;
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


int ModelManager::IndexCount(int id)
{
	return models[id]->GetIndexCount();
}

std::vector<int> ModelManager::GetModdelList()
{
	return storedModdels;
}

ModelManager * ModelManager::GetInstance()
{
	return instance;
}

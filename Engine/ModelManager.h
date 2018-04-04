#pragma once
#include <map>
#include <vector>
#include "ModelClass.h"

//Created By Matthew Oldfield

class ModelManager
{
public:
	ModelManager();
	~ModelManager();
	void Initalize();
	void ShutDown();
	void Render(ID3D11DeviceContext*, int id);
	void AddModle(ID3D11Device*, char* filePath, int id);
	int AddModle(ID3D11Device*, char* filePath);
	ModelClass* GetModel(int id);
	bool ModelLoaded(int id);
	int IndexCount(int id);
	std::vector<int> GetModdelList();
private:
	static ModelManager* instance;
	std::map<int, ModelClass*> models;
	std::vector<int> storedModdels;
public:
	static ModelManager* GetInstance();
};


#pragma once

#include "core.h"

class GameObject;

class World
{
protected:
	string m_name;
	
	string m_objectTypes[5][5];
	GameObject m_gameObjects[5][5];
public:
	World();
	~World();

	//initialize world using loaded file
	void Init();

	//load details from a file
	void Load(ifstream& _file);
};
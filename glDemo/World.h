#pragma once

#include "core.h"

class GameObject;

class World
{
protected:
	string m_name;
	
	GameObject m_wallMatrix[5][5];
public:
	World();
	~World();

	//initialize world using loaded file
	void Init();

	//load details from a file
	void Load(ifstream& _file);
};
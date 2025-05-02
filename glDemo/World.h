#pragma once

#include "core.h"

class GameObject;
class Scene;

class World
{
protected:
	string m_name;
	

	string m_objectTypes[5][5];
	GameObject* m_gameObjects[5][5];


	glm::vec3 m_position;
public:
	World();
	~World();

	//initialize world using loaded file
	virtual void Init(Scene* scene, float _width, float _height);

	//load details from a file
	virtual void Load(ifstream& _file);

	string GetName() { return m_name; }
};
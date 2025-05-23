#pragma once

#include "core.h"
#include "GameObject.h"

class Scene;

class World : public GameObject
{
protected:
	string m_objectTypes[5][5];
	GameObject* m_gameObjects[5][5];

	glm::vec3 m_positions[5][5];
public:
	World();
	~World();

	void Render() override;

	//initialize world using loaded file
	virtual void Init(Scene* scene, float _width, float _height);

	virtual void Tick(float _dt) override;
	//load details from a file
	virtual void Load(ifstream& _file);

	string GetName() { return m_name; }
};
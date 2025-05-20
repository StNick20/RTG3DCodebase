#include "World.h"
#include "GameObject.h"
#include "Scene.h"
#include "GameObjectFactory.h"
#include "ExampleGO.h"

World::World()
{
	m_pos = glm::vec3(0.0, 0.0, 0.0);
}

World::~World()
{

}

void World::Tick(float _dt)
{

}

void World::Render()
{
	for (int i = 0; i < 5; i++)
	{
		for (int ii = 0; ii < 5; ii++)
		{
			if (m_gameObjects[i][ii] != nullptr)
			{
				m_gameObjects[i][ii]->SetPos(m_positions[i][ii]);
				m_gameObjects[i][ii]->Render();
			}
		}
	}	
}

void World::Init(Scene* scene, float _width, float _height)
{
	for (int i = 0; i <= 4; i++)
	{
		for (int ii = 0; ii <= 4; ii++)
		{
			if (m_objectTypes[i][ii] != "NULL")
			{
				m_gameObjects[i][ii] = scene->GetGameObject(m_objectTypes[i][ii]);
			}
			else
				m_gameObjects[i][ii] = nullptr;
		}
	}

	//set the positions of the objects
	for (int i = 0; i <= 4; i++)
	{
		for (int ii = 0; ii <= 4; ii++)
		{
			if (m_gameObjects[i][ii] != nullptr)
			{
				m_gameObjects[i][ii]->SetPos(m_pos + glm::vec3(i * 2, 0, ii * 2));
			}
		}
	}
}

void World::Load(ifstream& _file)
{
	StringHelp::String(_file, "NAME", m_name);

	//originaly had each one done individually 
	//then realised i could loop it
	for (int i = 0; i <= 4; i++)
	{
		for (int ii = 0; ii <= 4; ii++)
		{
			string key = "OBJ" + to_string(i) + to_string(ii);
			StringHelp::String(_file, key, m_objectTypes[i][ii]);
		}
	}
}
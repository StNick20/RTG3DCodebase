#include "World.h"
#include "GameObject.h"
#include "Scene.h"
#include "GameObjectFactory.h"

World::World()
{

}

World::~World()
{

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
				m_gameObjects[i][ii]->Init(scene, _width, _height);
				scene->AddGameObject(m_gameObjects[i][ii]);//add to the scene so it can be rendered
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
				m_gameObjects[i][ii]->SetPos(glm::vec3(i * 2, 0, ii * 2));
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
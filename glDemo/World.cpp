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

void World::Init(Scene* scene)
{
	for (int i = 0; i <= 4; i++)
		for (int ii = 0; ii <= 4; ii++)
			m_gameObjects[i][ii] = scene->GetGameObject(m_objectTypes[i][ii]);

	//set the positions of the objects
	for (int i = 0; i <= 4; i++)
	{
		for (int ii = 0; ii <= 4; ii++)
		{
			if (m_gameObjects[i][ii] != nullptr)
			{
				m_gameObjects[i][ii]->SetPos(glm::vec3(i * 3, 0, ii * 3));
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
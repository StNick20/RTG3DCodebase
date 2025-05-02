#include "World.h"
#include "GameObject.h"
#include "GameObjectFactory.h"

World::World()
{

}

World::~World()
{

}

void World::Init()
{
	m_gameObjects[0][0] = ;
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
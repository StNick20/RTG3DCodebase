#include "World.h"
#include "GameObject.h"

World::World()
{

}

World::~World()
{

}

void World::Init()
{

}

void World::Load(ifstream& _file)
{
	StringHelp::String(_file, "NAME", m_name);
}
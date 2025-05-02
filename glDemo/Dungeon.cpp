#include "Dungeon.h"
#include "World.h"

Dungeon::Dungeon()
{
	// Initialize the dungeon
	for (int i = 0; i < 5; ++i)
	{
		for (int ii = 0; ii < 5; ++ii)
		{
			m_Parts[i][ii] = nullptr;
		}
	}
}


Dungeon::~Dungeon()
{

}

void Dungeon::Init()
{

}

void Dungeon::Load(ifstream& _file)
{
	World::Load(_file);
}
#include "WorldFactory.h"
#include "World.h"
#include "Dungeon.h"


World* WorldFactory::makeNewWorld(string type)
{
	if (type == "WORLD")
	{
		return new World();
	}
	if (type == "DUNGEON")
	{
		return new Dungeon();
	}
	else
	{
		return nullptr;
	}
}
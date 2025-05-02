#pragma once
#include "core.h"

class World;

class WorldFactory
{
public:
	static World* makeNewWorld(string type);
};
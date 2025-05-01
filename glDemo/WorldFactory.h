#pragma once
#include "core.h"

class World;

class WorldFactory
{
protected:
	World* makeNew(string type);
};
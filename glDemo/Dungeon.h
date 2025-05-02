#pragma once
#include "World.h"
#include "Scene.h"

class Dungeon : public World
{
protected:
	World* m_Parts[5][5];
public:
	Dungeon();
	~Dungeon();

	void Init(Scene* scene) override;
	void Load(ifstream& _file) override;


};

#pragma once
#include "World.h"

class Dungeon : public World
{
protected:
	World* m_Parts[5][5];
public:
	Dungeon();
	~Dungeon();

	void Init() override;
	void Load(ifstream& _file) override;


};

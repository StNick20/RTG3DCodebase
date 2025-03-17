#pragma once

#include "core.h"
#include "Model.h"

class Cube : public Model
{
public:

	Cube();
	~Cube();

	void Load(ifstream& _file);

	void Render();
};
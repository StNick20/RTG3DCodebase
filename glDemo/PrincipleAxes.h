#pragma once

#include "core.h"
#include "Model.h"



class CGPrincipleAxes : public Model {
public:

	CGPrincipleAxes();
	~CGPrincipleAxes();

	void Load(ifstream& _file);
	void Render(/*bool _showZAxis = true*/);
};

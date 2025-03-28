#pragma once
#include "core.h"
#include "DirectionLight.h"

class PointLight : public DirectionLight
{
private:

public:
	PointLight();
	~PointLight();

	glm::vec3 CalculateDirection();

	void Load(ifstream& _file) override;
	void SetRenderValues(unsigned int _prog) override;
};
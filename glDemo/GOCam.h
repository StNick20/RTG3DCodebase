#pragma once
#include "Core.h"
#include "ExampleGO.h"
class FirstPersonCamera;


class GOCam : public ExampleGO
{
protected:
	FirstPersonCamera* m_FPC;
	vec3 m_camOffset;

public:
	GOCam();
	~GOCam();

	void Load(ifstream& _file);
	void Init(Scene* _scene, float _Width, float _Height);
	void Tick(float _dt);
};
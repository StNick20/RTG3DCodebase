#pragma once
#include "Light.h"

//a simple directional light
//essentially only has one difference a direction variable
class DirectionLight :
	public Light
{
public:
	DirectionLight();
	~DirectionLight();

	//load from manifest
	virtual void Load(ifstream& _file);

	//set render values
	virtual void SetRenderValues(unsigned int _prog);


	//TODO: We don't have our own tick
	// a nice feature would be a day / night cycle effect 
	void Tick(float _dt);

protected:
	vec3 m_direction;

	//for day night cycle
	float time;

	vec3 m_OriginalCol;

	//set max time for day night cycle too 10 minutes
	const float maxTime = 60;
	const float halfTime = maxTime / 2.0f;
};


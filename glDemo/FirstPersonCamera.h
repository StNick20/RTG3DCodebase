#pragma once
#include "core.h"
#include "Camera.h"


class FirstPersonCamera : public Camera
{
private:

public:
	FirstPersonCamera();
	~FirstPersonCamera();

	void Init(float _w, float _h, Scene* _scene);
	
	void Tick(float _dt, float aspectRatio);

	void Load(ifstream& _file);


};
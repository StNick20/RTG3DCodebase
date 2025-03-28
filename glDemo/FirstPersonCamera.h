#pragma once
#include "core.h"
#include "ArcballCamera.h"
#include "Camera.h"


class FirstPersonCamera : public ArcballCamera
{
public:
	FirstPersonCamera();
	~FirstPersonCamera();

	void Init(float _w, float _h, Scene* _scene);
	
	void Tick(float _dt, float aspectRatio);

	void Load(ifstream& _file);

	void rotateCamera(float _dTheta, float _dPhi) override;

	void Move(glm::vec3 _d);
	
	glm::vec3 GetForward();
	glm::vec3 GetRight();
};
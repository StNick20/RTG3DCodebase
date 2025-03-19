#pragma once
#include "core.h"
#include "Camera.h"

class OrthoCam : public Camera
{
private:
	float m_orthoWidth;
	float m_orthoHeight;

public:

	OrthoCam();
	~OrthoCam();

	void Init(float _screenWidth, float _screenHeight, Scene* _scene) { Camera::Init(_screenWidth, _screenHeight, _scene); }
	void Tick(float _dt, float aspectRatio) override;
	void Load(ifstream& _file);

	//override the base class function so that the look at point moves with the camera
	void Move(glm::vec3 _d) override; 


};
#pragma once
#include "core.h"
#include "Camera.h"

class GameObject;

class FirstPersonCamera : public Camera
{
protected:
	GameObject* m_object;
	string m_objectName;

	glm::vec3 m_offset;

public:
	FirstPersonCamera();
	~FirstPersonCamera();

	void Init(float _w, float _h, Scene* _scene);
	
	void Tick(float _dt, float aspectRatio);

	void Load(ifstream& _file);


	void Move(glm::vec3 _d);
	
	glm::vec3 GetForward();
	glm::vec3 GetRight();


};
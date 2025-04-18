#include "FirstPersonCamera.h"
#include "Scene.h"
#include "GameObject.h"
#include "ArcballCamera.h"
#include "Collider.h"

FirstPersonCamera::FirstPersonCamera()
{
	m_type = "FPC";
}

FirstPersonCamera::FirstPersonCamera(string m_name, GameObject* m_object, glm::vec3 m_offset)
{
	m_type = "FPC";
	this->m_name = m_name;
	m_theta = 0.0;
	m_phi = 0.0;
	m_radius = 10.0;
	m_fov = 45.0;
	m_near = 0.5;
	m_far = 100.0;
	this->m_object = m_object;
	this->m_offset = m_offset;
}

FirstPersonCamera::~FirstPersonCamera()
{
}

void FirstPersonCamera::Load(ifstream& _file)
{
	ArcballCamera::Load(_file);
	StringHelp::String(_file, "OBJECT", m_objectName);
	StringHelp::Float3(_file, "OFFSET", m_offset.x, m_offset.y, m_offset.z);
}

void FirstPersonCamera::Tick(float dt, float aspectRatio)
{
	setAspect(aspectRatio);

	const float theta_ = glm::radians<float>(m_theta);
	const float phi_ = glm::radians<float>(m_phi);

	m_lookAt = m_pos + glm::vec3(sinf(phi_) * cosf(theta_), sinf(theta_), cosf(phi_) * cosf(theta_));

	// calculate view and projection transform matrices
	m_viewMatrix = glm::lookAt(m_pos, m_lookAt, vec3(0, 1, 0));
	m_projectionMatrix = glm::perspective(glm::radians<float>(m_fovY), m_aspect, m_nearPlane, m_farPlane);
}

void FirstPersonCamera::Init(float _w, float _h, Scene* scene)
{
	ArcballCamera::Init(_w, _h, scene);
	if(m_objectName != "")
		m_object = scene->GetGameObject(m_objectName);

	m_pos = m_object->GetPos() + m_offset;
}

void FirstPersonCamera::rotateCamera(float _dTheta, float _dPhi)
{
	m_theta += _dTheta;
	m_phi += _dPhi;

	if (_dTheta > 45)
		_dTheta = 45;
	else if(_dTheta < -45)
		_dTheta = -45;

	calculateDerivedValues();	

	//this does not work :(
	m_object->Rotate(GetForward());
}

void FirstPersonCamera::Move(glm::vec3 _d)
{	
	glm::vec3 forward = GetForward();
	glm::vec3 right = GetRight();
	glm::vec3 movement = glm::vec3(0.0, 0.0, 0.0);

	if (_d.x != 0.0)
		movement = forward * _d.x;
	else if (_d.z != 0.0)
		movement = right * _d.z;

	m_pos += movement;
	m_lookAt += movement;

	m_object->Move(m_pos - m_offset);

	if (m_object->GetCollider()->checkColliders())
	{
		m_pos -= movement;
		m_lookAt -= movement;
		m_object->Move(m_pos - m_offset);
	}
}

glm::vec3 FirstPersonCamera::GetForward()
{
	glm::vec3 forward = glm::normalize(m_lookAt - m_pos);

	return forward;
}

glm::vec3 FirstPersonCamera::GetRight()
{
	glm::vec3 right = glm::normalize(glm::cross(GetForward(), glm::vec3(0.0, 1.0, 0.0)));

	return right;
}


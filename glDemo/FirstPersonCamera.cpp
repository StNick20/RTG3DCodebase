#include "FirstPersonCamera.h"
#include "ArcballCamera.h"

FirstPersonCamera::FirstPersonCamera()
{
	m_type = "FPC";
}

FirstPersonCamera::~FirstPersonCamera()
{
}

void FirstPersonCamera::Load(ifstream& _file)
{
	ArcballCamera::Load(_file);
	StringHelp::Float3(_file, "POS", m_pos.x, m_pos.y, m_pos.z);

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
}

void FirstPersonCamera::rotateCamera(float _dTheta, float _dPhi)
{
	m_theta += _dTheta;
	m_phi += _dPhi;

	if (_dTheta > 45)
		_dTheta = 65;
	else if(_dTheta < -45)
		_dTheta = -65;

	calculateDerivedValues();	
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
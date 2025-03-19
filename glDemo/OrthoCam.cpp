#include "OrthoCam.h"

OrthoCam::OrthoCam()
{
	m_type = "ORTHO";
}

OrthoCam::~OrthoCam()
{

}

void OrthoCam::Load(ifstream& _file)
{
	StringHelp::String(_file, "NAME", m_name);
	StringHelp::Float3(_file, "POS", m_pos.x, m_pos.y, m_pos.z);
	StringHelp::Float3(_file, "LOOKAT", m_lookAt.x, m_lookAt.y, m_lookAt.z);
	StringHelp::Float(_file, "FOV", m_fov);
	StringHelp::Float(_file, "NEAR", m_near);
	StringHelp::Float(_file, "FAR", m_far);
}

void OrthoCam::Tick(float _dt, float aspectRatio)
{
	aspect_ratio = aspectRatio;
	m_viewMatrix = glm::lookAt(m_pos, m_lookAt, vec3(0, 1, 0));
	m_projectionMatrix = glm::ortho(-10.0f, 10.0f, -1.0f, 10.0f, m_near, m_far);
}

void OrthoCam::Move(glm::vec3 _d)
{
	m_pos += _d;
	m_lookAt += _d;
}
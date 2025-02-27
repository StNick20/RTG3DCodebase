#include "Camera.h"
#include "ArcballCamera.h"
#include "helper.h"
#include <fstream>
#include <iostream>
#include "stringHelp.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////
// constructor
/////////////////////////////////////////////////////////////////////////////////////
Camera::Camera(bool arc)
{
	if (arc)
		m_type = "ARCBALL_CAMERA";
	else
		m_type = "CAMERA";
}

/////////////////////////////////////////////////////////////////////////////////////
// destructor
/////////////////////////////////////////////////////////////////////////////////////
Camera::~Camera()
{
}

/////////////////////////////////////////////////////////////////////////////////////
// Init() - 
/////////////////////////////////////////////////////////////////////////////////////
void Camera::Init(float _screenWidth, float _screenHeight, Scene* _scene)
{
	//TODO: move the calculation of the Projection Matrix to Camera::Tick
	// so that we can do the same rescaling of the aspect ratio to match the current window
	if(m_type == "CAMERA")
		aspect_ratio = _screenWidth / _screenHeight;
	else
	{
		arcCam = new ArcballCamera(m_theta, m_phi, m_radius, m_fov, m_aspect, m_near, m_far);
	}
}

/////////////////////////////////////////////////////////////////////////////////////
// Update() - 
/////////////////////////////////////////////////////////////////////////////////////
void Camera::Tick(float _dt)
{
	m_viewMatrix = glm::lookAt(m_pos, m_lookAt, vec3(0, 1, 0));
	
	m_projectionMatrix = glm::perspective(glm::radians(m_fov), aspect_ratio, m_near, m_far);
}

void Camera::Load(ifstream& _file)
{
	//StringHelp::String(_file, "TYPE", m_type);
	StringHelp::String(_file, "NAME", m_name);
	if (m_type == "CAMERA")
	{
		StringHelp::Float3(_file, "POS", m_pos.x, m_pos.y, m_pos.z);
		StringHelp::Float3(_file, "LOOKAT", m_lookAt.x, m_lookAt.y, m_lookAt.z);
	}
	else if (m_type == "ARCBALL_CAMERA")
	{
		StringHelp::Float(_file, "THETA", m_theta);
		StringHelp::Float(_file, "PHI", m_phi);
		StringHelp::Float(_file, "RADIUS", m_radius);
		StringHelp::Float(_file, "ASPECT", m_aspect);
	}
	StringHelp::Float(_file, "FOV", m_fov);
	StringHelp::Float(_file, "NEAR", m_near);
	StringHelp::Float(_file, "FAR", m_far);
}

//set the base render values for this camera in the shaders
void Camera::SetRenderValues(unsigned int _prog)
{
	GLint loc;

	//matrix for the view transform
	if (Helper::SetUniformLocation(_prog, "viewMatrix", &loc))
		glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(GetView()));

	//matrix for the projection transform
	if (Helper::SetUniformLocation(_prog, "projMatrix", &loc))
		glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(GetProj()));

	//the current camera is at this position
	if (Helper::SetUniformLocation(_prog, "camPos", &loc))
		glUniform3fv(loc, 1, glm::value_ptr(GetPos()));
}

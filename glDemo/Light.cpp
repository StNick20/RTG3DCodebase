#include "core.h"
#include "Light.h"

#include "helper.h"
#include "stringHelp.h"

Light::Light()
{
	m_type = "LIGHT";
	m_pos.x = 0.0f;
	m_pos.y = 0.0f;
	m_pos.z = 0.0f;

	time = 12.0f;
}

void Light::Load(ifstream& _file)
{
	StringHelp::String(_file, "NAME", m_name);
	StringHelp::Float3(_file, "POS", m_pos.x, m_pos.y, m_pos.z);
	StringHelp::Float3(_file, "COL", m_col.x, m_col.y, m_col.z);
	StringHelp::Float3(_file, "AMB", m_amb.x, m_amb.y, m_amb.z);

}

/////////////////////////////////////////////////////////////////////////////////////
// Update() - 
/////////////////////////////////////////////////////////////////////////////////////
void Light::Tick(float _dt)
{
	//day night cycle
	time += _dt;

	if (time > 24.0f)
		time = 0.0f;

	if ((time > 22.0f && time < 24.0f) || (time > 0.0f && time < 4.0f))
	{
		m_amb = glm::vec3(0.1, 0.1, 0.1);
	}
	else if (time > 4.0f && time < 7.0f)
	{
		m_amb = glm::vec3(0.3, 0.3, 0.3);
	}
	else if (time > 7.0f && time < 11.0f)
	{
		m_amb = glm::vec3(0.6, 0.6, 0.6);
	}
	else if (time > 11.0f && time < 14.0f)
	{
		m_amb = glm::vec3(1.0, 1.0, 1.0);
	}
	else if (time > 14.0f && time < 17.0f)
	{
		m_amb = glm::vec3(0.6, 0.6, 0.6);
	}
	else if (time > 17.0f && time < 22.0f)
	{
		m_amb = glm::vec3(0.3, 0.3, 0.3);
	}
}

//send values to the shaders to allow the use of this light
// <m_name>Pos <m_name>Col <m_name>Amb
void Light::SetRenderValues(unsigned int _prog)
{
	GLint loc;
	string posString = m_name + "Pos";
	string colString = m_name + "Col";
	string ambString = m_name + "Amb";

	if (Helper::SetUniformLocation(_prog, posString.c_str(), &loc))
		glUniform3fv(loc, 1, glm::value_ptr(GetPos()));

	if (Helper::SetUniformLocation(_prog, colString.c_str(), &loc))
		glUniform3fv(loc, 1, glm::value_ptr(GetCol()));

	if (Helper::SetUniformLocation(_prog, ambString.c_str(), &loc))
		glUniform3fv(loc, 1, glm::value_ptr(GetAmb()));
}

#include "core.h"
#include "DirectionLight.h"
#include "helper.h"
#include "stringHelp.h"

DirectionLight::DirectionLight()
{
	m_type = "DIRECTION";
	m_pos = vec3(0.0, 0.0, 0.0);
	m_direction = vec3(0.0, 1.0, 0.0);

	time = halfTime;
}

DirectionLight::~DirectionLight()
{
}

void DirectionLight::Load(ifstream& _file)
{
	Light::Load(_file);
	StringHelp::Float3(_file, "DIRECTION", m_direction.x, m_direction.y, m_direction.z);

	m_OriginalCol = m_col;
}

void DirectionLight::SetRenderValues(unsigned int _prog)
{
	//still need to tell the shader about the basic light data
	Light::SetRenderValues(_prog);

	GLint loc;
	string dirString = m_name + "Dir";//only thing I add is a direction

	if (Helper::SetUniformLocation(_prog, dirString.c_str(), &loc))
		glUniform3fv(loc, 1, glm::value_ptr(m_direction));
}

void DirectionLight::Tick(float _dt)
{
	float factor;

	//day night cycle
	time += _dt;

	if (time > maxTime)
		time = 0.0f;

	if (time <= halfTime)
	{
		factor = (time / halfTime);
	}
	else
	{
		factor = (1 - ((time - halfTime) / halfTime));
	}
	
	m_col = m_OriginalCol * factor;

	m_col.r = clamp(m_col.r, 0.1f, 1.0f);
	m_col.y = clamp(m_col.y, 0.1f, 1.0f);
	m_col.z = clamp(m_col.z, 0.1f, 1.0f);

	std::cout << m_col.x << ", " << m_col.y << ", " << m_col.z << endl;
	std::cout << (time / 12) << endl;
}
#include "PointLight.h"
#include "helper.h"

PointLight::PointLight()
{
	m_type = "PNTLIGHT";
	m_pos = vec3(0.0, 0.0, 0.0);
	m_col = vec3(1.0, 1.0, 1.0);
	m_amb = vec3(0.1, 0.1, 0.1);
}

PointLight::~PointLight()
{

}

void PointLight::Load(ifstream& _file)
{
	Light::Load(_file);
}

void PointLight::SetRenderValues(unsigned int _prog)
{
	Light::SetRenderValues(_prog);

	GLint loc;
	string posString = m_name + "Pos";
	string colString = m_name + "Col";
	string ambString = m_name + "Amb";

	if (Helper::SetUniformLocation(_prog, posString.c_str(), &loc))
		glUniform3fv(loc, 1, glm::value_ptr(m_pos));

	if (Helper::SetUniformLocation(_prog, colString.c_str(), &loc))
		glUniform3fv(loc, 1, glm::value_ptr(m_col));

	if (Helper::SetUniformLocation(_prog, ambString.c_str(), &loc))
		glUniform3fv(loc, 1, glm::value_ptr(m_amb));
}

//glm::vec3 PointLight::CalculateDirection()
//{
//	//need to use something from texture-directional.frag/.vert to calculate the direction
//	return glm::normalize(fragmentPos - m_pos);
//}
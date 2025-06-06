#include "core.h"
#include "GameObject.h"
#include "stringHelp.h"
#include "helper.h"
#include "Collider.h"

using namespace glm;

GameObject::GameObject()
{
	m_type = "GAMEOBJECT";

	m_collider = new Collider;
}

GameObject::GameObject(GameObject* _object)
{
	m_type = "GAMEOBJECT";
	m_pos = _object->m_pos;
	m_rot = _object->m_rot;
	m_scale = _object->m_scale;
	m_rot_incr = _object->m_rot_incr;
}

GameObject::~GameObject()
{
}

void GameObject::Load(ifstream& _file)
{
	StringHelp::String(_file, "NAME", m_name);
	StringHelp::Float3(_file, "POS", m_pos.x, m_pos.y, m_pos.z);
	StringHelp::Float3(_file, "ROT", m_rot.x, m_rot.y, m_rot.z);
	StringHelp::Float3(_file, "SCALE", m_scale.x, m_scale.y, m_scale.z);
	StringHelp::Float3(_file, "ROT INC", m_rot_incr.x, m_rot_incr.y, m_rot_incr.z);
}

void GameObject::Tick(float _dt)
{
	m_rot += m_rot_incr;

	m_worldMatrix = glm::translate(mat4(1.0), vec3(m_pos));
	m_worldMatrix = glm::rotate(m_worldMatrix, glm::radians(m_rot.x), glm::vec3(1.0f, 0.0f, 0.0f));
	m_worldMatrix = glm::rotate(m_worldMatrix, glm::radians(m_rot.y), glm::vec3(0.0f, 1.0f, 0.0f));
	m_worldMatrix = glm::rotate(m_worldMatrix, glm::radians(m_rot.z), glm::vec3(0.0f, 0.0f, 1.0f));

	m_worldMatrix = glm::scale(m_worldMatrix, glm::vec3(m_scale));

	m_collider->SetPos(this->GetPos());
}

void GameObject::PreRender()
{
	// Setup model transform
	GLint pLocation;
	Helper::SetUniformLocation(m_ShaderProg, "modelMatrix", &pLocation);
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, (GLfloat*)&m_worldMatrix);
}

void GameObject::Render()
{
	//I have nothing to draw
}

void GameObject::Init(Scene* _scene, float _Width, float _Height)
{
	//I have nothing to link up to
}

void GameObject::Move(glm::vec3 _pos)
{
	m_pos = _pos;
}

void GameObject::Rotate(glm::vec3 _rot)
{
	m_rot = _rot;
}
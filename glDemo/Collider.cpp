#include "Collider.h"
#include "Scene.h"

Collider::Collider()
{
	m_pos = glm::vec3(0.0, 0.0, 0.0);
	m_scale = glm::vec3(0.0, 0.0, 0.0);
}

Collider::~Collider()
{

}

void Collider::Init(Scene* _scene, glm::vec3 _pos, glm::vec3 _scale)
{
	m_pos = _pos;
	m_scale = _scale;

	m_Colliders = _scene->GetColliders();
}

bool Collider::CheckCollision(Collider* _other)
{
	if(_other == nullptr)
		return false;

	//check if within the x bound
	if (_other->GetPos().x <= m_pos.x + (m_scale.x / 2) || _other->GetPos().x >= m_pos.x - (m_scale.x / 2))
	{
		return true;
	}

	//check if within the y bound
	if (_other->GetPos().y <= m_pos.y + (m_scale.y / 2) || _other->GetPos().y >= m_pos.y - (m_scale.y / 2))
	{
		return true;
	}

	//check if within the z bound
	if (_other->GetPos().z <= m_pos.z + (m_scale.z / 2) || _other->GetPos().z >= m_pos.z - (m_scale.z / 2))
	{
		return true;
	}
}

void Collider::SetPos(glm::vec3 _pos)
{
	m_pos = _pos;
}

bool Collider::checkColliders()
{
	for (list<Collider*>::iterator it = m_Colliders.begin(); it != m_Colliders.end(); it++)
	{
		if (CheckCollision(*it))
			return true;
	}
	return false;
}
#pragma once
#include "core.h"

class Scene;

class Collider
{
protected:
	glm::vec3 m_pos; //position of the collider
	glm::vec3 m_scale;

	std::list<Collider*> m_Colliders; //list of colliders to check against

public:
	Collider();
	~Collider();

	void Init(Scene* _scene, glm::vec3 _pos, glm::vec3 _scale);

	void SetPos(glm::vec3 _pos);

	glm::vec3 GetPos() { return m_pos; }

	//check if two colliders are colliding
	virtual bool CheckCollision(Collider* _other);

	//loop through all the colliders
	bool checkColliders();

};
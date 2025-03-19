#include "FirstPersonCamera.h"

FirstPersonCamera::FirstPersonCamera()
{

}

FirstPersonCamera::~FirstPersonCamera()
{
}

void FirstPersonCamera::Load(ifstream& _file)
{
	Camera::Load(_file);
}

void FirstPersonCamera::Tick(float dt, float aspectRatio)
{

}

void FirstPersonCamera::Init(float _w, float _h, Scene* scene)
{

}
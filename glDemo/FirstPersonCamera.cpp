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
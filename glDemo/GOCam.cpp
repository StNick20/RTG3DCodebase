#include "GOCam.h"
#include "FirstPersonCamera.h"
#include "Scene.h"

GOCam::GOCam()
{
	m_FPC = nullptr;
}

GOCam::~GOCam()
{

}

void GOCam::Load(ifstream& _file)
{

	ExampleGO::Load(_file);
	StringHelp::Float3(_file, "CAMOFFSET", m_camOffset.x, m_camOffset.y, m_camOffset.z);
}

void GOCam::Init(Scene* _scene, float _Width, float _Height)
{
	ExampleGO::Init(_scene, _Width, _Height);

	m_FPC = new FirstPersonCamera(m_name + "_FPC", this, m_camOffset);
	m_FPC->Init(_Width, _Height, _scene);
	_scene->AddCamera(m_FPC);
}

void GOCam::Tick(float _dt)
{
	ExampleGO::Tick(_dt);
}
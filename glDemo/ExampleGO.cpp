#include "ExampleGO.h"
#include "AIModel.h"
#include "stringHelp.h"
#include "Scene.h"
#include "Shader.h"
#include "Texture.h"
#include "FirstPersonCamera.h"

ExampleGO::ExampleGO()
{

}

ExampleGO::ExampleGO(ExampleGO* _object)
{
	GameObject::GameObject(_object);
	m_ShaderProg = _object->m_ShaderProg;
	m_texture = _object->m_texture;
	m_model = _object->m_model;
}

ExampleGO::~ExampleGO()
{
}

void ExampleGO::Load(ifstream& _file)
{
	GameObject::Load(_file);
	StringHelp::String(_file, "MODEL", m_ModelName);
	StringHelp::String(_file, "TEXTURE", m_TexName);
	StringHelp::String(_file, "SHADER", m_ShaderName);
}

void ExampleGO::Tick(float _dt)
{
	GameObject::Tick(_dt);
}

void ExampleGO::PreRender()
{
	GameObject::PreRender();

	//only thing I need to do is tell the shader about my texture

	glEnable(GL_TEXTURE_2D);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	//TODO: this does sort of replicate stuff in the AIMesh class, could we make them more compatible.

	//TODO: NORMAL MAPS!
}

void ExampleGO::Render()
{
	m_model->Render();
}

void ExampleGO::Init(Scene* _scene, float _Width, float _Height)
{
	m_ShaderProg = _scene->GetShader(m_ShaderName)->GetProg();
	m_texture = _scene->GetTexture(m_TexName)->GetTexID();
	m_model = _scene->GetModel(m_ModelName);
}

#include "World.h"
#include "GameObject.h"

World::World()
{

}

World::~World()
{

}

void World::Init()
{

}

void World::Load(ifstream& _file)
{
	StringHelp::String(_file, "NAME", m_name);

	StringHelp::String(_file, "OBJ00", m_worldMatrix[0][0]);
	StringHelp::String(_file, "OBJ01", m_worldMatrix[0][1]);
	StringHelp::String(_file, "OJB02", m_worldMatrix[0][2]);
	StringHelp::String(_file, "OJB03", m_worldMatrix[0][3]);
	StringHelp::String(_file, "OJB04", m_worldMatrix[0][4]);
	StringHelp::String(_file, "OJB10", m_worldMatrix[1][0]);
	StringHelp::String(_file, "OJB11", m_worldMatrix[1][1]);
	StringHelp::String(_file, "OJB12", m_worldMatrix[1][2]);
	StringHelp::String(_file, "OJB13", m_worldMatrix[1][3]);
	StringHelp::String(_file, "OJB14", m_worldMatrix[1][4]);
	StringHelp::String(_file, "OJB20", m_worldMatrix[2][0]);
	StringHelp::String(_file, "OJB21", m_worldMatrix[2][1]);
	StringHelp::String(_file, "OJB22", m_worldMatrix[2][2]);
	StringHelp::String(_file, "OJB23", m_worldMatrix[2][3]);
	StringHelp::String(_file, "OJB24", m_worldMatrix[2][4]);
	StringHelp::String(_file, "OJB30", m_worldMatrix[3][0]);
	StringHelp::String(_file, "OJB31", m_worldMatrix[3][1]);
	StringHelp::String(_file, "OJB32", m_worldMatrix[3][2]);
	StringHelp::String(_file, "OJB33", m_worldMatrix[3][3]);
	StringHelp::String(_file, "OJB34", m_worldMatrix[3][4]);
	StringHelp::String(_file, "OJB40", m_worldMatrix[4][0]);
	StringHelp::String(_file, "OJB41", m_worldMatrix[4][1]);
	StringHelp::String(_file, "OJB42", m_worldMatrix[4][2]);
	StringHelp::String(_file, "OJB43", m_worldMatrix[4][3]);
	StringHelp::String(_file, "OJB44", m_worldMatrix[4][4]);
}
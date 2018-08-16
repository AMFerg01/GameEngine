#include "Entity.h"

std::vector<Entity> Entity::_entityList;
Entity::Entity(size_t ID) : _ID(ID), _componentMask(0)
{
}

size_t Entity::getID()
{
	return _ID;
}

Entity::Entity() : _componentMask(0)
{

}
uint32_t Entity::getComponentMask()
{
	return _componentMask;
}
std::vector<Entity>& Entity::getEntityList()
{
	return Entity::_entityList;
}
Entity& Entity::create()
{
	Entity e( _entityList.size());
	_entityList.push_back(e);
	return _entityList.back();
}
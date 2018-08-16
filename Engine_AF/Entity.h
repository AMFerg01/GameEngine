#pragma once
#include <SDL.h>
#include <type_traits>
#include <cassert>
#include <vector>
#include "Component.h"

class Entity
{
public:

	template <typename C>
	C& addComponent()
	{
		static_assert(
			std::is_base_of < Component <C>, C >::value,
			"ERROR: Can only ass Component Types to Entities"
			);
		_componentMask = _componentMask | C::getMask();
		return getComponent<C>();
	}
	template<typename C>
	C& getComponent()
	{
		static_assert(std::is_base_of<Component<C>, C>::value, "Error: Can only get Component Types from Entities")
		return C::getComponentWithEntityID(_ID); 
	}
	uint32_t getComponentMask();
	size_t getID();
	static std::vector<Entity>& getEntityList();
	static Entity& create();
private:
	Entity();
	Entity(size_t ID);
	size_t _ID;
	static std::vector<Entity> _entityList;
	uint32_t _componentMask;
	template <typename C>
	void  removeComponent()
	{
	}


};


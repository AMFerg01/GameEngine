#include "RenderingSystem.h"
#include "Position.h"
#include "Sprite.h"
RenderingSystem::RenderingSystem(SDL_Window* window)
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if(renderer == nullptr)
	{
		std::cerr << "Unable to Create Renderer:" << std::endl;
		std::cerr << SDL_GetError() << std::endl;
		system("Pause");
		exit(EXIT_FAILURE);
	}
		componentMask = Position::getMask() | Sprite::getMask();

}

void RenderingSystem::update()
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);

	SDL_RenderClear(renderer);

	for(Entity& entity : Entity::getEntityList())
	{
		if((entity.getComponentMask() & componentMask) == componentMask)
		{
			Position& position = entity.getComponent<Position>();
			Sprite& sprite = entity.getComponent<Sprite>();
		}
	}

	SDL_RenderPresent(renderer);
}

RenderingSystem::~RenderingSystem(void)
{
}

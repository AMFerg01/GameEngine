#include "Engine.h"
#include <SDL.h>
#include <iostream>
#include "Entity.h"
Engine::Engine(void) : quit(false)
{
	if( SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "Unable to Initialize SDL:" << std::endl;
		std::cerr << SDL_GetError() << std::endl;
		system("Pause");
		exit(EXIT_FAILURE);
	}

	

	SDL_Window* window = SDL_CreateWindow(
		"Engine", 
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
		NULL
		);
	if(window == nullptr)
	{
		std::cerr << "Unable to Create Window:" << std::endl;
		std::cerr << SDL_GetError() << std::endl;
		system("Pause");
		exit(EXIT_FAILURE);
	}

	renderingSystem = new RenderingSystem(window);
}
void Engine::start()
{
	Entity e;
	std::cout << "Entity e ComponentMask: " << e.getComponentMask() << std::endl;
	e.addComponent<Position>();
	std::cout << "Entity e ComponentMask: " << e.getComponentMask() << std::endl;
	e.addComponent<Sprite>();
	std::cout << "Entity e ComponentMask: " << e.getComponentMask() << std::endl;
	while(!quit)	
	{
		update();
	}
}
void Engine::update()
{
	SDL_Event e;
	while(SDL_PollEvent(&e) != NULL)
	{
		if(e.type == SDL_QUIT)
		{
			quit = true;
		}
		renderingSystem->update();
	}
}
Engine& Engine::getInstance(void)
{
	static Engine instance;
	return instance;
}

Engine::~Engine(void)
{
	delete renderingSystem;
	SDL_DestroyWindow(window);
	SDL_Quit();
}

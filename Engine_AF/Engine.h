#pragma once
#include <SDL.h>
#include "RenderingSystem.h"
#include "Component.h"
#include "Sprite.h"
#include "Position.h"
class Engine
{
private:
	SDL_Window* window;
	bool quit;
	RenderingSystem* renderingSystem;
	Engine(void);
	~Engine(void);

Engine(Engine& copy);
Engine(Engine&& other);
Engine operator= (Engine& copy);
public:
	static Engine& getInstance(void);
	void start(void);
	void update(void);
};


#pragma once
#include "System.h"
#include <SDL.h>
#include "iostream"
#include "Entity.h"

class RenderingSystem : System<RenderingSystem>
{
public:
	RenderingSystem(SDL_Window* window);
	void update();
	~RenderingSystem(void);
private:
	SDL_Renderer* renderer;
};
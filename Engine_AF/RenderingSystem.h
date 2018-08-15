#pragma once
#include "ISystem.h"
#include <SDL.h>
#include "iostream"

class RenderingSystem : ISystem
{
public:
	RenderingSystem(SDL_Window* window);
	void update();
	~RenderingSystem(void);
private:
	SDL_Renderer* renderer;
};


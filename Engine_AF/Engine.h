#pragma once
#include <SDL.h>
class Engine
{
private:
	SDL_Window* window;
	bool quit;

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


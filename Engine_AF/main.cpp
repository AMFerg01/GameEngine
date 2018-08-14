#include "main.h"
#include <iostream>
#include <SDL.h>
#include "Engine.h"

int main(int argc, char *args[])
{
	Engine::getInstance().start();

	return EXIT_SUCCESS;

}
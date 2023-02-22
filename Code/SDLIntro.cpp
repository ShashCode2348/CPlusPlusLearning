#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>
using namespace std;

int main() {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {						//From here to line 19: Makes sure everything is working,
		cout << "SDL Init falied. " << endl;				//else returns corresponding error code(1/2)
		return 1;
	}
	SDL_Window* window = SDL_CreateWindow("Particle Fire Explosion",		//Title, Position on screen(2), Screen size(2), Flags(This one shows it)
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		//printf("Could not create window: %s\n", SDL_GetError());	cout alternative, something from C. No need for other includes.
		SDL_Quit();
		return 2;
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);	//last one syncs rendering with refreshing
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
		SCREEN_WIDTH, SCREEN_HEIGHT);		//args :the renderer, pixel formatting method(rgba(a->alpha(transparency))),
	//how we write to the texture, size(2)
	if (renderer == NULL) {
		cout << "Could not create renderer" << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}
	if (texture == NULL) {
		cout << "Could not create texture" << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}
	Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];	 //Uint32 is an integer type which stores 4-byte ints(int type does this but not always)
	memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));	//Sets a block of data to a certain value, args: array, value, bytes of data to set
	buffer[30000] = 0xFFFFFFFF;		//An integer in hexadecimal(0x is the prefix)
	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {			//Slower than memset, but can change individual bytes
		buffer[i] = 0xFFFFFFFF;		//The last 2 are alpha(transparecy), but doesn't work
	}
	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32)); //texture, recctangle of update, buffer list, number of bytes in row
	SDL_RenderClear(renderer);		//Clears renderer
	SDL_RenderCopy(renderer, texture, NULL, NULL);		//renderer, texture, specifies how much texture then renderer used correspondingly(NULL -> whole)
	SDL_RenderPresent(renderer);	//Updates renderer(Required to see the results of above)
	bool quit = false;
	SDL_Event event;				//Tracks the events concerning the window
	while (!quit) {					//Another form of 'while(quit == false) {'
		//Update particles
		//Draw particles
		//Check for messages/events(anything that involves the window)
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {  					//This loop checks if the user closed the window
				quit = true;
			}
		}
	}
	cout << "Closing window" << endl;
	delete[] buffer;
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);			//Closes window
	SDL_Quit();							//Closes SDL and its resourcecs(in that program run)
	return 0;
}

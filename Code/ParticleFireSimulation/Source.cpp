#include "Screen.h"
#include <math.h>
#include <stdlib.h>
using namespace std;
using namespace scr;

int main() {
	srand(time(NULL));		//time(NULL) returns time in seconds, srand returns a truly random value seeded on a number
	Screen screen;
	if (screen.init() == false) {
		cout << "Error initialising SDL" << endl;
	}

	Swarm swarm;

	while (true) {
		//Update particles
		//Draw particles

		const Particle* const pParticles = swarm.particles();
		int elapsed = SDL_GetTicks();							//SDL_GetTicks show the time elapsed in milliseconds
		swarm.update(elapsed);
		unsigned char red = (1 + sin(elapsed * 0.0001)) * 128;			//Can never be above 256
		unsigned char green = (1 + cos(elapsed * 0.0004)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];
			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;
			screen.setPixel(x, y, red, green, blue);
		}
		screen.boxBlur();
		//Draw the screen
		screen.update();
		//Check for messages/events(anything that involves the window)
		if (screen.processEvents() == false) {
			break;
		}
	}
	screen.close();
	return 0;
}

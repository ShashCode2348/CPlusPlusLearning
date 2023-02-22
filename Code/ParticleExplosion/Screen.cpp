#include <iostream>
#include <math.h>
#include "Screen.h"
using namespace std;

namespace scr {
	Screen::Screen() :
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL) {
	}

	bool Screen::init() {
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			return false;
		}
		m_window = SDL_CreateWindow("Particle Fire Explosion",		//Title, Position on screen(2), Screen size(2), Flags(This one shows it)
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (m_window == NULL) {
			SDL_Quit();
			return false;
		}
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
			SCREEN_WIDTH, SCREEN_HEIGHT);
		if (m_renderer == NULL) {
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}
		if (m_texture == NULL) {
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}
		m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
		m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
		memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
		memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
		return true;
	}

	void Screen::update() {
		SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);
	}

	bool Screen::processEvents() {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return false;
			}
		}
		return true;
	}

	void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
		if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {		// '||' is the 'or' operator
			return;			//Exits the function without any output
		}
		Uint32 colour = 0;
		colour += red; colour <<= 8;
		colour += green; colour <<= 8;
		colour += blue; colour <<= 8;
		colour += 0xFF;
		m_buffer1[(y * SCREEN_WIDTH) + x] = colour;
	}

	/*Box Blur Effect
		0 0 0
		0 1 0
		0 0 0
		Let these be the colour value of the central pixels and its surroundings(1 is a colour, 0 is black/another colour)
		The values of all of them will be their average, i.e.
		1/9   1/9   1/9
		1/9   1/9   1/9
		1/9   1/9   1/9
		Below is the function*/
	void Screen::boxBlur() {
		//Swap the buffers, so pixel is in m_buffer2 and we are drawing to m_buffer1.
		Uint32* temp = m_buffer1;
		m_buffer1 = m_buffer2;
		m_buffer2 = temp;

		for (int y = 0; y < SCREEN_HEIGHT; y++) {
			for (int x = 0; x < SCREEN_WIDTH; x++) {
				int redTotal = 0;
				int greenTotal = 0;
				int blueTotal = 0;
				for (int row = -1; row <= 1; row++) {
					for (int col = -1; col <= 1; col++) {		//These 4 nested for loops range over each pixel and its surrounding pixels
						int currentX = x + col;
						int currentY = y + row;
						if (currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT) {
							Uint32 colour = m_buffer2[currentY * SCREEN_WIDTH + currentX];
							Uint8 red = colour >> 24; Uint8 green = colour >> 16; Uint8 blue = colour >> 8;
							redTotal += red; greenTotal += green; blueTotal += blue;
						}
					}
				}
				Uint8 red = redTotal / 9; Uint8 green = greenTotal / 9; Uint8 blue = blueTotal / 9;
				setPixel(x, y, red, green, blue);
			}
		}
	}

	void Screen::close() {
		delete[] m_buffer1;
		delete[] m_buffer2;
		SDL_DestroyTexture(m_texture);
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}


	Particle::Particle() :m_x(0), m_y(0) {
		m_direction = (2 * M_PI * rand()) / RAND_MAX;	//As long as either numerator or denominator are double,
		m_speed = (0.04 * rand()) / RAND_MAX;			//double is returned
	}

	Particle::~Particle() {

	}

	void Particle::update(int interval) {
		/*		This will make the particles bounce off the walls(except for the top and bottom where the walls are off screen)
		if (m_x <= -1 || m_x >= 1 || m_y <= -1 || m_y >= 1) {
			if (m_direction >= M_PI) {
				m_direction -= M_PI;
			}
			else {
				m_direction += M_PI;
			}
		}*/
		double xspeed = m_speed * cos(m_direction);
		double yspeed = m_speed * sin(m_direction);
		m_x += xspeed * interval;
		m_y += yspeed * interval;
	}


	Swarm::Swarm() :lastTime(0) {
		m_pParticles = new Particle[NPARTICLES];
	}

	Swarm::~Swarm() {
		delete[] m_pParticles;
	}

	void Swarm::update(int elapsed) {
		int interval = elapsed - lastTime;
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			m_pParticles[i].update(interval);
		}
		lastTime = elapsed;
	}
} /* namespace scr*/

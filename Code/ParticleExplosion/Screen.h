#pragma once
#include <iostream>
#include <stdlib.h>
#define SDL_MAIN_HANDLED
#include <SDL.h>

namespace scr {
	class Screen {
	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 600;
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texture;
		Uint32* m_buffer1;
		Uint32* m_buffer2;
	public:
		Screen();
		bool init();
		void update();
		void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		bool processEvents();
		void boxBlur();
		void close();
	};

	struct Particle {		//A struct is a class, but member vars are public by default, rather than privet in a class
		double m_x;			//Double as although position is int, gradual change can be defined with decimals then rounded off
		double m_y;
		double m_speed;
		double m_direction;
	public:
		Particle();
		~Particle();
		void update(int interval);
	};

	class Swarm {
	public:
		const static int NPARTICLES = 5000;
	private:
		Particle* m_pParticles;
		int lastTime;
	public:
		Swarm();
		~Swarm();
		void update(int elapsed);
		const Particle* const particles() { return m_pParticles; };
	};
} /*namespace scr*/


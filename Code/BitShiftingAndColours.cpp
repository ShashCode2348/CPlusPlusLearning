#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
	unsigned char red = 0x12;           //0x is the hexadecimal prefix
	unsigned char green = 0x34;
	unsigned char blue = 0x56;
	unsigned char alpha = 0xFF;
	unsigned int colour = 0;
	colour += red;
	colour = colour << 8;	//moves the digis in the value 8 bits(1 byte, 2 places) to the left
	colour += green; colour <<= 8;	//bit shifting operator like the others
	colour += blue; colour <<= 8;
	colour += alpha;
	cout << setfill('0') << setw(8) << hex << colour << endl;	//setfill and setw gives extra characters
				//(setw takes the int amount of total chars, setfill the char to put in front(without it would be spaces)
				//hex makes the outputted value be in hex


	//Colour Animation - Doesn't run here but works in Particle Explosion(due to SDL not being initialised here)

	/*
	int elapsed = SDL_GetTicks();						//SDL_GetTicks show the time elapsed in milliseconds
	unsigned char red = (1 + sin(elapsed * 0.0001)) * 128;			//Can never be above 256
	unsigned char green = (1 + cos(elapsed * 0.0004)) * 128;
	unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;
	for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {			//Changes all the pixel colours
		for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
			screen.setPixel(x, y, red, green, blue);
		}
	}*/
	return 0;
}

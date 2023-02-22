#include <iostream>
#include <thread>
#include <chrono>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
using namespace std;

void cb(Fl_Widget* b, void* data) {				//changes window name(idk how, it just does)
	auto win = static_cast<Fl_Window*>(data);
	win->label("Works");
}

int main() {
	Fl::scheme("gtk+");
	auto win = new Fl_Window(190, 100, 800, 600, "Intro");	//screen_pos, size, title
	auto group1 = new Fl_Group(0, 0, 800, 600, "");
	group1->begin();
	auto button = new Fl_Button(160, 200, 80, 40, "Click me");//pos on window, size, text
	button->callback(cb, win);				//calls function(1) when action(2: window means button pressed) occurs
	auto box = new Fl_Box(20, 40, 300, 100, "Hello World");
	box->box(FL_UP_BOX);					//makes the box be drawn on the outside of the widget
	box->labelfont(FL_BOLD + FL_ITALIC);		//Font: can also specify font type directly
	box->labelsize(36);					//font size
	box->labeltype(FL_SHADOW_LABEL);
	group1->end();							//Cannot add any more widgets after this line
	win->show(); //shows window(required)
	Fl::run();
	this_thread::sleep_for(chrono::milliseconds(5000));		//waits 5 seconds(after program closes)
	group1->clear();
	return 0;
}

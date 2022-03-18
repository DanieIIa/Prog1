//g++ drill15_graphing.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15 `fltk-config --ldflags --use-images`

#include "Simple_window.h"
#include "Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x){return cos(x)+slope(x);}

int main(){

try{
	Point t1{100,100};
	Simple_window win{t1, 600, 600, "Function graphs"};
	win.wait_for_button();

	Axis xa{Axis::x, Point{100,300}, 400, 20, "1 == 20 pixels"};
	win.attach(xa);
	xa.set_color(Color::red);
	win.wait_for_button();
	
	Axis ya{Axis::y, Point{300,500}, 400, 20, "1 == 20 pixels"};
	ya.set_color(Color::red);
	win.attach(ya);
	win.wait_for_button();

	Function f1 {one, -10, 11, Point{300, 300}, 400, 20, 20};
	win.attach(f1);
	win.wait_for_button();

	Function f2 {slope, -10, 11, Point{300, 300}, 400, 20, 20};
	win.attach(f2);
	win.wait_for_button();

	Text t {Point{100, 385}, "x/2"};
	win.attach(t);
	win.wait_for_button();

	Function f3 {square, -10, 11, Point{300, 300}, 400, 20, 20};
	win.attach(f3);
	win.wait_for_button();

	Function c {cos, -10, 11, Point{300, 300}, 400, 20, 20};
	win.attach(c);
	c.set_color(Color::blue);
	win.wait_for_button();

	Function sc {sloping_cos, -10, 11, Point{300, 300}, 400, 20, 20};
	win.attach(sc);
	win.wait_for_button();
}catch(exception& e){
		cerr << "exception: " << e.what() << endl;
		return 1;
}catch(...){
	cerr << "error" << endl;
		return 1;
}
	


}

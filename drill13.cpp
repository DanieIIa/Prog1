
/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"
#include "string"
#include "iostream"

using namespace Graph_lib;

int main(){
	try{
		Point t1(300,50);
		Simple_window win(t1,1000, 800, "My window");
		win.wait_for_button();
		
		Lines grid;
		int x_size=800;
		int y_size=800;
		for(int i=100; i<=x_size; i+=100){
			grid.add(Point(i,0), Point(i,y_size));
			grid.add(Point(0,i), Point(x_size,i));
		}
		
		win.attach(grid);
		win.wait_for_button();
		
		Vector_ref<Rectangle>v;
		for(int i=0; i<8; i++){
			v.push_back(new Rectangle(Point(i*100,i*100),100,100));     
			v[v.size()-1].set_fill_color(Color::red);
			win.attach(v[v.size()-1]);
		}
		win.wait_for_button();

		Vector_ref<Image>im;
		for(int i=0; i<3; i++){
			im.push_back(new Image(Point{(i+1)*200, i*150},"badge.jpg"));
			im[im.size()-1].set_mask(Point{100, 100}, 200, 200);
			win.attach(im[im.size()-1]);
		}
		win.wait_for_button();
		
		
		
		srand(time(NULL));
		int x = 0, y = 0;
		Image ii{Point{0, 0},"badge.jpg"};
		ii.set_mask(Point{100, 100}, 100, 100);
		win.attach(ii);
		while(true){	
			int xx = (rand() %7+1)*100;
			int yy = (rand() %7+1)*100;
			ii.move(xx-x, yy-y);
			x = xx;
			y = yy;
			win.wait_for_button();
		}
		

	}
	catch(exception& e){
		cerr<<"exception: "<<e.what()<<endl;
		return 1;
		}
	catch(...){
		cerr<<"exception \n";
		return 2;
	}


}

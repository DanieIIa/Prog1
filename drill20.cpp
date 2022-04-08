#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;


template<typename C>
void print_contents(const C& c){
	for(auto & a: c){
		cout << a << ' ';
	}
	cout << endl;
}

template<typename C>
void inc(C& c, int n){
	for(auto & a: c) 
		a+=n;
}

template<typename Iter1, typename Iter2>
Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2 ){
	for(Iter1 p = f1; p != e1; ++p){
		*f2 = *p;
		f2++;
		//*f2++=*p rövidebben
	} 
	return f2;
}

template<typename InputIt, typename T>
InputIt orai_find(InputIt f, InputIt l, const T& value){
	for(InputIt p = f; p != l; ++p){
		if(*f == value){
			return f;
		}
	}
	return l;
}


int main(){
	
	constexpr int size = 10;
	int arr[size];
	for(int i = 0; i < size; i++) arr[i] = i;
	
	std::array<int, size> ai;
	std::copy(arr,arr+size,ai.begin());
	
	std::vector<int> vi(size); 
	std::copy(arr,arr+size,vi.begin());
	
	std::list<int> li(size); 
	std::copy(arr,arr+size,li.begin());
	
	std::array<int, size> ai2 = ai;
	std::vector<int> vi2 = vi;
	std::list<int> li2 = li;
	
	print_contents(ai2);
	print_contents(vi2);
	print_contents(li2);
	
	inc(ai2, 2);
	inc(vi2, 3);
	inc(li2, 5);
	
	print_contents(ai2);
	print_contents(vi2);
	print_contents(li2);
	
	orai_copy(ai2.begin(), ai2.end(), vi2.begin());
	orai_copy(li2.begin(), li2.end(), ai2.begin());
	
	print_contents(ai2);
	print_contents(vi2);
	print_contents(li2);
	
	//int *p = orai_find(ai.begin(), ai.end(), 3);

	vector<int>::iterator vit;
	vit = find(vi2.begin(), vi2.end(), 3);
	cout << "Is the vector contain the 3?\n";

	if(vit != vi2.end()){
		cout << "Found at: " << distance(vi2.begin(), vit) << endl << endl;
	}else{
		cout<< "Not found" << endl << endl;
	}	
	cout << "Is the vector contain the 27?\n";

	std::list<int>::iterator lit;
	lit = std::find(li2.begin(), li2.end(), 27);

	if(lit != li2.end()){
		cout << "Found at: " << distance(li2.begin(), lit) << endl << endl;
	}else{
		cout<< "Not found" << endl << endl;
	}

	

}

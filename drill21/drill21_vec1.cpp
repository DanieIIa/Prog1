#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <numeric>
#include <fstream>
#include <algorithm>
#include <list>
#include <iterator>


struct Item{
	std::string name;
	int iid;
	double value; 
	Item(std::string n, int i, double v): name{n}, iid{i}, value{v} {}
};
struct comp_name{
	bool operator()(const Item& a, const Item& b){
		return a.name < b.name;
	}
};
struct comp_iid{
	bool operator()(const Item & a, const Item & b){
		return a.iid < b.iid;
	}
};
struct comp_value{
	bool operator()(const Item & a, const Item & b){
		return a.value > b.value;
	}
};
void print(const std::vector<Item> v){
	for(const Item& a : v){
		std::cout  << a.name << " " << a.iid << " " << a.value << std::endl;
	}
	std::cout << std::endl;
}

void print_list(const std::list<Item> v){
	for(const Item& a : v){
		std::cout  << a.name << " " << a.iid << " " << a.value << std::endl;
	}
	std::cout << std::endl;
}
struct find_name{
	std::string name;
	find_name(std::string& n): name{n}{};
	bool operator()(const Item& a){
		return a.name == name;
	}
};

struct find_iid{
	int id;
	find_iid(int& n): id{n}{};
	bool operator()(const Item& a){
		return a.iid == id;
	}
};

int main(){
try{

	std::cout << "Vector:" << std::endl; 
	const std::string input = "inp.txt";
	std::ifstream ifs{input};
	if(!ifs) throw std::runtime_error("Could not read from file: " + input);
	
	std::vector<Item> vi;
	for(int i = 0; i < 10; ++i){
		std::string n;
		int id;
		double v;
		ifs >> n >> id >> v;
		vi.push_back({n,id,v});
	}

	print(vi);
	std::cout << "Order by name:" << std::endl; 
	sort(vi.begin(), vi.end(), comp_name());
	print(vi);

	std::cout << "Order by id:" << std::endl; 
	sort(vi.begin(), vi.end(), comp_iid());
	print(vi);

	std::cout << "Order by value:" << std::endl; 
	sort(vi.begin(), vi.end(), comp_value());
	print(vi);


	vi.push_back({"horse shoe", 99, 12.34});
	vi.push_back({"Canon S400", 9988, 499.95});
	print(vi);
	
	for(int i = 0; i < vi.size(); i++){
		if(vi[i].name == "aha") vi.erase(vi.begin() + i);
		if(vi[i].name == "horse shoe") vi.erase(vi.begin() + i);
	}
	print(vi);

	for(int i = 0; i < vi.size(); i++){
		if(vi[i].iid == 1) vi.erase(vi.begin() + i);
		if(vi[i].iid == 5) vi.erase(vi.begin() + i);
	}
	print(vi);

	std::cout << "List:" << std::endl; 

	const std::string input2 = "inp2.txt";
	std::ifstream ifs2{input2};
	if(!ifs2) throw std::runtime_error("Could not read from file: " + input2);

	std::list<Item> li;
	for(int i = 0; i < 10; ++i){
		std::string n;
		int id;
		double v;
		ifs2 >> n >> id >> v;
		li.push_back({n,id,v});
	}
	print_list(li);

	std::cout << "Order by name:" << std::endl; 
	li.sort(comp_name());
	print_list(li);

	std::cout << "Order by id:" << std::endl; 
	li.sort(comp_iid());
	print_list(li);

	std::cout << "Order by value:" << std::endl; 
	li.sort(comp_value());
	print_list(li);

	li.push_back({"horse shoe", 99, 12.34});
	li.push_back({"Canon S400", 9988, 499.95});
	print_list(li);

	std::string name1 = "aha";
	std::string name2 = "likr";
	std::list<Item>::iterator lit = find_if(li.begin(), li.end(), find_name(name1));
	li.erase(lit);

	lit = find_if(li.begin(), li.end(), find_name(name2));
	li.erase(lit);

	print_list(li);

	int num1 = 3;
	int num2 = 7;
	lit = find_if(li.begin(), li.end(), find_iid(num1));
	li.erase(lit);
	lit = find_if(li.begin(), li.end(), find_iid(num2));
	li.erase(lit);
	print_list(li);



}catch(std::exception& e){
	std::cerr << "Exception: " << e.what() << std::endl;
	return 1;
}catch(...){
	std::cerr << "Unknow exception " << std::endl;
		return 2;
}


}
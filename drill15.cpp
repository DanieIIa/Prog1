#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;

class Person{
	public: 
		
		Person(){};
		//Person(string name,  int a): n{n}, a{a}
		Person(string f, string l, int a):f{f}, l{l}, a{a}{
			if(a < 0 || a >= 150) throw runtime_error("Invalid age");
			string n = f+l;
			for(int i = 0; i < n.length(); i++){
			
				if(n[i] == ';' || n[i] == ':' || n[i] == '"' ||
					n[i] == '\'' || n[i] == '[' || n[i] == ']' ||
					n[i] == '*' || n[i] == '&' || n[i] == '^' ||
					n[i] == '%' || n[i] == '$' || n[i] == '#' ||
					n[i] == '@' || n[i] == '!'
				) throw runtime_error("Invalid name");
			}
		};
		string first() const {return f;}
		string last() const {return l;}
		int age() const {return a;}
	private:
		//string n = " ";
		string f;
		string l;
		int a;	
	
	
	
};
ostream &operator<<(ostream & os, Person &p){
		return os << p.first() << " " << p.last()<< " " << p.age() << endl;
	}
istream &operator>>(istream & is, Person &p){
		string f;
		string l;
		int a;
		is >> f >> l >> a;
		p = Person(f,l,a);
		
		return is;
}
 

int main(){
	
	Person p("Goofy","Asd", 63);
	cout <<p.first() << " " << p.last() <<" "<<p.age() << endl;
	Person p2;
	cin >> p2;
	cout << p2 << endl;
	
	vector<Person> vec;
	for(Person p; cin>>p;){ //while(cin >> p)
		if(p.first() == "end") break;
		vec.push_back(p);
	}
	for(Person p:vec){
		cout << p;
	}
	
	
}

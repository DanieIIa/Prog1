#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T> struct S{
	S(T vv = 0): val{vv}{} 
	T& get();
	const T& get()const;
	void set(T new_t){val = new_t;}
	void operator=(const T&);
	
	private:
	T val;
		
};

template<typename T>
T& S<T>::get(){
	return val;
};
template<typename T>
const T& S<T>::get()const{
	return val;
};
template<typename T>
void S<T>::operator=(const T& s){
	val = s;
}
template<typename T> void read_val(T& v){
	cin >> v;
}

template<typename T>
istream& operator>>(istream &is,  vector<T>& vec){
	char ch = 0;
	is >> ch;
	if(ch != '{'){
		is.unget();
		return is;
	} 
	for(T val; is >> val;){
		vec.push_back(val);
		is >> ch;
		if(ch != ',') break;
	}
	return is;
}

template<typename T>
ostream& operator<<(ostream &os,  vector<T> &vec){
	os << '{';
	for(int i = 0; i < vec.size(); ++i){
		os << vec[i] << (i < vec.size()-1 ? ", ": " ");
	}
	os << '}' << endl;
	return os;
}

int main(){
	S<int> s;	
	S<int> si{37};
	S<char> sc{'c'};
	S<double> sd{3.2};
	S<std::string> ss{"hello"};
	S<vector<int>> svi{std::vector<int>{1,1,2,3,5,8}};
	
	cout << "S<int>: " << s.get() << endl;
	cout << "S<int>: " << si.get() << endl;
	cout << "S<char>: " << sc.get() << endl;
	cout << "S<double>: " << sd.get() << endl;
	cout << "S<string>: " << ss.get() << endl;
	//cout << "S<vector<int>>: " << svi.val << endl;
	for(auto& a: svi.get()){
		cout << a << " ";
	}
	cout << endl;
	S<int> sett;
	sett.set(6);
	cout << "S<int> setteres " << sett.get() << endl;
	
	si = 30;
	cout << "S<int>: " << si.get() << endl;
	
	int ii;
	read_val(ii);
	S<int> si2{ii};
	
	double id;
	read_val(id);
	S<double> sd2{id};
	
	string is;
	read_val(is);
	S<string> ss2{is};

	cout << "S<int>: " << si2.get() << endl;
	cout << "S<double>: " << sd2.get() << endl;
	cout << "S<string>: " << ss2.get() << endl;
	
	vector<int> vec;
	//read_val(vec);
	cin >> vec;
	cout << vec << endl;
	S<vector<int>> svec{vec};
	cout << svec.get() << endl;
	
}

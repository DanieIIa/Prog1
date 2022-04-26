// map<int, strink> kulcs érték pár

#include <iostream>
#include <string>
#include <map>
#include <numeric>
#include <stdexcept>


void read_map(std::map<std::string, int>& m){
	std::string s;
	int i = 0;
	
	while(m.size()<10){
		std::cin >> s >> i;
		//map[s] = i; ugyanaz mint az alattalevo
		m.insert(std::make_pair(s,i));
	}
}

template<typename K, typename V>
void print(const std::map<K,V>& m){

	for(std::pair<K,V> a : m){
	//for(auto& a : m){
		std::cout << a.first << '\t' << a.second << std::endl;
	}
}

using namespace std;

int main(){
try{
	std::map<std::string, int> msi;
	msi["a"] = 1;
	msi["b"] = 2;
	msi["abc"] = 45;
	msi["x"] = 23;
	msi["g"] = 41;
	msi["wert"] = 92;
	msi["j"] = 30;
	msi["po"] = 11;
	msi["px"] = 67;
	msi["ac"] = 4;
	print(msi);
	cout << endl;
	msi.erase("a");
	print(msi);
	
	msi.erase(msi.begin(), msi.end());
	print(msi);
	std::cout << "10 név érték pár megadása: " << std::endl;
	read_map(msi);
	print(msi);
	
	int sum1 = std::accumulate(msi.begin(), msi.end(),0,[](int sum, const std::pair<string, int>& p){
							return sum+= p.second;});
	
	int sum2 = 0;
	for(std::pair<std::string, int> a: msi){
		sum2 += a.second;
	}
	std::cout << "sum1 = " << sum2 << std::endl;
	std::cout << "sum2 = " << sum1 << std::endl;
	
	std::map<int, std::string> mis; 
	
	for(std::pair<std::string, int> a : msi){
		mis[a.second] = a.first;
		//mis.insert(std::make_pair(a.second, a.first));
	}
	std::cout << "mis map: " << endl;
	print(mis);
} catch(exception& e){
	cerr << "Exception: " << e.what() << endl;
	return 1;
}catch(...){
	cerr << "Exception " << endl;
		return 2;
}

}

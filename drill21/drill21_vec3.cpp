#include <iostream>
#include <vector>
#include <stdexcept>
#include <numeric>
#include <fstream>
#include <algorithm>

class Less_than{
	double v;
	public: 
		Less_than(double vv) : v{vv}{}
		bool operator()(const double val){return val < v;}
};

template<typename C>
void print(const C& c, char sep = '\n'){
	std::cout<<"Container elements:\n";
	
	for(const auto elem : c){
		std::cout << elem << sep;
	}
	std::cout << std::endl;
}




int main(){
try{
	const std::string iname{"input_float.txt"};
	std::ifstream ifs{iname};
	if(!ifs) throw std::runtime_error("Could not read from file: " + iname);
	
	std::vector<double> vd;
	for(double d; ifs >> d;){
		vd.push_back(d);
	}
	print(vd);
	
	std::vector<int> vi(vd.size());
	std::copy(vd.begin(), vd.end(), vi.begin());
	print(vi);
	
	for(int i = 0; i < vd.size(); i++){
		std::cout << vd[i] << '\t' << vi[i] << std::endl;
	}
	
	double vd_sum = std::accumulate(vd.begin(), vd.end(), 0.0);
	int vi_sum = std::accumulate(vi.begin(), vi.end(), 0.0);

	std::cout<<" vd_sum = " << vd_sum <<  '\n' ;
	std::cout<<" vi_sum = " << vi_sum <<  '\n' ;
	double diff_sum = std::inner_product(vd.begin(), vd.end(), vi.begin(), 0.0, std::plus<double>(), std::minus<double>());
	std::cout<<" diff_sum  = " << diff_sum << '\n' ;
	
	std::reverse(vd.begin(), vd.end());
	
	print(vd);
	
	double vd_mean = vd_sum / vd.size();
	std::cout<<" vd_mean = " << vd_mean <<  '\n' ;
	
	std::vector<double> vd2(vd.size());
	
	auto it = std::copy_if(vd.begin(), vd.end(), vd2.begin(),
			Less_than(vd_mean));
	vd2.resize(std::distance(vd2.begin(),it));
	
	print(vd2);
	
	std::sort(vd.begin(), vd.end());
	print(vd);
}catch(std::exception& e){
	std::cerr << "Exception: " << e.what() << std::endl;
	return 1;
}catch(...){
	std::cerr << "Unknow exception " << std::endl;
		return 2;
}

}

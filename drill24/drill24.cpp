#include <iostream>
#include <cmath>
#include <climits>
#include <complex>

#include "Matrix.h"

void my_sqrt(){
	int n;
	std::cout << "Please, enter a number" << std::endl;
	std::cin >> n;
	double sqrt_num = sqrt(n);
	if(sqrt_num <= std::numeric_limits<double>::max())
		std::cout << sqrt_num << std::endl;
	else  
		std::cout << "no square root" << std::endl;
}

Numeric_lib::Matrix<double,2> mult_table(int n, int m){
	Numeric_lib::Matrix<double, 2> out(n+1,m+1);
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= m; ++j){
			out[i][j] = i*j;
		}
	}
	return out;
}
int main(){

	std::cout << "Size of char: " << sizeof(char) << " bytes." << std::endl;
	std::cout << "Size of short: " << sizeof(short) << " bytes." << std::endl;
	std::cout << "Size of int: " << sizeof(int) << " bytes." << std::endl;
	std::cout << "Size of long: " << sizeof(long) << " bytes." << std::endl;
	std::cout << "Size of float: " << sizeof(float) << " bytes." << std::endl;
	std::cout << "Size of double: " << sizeof(double) << " bytes." << std::endl;
	std::cout << "Size of int*: " << sizeof(int*) << " bytes." << std::endl;
	std::cout << "Size of double*: " << sizeof(double*) << " bytes." << std::endl;

	Numeric_lib::Matrix<int> a(10);
	std::cout << "Size of Matrix<int>a(10): " << sizeof(a) << " bytes." << std::endl;
	Numeric_lib::Matrix<int> b(100);
	std::cout << "Size of Matrix<int>b(100): " << sizeof(b) << " bytes." << std::endl;
	Numeric_lib::Matrix<double> c(10);
	std::cout << "Size of Matrix<int>(10): " << sizeof(c) << " bytes." << std::endl;
	Numeric_lib::Matrix<int,2> d(10,10);
	std::cout << "Size of Matrix<int,2>d(10,10): " << sizeof(d) << " bytes." << std::endl;
	Numeric_lib::Matrix<int,3> e(10,10,10);
	std::cout << "Size of Matrix<int,3>(10,10,10): " << sizeof(e) << " bytes." << std::endl;
	
	std::cout << "The number of elements in a: " << a.size()  << std::endl;
	std::cout << "The number of elements in b: " << b.size()  << std::endl;
	std::cout << "The number of elements in c: " << c.size()  << std::endl;
	std::cout << "The number of elements in d: " << d.size()  << std::endl;
	std::cout << "The number of elements in e: " << e.size()  << std::endl;

	my_sqrt();

	Numeric_lib::Matrix<double> mat(10);

	std::cout << "Enter 10 number" << std::endl;
	for(int i = 0; i < 10; i++){
		int val;
		std::cin >> val;
		mat[i] = val;

	}
	std::cout << "mat:" << std::endl;
	for(int i = 0; i < 10; i++){
		std::cout << mat[i] << " ";
	}
	std::cout<<std::endl;

	{
		int n, m;
		std::cin >> n >> m;
		Numeric_lib::Matrix<double,2> mult(mult_table(n,m));
		for(int i = 0; i <= n; ++i){
			for(int j = 0; j <= m; ++j){
				std::cout << mult[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	std::complex<double> sum;
	for(int i = 0; i < 10; ++i){
		std::complex<double> val;
		std::cin >> val;
		sum += val;
	}
	std::cout << "Sum: " << sum << std::endl; 

	Numeric_lib::Matrix<int,2> m(2,3);
	std::cout << "Please, enter 6 number" << std::endl;
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 3; ++j){
			std::cin >> m[i][j];
		}
	}
	std::cout << std::endl;
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 3; ++j){
			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}
}	


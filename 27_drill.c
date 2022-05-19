#include <stdio.h>

void func(char* p, int x){
	printf("p: %s, x: %d\n", p,x);
}

int main(){
	printf("Hello, World!\n");

	char* h = "Hello";
	char* w = "World!";

	printf("%s %s\n",h,w);

	func("foo",7);

	return 0;
}
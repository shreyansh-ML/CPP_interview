#include<iostream>

#define SQUARE(x) x*x

int main(){
	int a=3;
	int b=3;
	int c=3;
	int d=3;
	std::cout<<SQUARE(a++)<<std::endl;
	std::cout<<SQUARE(++a)<<std::endl;
	std::cout<<SQUARE(a+1)<<std::endl;
	std::cout<<SQUARE(b++)<<std::endl;
	std::cout<<SQUARE(++c)<<std::endl;
	std::cout<<SQUARE(d+1)<<std::endl;
	return 0;
}



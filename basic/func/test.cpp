#include<iostream>


int sum(int x)
{
	std::cout<<"inside one param"<<std::endl;
	return x+10;
}

int sum(int x,int y=5) //with this definition it has two candidate function so it will not be resolved and result in compilation error if we call sum(2) in main
{
	std::cout<<"inside two param"<<std::endl;
	return x+y;
}

int sum(double x,double y)
{
	return x+y;
}


int main(){

	int i=2,j=3;
	sum(i,j);
}

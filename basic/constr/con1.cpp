#include<iostream>

void print2(int i)
{
	std::cout<<i;
}
void print1( int& i)
{
	print2(i);
}
void print(const int i)
{
	print1(i);
}

int main()
{
      const 	int j=1;
	print(j);
}

#include<iostream>

class test
{
	int a;
	public:
	explicit test(int t):a(t) {};

	int get()
        {
		return a;
	}
	test(test& k)
	{
		a=k.a;
	}
};

int main()
{
       const test t(1);
	test t1(t);
	std::cout<<t1.get();
}
	


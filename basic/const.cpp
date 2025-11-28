#include<iostream>


int main()
{
	/*
	 * int &i;
	 * int &i=5 no address to refer to as 5 is constant
	 * int &i=j+k only temporary address
	 */
	int k=5;
	int l=9;

	cont int &j=5; // compiler allocates memory
        const int &j= k+l;
}

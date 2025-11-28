#include<iostream>
#include<cstring>

class Base1
{
	char *str{nullptr};
	int len{0};
	int num=0;
	public:
        static int counter;
	//any constructor with single argument without any purpose of implicit conversion should be declared explicit
	  explicit Base1(int l,char *s)
	  {
		  if(l>0)
		  {
			  len=l;
			  str=new char[len];
			  strcpy(str,s);
			  num=++counter;
		  }
	  }

	  Base1(const Base1 &b)
	  {
		  str=new char[b.len];
		  len=b.len;
		  memcpy(str,b.str,len);
		  num=++counter;
	  }
	  Base1& operator=(const Base1 &b)
	  {
		  std::cout<<"\n inside assignment operator"<<std::endl;
		  if( this == &b)
			  return *this;
		  delete[] str;
		  len=b.len;
		  str=new char[len];
		  std::copy(b.str,b.str+len,str);
		  str[len-1]='A';
		  return *this;
	  }

	  Base1( Base1&& b) noexcept //do not make const Base1&& b because it is required to modify b data elements directly
	  :size(b.size),str(b.str)
	  {
		  b.str=nullptr;
		  b.size=0;
	  }
	  Base1& operator=(Base1&& b) noexcept
          {
		  if(this==&b)
			  return *this;
		  delete[] str;
		  str=b.str;
		  size=b.size;
		  b.str=nullptr;
		  b.size=0;
		  return *this;
	  }
	  /*
	   *copy and swap idiom
            Base1 operator=(const Base1 &b)
	    {
	     if(this==&b)
	        return *this;
	       Base1 tmp(b);
	       tmp.str=nullptr;
	       tmp.size=0;
            ////////////////////////
	    swap(*this,tmp);
	    delete[] tmp.str;
	    tmp.str=nullptr;
	    tmp.size=0;
            

	   *
	   */
       friend swap(Base1& a,Base1& b)
       {
	using std::swap;
	swap(a.str,b.str);
	swap(a.size,b.size);
       }
	  ~Base1()
	  {
		  std::cout<<"inside destructori\n";
		  delete[] str;
		  std::cout<<num<<std::endl;
	  }
	  void get() const
	  {
		  std::cout<<str<<std::endl;
	  }
};

	int Base1::counter=0;
int main()
{
	char c1[]="abcde"; //it is char* 
	//char* c1="abcde"; // here "abcde" is treated as string constant and compiler gives warning ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
	char c3[]="xy";
	//char* c3="xy";
	Base1 b(5,c1);
	Base1 b2(b);
	Base1 b3(2,c3);
	b3=b;
	b2.get();
	b3.get();
}

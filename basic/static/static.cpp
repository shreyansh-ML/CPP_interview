#include <iostream>

class print{
    static int queue; //queue=1 error C++ forbids in-class initialization of non-const static member
    constexpr static int max_queue=5;
    constexpr static int max_page=100;
    public:
    static int page;
    
public:
       void set_queue(int q){
        queue = q;   
}
int get_max_queue(){
        return max_queue;
    }   
int get_queue(){
        return queue;
    } 
static int get_max_page() { //can't be declared as const const why-- due to this pointer does
    //not exist in static member function and hence it can't be made constant.
        return max_page;
    }  
};
int print::page = 0;
int print::queue = 0;
//int print::max_page = 100;

int main() {
    //print().set_queue(1);
    print::page = 10; // Accessing static member directly through class name
    std::cout << "Current queue page: " << print().get_queue()<<" " << print::page<<std::endl;
    std::cout << "Current max queue : " << print().get_max_queue()<<" "<<print::get_max_page()<<std::endl;
    std::cout<<"getmax page var: "<<print().get_max_page<<std::endl;    
    std::cout<<print().get_max_page()<<std::endl;
    return 0;
}

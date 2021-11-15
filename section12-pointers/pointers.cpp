#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    int *p1 {nullptr};
    std::cout << sizeof(p1) << std::endl;

    double *p2 {nullptr};
    std::cout << sizeof(p2) << std::endl;

    unsigned long long *p3 {nullptr};
    std::cout << sizeof(p3) << std::endl;

    std::vector<std::string> *p4 {nullptr};
    std::cout << sizeof(p4) << std::endl;

    std::cout << '\n';

    int num {10};

    std::cout << "value of num: " << num << std::endl;
    std::cout << "size of num: " << sizeof(num) << std::endl;
    std::cout << "address to num: " << &num << std::endl;

    int *num_ptr {&num};
    std::cout << "value of num_ptr: " << num_ptr << endl;
    std::cout << "size of num_ptr: " << sizeof(num_ptr) << endl;
    std::cout << "address of num_ptr: " << &num_ptr << endl;

    int arr[5] {1,2,3,4,5};
    int *arr_ptr {arr};

    std::cout << arr << std::endl;
    std::cout << &arr << std::endl;

    std::cout << arr[0] << std::endl;
    std::cout << *arr << std::endl;

    std::cout << arr[1] << std::endl;
    std::cout << *(arr + 1) << std::endl;

    char name[] {"Felipe"};

    char *name_ptr {nullptr};
    name_ptr = name;

    std::cout << name[4] << std::endl;
    std::cout << *(name+4) << std::endl;
    std::cout << name_ptr[4] << std::endl;
    std::cout << *(name_ptr + 4) << std::endl;

    name_ptr += 4;    
    while(*name_ptr != 'F') {
        std::cout << *name_ptr-- << std::endl;
    }

    name_ptr = &name[4];
    while(*name_ptr != 'F') {
        std::cout << *name_ptr-- << std::endl;
    }

    name_ptr = &(*(name+4));
    while(*name_ptr != 'F') {
        std::cout << *name_ptr-- << std::endl;
    }

    return 0;    
}
#include <iostream>

using namespace std;

int main() {

    int *num_ptr {nullptr};

    cout << num_ptr << endl;

    num_ptr = new int;

    cout << num_ptr << endl;

    cout << *num_ptr << endl;

    *num_ptr = 1997;

    cout << *num_ptr << endl;

    delete num_ptr;

    /*
    int num {2020};
    int *num_ptr {&num};

    cout << &num << endl;
    cout << num_ptr << endl;

    cout << num << endl;
    cout << *num_ptr << endl;

    *num_ptr = 1997;

    return 0;
    */
}
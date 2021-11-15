#include <iostream>

int *apply_all(const int *const, const size_t, const int *const, const size_t);
void print(const int *const, const size_t);

int main() {
    int array1[] {14,20,31,9,4,19};
    int array2[] {18,33,11,17,7};

    size_t array1_size {sizeof array1 / sizeof *array1};
    size_t array2_size {sizeof array2 / sizeof *array2};

    std::cout << "Array 1: ";
    print(array1, array1_size);

    std::cout << "Array 2: ";
    print(array2, array2_size);

    int *result {apply_all(array1, array1_size, array2, array2_size)};

    std::cout << "Results: ";
    print(result, array1_size*array2_size);

    delete [] result;
}

int *apply_all(const int *const arr1, const size_t size1, const int *const arr2, const size_t size2) {
    int *result {new int[size1*size2]};

    for (size_t i {0}; i < size2; ++i) {
        for (size_t j {0}; j < size1; ++j) {
            *(result+j+i*size1) = *(arr1+j) * *(arr2+i);
        }
    }

    return result;
}

void print(const int *const arr, const size_t size) {
    std::cout << "[ ";
    for (size_t i {0}; i < size; ++i) {
        std::cout << *(arr + i) << ' ';
    }
    std::cout << "]";
    std::cout << std::endl;
}
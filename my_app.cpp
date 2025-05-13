#define MY_LIB_DLL

#include "dll_export.hpp"
#include "my_lib.hpp"

#include <iostream>

volatile float v1 = 1.0f;
volatile float v2 = 2.0f;
volatile float v3 = 3.0f;
volatile float v4 = 4.0f;
volatile float v5 = 5.0f;
volatile float v6 = 6.0f;
volatile float v7 = 7.0f;
volatile float v8 = 8.0f;

int main() {
    my_lib::MyLibClass mlc;

    mlc.inline_fn();
    mlc.regular_fn();
    mlc.export_fn();

    float a[] = {v1, v2, v3, v4};
    float b[] = {v5, v6, v7, v8};
    float c[4];
    mlc.matmul(2, a, b, c);
    std::cout << c[0] << ", " << c[1] << ", " << c[2] << ", " << c[3] << std::endl;
}

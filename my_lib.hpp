#ifndef MY_LIB_HPP
#define MY_LIB_HPP

#include <cstdio>

namespace my_lib {

class MY_LIB_API MyLibClass {
private:
    int a = 0;
    float b = 0;

public:
    inline int get_a() const {
        return a;
    }

    inline float get_b() const {
        return b;
    }

    inline void inline_fn() {
        std::puts("inline_fn");
    }

    void regular_fn();
    MY_LIB_API void export_fn();

    inline void matmul(const int n, const float* a, const float* b, float* c) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                c[i * n + j] = 0;
                for(int k = 0; k < n; k++) {
                    c[i * n + j] += a[i * n + k] * b[k * n  +j];
                }
            }
        }
    }
};

} // namespace my_lib

#endif // MY_LIB_HPP

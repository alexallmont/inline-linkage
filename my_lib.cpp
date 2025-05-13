#define MY_LIB_DLL
#define MY_LIB_DLL_EXPORTS

#include "dll_export.hpp"
#include "my_lib.hpp"

namespace my_lib {

void MyLibClass::regular_fn() {
    std::puts("regular_fn");
}

void MyLibClass::export_fn() {
    std::puts("export_fn");
}

} // namespace my_lib

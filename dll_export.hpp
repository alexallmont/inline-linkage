#if defined _WIN32 || defined __CYGWIN__
    #define MY_LIB_HELPER_DLL_IMPORT __declspec(dllimport)
    #define MY_LIB_HELPER_DLL_EXPORT __declspec(dllexport)
    #define MY_LIB_HELPER_DLL_LOCAL
#else
    #if __GNUC__ >= 4
        #define MY_LIB_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
        #define MY_LIB_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
        #define MY_LIB_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
    #else
        #define MY_LIB_HELPER_DLL_IMPORT
        #define MY_LIB_HELPER_DLL_EXPORT
        #define MY_LIB_HELPER_DLL_LOCAL
    #endif
#endif

#ifdef MY_LIB_DLL
    #ifdef MY_LIB_DLL_EXPORTS
        #define MY_LIB_API MY_LIB_HELPER_DLL_EXPORT
    #else
        #define MY_LIB_API MY_LIB_HELPER_DLL_IMPORT
    #endif
    #define MY_LIB_LOCAL MY_LIB_HELPER_DLL_LOCAL
#else
    // Not building DLL, this is a static lib
    #define MY_LIB_API
    #define MY_LIB_LOCAL
#endif
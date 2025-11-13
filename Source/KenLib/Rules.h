#ifndef KENLIB_RULES_H
#define KENLIB_RULES_H

//
// Rule to enforce C++20 as the minimum standard.
//
// If it is not defined, it is not enforced.
//
// If it is defined, an error will occur if the C++ standard
// is not at least C++20.
//
#if defined(__KENLIB_CPP20_MIN__)
    #if defined(LANG_CPP)
        #if !defined(CPP20)
            #error "C++ 20 or higher is required to compile this project."
        #endif
    #endif
#endif

//
// Rule to enforce C++17 as the minimum standard.
//
// If it is not defined, it is not enforced.
//
// If it is defined, an error will occur if the C++ standard
// is not at least C++17.
//
#if defined(__KENLIB_CPP17_MIN__)
    #if defined(LANG_CPP)
        #if !defined(CPP17)
            #error "C++ 17 or higher is required to compile this project."
        #endif
    #endif
#endif

//
// Rule to enforce C++14 as the minimum standard.
//
// If it is not defined, it is not enforced.
//
// If it is defined, an error will occur if the C++ standard
// is not at least C++14.
//
#if defined(__KENLIB_CPP14_MIN__)
    #if defined(LANG_CPP)
        #if !defined(CPP14)
            #error "C++ 14 or higher is required to compile this project."
        #endif
    #endif
#endif

//
// Rule to warn about if __STDC_VERSION__ isn't defined.
//
// If it is not defined, no warning appears.
//
// If it is defined, a warning is given assuming that the
// C89 standard is being used.
//
#if defined(__KENLIB_WARN_ABOUT_STDC_VERSION_MACRO__)
    #if defined(LANG_C)
        #if defined(C_VERSION_NOT_DEFINED)
            #warning "__STDC_VERSION__ is not defined. Assuming C89 standard."
        #endif
    #endif
#endif

#endif // KENLIB_RULES_H
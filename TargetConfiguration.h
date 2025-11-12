#ifndef KENLIB_TARGET_CONFIGURATION_H
#define KENLIB_TARGET_CONFIGURATION_H

//
// Determine the compiler.
//
#if defined(__clang__)
    #define COMPILER_CLANG 1

    #if defined(__apple_build_version__)
        #define COMPILER_APPLE_CLANG 1
    #endif
#endif

#if !defined(__clang__)
    #if defined(__GNUC__) || defined(__GNUG__)
        #define COMPILER_GCC 1
    #endif
#endif

#if !defined(__clang__) || (!defined(__GNUC__) && !defined(__GNUG__))
    #if defined(_MSC_VER)
        #define COMPILER_MSVC 1
    #endif
#endif

#if defined(__WATCOMC__)
    #define COMPILER_WATCOM 1
#endif

#if defined(__BORLANDC__)
    #define COMPILER_BORLAND 1
#endif

#if defined(__MWERKS__)
    #define COMPILER_METROWERKS 1
    #define COMPILER_MWERKS 1
#endif

//
// Determine what language we are using.
//
#if defined(__cplusplus)
    #define LANG_CPP 1

    #if defined(COMPILER_MSVC)
        #if defined(_MSVC_LANG)
            #define CPP_VERSION _MSVC_LANG
        #else
            #define CPP_VERSION __cplusplus
        #endif
    #else
        #define CPP_VERSION __cplusplus
    #endif

    #if CPP_VERSION >= 202002L
        #define CPP20 1
    #endif

    #if CPP_VERSION >= 201703L
        #define CPP17 1
    #endif
    
    #if CPP_VERSION >= 201402L
        #define CPP14 1
    #endif

    #if CPP_VERSION >= 201103L
        #define CPP11 1
    #endif

    #if CPP_VERSION >= 199711L
        #define CPP98 1
    #endif
#endif

#if !defined(__cplusplus) || defined(__STDC__)
    #define LANG_C 1

    #if defined(__STDC_VERSION__)
        #define C_VERSION __STDC_VERSION__
    #else
        #define C_VERSION_NOT_DEFINED 1
    #endif

    #if defined(C_VERSION)
        #if C_VERSION == 201710L
            #define C17 1
            #define C18 1
        #endif

        #if C_VERSION == 201112L
            #define C11 1
        #endif

        #if C_VERSION == 199901L
            #define C99 1
        #endif

        #if C_VERSION == 199409L
            #define C94 1
            #define C89 1
        #endif
    #endif

    #if defined(C_VERSION_NOT_DEFINED)
        #define C89 1
    #endif
#endif

#if defined(__OBJC__)
    #define LANG_OBJC 1
#endif

//
// Determine the architecture.
//

//
// Determine the platform.
//

//
// Determine the data model.
//

//
// Determine the endianness.
//

#endif // KENLIB_TARGET_CONFIGURATION_H
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
#if defined(i386) || defined(__i386) || defined(__i386__) || defined(_M_IX86) || \
    defined(__x86_64) || defined(__x86_64__) || defined(__amd64) || defined(__amd64__) || \
    defined(_M_X64) || defined(_M_AMD64) || \
    defined(__INTEL__)

    #define CPU_X86 1

    #if defined(__x86_64) || defined(__x86_64__) || defined(__amd64) || defined(__amd64__) || \
        defined(_M_X64) || defined(_M_AMD64)
        #define CPU_X86_64 1
    #else
        #define CPU_X86_32 1
    #endif
#endif

#if defined(arm) || defined(__arm) || defined(__arm__) || defined(_M_ARM) || \
    defined(arm64) || defined(__arm64) || defined(__arm64__) || defined(__aarch64__) || \
    defined(__AARCH64EL__)

    #define CPU_ARM 1

    #if defined(arm64) || defined(__arm64) || defined(__arm64__) || defined(__aarch64__) || \
        defined(__AARCH64EL__)
        #define CPU_ARM64 1
    #else
        #define CPU_ARM32 1
    #endif
#endif

#if defined(__ppc) || defined(__ppc__) || defined(__powerpc) || defined(__powerpc__) || \
    defined(__ppc64) || defined(__ppc64__) || defined(__powerpc64) || defined(__powerpc64__) || \
    defined(_M_PPC) || defined(_ARCH_PPC) || defined(_ARCH_PPC64) || \
    defined(__POWERPC__) || defined(__PPC) || defined(__PPC__) || defined(__POWERPC) || \
    defined(__PPC64) || defined(__PPC64__) || defined(__POWERPC64__)

    #define CPU_PPC 1

    #if defined(__ppc64) || defined(__ppc64__) || defined(__powerpc64) || defined(__powerpc64__) || \
        defined(_ARCH_PPC64) || defined(__PPC64) || defined(__PPC64__) || defined(__POWERPC64__)
        #define CPU_PPC64 1
    #else
        #define CPU_PPC32 1
    #endif
#endif

#if defined(__mips) || defined(__mips__) || defined(__mips64) || defined(__mips64__)
    #define CPU_MIPS 1

    #if defined(__mips64) || defined(__mips64__)
        #define CPU_MIPS64 1
    #else
        #define CPU_MIPS32 1
    #endif
#endif

#if defined(__riscv) || defined(__riscv__)
    #define CPU_RISCV 1

    #if defined(__riscv_xlen)
        #if __riscv_xlen == 64
            #define CPU_RISCV64 1
        #elif __riscv_xlen == 32
            #define CPU_RISCV32 1
        #endif
    #endif
#endif

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
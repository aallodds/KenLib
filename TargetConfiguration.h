#ifndef KENLIB_TARGETCONFIGURATION_H
#define KENLIB_TARGETCONFIGURATION_H

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
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__) || \
    defined(WIN64) || defined(_WIN64) || defined(__WIN64) || defined(__WIN64__)

    #define PLATFORM_WINDOWS 1

    #if defined(WIN64) || defined(_WIN64) || defined(__WIN64) || defined(__WIN64__)
        #define PLATFORM_WIN64 1
    #else
        #define PLATFORM_WIN32 1
    #endif
#endif

#if defined(__MINGW32__) || defined(__MINGW64__)
    #define PLATFORM_MINGW 1

    #if defined(__MINGW64__)
        #define PLATFORM_MINGW64 1
    #else
        #define PLATFORM_MINGW32 1
    #endif
#endif

#if defined(__ANDROID__) || defined(ANDROID)
    #define PLATFORM_ANDROID 1
#endif

#if !defined(PLATFORM_ANDROID)
    #if defined(linux) || defined(__linux) || defined(__linux__) || defined(__gnu_linux__)
        #define PLATFORM_LINUX 1
    #endif
#endif

#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__bsdi__) || \
    defined(__DragonFly__)

    #define PLATFORM_BSD 1

    #if defined(__OpenBSD__)
        #define PLATFORM_OPENBSD 1
    #endif

    #if defined(__FreeBSD__)
        #define PLATFORM_FREEBSD 1
    #endif

    #if defined(__NetBSD__)
        #define PLATFORM_NETBSD 1
    #endif

    #if defined(__bsdi__)
        #define PLATFORM_BSDI 1
    #endif

    #if defined(__DragonFly__)
        #define PLATFORM_DRAGONFLY 1
    #endif
#endif

#if defined(GEKKO) || defined(__PPCGEKKO__)
    #define PLATFORM_GAMECUBE 1
#endif

#if defined(__DS__) || defined(SDK_ARM9) || defined(SDK_TS)
    #define PLATFORM_NDS 1
    #define PLATFORM_DS 1
#endif

#if defined(__3DS__) || defined(NN_COMPILER_RVCT) || defined(NN_PLATFORM_CTR)
    #define PLATFORM_3DS 1
#endif

#if defined(RVL) || defined(RVL_SDK) || defined(RVL_OS) || \
    defined(__PPCBROADWAY__) || \
    defined(_WII) || defined(__WII__) || \
    defined(cafe) || defined(__CAFE__)
    #define PLATFORM_WII 1
#endif

#if defined(__espresso__) || defined(__WIIU__)
    #define PLATFORM_WIIU 1
#endif

#if defined(__SWITCH__) || defined(_SWITCH) || defined(__NX__) || \
    defined(NN_NINTENDO_SDK)
    #define PLATFORM_SWITCH 1
#endif

#if defined(SN_TARGET_PSP) || defined(_PSP) || defined(__PSP__)
    #define PLATFORM_PSP 1
#endif

#if defined(SN_TARGET_PSP2) || defined(__VITA__) || defined(__PSP2__)
    #define PLATFORM_PSP2 1
    #define PLATFORM_VITA 1
#endif

#if defined(SN_TARGET_PS2) || defined(_PS2) || defined(__PS2__) || defined(__PLAYSTATION2__)
    #define PLATFORM_PS2 1
#endif

#if defined(SN_TARGET_PS3) || defined(_PS3) || defined(__PS3__) || defined(__CELLOS_LV2__)
    #define PLATFORM_PS3 1
#endif

#if defined(SN_TARGET_ORBIS) || defined(SN_TARGET_PS4) || \
    defined(__ORBIS__) || defined(_PS4) || defined(__PS4__)

    #define PLATFORM_PS4 1
    #define PLATFORM_ORBIS 1
#endif

#if defined(SN_TARGET_PROSPERO) || defined(__PROSPERO__)
    #define PLATFORM_PS5 1
    #define PLATFORM_PROSPERO 1
#endif

#if defined(_XENON) || defined(_X360) || defined(_XBOX360)
    #define PLATFORM_XBOX360 1
    #define PLATFORM_X360 1
    #define PLATFORM_XENON 1
#endif

#if defined(_DURANGO) || defined(_XBOX1) || defined(_XBOX_ONE) || defined(__XBOXONE__) || \
    defined(_GAMING_XBOX_ONE) || defined(_TITLE)
    #define PLATFORM_XBOXONE 1
    #define PLATFORM_XBOX_ONE 1
    #define PLATFORM_XBOX1 1
    #define PLATFORM_DURANGO 1
#endif

#if defined(__XBOXSERIES__) || defined(_GAMING_XBOX_SCARLETT)
    #define PLATFORM_XBOXSERIES 1
    #define PLATFORM_XBOX_SERIES 1
    #define PLATFORM_SCARLETT 1
#endif

// This refers to the original XBOX.
#if defined(_XBOX) && !defined(PLATFORM_XENON) && !defined(PLATFORM_DURANGO) && !defined(PLATFORM_SCARLETT)
    #define PLATFORM_XBOX 1
#endif

//
// Determine the data model.
//
#if defined(_ILP32) || defined(__ILP32__)
    #define KEN_ILP32 1
#endif

#if defined(_LP64) || defined(__LP64__)
    #define KEN_LP64 1
#endif

#if defined(_LLP64) || defined(__LLP64__)
    #define KEN_LLP64 1
#endif

#if !defined(KEN_ILP32)
    #if defined(CPU_X86_32) || defined(CPU_ARM32) || \
        defined(CPU_PPC32) || defined(CPU_MIPS32) || \
        defined(CPU_RISCV32)

        #define KEN_ILP32 1
    #endif
#endif

#if !defined(KEN_LP64) && !defined(PLATFORM_WIN64)
    #if defined(CPU_X86_64) || defined(CPU_ARM64) || \
        defined(CPU_PPC64) || defined(CPU_MIPS64) || \
        defined(CPU_RISCV64)

        #define KEN_LP64 1
    #endif
#endif

#if defined(PLATFORM_WIN64) && !defined(KEN_LLP64)
    #define KEN_LLP64 1
#endif

//
// Determine the endianness.
//
#if defined(__BYTE_ORDER__)
    #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        #define KEN_LITTLE_ENDIAN 1
    #elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        #define KEN_BIG_ENDIAN 1
    #endif
#endif

#if defined(CPU_PPC)
    #if !defined(KEN_LITTLE_ENDIAN) && !defined(KEN_BIG_ENDIAN)
        #define KEN_BIG_ENDIAN 1
    #endif
#endif

#if !defined(CPU_PPC)
    #if !defined(KEN_LITTLE_ENDIAN) && !defined(KEN_BIG_ENDIAN)
        #define KEN_LITTLE_ENDIAN 1
    #endif
#endif

//
// Define any unset macros to zero
//
#ifndef COMPILER_CLANG
    #define COMPILER_CLANG 0
#endif

#ifndef COMPILER_APPLE_CLANG
    #define COMPILER_APPLE_CLANG 0
#endif

#ifndef COMPILER_GCC
    #define COMPILER_GCC 0
#endif

#ifndef COMPILER_MSVC
    #define COMPILER_MSVC 0
#endif

#ifndef COMPILER_WATCOM
    #define COMPILER_WATCOM 0
#endif

#ifndef COMPILER_BORLAND
    #define COMPILER_BORLAND 0
#endif

#ifndef COMPILER_METROWERKS
    #define COMPILER_METROWERKS 0
#endif

#ifndef COMPILER_MWERKS
    #define COMPILER_MWERKS 0
#endif

#ifndef LANG_CPP
    #define LANG_CPP 0
#endif

#ifndef CPP_VERSION
    #define CPP_VERSION 0
#endif

#ifndef CPP20
    #define CPP20 0
#endif

#ifndef CPP17
    #define CPP17 0
#endif

#ifndef CPP14
    #define CPP14 0
#endif

#ifndef CPP11
    #define CPP11 0
#endif

#ifndef CPP98
    #define CPP98 0
#endif

#ifndef LANG_C
    #define LANG_C 0
#endif

#ifndef C_VERSION
    #define C_VERSION 0
#endif

#ifndef C17
    #define C17 0
#endif

#ifndef C18
    #define C18 0
#endif

#ifndef C11
    #define C11 0
#endif

#ifndef C99
    #define C99 0
#endif

#ifndef C94
    #define C94 0
#endif

#ifndef C89
    #define C89 0
#endif

#ifndef LANG_OBJC
    #define LANG_OBJC 0
#endif

#ifndef CPU_X86
    #define CPU_X86 0
#endif

#ifndef CPU_X86_64
    #define CPU_X86_64 0
#endif

#ifndef CPU_X86_32
    #define CPU_X86_32 0
#endif

#ifndef CPU_ARM
    #define CPU_ARM 0
#endif

#ifndef CPU_ARM64
    #define CPU_ARM64 0
#endif

#ifndef CPU_ARM32
    #define CPU_ARM32 0
#endif

#ifndef CPU_PPC
    #define CPU_PPC 0
#endif

#ifndef CPU_PPC64
    #define CPU_PPC64 0
#endif

#ifndef CPU_PPC32
    #define CPU_PPC32 0
#endif

#ifndef CPU_MIPS
    #define CPU_MIPS 0
#endif

#ifndef CPU_MIPS64
    #define CPU_MIPS64 0
#endif

#ifndef CPU_MIPS32
    #define CPU_MIPS32 0
#endif

#ifndef CPU_RISCV
    #define CPU_RISCV 0
#endif

#ifndef CPU_RISCV64
    #define CPU_RISCV64 0
#endif

#ifndef CPU_RISCV32
    #define CPU_RISCV32 0
#endif

#ifndef PLATFORM_WINDOWS
    #define PLATFORM_WINDOWS 0
#endif

#ifndef PLATFORM_WIN64
    #define PLATFORM_WIN64 0
#endif

#ifndef PLATFORM_WIN32
    #define PLATFORM_WIN32 0
#endif

#ifndef PLATFORM_MINGW
    #define PLATFORM_MINGW 0
#endif

#ifndef PLATFORM_MINGW64
    #define PLATFORM_MINGW64 0
#endif

#ifndef PLATFORM_MINGW32
    #define PLATFORM_MINGW32 0
#endif

#ifndef PLATFORM_ANDROID
    #define PLATFORM_ANDROID 0
#endif

#ifndef PLATFORM_LINUX
    #define PLATFORM_LINUX 0
#endif

#ifndef PLATFORM_BSD
    #define PLATFORM_BSD 0
#endif

#ifndef PLATFORM_OPENBSD
    #define PLATFORM_OPENBSD 0
#endif

#ifndef PLATFORM_FREEBSD
    #define PLATFORM_FREEBSD 0
#endif

#ifndef PLATFORM_NETBSD
    #define PLATFORM_NETBSD 0
#endif

#ifndef PLATFORM_BSDI
    #define PLATFORM_BSDI 0
#endif

#ifndef PLATFORM_DRAGONFLY
    #define PLATFORM_DRAGONFLY 0
#endif

#ifndef PLATFORM_GAMECUBE
    #define PLATFORM_GAMECUBE 0
#endif

#ifndef PLATFORM_NDS
    #define PLATFORM_NDS 0
#endif

#ifndef PLATFORM_DS
    #define PLATFORM_DS 0
#endif

#ifndef PLATFORM_3DS
    #define PLATFORM_3DS 0
#endif

#ifndef PLATFORM_WII
    #define PLATFORM_WII 0
#endif

#ifndef PLATFORM_WIIU
    #define PLATFORM_WIIU 0
#endif

#ifndef PLATFORM_SWITCH
    #define PLATFORM_SWITCH 0
#endif

#ifndef PLATFORM_PSP
    #define PLATFORM_PSP 0
#endif

#ifndef PLATFORM_PSP2
    #define PLATFORM_PSP2 0
#endif

#ifndef PLATFORM_VITA
    #define PLATFORM_VITA 0
#endif

#ifndef PLATFORM_PS2
    #define PLATFORM_PS2 0
#endif

#ifndef PLATFORM_PS3
    #define PLATFORM_PS3 0
#endif

#ifndef PLATFORM_PS4
    #define PLATFORM_PS4 0
#endif

#ifndef PLATFORM_ORBIS
    #define PLATFORM_ORBIS 0
#endif

#ifndef PLATFORM_PS5
    #define PLATFORM_PS5 0
#endif

#ifndef PLATFORM_PROSPERO
    #define PLATFORM_PROSPERO 0
#endif

#ifndef PLATFORM_XBOX360
    #define PLATFORM_XBOX360 0
#endif

#ifndef PLATFORM_X360
    #define PLATFORM_X360 0
#endif

#ifndef PLATFORM_XENON
    #define PLATFORM_XENON 0
#endif

#ifndef PLATFORM_XBOXONE
    #define PLATFORM_XBOXONE 0
#endif

#ifndef PLATFORM_XBOX_ONE
    #define PLATFORM_XBOX_ONE 0
#endif

#ifndef PLATFORM_XBOX1
    #define PLATFORM_XBOX1 0
#endif

#ifndef PLATFORM_DURANGO
    #define PLATFORM_DURANGO 0
#endif

#ifndef PLATFORM_XBOXSERIES
    #define PLATFORM_XBOXSERIES 0
#endif

#ifndef PLATFORM_XBOX_SERIES
    #define PLATFORM_XBOX_SERIES 0
#endif

#ifndef PLATFORM_SCARLETT
    #define PLATFORM_SCARLETT 0
#endif

#ifndef PLATFORM_XBOX
    #define PLATFORM_XBOX 0
#endif

#ifndef KEN_ILP32
    #define KEN_ILP32 0
#endif

#ifndef KEN_LP64
    #define KEN_LP64 0
#endif

#ifndef KEN_LLP64
    #define KEN_LLP64 0
#endif

#ifndef KEN_LITTLE_ENDIAN
    #define KEN_LITTLE_ENDIAN 0
#endif

#ifndef KEN_BIG_ENDIAN
    #define KEN_BIG_ENDIAN 0
#endif

#endif // KENLIB_TARGETCONFIGURATION_H
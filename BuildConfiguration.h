#ifndef KENLIB_BUILDCONFIGURATION_H
#define KENLIB_BUILDCONFIGURATION_H

#if defined(__ENABLE_NETWORKING__)
    #define BUILD_NETWORKING 1

    #if defined(__P2P_BUILD__)
        #define BUILD_P2P 1
        #define P2P_BUILD 1
    #else
        #define BUILD_P2P 0
        #define P2P_BUILD 0
    #endif

    #if defined(__DEDICATED_SERVER_BUILD__)
        #define BUILD_DEDICATED_SERVER 1
        #define DEDICATED_SERVER_BUILD 1
    #else
        #define BUILD_DEDICATED_SERVER 0
        #define DEDICATED_SERVER_BUILD 0
    #endif
    
    #if defined(__STEAM_BUILD__)
        #define BUILD_STEAM 1
        #define STEAM_BUILD 1
    #else
        #define BUILD_STEAM 0
        #define STEAM_BUILD 0
    #endif

    #if defined(__EOS_BUILD__)
        #define BUILD_EOS 1
        #define EOS_BUILD 1
    #else
        #define BUILD_EOS 0
        #define EOS_BUILD 0
    #endif

    #if defined(__PSN_BUILD__)
        #define BUILD_PSN 1
        #define PSN_BUILD 1
    #else
        #define BUILD_PSN 0
        #define PSN_BUILD 0
    #endif

    #if defined(__XBL_BUILD__)
        #define BUILD_XBL 1
        #define XBL_BUILD 1
    #else
        #define BUILD_XBL 0
        #define XBL_BUILD 0
    #endif
#else
    #define BUILD_NETWORKING 0
    #define BUILD_P2P 0
    #define P2P_BUILD 0
    #define BUILD_DEDICATED_SERVER 0
    #define DEDICATED_SERVER_BUILD 0
    #define BUILD_STEAM 0
    #define STEAM_BUILD 0
    #define BUILD_EOS 0
    #define EOS_BUILD 0
    #define BUILD_PSN 0
    #define PSN_BUILD 0
    #define BUILD_XBL 0
    #define XBL_BUILD 0
#endif

#if defined(__BUILD_ENABLE_OPTIMIZATIONS__)
    #define BUILD_OPTIMIZATIONS 1
    #define USE_OPTIMIZATIONS 1
#else
    #define BUILD_OPTIMIZATIONS 0
    #define USE_OPTIMIZATIONS 0
#endif

#if defined(__BUILD_ENABLE_ASSERTIONS__)
    #define BUILD_ASSERTIONS 1
    #define ASSERTS_ENABLED 1
#else
    #define BUILD_ASSERTIONS 0
    #define ASSERTS_ENABLED 0
#endif

#if defined(__BUILD_ENABLE_EXCEPTIONS__)
    #define BUILD_EXCEPTIONS 1
    #define EXCEPTIONS_ENABLED 1
#else
    #define BUILD_EXCEPTIONS 0
    #define EXCEPTIONS_ENABLED 0
#endif

#if defined(__BUILD_ENABLE_BETA__)
    #define BUILD_BETA 1
    #define BETA_ENABLED 1
#else
    #define BUILD_BETA 0
    #define BETA_ENABLED 0
#endif

#if defined(__BUILD_DEBUG__)
    #define BUILD_DEBUG 1
#else
    #define BUILD_DEBUG 0
#endif

#if defined(__BUILD_PROFILE__)
    #define BUILD_PROFILE 1
#else
    #define BUILD_PROFILE 0
#endif

#if defined(__BUILD_QA__)
    #define BUILD_QA 1
#else
    #define BUILD_QA 0
#endif

#if defined(__BUILD_RELEASE__)
    #define BUILD_RELEASE 1
#else
    #define BUILD_RELEASE 0
#endif

#if defined(__BUILD_FINAL__)
    #define BUILD_FINAL 1
#else
    #define BUILD_FINAL 0
#endif

#if defined(__BUILD_WITH_TOOLS__)
    #define TOOLS_ENABLED 1
    #define WITH_TOOLS 1
#else
    #define TOOLS_ENABLED 0
    #define WITH_TOOLS 0
#endif

#if defined(__BUILD_TESTS__)
    #define BUILD_TESTS 1
    #define TESTS_ENABLED 1
#else
    #define BUILD_TESTS 0
    #define TESTS_ENABLED 0
#endif

#if defined(__BUILD_DEBUG__) || defined(__BUILD_PROFILE__) || defined(__BUILD_QA__)
    #define BUILD_DEV 1
#else
    #define BUILD_DEV 0
#endif

#if defined(__FORCE_DISABLE_SIMD_USAGE__)
    #define DISABLE_SIMD_USAGE 1
#else
    #define DISABLE_SIMD_USAGE 0
#endif

#endif // KENLIB_BUILDCONFIGURATION_H
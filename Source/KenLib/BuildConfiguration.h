#ifndef KENLIB_BUILDCONFIGURATION_H
#define KENLIB_BUILDCONFIGURATION_H

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

#if defined(__ENABLE_NETWORKING__)
    #define BUILD_NETWORKING 1

    #if defined(__P2P_BUILD__)
        #define BUILD_P2P 1
        #define P2P_BUILD 1
    #endif

    #if defined(__DEDICATED_SERVER_BUILD__)
        #define BUILD_DEDICATED_SERVER 1
        #define DEDICATED_SERVER_BUILD 1
    #endif
    
    #if defined(__STEAM_BUILD__)
        #define BUILD_STEAM 1
        #define STEAM_BUILD 1
    #endif

    #if defined(__EOS_BUILD__)
        #define BUILD_EOS 1
        #define EOS_BUILD 1
    #endif

    #if defined(__PSN_BUILD__)
        #define BUILD_PSN 1
        #define PSN_BUILD 1
    #endif

    #if defined(__XBL_BUILD__)
        #define BUILD_XBL 1
        #define XBL_BUILD 1
    #endif
#endif

#define BUILD_OPTIMIZATIONS 0
#define USE_OPTIMIZATIONS 0
#define BUILD_ASSERTIONS 0
#define ASSERTS_ENABLED 0
#define BUILD_EXCEPTIONS 0
#define EXCEPTIONS_ENABLED 0

#define BUILD_DEBUG 0
#define BUILD_DEV 0
#define BUILD_BETA 0
#define BETA_ENABLED 0
#define BUILD_PROFILE 0
#define BUILD_QA 0
#define BUILD_RELEASE 0
#define BUILD_FINAL 0
#define BUILD_TOOLS 0
#define TOOLS_ENABLED 0
#define WITH_TOOLS 0

#if defined(__ENABLE_OPTIMIZATIONS__)
    #undef BUILD_OPTIMIZATIONS
    #undef USE_OPTIMIZATIONS
    #define BUILD_OPTIMIZATIONS 1
    #define USE_OPTIMIZATIONS 1
#endif

#if defined(__ENABLE_ASSERTIONS__)
    #undef BUILD_ASSERTIONS
    #undef ASSERTS_ENABLED
    #define BUILD_ASSERTIONS 1
    #define ASSERTS_ENABLED 1
#endif

#if defined(__ENABLE_EXCEPTIONS__)
    #undef BUILD_EXCEPTIONS
    #undef EXCEPTIONS_ENABLED
    #define BUILD_EXCEPTIONS 1
    #define EXCEPTIONS_ENABLED 1
#endif

#if defined(__TARGET_BUILD_DEBUG__)
    #undef BUILD_DEBUG
    #define BUILD_DEBUG 1
#endif

#if defined(__TARGET_BUILD_PROFILE__)
    #undef BUILD_PROFILE
    #define BUILD_PROFILE 1
#endif

#if defined(__TARGET_BUILD_RELEASE__)
    #undef BUILD_RELEASE
    #define BUILD_RELEASE 1
#endif

#if defined(__TARGET_BUILD_FINAL__)
    #undef BUILD_FINAL
    #define BUILD_FINAL 1
#endif

#if defined(__ENABLE_TOOLS__)
    #undef BUILD_TOOLS
    #undef TOOLS_ENABLED
    #undef WITH_TOOLS
    #define BUILD_TOOLS 1
    #define TOOLS_ENABLED 1
    #define WITH_TOOLS 1
#endif

#if defined(__ENABLE_BETA__)
    #undef BUILD_BETA
    #undef BETA_ENABLED
    #define BUILD_BETA 1
    #define BETA_ENABLED 1
#endif

#if defined(__DEV_BUILD__)
    #undef BUILD_DEV
    #define BUILD_DEV 1
#endif

//
// Determine if we are a development build.
//
#if defined(__DO_NOT_AUTO_DETERMINE_DEV_BUILD__)
    #if BUILD_DEBUG == 1 || BUILD_PROFILE == 1 || BUILD_BETA == 1 || BUILD_QA == 1
        #undef BUILD_DEV
        #define BUILD_DEV 1

        // Development builds have access to tools. If we are a beta build
        // and for shipping, we do not want to have access to tools.
        #if BUILD_BETA == 1 && (BUILD_RELEASE == 1 || BUILD_FINAL == 1)
            #undef BUILD_DEV
            #define BUILD_DEV 0
        #endif
    #endif
#endif

//
// Enable tools by default for development builds.
//
#if !defined(__DO_NOT_ENABLE_TOOLS_FOR_DEV_BUILDS_BY_DEFAULT__)
    #if BUILD_DEV == 1
        #if !defined(__ENABLE_TOOLS__)
            #undef BUILD_TOOLS
            #undef TOOLS_ENABLED
            #undef WITH_TOOLS
            #define BUILD_TOOLS 1
            #define TOOLS_ENABLED 1
            #define WITH_TOOLS 1
        #endif
    #endif
#endif

#endif // KENLIB_BUILDCONFIGURATION_H
#ifndef KENLIB_TYPES_H
#define KENLIB_TYPES_H

#if defined(LANG_CPP)
    #include <cstddef>
    #if defined(CPP11)
        #include <cstdint>
    #else
        #include <stdint.h>
    #endif
#else
    #include <stddef.h>
    #include <stdint.h>
#endif

#if defined(LANG_CPP)
namespace Ken {
#endif

#if defiend(LANG_CPP)
using f32 = float;
using f64 = double;
#else
typedef float f32;
typedef double f64;
#endif

#if defined(LANG_CPP)
using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using s8 = std::int8_t;
using s16 = std::int16_t;
using s32 = std::int32_t;
using s64 = std::int64_t;
#if __cpp_lib_byte >= 201603L
using byte = std::byte;
#else
using byte = u8;
#endif
#else
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;
typedef u8 byte;
#endif

#if defined(LANG_CPP)
} // namespace Ken
#endif

#endif // KENLIB_TYPES_H
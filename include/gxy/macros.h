#pragma once

#if defined(__APPLE__)
  #define GXY_OS_OSX
#elif defined(__linux__) || defined(__linux)
  #define GXY_OS_LINUX
#elif defined(__WIN32)
  #define GXY_OS_WIN
#else
  #error "Galaxy is not supported on this system, please file an issue: "
    "https://github.com/samkellett/galaxy/issues"
#endif

#define GXY_PAIR(Pair, T1, first, T2, second) \
  struct Pair \
  { \
    Pair() : first ( T1 ()), second ( T2 ()) {} \
    Pair(const T1 &t1, const T2 &t2) : first (t1), second (t2) {} \
  \
    Pair &operator =(const Pair &other) \
    { first = other.##first ; second = other.##second ; return *this; } \
  \
    T1 first ; \
    T2 second ; \
  };

#define GXY_STR(str) #str

#define GXY_UNUSED(var) static_cast<void>(var)

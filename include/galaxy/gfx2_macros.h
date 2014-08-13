
#ifndef GXY_GFX_HELPERS
  #define GXY_GFX_HELPERS

  #define GXY_UPPER_a A
  #define GXY_UPPER_b B
  #define GXY_UPPER_c C
  #define GXY_UPPER_d D
  #define GXY_UPPER_e E
  #define GXY_UPPER_f F
  #define GXY_UPPER_g G
  #define GXY_UPPER_h H
  #define GXY_UPPER_i I
  #define GXY_UPPER_j J
  #define GXY_UPPER_k K
  #define GXY_UPPER_l L
  #define GXY_UPPER_m M
  #define GXY_UPPER_n N
  #define GXY_UPPER_o O
  #define GXY_UPPER_p P
  #define GXY_UPPER_q Q
  #define GXY_UPPER_r R
  #define GXY_UPPER_s S
  #define GXY_UPPER_t T
  #define GXY_UPPER_u U
  #define GXY_UPPER_v V
  #define GXY_UPPER_w W
  #define GXY_UPPER_x X
  #define GXY_UPPER_y Y
  #define GXY_UPPER_z Z
  #define GXY_TO_UPPER(x) UPPER_ ## x

  #define GXY_GFX_METHOD(n, ame) template<typename... Args> \
    inline void n##ame(Args&&... args) \
    { \
      gl##GXY_TO_UPPER(n)##ame(std::forward<Args>(args)...); \
      auto error = glGetError(); \
      BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error)); \
    }

  #define GXY_GFX_METHOD(ret, n, ame) template<typename... Args> \
    inline ret n##ame(Args&&... args) \
    { \
      auto value = gl##GXY_TO_UPPER(n)##ame(std::forward<Args>(args)...); \
      auto error = glGetError(); \
      BOOST_ASSERT_MSG(error == GL_NO_ERROR, getErrorString(error)); \
      return value; \
    }

#else
  #undef GXY_GFX_HELPERS

  #undef GXY_UPPER_a
  #undef GXY_UPPER_b
  #undef GXY_UPPER_c
  #undef GXY_UPPER_d
  #undef GXY_UPPER_e
  #undef GXY_UPPER_f
  #undef GXY_UPPER_g
  #undef GXY_UPPER_h
  #undef GXY_UPPER_i
  #undef GXY_UPPER_j
  #undef GXY_UPPER_k
  #undef GXY_UPPER_l
  #undef GXY_UPPER_m
  #undef GXY_UPPER_n
  #undef GXY_UPPER_o
  #undef GXY_UPPER_p
  #undef GXY_UPPER_q
  #undef GXY_UPPER_r
  #undef GXY_UPPER_s
  #undef GXY_UPPER_t
  #undef GXY_UPPER_u
  #undef GXY_UPPER_v
  #undef GXY_UPPER_w
  #undef GXY_UPPER_x
  #undef GXY_UPPER_y
  #undef GXY_UPPER_z
  #undef GXY_TO_UPPER(x)

  #undef GXY_GFX_METHOD(n, ame)
  #undef GXY_GFX_METHOD(ret, n, ame)
#endif

#ifndef MY_ASSERT
#define MY_ASSERT
#include <cassert>
#include <iostream>
#include <string>

#ifdef LOCAL

#define ASSERT_MSG(expr, msg)                                                                                          \
  do {                                                                                                                 \
    if (!(expr)) {                                                                                                     \
      std::cerr << msg << std::endl;                                                                                   \
      assert(expr);                                                                                                    \
    }                                                                                                                  \
  } while (0)

#define FAIL ASSERT_MSG(false, "到達しない想定の場所に到達しました")

#else

#define ASSERT_MSG(...) (void)0
#define FAIL (void)0

#endif

#endif

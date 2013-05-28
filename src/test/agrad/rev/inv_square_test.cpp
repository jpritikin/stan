#include <stan/agrad/rev/inv_square.hpp>
#include <test/agrad/util.hpp>
#include <gtest/gtest.h>

TEST(AgradRev,inv_square) {
  AVAR a = 7.0;
  AVEC x = createAVEC(a);
  AVAR f = inv_square(a);
  EXPECT_FLOAT_EQ(1 / 49.0, f.val());

  VEC grad_f;
  f.grad(x,grad_f);
  EXPECT_EQ(1U,grad_f.size());
  EXPECT_FLOAT_EQ(-2.0 / 343.0, grad_f[0]);

  a = 0.0;
  x = createAVEC(a);
  f = inv_square(a);
  std::isnan(f.val());

  f.grad(x,grad_f);
  std::isnan(grad_f[0]);
}

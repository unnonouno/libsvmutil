#include <gtest/gtest.h>
#include "libsvmutil.hpp"

#include <sstream>

using namespace std;

namespace libsvmutil {

TEST(libsvmutil, empty) {
  stringstream ss("");
  example e;
  EXPECT_FALSE(read_data(ss, e));
}

TEST(libsvmutil, read_data) {
  stringstream ss("-1 3:1 11:2 14:3");
  example e;
  ASSERT_TRUE(read_data(ss, e));
  EXPECT_EQ("-1", e.label);
  ASSERT_EQ(3u, e.feature_vector.size());
  EXPECT_EQ(3, e.feature_vector[0].first);
  EXPECT_EQ(1.0, e.feature_vector[0].second);
  EXPECT_EQ(11, e.feature_vector[1].first);
  EXPECT_EQ(2.0, e.feature_vector[1].second);
  EXPECT_EQ(14, e.feature_vector[2].first);
  EXPECT_EQ(3.0, e.feature_vector[2].second);

  EXPECT_FALSE(read_data(ss, e));
}

TEST(libsvmutil, read_all) {
  stringstream ss("-1 2:3\n+1 1:4");
  vector<example> es;
  read_all(ss, es);
  ASSERT_EQ(2u, es.size());
  EXPECT_EQ("-1", es[0].label);
  EXPECT_EQ("+1", es[1].label);
}


}


/* Do not edit below this line. */
/* Do not edit below this line. */
/* Do not edit below this line. */

#include <gtest/gtest.h>

#include <cassert>
#include <climits>
#include <cstdio>
#include <future>

#include "demographics_functions.h"

// Thanks to Paul Inventado
// https://github.com/google/googletest/issues/348#issuecomment-431714269
#define MAX_DURATION_MS 500
// Fail immediately.
// NOLINT(cppcoreguidelines-macro-usage)
#define ASSERT_DURATION_LE(millisecs, stmt)                                 \
  {                                                                         \
    std::promise<bool> completed;                                           \
    auto stmt_future = completed.get_future();                              \
    std::thread(                                                            \
        [&](std::promise<bool>& completed) {                                \
          stmt;                                                             \
          completed.set_value(true);                                        \
        },                                                                  \
        std::ref(completed))                                                \
        .detach();                                                          \
    if (stmt_future.wait_for(std::chrono::milliseconds(millisecs)) ==       \
        std::future_status::timeout)                                        \
      GTEST_FATAL_FAILURE_("\tExecution time greater than " #millisecs      \
                           " milliseconds.\n\tRevise algorithm for better " \
                           "performance and check for "                     \
                           "infinite loops.");                              \
  }

// Defer failure
// NOLINT(cppcoreguidelines-macro-usage)
#define EXPECT_DURATION_LE(millisecs, stmt)                                    \
  {                                                                            \
    std::promise<bool> completed;                                              \
    auto stmt_future = completed.get_future();                                 \
    std::thread(                                                               \
        [&](std::promise<bool>& completed) {                                   \
          stmt;                                                                \
          completed.set_value(true);                                           \
        },                                                                     \
        std::ref(completed))                                                   \
        .detach();                                                             \
    if (stmt_future.wait_for(std::chrono::milliseconds(millisecs)) ==          \
        std::future_status::timeout)                                           \
      GTEST_NONFATAL_FAILURE_("\tExecution time greater than " #millisecs      \
                              " milliseconds.\n\tRevise algorithm for better " \
                              "performance and check for "                     \
                              "infinite loops.");                              \
  }

#define FP_DELTA 0.001

namespace {

TEST(StateTest, ReadCSV) {
  std::vector<std::vector<std::string>> csv{ReadCSV("state_demographics.csv")};
  ASSERT_FALSE(csv.empty());
  ASSERT_EQ(52, csv.size());

  ASSERT_EQ(48, csv.at(0).size());
  EXPECT_EQ("State", csv.at(0).at(0));
  EXPECT_EQ("Miscellaneous.Land Area", csv.at(0).at(47));

  ASSERT_EQ(48, csv.at(1).size());
  EXPECT_EQ("Connecticut", csv.at(1).at(0));
  EXPECT_EQ("4842.36", csv.at(1).at(47));

  ASSERT_EQ(48, csv.at(51).size());
  EXPECT_EQ("Wyoming", csv.at(51).at(0));
  EXPECT_EQ("97093.14", csv.at(51).at(47));
}

TEST(StateTest, ConstructorAndName) {
  State california{"California", 39538223, 155779.22};
  State vermont{"Vermont", 643077, 9216.66};
  EXPECT_EQ("California", california.name());
  EXPECT_EQ("Vermont", vermont.name());
}

TEST(StateTest, ConstructorAndPopulation) {
  State california{"California", 39538223, 155779.22};
  State vermont{"Vermont", 643077, 9216.66};
  EXPECT_EQ(39538223, california.population());
  EXPECT_EQ(643077, vermont.population());
}

TEST(StateTest, ConstructorAndLandArea) {
  State california{"California", 39538223, 155779.22};
  State vermont{"Vermont", 643077, 9216.66};
  EXPECT_DOUBLE_EQ(155779.22, california.land_area());
  EXPECT_DOUBLE_EQ(9216.66, vermont.land_area());
}

TEST(StateTest, DefaultConstructor) {
  State def;
  EXPECT_EQ("", def.name());
  EXPECT_EQ(0, def.population());
  EXPECT_DOUBLE_EQ(0.0, def.land_area());
}

TEST(StateTest, PopulationDensity) {
  State california{"California", 39538223, 155779.22};
  State vermont{"Vermont", 643077, 9216.66};
  EXPECT_NEAR(253.809, california.population_density(), .1);
  EXPECT_NEAR(69.773, vermont.population_density(), .1);
}

TEST(StateTest, ReadStatesFailure) {
  std::vector<State> states{ReadStates("NONEXISTENT.csv")};
  EXPECT_TRUE(states.empty());
}

TEST(StateTest, ReadStatesSuccess) {
  std::vector<State> states{ReadStates("state_demographics.csv")};
  ASSERT_FALSE(states.empty());
  ASSERT_EQ(51, states.size());

  EXPECT_EQ("Connecticut", states.at(0).name());
  EXPECT_EQ(3605944, states.at(0).population());
  EXPECT_DOUBLE_EQ(4842.36, states.at(0).land_area());

  EXPECT_EQ("California", states.at(10).name());
  EXPECT_EQ(39538223, states.at(10).population());
  EXPECT_DOUBLE_EQ(155779.22, states.at(10).land_area());

  EXPECT_EQ("Indiana", states.at(20).name());
  EXPECT_EQ(6785528, states.at(20).population());
  EXPECT_DOUBLE_EQ(35826.11, states.at(20).land_area());

  EXPECT_EQ("Tennessee", states.at(30).name());
  EXPECT_EQ(6910840, states.at(30).population());
  EXPECT_DOUBLE_EQ(41234.9, states.at(30).land_area());

  EXPECT_EQ("South Carolina", states.at(40).name());
  EXPECT_EQ(5118425, states.at(40).population());
  EXPECT_DOUBLE_EQ(30060.7, states.at(40).land_area());

  EXPECT_EQ("Wyoming", states.at(50).name());
  EXPECT_EQ(576851, states.at(50).population());
  EXPECT_DOUBLE_EQ(97093.14, states.at(50).land_area());
}

}  // namespace

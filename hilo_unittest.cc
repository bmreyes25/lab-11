
/* Do not edit below this line. */
/* Do not edit below this line. */
/* Do not edit below this line. */

#include "hilo_functions.h"

#include <gtest/gtest.h>

TEST(GameStateTest, ConstructorAndSecret) {
  GameState g1{1};
  GameState g5{5};
  GameState g10{10};
  EXPECT_EQ(1, g1.secret());
  EXPECT_EQ(5, g5.secret());
  EXPECT_EQ(10, g10.secret());
}

TEST(GameStateTest, GuessesLeft) {
  GameState g1{1};
  GameState g5{5};
  GameState g10{10};
  EXPECT_EQ(4, g1.guesses_left());
  EXPECT_EQ(4, g5.guesses_left());
  EXPECT_EQ(4, g10.guesses_left());
}

TEST(GameStateTest, GuessCorrect) {
  GameState g1{1};
  GameState g5{5};
  GameState g10{10};

  EXPECT_TRUE (g1.IsGuessCorrect(1));
  EXPECT_FALSE(g1.IsGuessCorrect(2));
  EXPECT_FALSE(g1.IsGuessCorrect(3));
  EXPECT_FALSE(g1.IsGuessCorrect(4));
  EXPECT_FALSE(g1.IsGuessCorrect(5));
  EXPECT_FALSE(g1.IsGuessCorrect(6));
  EXPECT_FALSE(g1.IsGuessCorrect(7));
  EXPECT_FALSE(g1.IsGuessCorrect(8));
  EXPECT_FALSE(g1.IsGuessCorrect(9));
  EXPECT_FALSE(g1.IsGuessCorrect(10));

  EXPECT_FALSE(g5.IsGuessCorrect(1));
  EXPECT_FALSE(g5.IsGuessCorrect(2));
  EXPECT_FALSE(g5.IsGuessCorrect(3));
  EXPECT_FALSE(g5.IsGuessCorrect(4));
  EXPECT_TRUE (g5.IsGuessCorrect(5));
  EXPECT_FALSE(g5.IsGuessCorrect(6));
  EXPECT_FALSE(g5.IsGuessCorrect(7));
  EXPECT_FALSE(g5.IsGuessCorrect(8));
  EXPECT_FALSE(g5.IsGuessCorrect(9));
  EXPECT_FALSE(g5.IsGuessCorrect(10));

  EXPECT_FALSE(g10.IsGuessCorrect(1));
  EXPECT_FALSE(g10.IsGuessCorrect(2));
  EXPECT_FALSE(g10.IsGuessCorrect(3));
  EXPECT_FALSE(g10.IsGuessCorrect(4));
  EXPECT_FALSE(g10.IsGuessCorrect(5));
  EXPECT_FALSE(g10.IsGuessCorrect(6));
  EXPECT_FALSE(g10.IsGuessCorrect(7));
  EXPECT_FALSE(g10.IsGuessCorrect(8));
  EXPECT_FALSE(g10.IsGuessCorrect(9));
  EXPECT_TRUE (g10.IsGuessCorrect(10));
}

TEST(GameStateTest, GuessTooBig) {
  GameState g1{1};
  GameState g5{5};
  GameState g10{10};

  EXPECT_FALSE(g1.IsGuessTooBig(1));
  EXPECT_TRUE (g1.IsGuessTooBig(2));
  EXPECT_TRUE (g1.IsGuessTooBig(3));
  EXPECT_TRUE (g1.IsGuessTooBig(4));
  EXPECT_TRUE (g1.IsGuessTooBig(5));
  EXPECT_TRUE (g1.IsGuessTooBig(6));
  EXPECT_TRUE (g1.IsGuessTooBig(7));
  EXPECT_TRUE (g1.IsGuessTooBig(8));
  EXPECT_TRUE (g1.IsGuessTooBig(9));
  EXPECT_TRUE (g1.IsGuessTooBig(10));

  EXPECT_FALSE(g5.IsGuessTooBig(1));
  EXPECT_FALSE(g5.IsGuessTooBig(2));
  EXPECT_FALSE(g5.IsGuessTooBig(3));
  EXPECT_FALSE(g5.IsGuessTooBig(4));
  EXPECT_FALSE(g5.IsGuessTooBig(5));
  EXPECT_TRUE (g5.IsGuessTooBig(6));
  EXPECT_TRUE (g5.IsGuessTooBig(7));
  EXPECT_TRUE (g5.IsGuessTooBig(8));
  EXPECT_TRUE (g5.IsGuessTooBig(9));
  EXPECT_TRUE (g5.IsGuessTooBig(10));

  EXPECT_FALSE(g10.IsGuessTooBig(1));
  EXPECT_FALSE(g10.IsGuessTooBig(2));
  EXPECT_FALSE(g10.IsGuessTooBig(3));
  EXPECT_FALSE(g10.IsGuessTooBig(4));
  EXPECT_FALSE(g10.IsGuessTooBig(5));
  EXPECT_FALSE(g10.IsGuessTooBig(6));
  EXPECT_FALSE(g10.IsGuessTooBig(7));
  EXPECT_FALSE(g10.IsGuessTooBig(8));
  EXPECT_FALSE(g10.IsGuessTooBig(9));
  EXPECT_FALSE(g10.IsGuessTooBig(10));
}

TEST(GameStateTest, GuessTooSmall) {
  GameState g1{1};
  GameState g5{5};
  GameState g10{10};

  EXPECT_FALSE(g1.IsGuessTooSmall(1));
  EXPECT_FALSE(g1.IsGuessTooSmall(2));
  EXPECT_FALSE(g1.IsGuessTooSmall(3));
  EXPECT_FALSE(g1.IsGuessTooSmall(4));
  EXPECT_FALSE(g1.IsGuessTooSmall(5));
  EXPECT_FALSE(g1.IsGuessTooSmall(6));
  EXPECT_FALSE(g1.IsGuessTooSmall(7));
  EXPECT_FALSE(g1.IsGuessTooSmall(8));
  EXPECT_FALSE(g1.IsGuessTooSmall(9));
  EXPECT_FALSE(g1.IsGuessTooSmall(10));

  EXPECT_TRUE (g5.IsGuessTooSmall(1));
  EXPECT_TRUE (g5.IsGuessTooSmall(2));
  EXPECT_TRUE (g5.IsGuessTooSmall(3));
  EXPECT_TRUE (g5.IsGuessTooSmall(4));
  EXPECT_FALSE(g5.IsGuessTooSmall(5));
  EXPECT_FALSE(g5.IsGuessTooSmall(6));
  EXPECT_FALSE(g5.IsGuessTooSmall(7));
  EXPECT_FALSE(g5.IsGuessTooSmall(8));
  EXPECT_FALSE(g5.IsGuessTooSmall(9));
  EXPECT_FALSE(g5.IsGuessTooSmall(10));

  EXPECT_TRUE (g10.IsGuessTooSmall(1));
  EXPECT_TRUE (g10.IsGuessTooSmall(2));
  EXPECT_TRUE (g10.IsGuessTooSmall(3));
  EXPECT_TRUE (g10.IsGuessTooSmall(4));
  EXPECT_TRUE (g10.IsGuessTooSmall(5));
  EXPECT_TRUE (g10.IsGuessTooSmall(6));
  EXPECT_TRUE (g10.IsGuessTooSmall(7));
  EXPECT_TRUE (g10.IsGuessTooSmall(8));
  EXPECT_TRUE (g10.IsGuessTooSmall(9));
  EXPECT_FALSE(g10.IsGuessTooSmall(10));
}

TEST(GameStateTest, CountGuess) {
  GameState g1{1};
  ASSERT_EQ(4, g1.guesses_left());

  g1.CountGuess();
  EXPECT_EQ(3, g1.guesses_left());

  g1.CountGuess();
  EXPECT_EQ(2, g1.guesses_left());

  g1.CountGuess();
  EXPECT_EQ(1, g1.guesses_left());

  g1.CountGuess();
  EXPECT_EQ(0, g1.guesses_left());
}

TEST(GameStateTest, GameOver) {
  GameState g1{1};  // 4 left
  EXPECT_FALSE(g1.IsGameOver());
  g1.CountGuess();  // 3 left
  EXPECT_FALSE(g1.IsGameOver());
  g1.CountGuess();  // 2 left
  EXPECT_FALSE(g1.IsGameOver());
  g1.CountGuess();  // 1 left
  EXPECT_FALSE(g1.IsGameOver());
  g1.CountGuess();  // 0 left
  EXPECT_TRUE(g1.IsGameOver());
}
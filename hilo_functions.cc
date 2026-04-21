#include "hilo_functions.h"

#include "rng.h"

GameState::GameState(int secret) : secret_(secret), guesses_left_(4) {
  // DONE: complete the definition of this constructor.
  // Since this is a constructor, it should use a member initialization list
  // to initialize data members.
  // When you are done, delete this comment.
}

int GameState::secret() const {
  // DONE: write statements to implement this function, and delete this comment
  // Hint: This is a simple accessor function. The function definition only
  // needs to be a single statement.
  return secret_;  // DONE: replace this return statement with one that actually
                   // works
}

int GameState::guesses_left() const {
  // DONE: write statements to implement this function, and delete this comment
  // Hint: This is a simple accessor function. The function definition only
  // needs to be a single statement.
  return guesses_left_;  // DONE: replace this return statement with one that
                         // actually works
}

bool GameState::IsGuessCorrect(int guess) const {
  // DONE: write statements to implIsement this function, and delete this
  // comment Hint: Use an if statement.
  if (guess == secret_) {
    return true;
  }
  return false;  // DONE: replace this return statement with one that actually
                 // works
}

bool GameState::IsGuessTooBig(int guess) const {
  // DONE: write statements to implement this function, and delete this comment
  // Hint: Use an if statement.
  if (guess > secret_) {
    return true;
  }
  return false;  // DONE: replace this return statement with one that actually
                 // works
}

bool GameState::IsGuessTooSmall(int guess) const {
  // DONE: write statements to implement this function, and delete this comment
  // Hint: Use an if statement.
  if (guess < secret_) {
    return true;
  }
  return false;  // DONE: replace this return statement with one that actually
                 // works
}

void GameState::CountGuess() {
  // DONE: write statements to implement this function, and delete this comment
  guesses_left_--;
}

bool GameState::IsGameOver() const {
  // DONE: write statements to implement this function, and delete this comment
  return guesses_left_ <= 0;  // DONE: replace this return statement with one
                              // that actually works
}

int RandomSecretNumber() {
  // DONE: write statements to implement this function, and delete this comment
  // Hint: first seed the random number generator
  // then generate a random number between 1 and 10
  // finally return that random number
  RandomNumberGenerator rng(1, 10);
  return rng.Next();  // DONE: replace this return statement with one that
                      // actually works
}
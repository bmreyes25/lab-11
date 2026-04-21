
#ifndef HILO_H
#define HILO_H

class GameState {
 public:
  // Construct a GameState with the given secret number, and with 4 guesses
  // left.
  explicit GameState(int secret);

  // Accessors
  int secret() const;
  int guesses_left() const;

  // Return true if guess matches the secret number, or false otherwise.
  bool IsGuessCorrect(int guess) const;

  // Return true if guess is greater than the secret number, or false
  // otherwise.
  bool IsGuessTooBig(int guess) const;

  // Return true if guess is less than the secret number, or false otherwise.
  bool IsGuessTooSmall(int guess) const;

  // Decrement the number of guesses left.
  void CountGuess();

  // Return true if the number of guesses left is zero, or false otherwise.
  bool IsGameOver() const;

 private:
  int secret_;
  int guesses_left_;
};

// Seed a random number generator, then generate and return a random number
// between 1 and 10 inclusive.
int RandomSecretNumber();

#endif  // HILO_H_

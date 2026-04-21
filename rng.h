
#ifndef RNG_H
#define RNG_H

#include <random>

// The RandomNumberGenerator class is a wrapper around the Standard C++
// Library's Mersenne Twister pseudo random number generator.
// This class is complete and correct; please do not make any changes to it.
//
// In lieu of directly working with the [Mersenne Twister class]
// (https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine),
// this class serves as a lightweight wrapper around the necessary elements of
// the library. The usage of this class is very simple and requires a
// minimum and maximum value for initialization.
// \code
// int minimum_random_number = 1;
// int maximum_random_number = 10;
// RandomNumberGenerator my_random_number_generator{minimum_random_number,
// maximum_random_number}; int random_number =
// my_random_number_generator.next();
// \endcode
class RandomNumberGenerator {
 private:
  // A hardware entropy source (a device on your computer to give random bits)
  std::random_device rd_;
  // A sequence of random bits to seed the Mersenne Twister engine
  std::seed_seq seed_;
  // A Mersenne Twister engine
  std::mt19937 mt_engine_;
  // A uniform distribution; select numbers randomly in a uniform manner
  std::uniform_int_distribution<> uniform_dist_;

 public:
  // Constructor to the RandomNumberGenerator class
  //
  // The RandomNumberGenerator generates random integer numbers between
  //  minimum and  maximum. The constructor initializes and prepares
  // the engine. To generate a number use the <RandomNumberGenerator::next>()
  // method.
  //
  // param minimum The lowest value the random number generator will return
  // param maximum The largest value the random number generator will return
  RandomNumberGenerator(int minimum, int maximum)
      : seed_{rd_()}, mt_engine_{rd_()}, uniform_dist_{minimum, maximum} {}

  // Return a random number
  //
  // Returns a random integer number between the minimum and maximum set
  // when the constructor was called.
  // RandomNumberGenerator::RandomNumberGenerator
  //
  // returns An integer between the minimum and maximum set when
  // the constructor was called
  int Next() {
    auto random_number = uniform_dist_(mt_engine_);
    // std::cout << "Debugging: The random number is " << random_number << "\n";
    return random_number;
  }
};

// Generate a random number between min and max.
// Uses the class RandomNumberGenerator to generate and return
// a random number between min and max.
// param min The smallest value the random number generator should return
// param max The largest value the random number generator should return
// returns A random number
int RandomInteger(int min, int max){
  RandomNumberGenerator rng{min, max};
  return rng.Next();
}


#endif

#include <iostream>
#include <string>
#include <vector>

#include "demographics_functions.h"

int main(int argc, char* argv[]) {
  std::vector<State> states{ReadStates("state_demographics.csv")};

  State densest{states.front()};
  State sparsest{states.front()};
  for (const State& state : states) {
    if (state.population_density() > densest.population_density()) {
      densest = state;
    }
    if (state.population_density() < sparsest.population_density()) {
      sparsest = state;
    }
  }

  std::cout << "The densest state is " << densest.name() << " ("
            << densest.population_density() << ")\n";

  std::cout << "The sparsest state is " << sparsest.name() << " ("
            << sparsest.population_density() << ")\n";

  return 0;
}

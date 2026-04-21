
#ifndef DEMOGRAPHICS_FUNCTIONS_H
#define DEMOGRAPHICS_FUNCTIONS_H

#include <string>
#include <vector>

std::vector<std::vector<std::string>> ReadCSV(const std::string& csv_filename);

class State {
 public:
  State(const std::string& name, int population, double land_area);

  State();

  const std::string& name() const;
  int population() const;
  double land_area() const;

  double population_density() const;

 private:
  std::string name_;
  int population_;
  double land_area_;
};

std::vector<State> ReadStates(const std::string& csv_filename);

#endif  // DEMOGRAPHICS_FUNCTIONS_H

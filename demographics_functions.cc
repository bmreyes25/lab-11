#include "demographics_functions.h"

#include <cstddef>  // Added to provide "size_t"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::vector<std::string>> ReadCSV(const std::string& csv_filename) {
  std::vector<std::vector<std::string>> table;
  std::ifstream file(csv_filename);

  // read each row
  std::string line;
  while (std::getline(file, line)) {
    // read each column in this row
    std::vector<std::string> row;

    std::stringstream line_stream{line};
    while (line_stream) {
      std::string cell;
      line_stream.ignore(1);  // leading quote
      if (!std::getline(line_stream, cell, '"')) {
        break;
      }
      if (line_stream.peek() == ',') {
        line_stream.ignore(1);  // comma delimiter
      }
      row.push_back(cell);
    }

    table.push_back(row);
  }

  return table;
}

State::State(const std::string& name, int population, double land_area)
    : name_(name), population_(population), land_area_(land_area) {
  // DONE: complete the definition of this constructor.
  // Since this is a constructor, it should use a member initialization list
  // to initialize data members.
  // When you are done, delete this comment.
}

State::State() : population_(0), land_area_(0.0) {
  // DONE: complete the definition of this constructor.
  // Since this is a constructor, it should use a member initialization list
  // to initialize data members.
  // When you are done, delete this comment.
}

const std::string& State::name() const {
  // DONE: write statements to implement this function, and delete this comment
  // Hint: This is a simple accessor function. The function definition only
  // needs to be a single statement.
  return name_;  // DONE: replace this return statement with one that actually
                 // works
}

int State::population() const {
  // DONE: write statements to implement this function, and delete this comment
  // Hint: This is a simple accessor function. The function definition only
  // needs to be a single statement.
  return population_;  // DONE: replace this return statement with one that
                       // actually works
}

double State::land_area() const {
  // DONE: write statements to implement this function, and delete this comment
  // Hint: This is a simple accessor function. The function definition only
  // needs to be a single statement.
  return land_area_;  // DONE: replace this return statement with one that
                      // actually works
}

double State::population_density() const {
  // DONE: write statements to implement this function, and delete this comment
  // Hint: Population density is the population divided by the land area.
  if (land_area_ == 0.0) {
    return 0.0;
  }
  return static_cast<double>(population_) /
         land_area_;  // DONE: replace this return statement with one that
                      // actually works
}

std::vector<State> ReadStates(const std::string& csv_filename) {
  // DONE: write statements to implement this function, and delete this comment
  // Hint: this function should:
  //  - create an empty vector of States
  std::vector<State> states;
  //  - call ReadCSV to create a 2D vector of strings
  std::vector<std::vector<std::string>> raw_data = ReadCSV(csv_filename);
  //  - loop through each row of the CSV
  //    - skip the first row that contains a header
  for (size_t i = 1; i < raw_data.size(); ++i) {
    const std::vector<std::string>& row = raw_data[i];
    //    - for all other rows:
    if (row.size() > 47) {
      //      - get the name (as a string) from column 0
      std::string name = row[0];
      //      - get the population (as a string) from column 2
      //        convert the string to an int with std::stoi
      int population = std::stoi(row[2]);
      //      - get the land area (as a string) from column 47
      //        convert the string to a double with std::stod
      double land_area = std::stod(row[47]);
      //      - create a State object with the name, population, land area
      //      - add the State to your vector with push_back
      states.emplace_back(name, population, land_area);
    }
  }

  return states;  // DONE: replace this return statement with one
                  // that actually works
}
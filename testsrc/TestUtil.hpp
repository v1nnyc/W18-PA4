// Test Utils for PA4
//
// DO NOT MODIFY

#ifndef __TEST_UTIL_HPP__
#define __TEST_UTIL_HPP__

#include <iostream>
#include <fstream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include <string>
#include <ctime>

// exit with bad file handler
void failBadFile() {
  std::cerr << "Unable to open file or incorrectly formatted." << std::endl;
  exit(1);
}

int getSoln(std::string fname) {
  std::ifstream input (fname.c_str(), std::ios::in);
  int soln;
  std::string line;
  getline(input, line);
  std::stringstream stream(line);
  stream >> soln;
  return soln;
}


// Process single number from file
void getNum(std::ifstream &input, int& num) {
  std::string line;

  if (getline(input, line)) {
    std::stringstream stream(line);
    stream >> num;
  } else {
    failBadFile();
  }
}

#endif

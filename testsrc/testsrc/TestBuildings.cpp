// Tester for PA4 Ice
//
// DO NOT MODIFY

#ifndef __TEST_ICE_CPP__
#define __TEST_ICE_CPP__

#include "TestUtil.hpp"
#include "TwoD_Array.hpp"
#include "Buildings.hpp"

// run a single test
std::pair<int, double> runSingle(const char* fname) {
  std::ifstream input (fname, std::ios::in);
  int rows;
  int cols;
  getNum(input, rows);
  getNum(input, cols);

  TwoD_Array<int> survey(rows, cols);
  for (int i = 0; i < rows; i++) {
    std::string line;
    if (getline(input, line)) {
      std::stringstream stream(line);
      for (int j = 0; j < cols; j++) {
        stream >> survey.at(i, j);
      }
    }
    else {
      failBadFile();
    }
  }
  clock_t start, end;
  double msecs;
  start = clock();
  int res = buildings(survey);
  end = clock();
  msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
  return std::pair<int, double>(res, msecs);
}

int main(int argc, char * argv[]) {
  if (argc == 2) {
    // run single test 
    std::pair<int, double> res = runSingle(argv[1]); 
    std::cout << "Total buildings: " << res.first << std::endl;
  } else {
    std::string btest = "testcases/buildings/buildings";
    std::string bsoln = "solutions/buildings/buildings";
    for (int i = 1; i <= 10; i++) {
      std::pair<int, double> res = runSingle((btest + std::to_string(i)).c_str());
      int soln = getSoln((bsoln + std::to_string(i)).c_str());
      if (res.first == soln) {
        std::cout << "Test " << i << ": PASSED" << std::endl;
      } else {
        std::cout << "Test " << i << ": FAILED" << std::endl;
        std::cout << "Expected " << soln << " but got " << res.first << std::endl;
      }
    }
  }
  return 0;
}

#endif

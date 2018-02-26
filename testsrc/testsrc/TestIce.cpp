// Tester for PA4 Ice
//
// DO NOT MODIFY

#ifndef __TEST_ICE_CPP__
#define __TEST_ICE_CPP__

#include "TestUtil.hpp"
#include "TwoD_Array.hpp"
#include "Ice.hpp"

// run a single test
std::pair<int, double> runSingle(const char* fname) {
  std::ifstream input (fname, std::ios::in);
  int rows;
  int cols;
  getNum(input, rows);
  getNum(input, cols);

  TwoD_Array<int> rooms(rows, cols);
  for (int i = 0; i < rows; i++) {
    std::string line;
    if (getline(input, line)) {
      std::stringstream stream(line);
      for (int j = 0; j < cols; j++) {
        stream >> rooms.at(i, j);
      }
    }
    else {
      failBadFile();
    }
  }
  clock_t start, end;
  double msecs;
  start = clock();
  int res = ice(rooms);
  end = clock();
  msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
  return std::pair<int, double>(res, msecs);
}

int main(int argc, char * argv[]) {
  if (argc == 2) {
    // run single test 
    std::pair<int, double> res = runSingle(argv[1]); 
    std::cout << "Min ice required: " << res.first << std::endl;
  } else {
    std::string btest = "testcases/ice/ice";
    std::string bsoln = "solutions/ice/ice";
    for (int i = 1; i <= 10; i++) {
      if (i == 9 || i == 10) {
        std::pair<int, double> res = runSingle((btest + std::to_string(i)).c_str());
        int soln = getSoln((bsoln + std::to_string(i)).c_str());
        if (res.second > 750) {
          std::cout << "Test " << i << ": FAILED" << std::endl;
          std::cout << "Function ran in " << res.second << "ms but needed to complete in 500ms." << std::endl; 
        } else if (res.first == soln) {
          std::cout << "Test " << i << ": PASSED" << std::endl;
        } else {
          std::cout << "Test " << i << ": FAILED" << std::endl;
          std::cout << "Expected " << soln << " but got " << res.first << std::endl;
        }
      } else {
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

  }
  return 0;
}

#endif

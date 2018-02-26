// Tester for PA4 Serial
//
// DO NOT MODIFY

#ifndef __TEST_SERIAL_CPP__
#define __TEST_SERIAL_CPP__

#include "TestUtil.hpp"
#include "Serial.hpp"

// run a single test
std::pair<int, double> runSingle(const char* fname) {
  std::ifstream input (fname, std::ios::in);
  int numSerials;
  getNum(input, numSerials);

  std::vector<int> nums;
  std::string line;
  if(getline(input, line)) {
    std::stringstream stream(line);
    for (int i = 0; i < numSerials; i++) {
      int next;
      stream >> next;
      nums.push_back(next);
    }
  } else {
    failBadFile();
  }

  clock_t start, end;
  double msecs;
  start = clock();
  int res = serial(nums);
  end = clock();
  msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
  return std::pair<int, double>(res, msecs);
}

int main(int argc, char * argv[]) {
  if (argc == 2) {
    // run single test 
    std::pair<int, double> res = runSingle(argv[1]); 
    std::cout << "Repeated serial number: " << res.first << std::endl;
  } else {
    std::string btest = "testcases/serial/serial";
    std::string bsoln = "solutions/serial/serial";
    bool retry = true;
    for (int i = 1; i <= 10; i++) {
      if (i == 9 || i == 10) {
        std::pair<int, double> res = runSingle((btest + std::to_string(i)).c_str());
        int soln = getSoln((bsoln + std::to_string(i)).c_str());
        if (res.second > 3) {
          std::cout << "Test " << i << ": FAILED" << std::endl;
          std::cout << "Function ran in " << res.second << "ms but needed to complete in 3ms." << std::endl; 
          if(retry) {
            i--;
            retry = false;
            std::cout <<"Retrying..."<<std::endl;
          } else {
            retry = true;
          }
        } else if (res.first == soln) {
          std::cout << "Test " << i << ": PASSED" << std::endl;
          retry = true;
        } else {
          std::cout << "Test " << i << ": FAILED" << std::endl;
          std::cout << "Expected " << soln << " but got " << res.first << std::endl;
          retry = true;
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

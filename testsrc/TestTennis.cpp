// Tester for PA4 Tennis
//
// DO NOT MODIFY

#ifndef __TEST_TENNIS_CPP__
#define __TEST_TENNIS_CPP__

#include "TestUtil.hpp"
#include "Tennis.hpp"

// Process single interval from file
Interval getInterval(std::ifstream &input) {
  std::string line;
  int start;
  int end;
  if (getline(input, line)) {
    std::stringstream stream(line);
    stream >> start;
    stream >> end;
  }
  if (start > end) {
    failBadFile();
  }
  return Interval(start, end);
}

// run a single test
std::pair<int, double> runSingle(const char* fname) {
  std::ifstream input (fname, std::ios::in);
  int numLessons;
  getNum(input, numLessons);

  std::vector<Interval> lessons;
  for (int i = 0; i < numLessons; i++) {
    Interval next = getInterval(input);
    lessons.push_back(next);
  }

  clock_t start, end;
  double msecs;
  start = clock();
  int res = tennis(lessons);
  end = clock();
  msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
  return std::pair<int, double>(res, msecs);
}

int main(int argc, char * argv[]) {
  if (argc == 2) {
    // run single test 
    std::pair<int, double> res = runSingle(argv[1]); 
    std::cout << "Min courts required: " << res.first << std::endl;
  } else { 
    std::string btest = "testcases/tennis/tennis";
    std::string bsoln = "solutions/tennis/tennis";
    for (int i = 1; i <= 10; i++) {
      /*
      if (i == 9 || i == 10) {
        std::pair<int, double> res = runSingle((btest + std::to_string(i)).c_str());
        int soln = getSoln((bsoln + std::to_string(i)).c_str());
        if (res.second > 500) {
          std::cout << "Test " << i << ": FAILED" << std::endl;
          std::cout << "Function ran in " << res.second << "ms but needed to complete in 500ms." << std::endl; 
        } else if (res.first == soln) {
          std::cout << "Test " << i << ": PASSED" << std::endl;
        } else {
          std::cout << "Test " << i << ": FAILED" << std::endl;
          std::cout << "Expected " << soln << " but got " << res.first << std::endl;
        }
      } else {
      */
      std::pair<int, double> res = runSingle((btest + std::to_string(i)).c_str());
      int soln = getSoln((bsoln + std::to_string(i)).c_str());
      if (res.first == soln) {
        std::cout << "Test " << i << ": PASSED" << std::endl;
      } else {
        std::cout << "Test " << i << ": FAILED" << std::endl;
        std::cout << "Expected " << soln << " but got " << res.first << std::endl;
      }
      //}
    }
  }
  return 0;
}

#endif

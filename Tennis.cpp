// CSE 101 Winter 2018, PA 4
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
// Due: March 10th, 2018 at 11:59 PM


//make TestTennis
//build/TestTennis testcases/tennis/input_file
//build/TestTennis

#ifndef __TENNIS_CPP__
#define __TENNIS_CPP__

#include "Tennis.hpp"
#include <iostream>
#include <queue>

struct LessThanByEnd
{
  bool operator()(const Interval& lhs, const Interval& rhs) const
  {
    return lhs.end > rhs.end;
  }
};

int tennis(std::vector<Interval> lessons) {
	std::sort(lessons.begin(),lessons.end(),
          [](const Interval& lhs, const Interval& rhs)
          {
          	return lhs.start < rhs.start;
          });

	int roomCount = 0;
	std::priority_queue<Interval, std::vector<Interval>, LessThanByEnd> mypq;
	mypq.push(lessons[0]);
	for(int i = 1; i < lessons.size(); i++){
		while(!mypq.empty() && mypq.top().end <= lessons[i].start){
			std::cout<<"popped: "<<mypq.top().start<<","<<mypq.top().end<<"\n";
			mypq.pop();

		}
		mypq.push(lessons[i]);
		std::cout<<"pushed: "<<lessons[i].start<<","<<lessons[i].end<<"\n";
		roomCount = std::max(roomCount, (int)mypq.size());
	}
	return roomCount;
}
#endif

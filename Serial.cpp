// CSE 101 Winter 2018, PA 4
//
// Name: Vincent Cannalla/Colin Van Winkle
// PID: A13006747 A12792067
// Sources of Help: none
// Due: March 10th, 2018 at 11:59 PM


//make TestSerial
//build/TestSerial testcases/serial/input_file
//build/TestSerial

#ifndef __SERIAL_CPP__
#define __SERIAL_CPP__

#include "Serial.hpp"
#include <iostream>


int serial(std::vector<int> nums) {
  int min = 0;
  int max = nums.size()-1;
  int mid;
  while(max > min){
  	mid = ((max+min)/2);
  	if(nums[mid + 1] == nums[mid] || nums[mid - 1] == nums[mid]){
  		return nums[mid];
  	}
  	if(nums[mid] < (nums[min] + (mid - min))){
  		max = mid;
  	}
  	else{
  		min = mid;
  	}
  }
  return 0;
}
#endif

// CSE 101 Winter 2018, PA 4
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: March 10th, 2018 at 11:59 PM


//make TestIce
//build/TestIce testcases/ice/input_file
//build/TestIce


#ifndef __ICE_CPP__
#define __ICE_CPP__

#include "Ice.hpp"

int min(int x, int y){ 
	if( y == 0)
		return 0;
	return (((x) < (y)) ? (x) : (y));
}

int ice(TwoD_Array<int> rooms) {
	TwoD_Array<int> * ice = new TwoD_Array<int>(rooms.getNumRows(), rooms.getNumCols());
	ice->at(rooms.getNumRows()-1, rooms.getNumCols()-1) = 1;
	//initialize array to 0
	for(int i = rooms.getNumRows() - 1; i >= 0; i--){
		for(int j = rooms.getNumCols() - 1; j>=0; j--){
			ice->at(i,j)=1;
		}
	}

	ice->at(rooms.getNumRows()-1, rooms.getNumCols()-1) = 1;

	for(int i = rooms.getNumRows() - 1; i >= 0; i--){
		for(int j = rooms.getNumCols() - 1; j>=0; j--){
			int iceAmount = 0;
			if(ice->at(i,j) + rooms.at(i,j) > 0){
				iceAmount = ice->at(i,j) + rooms.at(i,j);
			}
			else{
				iceAmount = 0;
			}
			if(j > 0){
				ice->at(i, j - 1) = iceAmount; //min(iceAmount, ice->at(i, j - 1));
			}
			if(i>0){
				ice->at(i - 1, j) = iceAmount; //min(iceAmount, ice->at(i-1, j));
			}
		ice->printOut();
		}
		
	}
	
	if(ice->at(0,0)+rooms.at(0,0) < 1)
		return 1;
	else
  		return ice->at(0,0)+rooms.at(0,0);
}
#endif

// CSE 101 Winter 2018, PA 4
//
// Name: Vincent Cannalla/Colin Van Winkle
// PID: A13006747 A12792067
// Sources of Help: none
// Due: March 10th, 2018 at 11:59 PM


//make TestIce
//build/TestIce testcases/ice/input_file
//build/TestIce


#ifndef __ICE_CPP__
#define __ICE_CPP__

#include "Ice.hpp"


int ice(TwoD_Array<int> rooms) {
	int cols = rooms.getNumCols() - 1;
	int rows = rooms.getNumRows() - 1;
	TwoD_Array<int> * netChange = new TwoD_Array<int>(rows + 1, cols + 1);
	for(int i = rows; i >= 0; i--){
		for(int j = cols; j>=0; j--){
			netChange->at(i,j)=0;
		}
	}
	if(rooms.at(rows, cols) > 0){
		netChange->at(rows, cols) = 1 + rooms.at(rows, cols);
	}
	else 
		netChange->at(rows, cols) = 1;

	for(int i = rows; i >= 0; i--){
		for(int j = cols; j>=0; j--){
			if(i != rows && j != cols){
				int a;
				if(rooms.at(i,j) < 0){
					if(abs(rooms.at(i, j)) < netChange->at(i, j+1)){
						a = netChange->at(i, j+1) + rooms.at(i, j);
					}
					else {
						a = 1;
					}
				}
				else{
					a = rooms.at(i, j) + netChange->at(i, j+1); 
				}
				int b;
				if(rooms.at(i,j) < 0){
					if(abs(rooms.at(i, j)) < netChange->at(i+1, j)){
						b = netChange->at(i+1, j) + rooms.at(i, j);
					}
					else {
						b = 1;
					}
				}
				else{
					b = rooms.at(i, j) + netChange->at(i+1, j); 
				}
				netChange->at(i,j) = (a<b)? a: b;
			}
			else if(i == rows && j != cols){
				if(rooms.at(rows, j) < 0){
					if(abs(rooms.at(rows, j)) < netChange->at(rows, j+1)){
						netChange->at(rows, j) = netChange->at(rows, j+1) - abs(rooms.at(rows, j));
					}
					else {

						netChange->at(rows, j) = 1;
					}
				}
				else{
					netChange->at(rows, j) = rooms.at(rows, j) + netChange->at(rows, j+1); 
				}
			}
			else if(i != rows && j == cols){
				if(rooms.at(i, cols) < 0){
					if(abs(rooms.at(i, cols)) < netChange->at(i+1, cols)){
						netChange->at(i, cols) = netChange->at(i+1, cols) + rooms.at(i, cols);
					}
					else {
						netChange->at(i, cols) = 1;
					}
				}
				else{
					netChange->at(i, cols) = rooms.at(i, cols) + netChange->at(i+1, cols); 
				}
			}
		}
	}
	return netChange->at(0,0);

			
}
#endif

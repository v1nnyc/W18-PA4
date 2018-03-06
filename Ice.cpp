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
	int cols = rooms.getNumCols() - 1;
	int rows = rooms.getNumRows() - 1;
	TwoD_Array<int> * netChange = new TwoD_Array<int>(rows + 1, cols + 1);
	//initialize array to 0
	for(int i = rows; i >= 0; i--){
		for(int j = cols; j>=0; j--){
			netChange->at(i,j)=0;
		}
	}

	netChange->at(rows, cols) = 0- rooms.at(rows, cols);

	//netChange->printOut();
	for(int i = rows; i >= 0; i--){
		for(int j = cols; j>=0; j--){
			if(i == rows && j != cols){
				netChange->at(rows, j) = netChange->at(rows, j+1) - rooms.at(rows, j);
			}
			else if(i != rows && j == cols){
				netChange->at(i, cols) = netChange->at(i+1, cols) - rooms.at(i, cols);
			}
			else{
				int a = netChange->at(i + 1, j) - rooms.at(i, j);
				int b = netChange->at(i, j + 1) - rooms.at(i, j);
				if(a > 0)
					netChange->at(i,j) = a;
				else if (b > 0)
					netChange->at(i,j) = b;
				else
				netChange->at(i,j) = (abs(a) < abs(b))? a: b;
				//std::cout<<a<<"\n";
				//std::cout<<b<<"\n";

			}
		//netChange->printOut();
		}
		
	}
	
	if(netChange->at(0,0) > 1)
		if(netChange->at(0,0) > 0 && rooms.at(0,0) < 0)
			return 1;
		else
			return 1 + rooms.at(0,0);

	else if(netChange->at(0,0) < 0)
		return 1 + rooms.at(0,0);

  	//	return 1 - netChange->at(0,0);
	//return 0;
}
#endif

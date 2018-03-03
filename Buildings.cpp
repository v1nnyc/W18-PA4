// CSE 101 Winter 2018, PA 4
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: March 10th, 2018 at 11:59 PM

//make TestBuildings
//build/TestBuildings testcases/buildings/input_file
//build/TestBuildings

#ifndef __BUILDINGS_CPP__
#define __BUILDINGS_CPP__

#include "Buildings.hpp"


void remove(TwoD_Array<int> survey, int i, int j){

	survey.at(i,j) = 0;
	if(i > 0 &&survey.at(i-1,j) == 1){
		remove(survey, i-1, j);
	}
	if(i < survey.getNumRows()-1 && survey.at(i+1,j) == 1){
		remove(survey, i+1, j);
	}
	if(j>0 && survey.at(i,j-1) == 1){
		remove(survey, i, j-1);
	}
	if(j < survey.getNumCols()-1 && survey.at(i,j+1) == 1){
		remove(survey, i, j+1);
	}
}

int buildings(TwoD_Array<int> survey) {
	int rows = survey.getNumRows();
	int cols = survey.getNumCols();

	int count = 0;

	TwoD_Array<int> * arr = new TwoD_Array<int>(rows+2, cols+2);
	//survey.printOut();
	for(int i = 0; i<rows; i++){

		for(int j = 0; j<cols; j++){

			if(survey.at(i,j) == 1){

				count++;
				//std::cout<<"i: " << i << " j: "<< j<<"\n";
				remove(survey, i, j);
				//survey.printOut();


			}
		}
	}
	return count;
}
#endif

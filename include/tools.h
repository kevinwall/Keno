#ifndef TOOLS_H_
#define TOOLS_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
//#include "Player.h"

int * unique( int * first, int* last);
void qsort( int* first, int* last);
void reader_file( std::ifstream&, int * &, float&, int&,int& );	
//void table( std::vector<std::vector<float>> , Player);

#endif
#include <iostream>
#include <fstream>
#include <string>
#include "../include/gamemanager.h"

int main(int argc, char const *argv[])
{
	std::ifstream file(argv[1]);
	std::string string;
	long int money;
	int number_of_bet, count;

	if( agrc != 2){
		std::cerr << " Número de argumentos invalidos\n";
	}

	if(file.is_open()){
		file >> money;
		file >> number_of_bet;
		getline(file,string);
	}

	std::ostringstream oss(string); 
	int A[15], i = 0;

	while( oss.empty()){
		oss >> A[i];
		i++
	}

	return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
//#include "../include/gamemanager.h"

int main(int argc, char const *argv[])
{
	std::ifstream file(argv[1]);
	std::string string;
	long int money;
	int number_of_bet;

	if( argc != 2){
		std::cerr << " Número de argumentos invalidos\n";
		return 0;
	}

	if(!file.is_open()){
		std::cerr << " Arquivo vazio\n";
		return 0;	
	}

	getline(file,string);
	std::stringstream oss(string); 
	std::cout <<"String atual: "<<string<<std::endl;
	oss >> money;
	oss.clear();

	getline(file,string);
	oss.str(string);
	std::cout <<"String atual: "<<string<<std::endl;
	oss >> number_of_bet;
	oss.clear();

	getline(file,string);
	oss.str(string);
	std::cout <<"String atual: "<<string<<std::endl;

	int A[15], i = 0;


	while(oss.good())
	{
		oss >> A[i];
		i++;
	}

	std::cout << "Dinheiro: " << money << "\n";
	std::cout << "Numero de apostas: " << number_of_bet << "\n";

	std::cout<<"Vetor de apostas: [";
	for(auto j{0}; j < i; j++)
	{
		std::cout << A[j] << " ";
	}
	std::cout <<"]"<<std::endl;

	return 0;
}
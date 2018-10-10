#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
//#include "../include/gamemanager.h"
//#include "keno.h"

int main(int argc, char const *argv[])
{
	std::ifstream file(argv[1]);
	std::string string;
	float money;
	int number_of_bet, dummy;

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

	while(! (oss >> money))
	{
		oss.clear();
		getline(file,string);
		oss.str(string);
	}

	oss.clear();

	getline(file,string);
	oss.str(string);
	
	while(! (oss >> number_of_bet))
	{
		oss.clear();
		getline(file,string);
		oss.str(string);
	}

	oss.clear();

	getline(file,string);
	oss.str(string);

	int A[15], i = 0;

	while(! (oss >> dummy) )
	{
		oss.clear();
		getline(file,string);
		oss.str(string);
	}

	A[i] = dummy;
	i++;

	while(oss>>A[i])
	{
		i++;
		
		if(i > 14)
		{
			break;
		}
	}

	std::cout << "Dinheiro: " << money << "\n";
	std::cout << "Numero de apostas: " << number_of_bet << "\n";

	std::cout<<"Vetor de apostas: [ ";

	for(auto j{0}; j < i; j++)
	{
		std::cout << A[j] << " ";
	}
	std::cout <<"]"<<std::endl;

	return 0;
}
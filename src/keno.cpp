#include "keno.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

keno::keno()
{

	int num = 1;

	keno_table = new int[80];

	for( auto i = 0; i < 80; i++)
	{
		keno_table[i] = num++;
	}
}

keno::~keno(){
	delete [] keno_table;
}


int main()
{
	keno k;
	std::string string1, string2;
	std::ifstream file("Blank.txt");
	std::stringstream oss;
	int i;
	
	std::getline(file, string1);
	std::cout<<string1<<std::endl;
	std::getline(file, string1);
	std::cout<<string1<<std::endl;

	oss.str(string1);

	oss >> i;

	if(oss.fail())
	{
		std::cout<<i<<std::endl;
		std::cout<<"Falhou"<<std::endl;
	}

	oss.clear();
	std::getline(file, string1);
	oss.str(string1);
	oss>>i;
	std::cout<<i<<std::endl;
	if(oss.fail())
	{
		
		std::cout<<"Falhou"<<std::endl;
	}


	string2 = " ";

	std::cout<<"Comparação: "<<string1.compare(string2)<<std::endl;

	return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
//#include "../include/gamemanager.h"
#include "keno.h"
#include "Player.h"
#include "gamemanager.h"

int* unique (int *first, int *last);

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

	int i = 0;
	int *A = new int[15];

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

	auto last = unique(A, A+i+1);

	std::cout<<"Tamanho de size: "<<last-A<<std::endl;

	Player player_1(A, last-A, money);

	player_1.print_bet();

	std::cout<<"Seu Dinheiro atual é: "<<player_1.get_money()<<std::endl;

	keno game;

	gamemanager mng;

	game.shuffle_keno();

	mng.get_bet_money(player_1, number_of_bet);

	auto lucro = mng.balance(player_1, game);

	player_1.set_money(player_1.get_money()+lucro);

	std::cout<<"Seu Dinheiro atual é: "<<player_1.get_money()<<std::endl;

	return 0;
}

int * unique (int * first, int * last)
{
	int aux;
	last--;
	int *slow = last;
	bool flag;

	while(first != last)
	{
		auto fast = first;
		flag = false;

		while(fast != last or fast > last)
		{
			if(*first == *fast and first != fast)
			{
				aux = *fast;
				*fast = *(fast+1);
				*(fast+1) = aux;
				flag = true;
			}	
			fast++;
		}

		if(flag == true)
		{
			slow--;
		}
		first++;
	}

	return slow;

}
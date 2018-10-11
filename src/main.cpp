#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
//#include "../include/gamemanager.h"
#include "keno.h"
#include "tools.h"
#include "Player.h"
#include "gamemanager.h"

int* unique (int *first, int *last);

int main(int argc, char const *argv[])
{
	
	int * A = new int[15];
	float money;
	int number_of_bet;

	if( argc != 2){
		std::cerr << " Número de argumentos invalidos\n";
		return 0;
	}

	std::ifstream file(argv[1]);

	int i = 0;

	if(!file.is_open()){
		std::cerr << " Arquivo vazio\n";
		return 0;	
	}

	reader_file( file,  A,  money, number_of_bet, i);

	//std::cout << "Dinheiro: " << money << "\n";
	//std::cout << "Numero de apostas: " << number_of_bet << "\n";

	

	auto last = unique(A, A+i+1);

	//std::cout<<"Tamanho de size: "<<last-A<<std::endl;

	qsort( A, last);

	Player player_1(A, last-A, money);

	//player_1.print_bet();

	//std::cout<<"Seu Dinheiro atual é: "<<player_1.get_money()<<std::endl;

	keno game;

	gamemanager mng;

	game.shuffle_keno();

	mng.get_bet_money(player_1, number_of_bet);

	auto wage = money/number_of_bet;

	std::cout << "Bet successfully read!" << std::endl<<std::endl << 
				   "You are going to wage a total of $ " << money << " dollars." << std::endl 
				   << "Going for a total of " << number_of_bet << " rounds, waging $"
				   << wage << " per round."<< std::endl << "Your bet has " << player_1.get_size()
				   << " numbers. They are:";
	player_1.print_bet();

	mng.print_table(player_1);

	for(auto k{0}; k < number_of_bet; k++)
	{
		player_1.set_money(player_1.get_money() - wage);

		std::cout<<"This is round #"<<k+1<<" of "<<number_of_bet<<", and your wage is $"<<wage<<". Good luck!"<<std::endl;

		auto result = game.get_chosen();
		std::cout<<"The hits are: [";
		for(auto cs{0}; cs < 20; cs++)
		{
			std::cout<<result[cs]<<" ";
		}
		std::cout<<"]"<<std::endl;

		mng.balance(player_1, game);

		game.shuffle_keno();

	//player_1.set_money(player_1.get_money()+lucro);

	//std::cout<<"Seu Dinheiro atual é: "<<player_1.get_money()<<std::endl;

	}

	return 0;
}


#include "gamemanager.h"


int gamemanager::comparate_bet ( Player& player_, keno& keno_){
	int hints = 0;
	auto bets = player_.get_bet();
	auto keno_numbers = keno_.get_chosen(); //replace

	int * p_hits = new int[player_.get_size()];

	auto first = bets; //replace
	auto last = bets+player_.get_size(); //replace

	while( first != last ){
		if( linear_search_keno( *first, keno_numbers
			, keno_numbers+20)){
			
			p_hits[hints] = *first;
			hints++;	
		}
		first++;
	}

	if(hints > 0)
	{
		std::cout<<"You hit the following number(s) [ ";
		for(auto i{0}; i < hints; i++)
		{
			std::cout<<p_hits[i]<<" ";
		} 
		std::cout<<"] a total of "<<hints<<" hits out of "<<player_.get_size()<<std::endl<<std::endl;
	}

	return hints;
}

bool gamemanager::linear_search_keno( int n , const int * first, const int * last){
	while( first != last ){
		if( *first == n ){
			return true;
		}
		first++;
	}
	return false;
}

void gamemanager::balance( Player& player_  , keno& keno_){
	int hints = comparate_bet( player_, keno_); //replace

	float balance_mult = payout_table[player_.get_size()][hints];

	float balance_ = bet_money +(bet_money * balance_mult);

	std::cout<<"Payout rate is "<<balance_mult<<", thus you came out with: $"<<balance_<<std::endl<<std::endl;

	std::cout<<"Dinheiro atual: "<<player_.get_money()<<std::endl;

}

void gamemanager::get_bet_money(Player& player_, int number_of_bet)
{
	bet_money = player_.get_money() / number_of_bet;

}

void gamemanager::print_table(Player& player_)
{
	auto size = player_.get_size();

	std::cout<<"Hits:   ";
	for(size_t i{0}; i <= size; i++)
	{
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;

	std::cout<<"Payout: ";
	for(size_t i{0}; i < size; i++)
	{
		std::cout<<payout_table[size][i]<<" ";
	}
	std::cout<<std::endl<<std::endl;
}


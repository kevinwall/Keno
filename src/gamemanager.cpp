#include "gamemanager.h"


int gamemanager::comparate_bet ( Player& player_, keno& keno_){
	int hints = 0;
	auto bets = player_.get_bet();
	auto keno_numbers = keno_.get_chosen(); //replace

	auto first = bets; //replace
	auto last = bets+player_.get_size(); //replace

	while( first != last ){
		if( linear_search_keno( *first, keno_numbers
			, keno_numbers+20)){
			hints++;
		}
		first++;
	}

	std::cout<<"Número de acertos: "<<hints<<std::endl;

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

float gamemanager::balance( Player& player_  , keno& keno_){
	int hints = comparate_bet( player_, keno_); //replace

	float balance_mult = payout_table[player_.get_size()][hints];
	float balance_ = bet_money +(bet_money * balance_mult);

	return balance_;
}

float gamemanager::get_bet_money(Player& player_, int number_of_bet)
{
	bet_money = player_.get_money() / number_of_bet;

	player_.set_money(player_.get_money() - bet_money);

	return bet_money;
}
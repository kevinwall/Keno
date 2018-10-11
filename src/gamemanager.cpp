#include "../include/gamemanager.h"

int gamemanager::comparate_bet ( Player player_, keno keno_){
	int hints = 0;
	auto bets = player_.get_bet();
	auto keno_numbers = keno_->keno_chosen;

	auto first = std::begin(bets);
	auto last = std::end(bets);

	while( first != last ){
		if( linear_search_keno( *first,std::begin(keno_numbers)
			, std::end(keno_numbers))){
			hints++;
			first++;
		}
		first++;
	}

	return hints;
}

bool gamemanager::linear_search_keno( int n , int * first, int * last){
	while( first != last ){
		if( *first == n ){
			return true;
		}
		first++;
	}
	return false;
}

float gamemanager::balance( Player player_  , keno keno_, int number_of_bet){
	int hints = comparate_bet( player_, keno_);

	float balance_mult = payout_table[player_.size()][hints];
	float balance_ = (get_money()/number_of_bet) * balance_mult;

	return balance_;
}
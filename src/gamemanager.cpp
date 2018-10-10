#include "../include/gamemanager.h"

int gamemanager::comparate_bet ( Player player_, keno keno_){
	int count = 0;
	auto bets = player_.get_bet();
	auto keno_numbers = keno_->keno_chosen;

	auto first = std::begin(bets);
	auto last = std::end(bets);

	while( first != last ){
		if( linear_search_keno( *first,std::begin(keno_numbers)
			, std::end(keno_numbers))){
			count++;
			first++;
		}
		first++;
	}

	return count;
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
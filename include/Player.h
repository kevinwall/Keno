#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{
	public:
		Player(int *bet_numbers, size_t size, float money);

		~Player();

		float get_money();

		void set_money(float money);

		void print_bet();

		int * get_bet();

		size_t get_size();

	private:
		int *bet_numbers;
		size_t size;
		float money;
};

#endif
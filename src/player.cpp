#include "Player.h"

Player::Player(int *bet_numbers, size_t size, float money)
{
	this->bet_numbers = new int[size];

	for(size_t i{0}; i < size; i++)
	{
		this->bet_numbers[i] = bet_numbers[i];
	}

	this->money = money;

	this->size = size;
}

Player::~Player()
{
	delete [] bet_numbers;
}

float Player::get_money()
{
	return money;
}

void Player::set_money(float& money)
{
	this->money = money;
}

void Player::print_bet()
{
	std::cout<<"Sua aposta é: [ ";
	for(size_t i{0}; i < size; i++)
	{
		std::cout<<bet_numbers[i]<<" ";
	}
	std::cout<<"]"<<std::endl;
}

const int * Player::get_bet()
{
	return bet_numbers;
}
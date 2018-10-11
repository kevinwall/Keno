#include "Player.h"

// Construtor da classe que cria o vetor de apostas e copia os valores do vetor parâmetro
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

// Destrutor que deleta o vetor alocado dinamicamente
Player::~Player()
{
	delete [] bet_numbers;
}

// Função que retorna o tamanho da aposta para acesso de certas funções
size_t Player::get_size(){
	return size-1;
}

// Função que retorna o dinheiro atual do jogador
float Player::get_money()
{
	return money;
}

// Função que modifica o dinheiro atual do jogador
void Player::set_money(float money)
{
	this->money = money;
}

// Função que imprime o vetor de aposta do jogador
void Player::print_bet()
{
	std::cout<<" [ ";
	for(size_t i{0}; i < size; i++)
	{
		std::cout<<bet_numbers[i]<<" ";
	}
	std::cout<<"]"<<std::endl;
}

// Função que retorna uma referência constante do vetor de apostas.
const int * Player::get_bet()
{
	return bet_numbers;
}
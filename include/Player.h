#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

/**
*@brief Classe Player que é responsável por guardar os dados do jogador (dinheiro e os números da aposta).
*/
class Player
{
	public:
		/**
		*@brief Construtor da classe que inicializa o vetor de apostas baseado no vetor filtrado na main.
		*@param int *bet_numbers vetor filtrado na main.
		*@param size_t size quantidade de números da aposta.
		*@param float money dinheiro do jogador fornecido pelo arquivo de entrada.
		*/
		Player(int *bet_numbers, size_t size, float money);

		/**
		*@brief Destrutor da classe que deleta o vetor bet_numbers que foi alocado dinamicamente.
		*/
		~Player();

		/**
		*@brief Função get_money que retorna o dinheiro atual do jogador.
		*/
		float get_money();

		/**
		*@brief Função set_money que atualiza o dinheiro atual do jogador.
		*@param float money quantidade atual de dinheiro do jogador (depois da aposta).
		*/
		void set_money(float money);

		/**
		*@brief Função print_bet que imprime o vetor aposta.
		*/
		void print_bet();

		/**
		*@brief Função get_bet que retorna uma referência constante para o vetror de aposta do jogador.
		*/
		const int * get_bet();

		/**
		*@brief Função get_size que retorna o tamanho da aposta do jogador.
		*/
		size_t get_size();

	private:
		// Vetor que guarda os números da aposta do jogador
		int *bet_numbers;
		// Vetor que guarda o tamanho da aposta do jogador
		size_t size;
		// Quantidade de dinheiro atual do jogador
		float money;
};

#endif
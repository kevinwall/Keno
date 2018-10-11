#ifndef GAMAMANAGER_H_
#define GAMAMANAGER_H_

#include "keno.h"
#include "Player.h"
#include "tools.h"
#include <vector>

class gamemanager{
public:
	/**
	*@brief Função que compara os numeros sorteados e os números apostados pelo jogador
	*@param objeto da classe de jogador 
	*@param e objeto da classe keno(do jogo)
	*@return o número de acertos feito pelo jogador
	*/
	int comparate_bet( Player& player_, keno& keno_);
	/**
	*@brief Função de busca linear que pega os numeros do jogador e busca no vetor de numeros sorteados
	*@param numero escolhido pelo jogador
	*@param ranged do vetor de numeros sorteados
	*@return retorna true caso tenha pelo menos um acerto e false se haver nenhum
	*/
	bool linear_search_keno( int n , const int * , const int * );
	/**
	*@brief Função que calcula o saldo da rodada em questão
	*@param objeto da classe de jogador 
	*@param e objeto da classe keno(do jogo)
	*/
	void balance( Player& player_, keno& keno_);
	/**
	*@brief Função que calcula o saldo total
	*@param objeto da classe de jogador 
	*@param numero de apostas
	*/
	void get_bet_money(Player& player_, int number_of_bet);
	/**
	*@brief Função auxiliar de odernação
	*@param o ponteiro que aponta para as apostas
	*@param o tamanho do vetor de apostas
	*/
	void qsort( int* bet, size_t count);
	/**
	*@brief Função que imprime a tabela do jogo
	*@param objeto da classe de jogador 
	*/
	void print_table(Player& player_);
private:
	/**
	*@brief Vector com os multiplicadores de apostas de acordo com os acertos
	*/
	std::vector<std::vector<float>> payout_table = {
		{ 0,   3 }, // 1 spot
        { 0,   1,   9 }, // 2 spots
        { 0,   1,   2,  16 }, // 3 spots
        { 0, 0.5,   2,   6,  12 }, // 4 spots
        { 0, 0.5,   1,   3,  15, 50 }, // 5 spots
        { 0, 0.5,   1,   2,   3, 30, 75 }, // 6 spots
        { 0, 0.5, 0.5,   1,   6, 12, 36, 100 }, // 7 spots
        { 0, 0.5, 0.5,   1,   3,  6, 19,  90, 720 }, // 8 spots
        { 0, 0.5, 0.5,   1,   2,  4,  8,  20,  80, 1200 }, // 9 spots
        { 0,   0, 0.5,   1,   2,  3,  5,  10,  30,  600, 1800 }, // 10 spots
        { 0,   0, 0.5,   1,   1,  2,  6,  15,  25,  180, 1000, 3000 }, // 11 spots
        { 0,   0,   0, 0.5,   1,  2,  4,  24,  72,  250,  500, 2000, 4000 }, // 12 spots
        { 0,   0,   0, 0.5, 0.5,  3,  4,   5,  20,   80,  240,  500, 3000, 6000 }, // 13 spots
        { 0,   0,   0, 0.5, 0.5,  2,  3,   5,  12,   50,  150,  500, 1000, 2000,  7500 }, // 14 spots
        { 0,   0,   0, 0.5, 0.5,  1,  2,   5,  15,   50,  150,  300,  600, 1200,  2500, 10000 } // 15 spots

	};

	float bet_money;
};
#endif

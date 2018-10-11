#ifndef KENO_H_
#define KENO_H_

#include <iostream>
#include <fstream>
#include "tools.h"
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock


/**
*@brief Classe responsável por guardar e gerar os números aleatórios.
*/
class keno
{
private :
	// Vetor responsável por gerar os números a serem escolhidos.
	int *keno_table;
	// Vetor responsável por guardar os números escolhidos.
	int *keno_chosen;
public:

	/**
	*@brief Construtor da classe que cria os dois vetores e inicializa o keno_table para realziar o shuffle.
	*/
	keno();

	/**
	*@brief Destrutor da classe que deleta os vetores alocados dinamicamente.
	*/
	~keno();

	/**
	*@brief Função shuffle_keno que embaralha o keno_table e retira os primeiros 20 elementos para armazená-los em keno_chosen.
	*/
	void shuffle_keno();

	/**
	*@brief Função get_chosen que retorna uma referência constante para o vetor dos números escolhidos.
	*/
	const int * get_chosen();

};
#endif
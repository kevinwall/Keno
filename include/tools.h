#ifndef TOOLS_H_
#define TOOLS_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

/**
*@brief Função Unique que remove os valores repetidos do vetor de apostas.
*@param int *first ponteiro para o início do range.
*@param int *last ponteiro para o final do range
*/
int * unique( int * first, int * last);
/**
*@brief Função qsort que ordena um vetor.
*@param int *first ponteiro para o início do range.
*@param int *last ponteiro para o final do range
*/
void qsort( int* first, int* last);
/**
*@brief Função reader_file responsável por remover as informações do arquivo e entrada e tratar os erros.
*@param std::ifstream& file referência para a stream que liga o arquivo ao algorítimo criada na main.
*@param int * & A referência para um ponteiro que será utilizado para guardar a informação "crua" que será retirada do arquivo.
*@param float & money Referência para a variável que vai guardar o dinheiro de entrada do jogador.
*@param int& number_of_bet referência para a variável que vai guardar a quantidade de apostas que o jogador fará.
*@param int & i referência para a variável que guardará o tamanho do vetor aposta do jogador
*/
void reader_file( std::ifstream& file, int * & A, float & money, int& number_of_bet, int & i);	

#endif
#ifndef KENO_H_
#define KENO_H_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock


class keno
{
private :
	// Vetor responsável por gerar os números escolhidos.
	int *keno_table;
	// Vetor responsável por guardar os números escolhidos.
	int *keno_chosen;
public:
	keno();

	~keno();

	void shuffle_keno();

};
#endif
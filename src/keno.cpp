#include "../include/keno.h"

// Construtor simples que aloca dinamicamente os dois vetores e inicializa o keno_table.
keno::keno()
{

	int num = 1;

	keno_table = new int[80];

	for( auto i = 0; i < 80; i++)
	{
		keno_table[i] = num++;
	}

	keno_chosen = new int[20];
}

// Destrutor que deleta os vetores dinamicamente alocados
keno::~keno(){
	delete [] keno_table;
	delete [] keno_chosen;
}

// Função que embaralha o vetor keno_table para depois retirarmos os números do sorteio atual
void keno::shuffle_keno(){

	 unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();	
	std::shuffle( keno_table+1,
					 keno_table+80, std::default_random_engine(seed));

	for( auto i = 0 ; i < 20 ; i++){
		keno_chosen[i] = keno_table[i];
	}
	qsort( keno_chosen, keno_chosen+20);

}

// Função que retorna uma referência constante para o vetor de escolhidos.
const int * keno::get_chosen()
{
	return keno_chosen;
}
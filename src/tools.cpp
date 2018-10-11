#include "../include/tools.h"

// Função auxilia que filtra o vetor de numeros sorteados para serem únicos
int * unique (int * first, int * last)
{
	int aux;// auxiliar para troca
	last--;
	int *slow = last;
	bool flag;// flag booleana q servirá iterar o ponteiro slow quando n achar mais elemento repetido

	while(first != last)
	{
		auto fast = first;
		flag = false;// setando falso

		while(fast != last or fast > last)// segundo laço para buscar se há elemento repetido
		{
			if(*first == *fast and first != fast)
			{
				aux = *fast;
				*fast = *(fast+1);
				*(fast+1) = aux;
				flag = true;
			}	
			fast++; 
		}
	// se sair do laço e o flag continuar falso,então apenas continua a primeira iteração para ver se o proximo elemento tem repetição
		if(flag == true)
		{
			slow--;
		}
		first++;
	}

	return slow;

}

void qsort( int* first , int * last) // função auxiliar de ordenação, sendo a logica igual a do seletion sort
{
	int* aux = new int;

	while( first < last){
		int* fast = first;
			while( fast < last){
				if(*first > *fast){
					*aux = *first;
					*first = *fast;
					*fast = *aux;
				}
			fast++;
			}
		first++;
	}

	delete aux;
}
// função auxiliar de leitura de arquivo que servirá para tratar os dados passado pelo arquivo texto
void reader_file( std::ifstream& file, int * & A, float & money, int& number_of_bet, int & i)
{

	int dummy;
	std::string string;
	// variaves que serão usadas para gravas os dados
	getline(file,string);
	std::stringstream oss(string); 
	// primeira variável que irá gravar o dinheiro,é usado um laço para ignorar os espaços em branco
	// e gravar quando há elementos
	while(! (oss >> money))
	{
		oss.clear();
		getline(file,string);
		oss.str(string);
	}
	// clear para reaproveitar a variavel stream
	oss.clear();

	getline(file,string);
	oss.str(string);
	// mesma lógica para money ,diferença que grava o número de apostas
	while(! (oss >> number_of_bet))
	{
		oss.clear();
		getline(file,string);
		oss.str(string);
	}

	oss.clear();

	getline(file,string);
	oss.str(string);

	// primeiramente itera até achar elementos,ignorando os espaços em branco
	while(! (oss >> dummy) )
	{
		oss.clear();
		getline(file,string);
		oss.str(string);
	}

	if(dummy > 0 and dummy < 81)
	{
		A[i] = dummy;
		i++;
	}
	
	// grava os números que o jogador quer jogar no sorteio em um vetor
	while(oss>>A[i])
	{
		if(A[i] < 81 and A[i] > 0)
		{
			i++;

			if(i > 14)
			{
				break;
			}
		}
	}
}

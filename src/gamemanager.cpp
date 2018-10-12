#include "gamemanager.h"

// Função que verifica quantos acertos o jogador obteve.
int gamemanager::comparate_bet ( Player& player_, keno& keno_){
	int hints = 0; //Quantidade de acertos
	auto bets = player_.get_bet(); //Vetor de apostas do jogador
	auto keno_numbers = keno_.get_chosen(); // Vetor com os números sorteados.

	int * p_hits = new int[player_.get_size()+1]; //Cria um vetor para ver quais números foram acertados.

	//Ponteiros para a iteração sobre o vetor de apostas.
	auto first = bets; 
	auto last = bets+player_.get_size();

	//Percorre o vetor de apostas fazendo buscas sobre o vetor de números sorteados para verificar se há um acerto.
	while( first != last ){
		if( linear_search_keno( *first, keno_numbers
			, keno_numbers+20)){
			
			p_hits[hints] = *first; //Caso haja um acerto, guardamos o número do acerto com p_hits.
			hints++; //Aumentando o números de acertos no total.
		}
		first++;
	}

	//Caso tenha ocorrido algum acerto, mostramos quais foram.
	if(hints > 0)
	{
		std::cout<<"You hit the following number(s) [ ";
		for(auto i{0}; i < hints; i++)
		{
			std::cout<<p_hits[i]<<" ";
		} 
		std::cout<<"] a total of "<<hints<<" hits out of "<<player_.get_size()+1<<std::endl<<std::endl;
	}
	else
	{
		//Caso não haja acertos, mostramos a seguinte mensagem
		std::cout<<"Sorry, you did't hit any number, better luck next time"<<std::endl<<std::endl;
	}

	delete [] p_hits; //Deletando o vetor de acertos.

	return hints;
}

//Funçaõ de busca auxiliar que procura um acerto no vetor de sorteados.
bool gamemanager::linear_search_keno( int n , const int * first, const int * last){
	while( first != last ){
		if( *first == n ){
			return true;
		}
		first++;
	}
	return false;
}

//Função balance que atualiza o valor do dinheiro do jogador e das apostas.
void gamemanager::balance( Player& player_  , keno& keno_){
	int hints = comparate_bet( player_, keno_); //Verificamos quantos acertos ocorreram.

	float balance_mult = payout_table[player_.get_size()][hints]; //Acessamos a tabela para ver qual será o ganho do jogador.

	float balance_ = bet_money +(bet_money * balance_mult); //Calculamos o lucro do jogador

	std::cout<<"Payout rate is "<<balance_mult<<", thus you came out with: $"<<balance_<<std::endl<<std::endl; //Mostramos o lucro do jogador

	player_.set_money(player_.get_money() + balance_); //Atualizamos o dinheiro total do jogador

	std::cout<<"Your net balance so far is: $"<<player_.get_money()<<" dollars."<<std::endl<<std::endl; //Mostramos o dinheiro atual do jogador

}

// Função que recebe o dinheiro que será retirado para cada aposta.
void gamemanager::get_bet_money(Player& player_, int number_of_bet)
{
	bet_money = player_.get_money() / number_of_bet;

}

//Função que imprime a tabela de ganho por acerto.
void gamemanager::print_table(Player& player_)
{
	auto size = player_.get_size();

	std::cout<<"Hits:   ";
	for(size_t i{0}; i <= size+1; i++)
	{
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;

	std::cout<<"Payout: ";
	for(size_t i{0}; i <= size+1; i++)
	{
		std::cout<<payout_table[size][i]<<" ";
	}
	std::cout<<std::endl<<std::endl;
}


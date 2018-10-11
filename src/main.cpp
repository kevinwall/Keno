#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "keno.h"
#include "tools.h"
#include "Player.h"
#include "gamemanager.h"

int main(int argc, char const *argv[])
{
	
	int * A = new int[15]; // Vetor responsável por guardar os dados "crus" retirados do arquivo.
	float money; //Variável que guarda o dinheiro inicial do jogador.
	int number_of_bet; //Variável que guarda a quantidade de apostas do jogador.

	// Caso o usuário não digite o arquivo de entrada
	if( argc != 2){
		std::cerr << " Número de argumentos invalidos\n";
		return 0;
	}

	std::ifstream file(argv[1]); //Stream responsável por retirar os dados dos arquivos.

	int i = 0; //Variável que armazena o valor do tamanho da aposta do jogador.

	// Verifica se o arquivo foi corretamente aberto.
	if(!file.is_open()){
		std::cerr << " Arquivo vazio\n";
		return 0;	
	}

	reader_file( file,  A,  money, number_of_bet, i); //Chama a função que irá remover as informações do arquivo.

	auto last = unique(A, A+i+1); //Remove os valores duplicados caso existam.

	qsort( A, last); //Ordena o vetor em ordem crescente

	Player player_1(A, last-A, money); //Cria o jogador baseado no vetor A filtrado.

	keno game; //Cria o objeto responsável por gerenciar os sorteios.

	gamemanager mng; //Cria o objeto responsável por comparar os resultados e atualizar o dinheiro do jogador

	game.shuffle_keno(); //Embaralha o vetor e sorteia os primeiros 20 números.

	mng.get_bet_money(player_1, number_of_bet); //Recebe o dinheiro da aposta.

	auto wage = money/number_of_bet; // Guarda o valor que será utilizado para cada aposta.

	//Imprime a mensagem de boas vindas.
	std::cout << "Bet successfully read!" << std::endl<<std::endl << 
				   "You are going to wage a total of $ " << money << " dollars." << std::endl 
				   << "Going for a total of " << number_of_bet << " rounds, waging $"
				   << wage << " per round."<< std::endl << "Your bet has " << player_1.get_size()+1
				   << " numbers. They are:";
	player_1.print_bet();

	mng.print_table(player_1);

	// Game loop
	for(auto k{0}; k < number_of_bet; k++)
	{
		player_1.set_money(player_1.get_money() - wage); //Atualiza o dinnheiro atual do jogador.

		// Mostra qual a rodada atual para o jogador
		std::cout<<"This is round #"<<k+1<<" of "<<number_of_bet<<", and your wage is $"<<wage<<". Good luck!"<<std::endl;

		// recebe os números que foram sorteados e os imprime para o usuário
		auto result = game.get_chosen();
		std::cout<<"The hits are: [";
		for(auto cs{0}; cs < 20; cs++)
		{
			std::cout<<result[cs]<<" ";
		}
		std::cout<<"]"<<std::endl;

		// Verifica os resultados da aposta e atualiza o lucro do jogador
		mng.balance(player_1, game);

		// Embaralha o vetor e gera um novo resultado
		game.shuffle_keno();

	}

	// Deleta o vetor alocado dinamicamente
	delete [] A;

	return 0;
}


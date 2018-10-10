#ifndef KENO_H_
#define KENO_H_

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

};
#endif
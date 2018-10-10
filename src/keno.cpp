#include "../include/keno.h"

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

keno::~keno(){
	delete [] keno_table;
	delete [] keno_chosen;
}

void keno::shuffle_keno(){

	 unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();	
	std::shuffle( keno_table+1,
					 keno_table+80, std::default_random_engine(seed));

	for( auto i = 0 ; i < 20 ; i++){
		keno_chosen[i] = keno_table[i];
	}

	for( auto i = 0; i < 80 ; i++){
		std::cout << keno_table[i] << " ";
	}
	std::cout << std::endl;
	for( auto i = 0; i < 20 ; i++){
		std::cout << keno_chosen[i] << " ";
	}

}




int main()
{
	keno k;
	std::string string1, string2;
	std::ifstream file("Blank.txt");
	std::stringstream oss;
	int i;
	
	std::getline(file, string1);
	std::cout<<string1<<std::endl;
	std::getline(file, string1);
	std::cout<<string1<<std::endl;

	oss.str(string1);

	oss >> i;

	if(oss.fail())
	{
		std::cout<<i<<std::endl;
		std::cout<<"Falhou"<<std::endl;
	}

	oss.clear();
	std::getline(file, string1);
	oss.str(string1);
	oss>>i;
	std::cout<<i<<std::endl;
	if(oss.fail())
	{
		
		std::cout<<"Falhou"<<std::endl;
	}

	k.shuffle_keno();

	// string2 = " ";

	// std::cout<<"Comparação: "<<string1.compare(string2)<<std::endl;

	return 0;
}
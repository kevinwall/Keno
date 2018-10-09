#include "../include/gamemanager.h"


class keno
{

public:
	keno(){

		int num = 1;

		keno_table = new int*[8];

		for( auto i = 0; i < 8; i++){
			keno_table[i] = new int[10]; 
		}

		for(auto i = 0 ; i <= 8; i++){
			for( auto j = 0 ; j <= 10; j++){
				keno_table[i][j] = num++;
			}
		}
	}

	~keno(){
		delete [] keno_table;
	}


};
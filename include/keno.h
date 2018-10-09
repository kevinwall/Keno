#ifndef KENO_H_
#define KENO_H_

#include "gamemanager.h"

class keno
{
private :
	int **keno_table;
public:
	keno();
	~keno();

friend std::ostream& operator<<( std::ostream& os, const keno & keno_){


}

};
#endif
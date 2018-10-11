#include "../include/tools.h"

int * unique (int * first, int * last)
{
	int aux;
	last--;
	int *slow = last;
	bool flag;

	while(first != last)
	{
		auto fast = first;
		flag = false;

		while(fast != last or fast > last)
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

		if(flag == true)
		{
			slow--;
		}
		first++;
	}

	return slow;

}

void qsort( int* first , int * last)
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

void reader_file( std::ifstream& file, int * & A, float & money, int& number_of_bet, int & i)
{

	int dummy;
	std::string string;

	getline(file,string);
	std::stringstream oss(string); 

	while(! (oss >> money))
	{
		oss.clear();
		getline(file,string);
		oss.str(string);
	}

	oss.clear();

	getline(file,string);
	oss.str(string);
	
	while(! (oss >> number_of_bet))
	{
		oss.clear();
		getline(file,string);
		oss.str(string);
	}

	oss.clear();

	getline(file,string);
	oss.str(string);


	while(! (oss >> dummy) )
	{
		oss.clear();
		getline(file,string);
		oss.str(string);
	}

	if(dummy > 1 and dummy < 80)
	{
		A[i] = dummy;
		i++;
	}
	

	while(oss>>A[i])
	{
		if(A[i] < 80 and A[i] > 1)
		{
			i++;

			if(i > 14)
			{
				break;
			}
		}
	}
}
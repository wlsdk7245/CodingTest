#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main(void)
{
	srand(time(NULL));
	for(int i=0; i<5; i++)
	{
		printf("Random number #%d: %d\n", i, rand()%100);
	}
	return 0;
}

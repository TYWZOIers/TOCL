#include <string>
#include <iostream>
#include "tocl.h"

using namespace TOCL; 

int main() 
{
        int get[]={2,19,18,17,16,15,14,13,12,11,10,9,8,7,1,5,4,3,2,1};
        heap_sort(get, 0, 19);
	for (int i = 0; i < 20; i++)
		std::cout << get[i] << ' ';
	return 0;
}


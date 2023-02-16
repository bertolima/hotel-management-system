#include<iostream>
#include<cstdlib>
#include "cRandom.hpp"
using namespace std;

int generateNumber(int a, int b){
	srand((unsigned) time(NULL));
	int random = a + (rand() % b);
	return random;
}

#include <iostream>
#include <cstdlib>
#include "cHotel.hpp"



int generateNumber(int a, int b){
	srand((unsigned) time(NULL));
	int random = a + (rand() % b);
	return random;
}

cRoom::cRoom(int n, int c, bool f){
    this->number = n;
    this->capacity = c;
    this->hasFridge = f;
}


cHotel::cHotel(std::string n, int s, int r, int f){
    this->name = n;
    this->stars = s;
    this->qRooms = r;
    this->qFloors = f;
}

void cHotel::roomGen(){
    int qtd = this->qRooms*this->qFloors;
    int number = 0;
    bool f;

    for (int i=0;i<qtd;i++){
        int c = generateNumber(0, 6);
        int x = generateNumber(0, 2);
        if (x == 0)  f = true;
        else f = false;
        this->rooms.push_back(cRoom(number, c, f));
        number++;
    }
}








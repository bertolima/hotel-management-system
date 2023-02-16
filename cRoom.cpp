#include "cRoom.hpp"
#include <iostream>

using namespace std;


cRoom::cRoom(int number, int nPeople, bool fridge){
    this->number = number;
    this->nPeople = nPeople;
    this->fridge = fridge;
}

int cRoom::getNumber(){
    return this->number;
}

int cRoom::getNPeople(){
    return this->nPeople;
}

bool cRoom::getFridge(){
    return this->fridge;
}
bool cRoom::getOccuped(){
    return this->occuped;
}



void cRoom::setNumber(int a){
    this->number = a;
}

void cRoom::setNPeople(int a){
    this->nPeople = a;
}

void cRoom::setFridge(bool a){
    this->fridge = a;
}

void cRoom::setOccuped(bool a){
    this->occuped = a;
}

void cRoom::printAll(){
    cout << this->number << endl;
    cout << this->nPeople << endl;
    cout << this->fridge << endl;
}
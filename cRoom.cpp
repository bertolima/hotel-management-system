#include "cRoom.hpp"
#include <iostream>
#include "cRandom.hpp"

using namespace std;


cRoom::cRoom(int number, int nPeople){
    this->number = number;
    this->nPeople = nPeople;
    this->occuped = false;
    setFridge();
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

void cRoom::setFridge(){
    int x = generateNumber(0, 2);
    if (x == 0) this->fridge = false;
    else if (x == 1) this->fridge = true;
    
}

void cRoom::setOccuped(bool a){
    this->occuped = a;
    
}

void cRoom::setGuest(cGuest x){
    *guest = x;
}

cGuest cRoom::getGuest(){
    return *guest;
}

void cRoom::printAll(){
    cout << endl;
    cout << this->number << endl;
    cout << this->nPeople << endl;
    cout << this->fridge << endl;
    cout << this->occuped << endl;
    cout << endl;
}
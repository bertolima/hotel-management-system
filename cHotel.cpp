#include <iostream>
#include "cHotel.hpp"
#include <string>
using namespace std;

cHotel::cHotel(string name, int star, int room, int floor){
    this->name = name;
    this->stars = star;
    this->nRoom = room;
    this->nFloor = floor;
}

string cHotel::getName(){
    return this->name;
}

int cHotel::getStars(){
    return this->stars;
}
int cHotel::getnRoom(){
    return this->nRoom;
}
int cHotel::getnFloor(){
    return this->nFloor;
}

void cHotel::setName(string a){
    this->name = a;
}

void cHotel::setStars(int a){
    this->stars = a;
}

void cHotel::setnRoom(int a){
    this->nRoom = a;
}

void cHotel::setnFloor(int a){
    this->nFloor = a;
}

void cHotel::printRoom(){
    cout << this->r->getNumber() << endl;
    cout << this->r->getNPeople() << endl;
    cout << this->r->getFridge() << endl;
}


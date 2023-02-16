#include <iostream>
#include "cHotel.hpp"
#include <string>
#include "cRandom.hpp"
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


void cHotel::printHotel(){
    cout << this->getName() << endl;
    cout << this->getStars() << endl;
    cout << this->getnRoom() << endl;
    cout << this->getnFloor() << endl;

}

// void cHotel::generateRoom(){
//     int x = (this->nRoom * this->nFloor);
//     int roomCapacity = generateNumber(0, 5);
//     for (int i =0;i<x;i++){
//         array[i] = new cRoom(roomNumber, roomCapacity);
//     }

// }



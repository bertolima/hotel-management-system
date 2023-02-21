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


void cHotel::generateGuests(int quantity){
    for (int i=0;i<quantity;i++){
        int x = generateNumber(1, 5);
        int y = generateNumber(0, 5);
        int z = generateNumber(0, 2);
        bool f;
        if (z==0){
            f = true;
        }
        else if(z==1) f = false;

        this->guests.push_back(cGuest(x, y, f));

    }

}

void cHotel::generateRoom(){
    int x = (this->nRoom * this->nFloor);
    for (int i =0;i<x;i++){
        int roomCapacity = generateNumber(0, 5);
        this->rooms.push_back(cRoom(roomNumber, roomCapacity));
        roomNumber++;
    }
}

void cHotel::allocateRoom(){
    for (int i=0;i<this->rooms.size();i++){
        if (this->rooms[i].getOccuped() == false){
            if (this->rooms[i].getFridge() == true){
                for (int j=0;j<this->guests.size();j++){
                    if (this->guests[j].getFridge() == this->rooms[i].getFridge() && this->guests[j].getQuant() == this->rooms[i].getNPeople() && this->guests[j].getStar() == this->getStars()){
                        this->rooms[i].setOccuped(true);
                        this->rooms[i].setGuest(this->guests[j]);
                        break;

                    }

                }
            }

        }
    }
}


void cHotel::printAllRoom(){
    for (int i=0;i<this->rooms.size();i++){
        this->rooms[i].printAll();
    }
    
}



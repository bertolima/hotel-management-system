#include <iostream>
#include <cstdlib>
#include "cHotel.hpp"

int generateNumber(int start, int range)
{
    // A function to generate random numbers
    return (start + rand() % range);
}

cRoom::cRoom(int n, int c, bool f){
    this->number = n;
    this->capacity = c;
    this->hasFridge = f;
}

void cRoom::print(){
    std::cout << "Numero do quarto: " << this->number << std::endl;
    std::cout << "Capacidade do quarto: " << this->capacity << " pessoas" << std::endl; 
    std::cout << "Tem frigideira? " << this->hasFridge << std::endl; 
    std::cout << std::endl;
}

void cRoom::setters(int n, int c, bool f){
    this->number = n;
    this->capacity = c;
    this->hasFridge = f;

}
cGuest::cGuest(int q, int s, bool f){
    this->quantity = q;
    this->starCount = s;
    this->wantFridge = f;
}
cHotel::cHotel(std::string n, int s, int r, int f){
    this->name = n;
    this->stars = s;
    this->qRooms = r;
    this->qFloors = f;
}

void cHotel::roomGen(){
    int qtd = this->qRooms*this->qFloors;
    int number = 0, c, x;
    bool f;
    for (int i=0;i<qtd;i++){
        c = generateNumber(0, 6);
        x = generateNumber(0, 2);
        if (x == 0)  f = true;
        else f = false;
        this->rooms.push_back(cRoom(number, c, f));
        number++;
        std::cout << number << " " << c << " " << f << std::endl;
    }
}

void cHotel::queueFill(int q){
    bool f;
    for (int i=0;i<q;i++){
        int qtt = generateNumber(1, 6);
        int stars = generateNumber(0, 6);
        int x = generateNumber(0, 2);
        if (x == 0)  f = true;
        else f = false;

        this->guests.push_back(cGuest(qtt, stars, f));
    }
}

void cHotel::print(int x){
    if (x==1){
        for (int i=0;i<this->rooms.size();i++){
            rooms[i].print();
        }
    }
}








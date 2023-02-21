#include "cGuest.hpp"

cGuest::cGuest(int qtd, int star, bool fridge){
    this->quantity = qtd;
    this->qttStars = star;
    this->wantFridge = fridge;
}

int cGuest::getQuant(){
    return this->quantity;
}

int cGuest::getStar(){
    return this->qttStars;
}

bool cGuest::getFridge(){
    return this->wantFridge;
}





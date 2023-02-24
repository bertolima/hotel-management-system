#include <iostream>
#include <cstdlib>
#include "cHotel.hpp"

int generateNumber(int start, int range)
{
    return (start + rand() % range);
}

//================ CROOM=======================================================
cRoom::cRoom(int n, int c, bool f){
    this->number = n;
    this->capacity = c;
    this->hasFridge = f;
    this->occuped = false;
}

cRoom::cRoom(){
    this->number = -1;
    this->capacity = -1;
    this->hasFridge = false;
    this->occuped = false;
}

void cRoom::print(){
    std::cout << "Numero do quarto: " << this->number << "   ";
    std::cout << "Capacidade do quarto: " << this->capacity << " pessoas" << "   ";
    std::cout << "Tem frigobar? ";
    if(hasFridge == 0) std::cout << "Nao" << "    ";
    else std::cout << "Sim" << "   ";
    std::cout << std::endl;
    std::cout << "Tamanho da familia: "<< guest.getQuant() << "   " << "Estrelas: " << guest.getStar() << "   " << "Frigobar: " << guest.getFridge() << std::endl;

    std::cout << std::endl;
}

int cRoom::getNumber(){
    return this->number;
}
int cRoom::getCapacity(){
    return this->capacity;
}
bool cRoom::getFridge(){
    return this->hasFridge;
}

bool cRoom::getOccuped(){
    return this->occuped;
}

void cRoom::setOccuped(bool a){
    this->occuped = a;
}

void cRoom::setGuest(cGuest x){
    this->guest = x;
}

cGuest cRoom::getGuest(){
    
}





//==============================================================================

//================ CGUEST=======================================================

cGuest::cGuest(int q, int s, bool f){
    this->quantity = q;
    this->starCount = s;
    this->wantFridge = f;
}
cGuest::cGuest(){
    this->quantity = -1;
    this->starCount = -1;
    this->wantFridge = false;
}

void cGuest::setters(int q, int s, bool f){
    this->quantity = q;
    this->starCount = s;
    this->wantFridge = f;
}

void cGuest::print(){
    std::cout << "Tamanho da familia: " << this->quantity << std::endl;
    std::cout << "Quantidade de estrelas: " << this->starCount << " estrelas" << std::endl; 
    std::cout << "Eles querem frigobar? ";
    if(this->wantFridge == false) std::cout << "Nao" << std::endl;
    else std::cout << "Sim" << std::endl;
    std::cout << std::endl;
}

int cGuest::getQuant(){
    return this->quantity;
}
int cGuest::getStar(){
    return this->starCount;
}
bool cGuest::getFridge(){
    return this->wantFridge;
}


//==============================================================================
//================ CHOTEL =======================================================

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
    }
}

void cHotel::queueFill(int q){
    bool f;
    for (int i=0;i<q;i++){
        int qtt = generateNumber(1, 5);
        int stars = generateNumber(0, 6);
        int x = generateNumber(0, 2);
        if (x == 0)  f = true;
        else f = false;

        this->guests.push_back(cGuest(qtt, stars, f));
    }
}

void cHotel::allocate(){
    if (!(this->guestsAux.empty())){
        int g = this->guestsAux.size();
        int r = this->rooms.size();
        for (int i=0;i<g;i++){
            for (int j=0;j<r;i++){
                if (this->rooms[i].getOccuped()) continue; 
                if (this->guestsAux[i].getQuant() == this->rooms[j].getCapacity() && this->guestsAux[i].getFridge() == this->rooms[j].getFridge()){
                    this->rooms[j].setGuest(this->guestsAux[i]);
                    this->rooms[j].setOccuped(true);
                    this->guestsAux.erase(this->guestsAux.begin() + i);
                }
            }
        }
    }

    int g = this->guests.size();
    int r = this->rooms.size();
    for(int i=0;i<g;i++){
        if (this->guests[i].getStar() > stars) {
            this->guests.erase(this->guestsAux.begin() + i);
            continue;
        }else{
            for (int j=0;j<r;j++){
                if (this->guests[i].getQuant() == this->rooms[j].getCapacity() && this->guests[i].getFridge() == this->rooms[j].getFridge() && this->rooms[j].getOccuped() == false){
                        this->rooms[j].setGuest(this->guests[i]);
                        this->rooms[j].setOccuped(true);
                        this->guests.erase(this->guests.begin() + i);
                        g--;
                        break;
                }
                else{
                    continue;
                }
            }    
        }
        
    }

}

void cHotel::print(){

    for (int i=0;i<this->rooms.size();i++){
        rooms[i].print();
    }

    
}








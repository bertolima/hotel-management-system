#include "cHotel.hpp"
#include <iostream>

using namespace std;


int main(){

    cHotel hotel("california", 5, 10, 4);
    hotel.roomGen();
    hotel.print(1);

    
}
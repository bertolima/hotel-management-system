#include "cHotel.hpp"
#include <iostream>
#include <ctime>

using namespace std;


int main(){
    srand(time(0));
    cHotel hotel("california", 5, 5, 2);
    hotel.roomGen();
    hotel.queueFill(10);
    hotel.print();
    hotel.allocate();
    hotel.print();
    
}
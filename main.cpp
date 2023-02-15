#include <iostream>
#include "cRoom.hpp"

using namespace std;

int main(){
    cRoom *r = new cRoom(10, 20, false);

    r->printAll();

    r->setFridge(true);
    
    
}
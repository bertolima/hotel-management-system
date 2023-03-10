#include <ctime>
#include "Screen.hpp"

using namespace std;

int main(){
    srand(static_cast<unsigned>(time(NULL)));

    Screen screen;

    //gameloop
    while(screen.running()){
        //update
        screen.update();
        //render
        screen.render();
    }

    return 0;
}
#include "cHotel.hpp"
#include <ctime>
#include "Screen.hpp"

using namespace std;


int main(){
    srand(time(0));
    cHotel hotel("california", 5, 5, 2);

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
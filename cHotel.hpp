#include <string>
#include <vector>
#include "cRoom.hpp"


class cHotel{
    private:
        std::string name;
        int stars;
        int nRoom;
        int nFloor;
        std::vector<cRoom> array;
        
        
    public:
        cHotel(std::string, int, int, int);
        std::string getName();
        int getStars();
        int getnRoom();
        int getnFloor();
        int roomNumber = 0;

        void setName(std::string);
        void setStars(int);
        void setnRoom(int);
        void setnFloor(int);
        void printHotel();

        void generateRoom();
        void allocateRoom();
        void updateRoom();
        
};
#include <string>
#include <vector>
int generateNumber(int, int);

class cRoom{
    private:
        int number;
        int capacity;
        bool hasFridge;

    public:
        cRoom(int, int, bool);
};

class cHotel{

    private:
        std::string name;
        int stars;
        int qRooms;
        int qFloors;
        

    public:
        cHotel(std::string, int, int, int);
        std::vector <cRoom> rooms;
        void roomGen();
};



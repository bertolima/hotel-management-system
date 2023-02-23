#include <string>
#include <vector>


int generateNumber(int, int);

class cGuest{
    private:
        int quantity;
        int starCount;
        bool wantFridge;

    public:
        cGuest(int, int, bool);
        void print();

};

class cRoom{
    
    int number;
    int capacity;
    bool hasFridge;

    public:
        cRoom(int, int, bool);
        void print();
        void setters(int, int, bool);
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
        std::vector <cGuest> guests;
        void roomGen();
        void queueFill(int);
        void print(int);
};



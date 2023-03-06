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
        cGuest();
        void print();
        int getQuant();
        int getStar();
        bool getFridge();
        void setters(int, int, bool);
        

};

class cRoom{
    private:
        int number;
        int capacity;
        bool hasFridge;
        bool occuped;
        cGuest guest;

    public:
        cRoom(int, int, bool);
        cRoom();
        void print();
        int getNumber();
        int getCapacity();
        bool getFridge();
        bool getOccuped();
        cGuest getGuest();
        void setOccuped(bool);
        void setGuest(cGuest);
};

class cHotel{

    private:
        std::string name;
        int stars;
        int qRooms;
        int qFloors;
        

    public:
        cHotel(std::string, int, int, int);
        cHotel();
        void setName(std::string);
        void setStars(int);
        void setRoooms(int);
        void setFloors(int);

        std::string getName();


        std::vector <cRoom> rooms;
        std::vector <cGuest> guests;
        std::vector <cGuest> guestsAux;
        void roomGen();
        void queueFill(int);
        void allocate();
        void getRoom();
        void print(int);
        int getRoomqtt();
        std::string getRoomsOccuped();
        std::string getRoomsFree();
        std::string getRoomOccuped(int);
        std::string getRoomFridge(int);
        std::string getRoomCapacity(int);
        std::string getRoomNumber(int);



        
};



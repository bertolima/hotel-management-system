#include <string>

class cHotel{
    private:
        std::string name;
        int stars;
        int nRoom;
        int nFloor;
        
    public:
        cHotel(std::string, int, int, int);
        std::string getName();
        int getStars();
        int getnRoom();
        int getnFloor();

        void setName(std::string);
        void setStars(int);
        void setnRoom(int);
        void setnFloor(int);
        
};
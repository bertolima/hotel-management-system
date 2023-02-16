
class cRoom{
    
    public:
        cRoom(int, int, bool);
        int getNumber();
        int getNPeople();
        bool getFridge();
        bool getOccuped();

        void setNumber(int);
        void setNPeople(int);
        void setFridge(bool);
        void setOccuped(bool);

        void printAll();

    private:
        int number;
        int nPeople;
        bool fridge;
        bool occuped;
};


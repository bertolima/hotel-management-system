
class cRoom{
    
    public:
        cRoom(int, int, bool);
        int getNumber();
        int getNPeople();
        bool getFridge();

        void setNumber(int);
        void setNPeople(int);
        void setFridge(bool);

        void printAll();

    private:
        int number;
        int nPeople;
        bool fridge;
};


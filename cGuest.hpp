

class cGuest{
    private:
        int quantity;
        bool wantFridge;
        int qttStars;

    public:
        cGuest(int, int,  bool);
        int getQuant();
        int getStar();
        bool getFridge();
};
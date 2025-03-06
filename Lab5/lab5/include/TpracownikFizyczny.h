#ifndef TPRACOWNIKFIZYCZNY_H
#define TPRACOWNIKFIZYCZNY_H
#include <Tpracownik.h>

class TpracownikFizyczny : public Tpracownik
{
    public:
        TpracownikFizyczny();
        TpracownikFizyczny(string, string, string, float, float, int);
        void wczytaj();
        void wyswietl();
        float oblicz();
        virtual ~TpracownikFizyczny();

    protected:

    private:
        int liczbaGodzin;
};

#endif // TPRACOWNIKFIZYCZNY_H

#ifndef TPRACOWNIK_H
#define TPRACOWNIK_H
#include <Tosoba.h>

class Tpracownik
{
    public:
        Tpracownik();
        Tpracownik(string, string, string, float, float);
        void wczytaj();
        void wyswietl();
        virtual ~Tpracownik();

    protected:
        string imie, nazwisko, firma;
        float premia, stawka; //wszyscy pracowniki maja to, ale tylko fizyczny ma ilosc godzin

    private:
};

#endif // TPRACOWNIK_H

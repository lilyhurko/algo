#ifndef TOSOBA_H
#define TOSOBA_H
#include <string>
#include <iostream>

using namespace std;

class Tosoba
{
    public:
        Tosoba();
        Tosoba(string, string);
        void wczytaj();
        void wyswietl();
        virtual ~Tosoba();

    protected:
        string imie, nazwisko;

    private:

};

#endif // TOSOBA_H

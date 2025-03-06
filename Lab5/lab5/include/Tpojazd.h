#ifndef TPOJAZD_H
#define TPOJAZD_H

#include <iostream>
using namespace std;

class Tpojazd
{
    public:
        Tpojazd();
        Tpojazd(string, string, int);
        void podajDane();
        void info();
        virtual ~Tpojazd();

    protected:
        string kolor, typ;
        int predkoscMax;
    private:
};

#endif // TPOJAZD_H

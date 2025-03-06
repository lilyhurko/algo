#ifndef TLODZ_H
#define TLODZ_H

#include <Tpojazd.h>
#include <iostream>

using namespace std;

class Tlodz : public Tpojazd
{
    public:
        Tlodz();
        Tlodz(string, string, int, bool, int);
        void podajDane();
        void info();
        virtual ~Tlodz();

    protected:
        bool silnik;
        int liczbaMiejsc;

    private:
};

#endif // TLODZ_H

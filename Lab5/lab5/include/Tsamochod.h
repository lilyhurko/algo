#ifndef TSAMOCHOD_H
#define TSAMOCHOD_H

#include <Tpojazd.h>


class Tsamochod : public Tpojazd
{
    public:
        Tsamochod();
        Tsamochod(string, string, int, bool, bool);
        void podajDane();
        void info();
        virtual ~Tsamochod();

    protected:
        bool klimatyzacja, radio;

    private:
};

#endif // TSAMOCHOD_H

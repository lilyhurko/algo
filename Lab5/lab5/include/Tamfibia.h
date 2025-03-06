#ifndef TAMFIBIA_H
#define TAMFIBIA_H

#include <Tsamochod.h>
#include "Tlodz.h"

class Tamfibia : public Tsamochod, public Tlodz
{
    public:
        Tamfibia();
        Tamfibia(string, string, int, bool, bool, bool, int, bool);
        void podajDane();
        void info();
        virtual ~Tamfibia();

    protected:
        bool maNapedNaKola;


    private:
};

#endif // TAMFIBIA_H

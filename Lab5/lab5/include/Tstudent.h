#ifndef TSTUDENT_H
#define TSTUDENT_H
#include <Tosoba.h>

class Tstudent : public Tosoba
{
    public:
        Tstudent();
        Tstudent(string, string, string, int);
        void wczytajOceny();
        void wyswietl();
        void wczytaj();
        float srednia();
        bool czyzaliczyl();
        virtual ~Tstudent();

    protected:

    private:
        string uczelnia;
        float *oceny;
        int liczbaOcen;
};

#endif // TSTUDENT_H

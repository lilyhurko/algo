#ifndef TPRACOWNIKUMYSLOWY_H
#define TPRACOWNIKUMYSLOWY_H
#include <Tpracownik.h>

class TpracownikUmyslowy : public Tpracownik
{
    public:
        TpracownikUmyslowy();
        TpracownikUmyslowy(string, string, string, float, float);
        void wyswietl();
        float oblicz();
        virtual ~TpracownikUmyslowy();

    protected:

    private:
};

#endif // TPRACOWNIKUMYSLOWY_H

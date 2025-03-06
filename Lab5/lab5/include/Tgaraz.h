#ifndef TGARAZ_H
#define TGARAZ_H


class Tgaraz
{
    public:
        Tgaraz();
        Tgaraz(int);
        void zaparkuj();
        void opusc();
        virtual ~Tgaraz();

    protected:
        int miescamax, wolnemiesca;

    private:
};

#endif // TGARAZ_H

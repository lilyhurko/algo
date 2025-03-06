#include "Tgaraz.h"
#include <iostream>

using namespace std;

Tgaraz::Tgaraz()
{
    miescamax = 10;
    wolnemiesca = 10;
}

Tgaraz::Tgaraz(int m)
{
    miescamax = m;
    wolnemiesca = m;
}

Tgaraz::~Tgaraz(){}

void Tgaraz::zaparkuj(){
    if (wolnemiesca == 0) {
        cout << "Garaz jest pelny." << endl;
    } else {
        wolnemiesca--;
        cout << "Pojazd zostal zaparkowany w garazu. Liczba wolnych miejsc: " << wolnemiesca << endl;
    }
}

void Tgaraz::opusc(){
    if (wolnemiesca == miescamax) {
        cout << "Garaz jest juz pusty." << endl;
    } else {
        wolnemiesca++;
        cout << "Pojazd opuscil garaz. Liczba wolnych miejsc: " << wolnemiesca << endl;
    }
}

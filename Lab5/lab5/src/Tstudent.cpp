#include "Tstudent.h"
#include <iostream>

using namespace std;

Tstudent::Tstudent():Tosoba(){
    if (oceny != nullptr) delete []oceny;
    cout << "Utworzono obiekt konstruktorem bez parametrow" << endl;
    uczelnia = "Politechnika Lubelska";
    liczbaOcen = 3;
    oceny = new float[liczbaOcen];
    for (int i = 0; i < liczbaOcen; i++){ *(oceny+i)=3; }
}
Tstudent::Tstudent(string imie, string nazwisko, string uczelnia, int liczbaOcen):Tosoba(imie, nazwisko){
    if (oceny != nullptr) delete []oceny;
    cout << "Utworzono obiekt konstruktorem z parametrami" << endl;
    this->uczelnia = uczelnia;
    this->liczbaOcen = liczbaOcen;
    oceny = new float[liczbaOcen];
    wczytajOceny();
}
Tstudent::~Tstudent(){cout << "Usunieto obiekt destruktorem" << endl; delete []oceny;}

void Tstudent::wczytaj(){
    delete []oceny;
    Tosoba::wczytaj();
    cout << "Podaj uczelnie: "; cin >> uczelnia;
    cout << "Podaj liczbe ocen: "; cin >> liczbaOcen;
    oceny = new float[liczbaOcen];
    wczytajOceny();
}

void Tstudent::wczytajOceny(){
    for (int i = 0; i < liczbaOcen; i++){
        cout << "Podaj ocene #" << i+1 << ": "; cin >> *(oceny+i);
    }
}

void Tstudent::wyswietl(){
    Tosoba::wyswietl();
    for (int i = 0; i < liczbaOcen; i++){
        cout << "Ocena #" << i+1 << ": " << *(oceny+i) << endl;
    }
    cout << "Srednia: " << srednia() << endl;
    if (czyzaliczyl()) {
        cout << "Student zaliczyl sesje" << endl;
    } else {
        cout << "Student nie zaliczyl sesje" << endl;
    }
}

float Tstudent::srednia(){
    float wynik = 0;
    for (int i = 0; i < liczbaOcen; i++){
        wynik += *(oceny+i);
    }
    wynik /= liczbaOcen;
    return wynik;
}

bool Tstudent::czyzaliczyl(){
    for (int i = 0; i < liczbaOcen; i++){
        if (*(oceny+i) < 3) {
            return false;
        }
    }
    return true;
}

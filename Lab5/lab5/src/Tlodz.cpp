#include "Tlodz.h"
#include <iostream>

using namespace std;

Tlodz::Tlodz():Tpojazd(){
    silnik = false;
    liczbaMiejsc = 5;
}

Tlodz::Tlodz(string t, string k, int p, bool s, int lm):Tpojazd(t,k,p){
    silnik = s;
    liczbaMiejsc = lm;
}
Tlodz::~Tlodz(){}

void Tlodz::podajDane(){
    Tpojazd::podajDane();
    cout << "Podaj czy ma silnik? (1 - prawda/0 - falsz):"; cin >> silnik;
    cout << "Podaj ilosc miejsc? :"; cin >> liczbaMiejsc;
}

void Tlodz::info(){
    Tpojazd::info();
    if (silnik){
        cout << "Ma silnik" << endl;
    } else {
        cout << "Nie ma silnika" << endl;
    }
    cout << "Ma " << liczbaMiejsc << " miejsc" << endl;
}

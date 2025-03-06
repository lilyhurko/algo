#include "Tpojazd.h"

Tpojazd::Tpojazd(){
    typ = "osobowy";
    kolor = "niebieski";
    predkoscMax = 150;
}

Tpojazd::Tpojazd(string t, string k, int p){
    typ = t;
    kolor = k;
    predkoscMax = p;
}
Tpojazd::~Tpojazd(){}

void Tpojazd::podajDane(){
    cout << "Podaj typ: "; cin >> typ;
    cout << "Podaj kolor: "; cin >> kolor;
    cout << "Podaj maxymalna predkosc: "; cin >> predkoscMax;
}

void Tpojazd::info(){
    cout << "Typ: " << typ << endl;
    cout << "Kolor: " << kolor << endl;
    cout << "Maxymalna predkosc: "<< predkoscMax << endl;
}

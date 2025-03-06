#include "Tsamochod.h"
#include <iostream>

using namespace std;

Tsamochod::Tsamochod():Tpojazd(){
    klimatyzacja = false;
    radio = false;
}

Tsamochod::Tsamochod(string t, string k, int p, bool kl, bool r):Tpojazd(t,k,p){
    klimatyzacja = kl;
    radio = r;
}
Tsamochod::~Tsamochod(){}

void Tsamochod::podajDane(){
    Tpojazd::podajDane();
    cout << "Podaj czy ma klimatyzacje? (1 - prawda/0 - falsz):"; cin >> klimatyzacja;
    cout << "Podaj czy ma radio? (1 - prawda/0 - falsz):"; cin >> radio;
}

void Tsamochod::info(){
    Tpojazd::info();
    if (klimatyzacja){
        cout << "Ma klimatyzacje" << endl;
    } else {
        cout << "Nie ma klimatyzacji" << endl;
    }
    if (radio){
        cout << "Ma radio" << endl;
    } else {
        cout << "Nie ma radia" << endl;
    }
}

#include "Tamfibia.h"
#include <iostream>

using namespace std;

Tamfibia::Tamfibia():Tsamochod(), Tlodz(){
    maNapedNaKola = true;
}

Tamfibia::Tamfibia(string t, string k, int p, bool kl, bool r, bool s, int lm, bool mn):Tsamochod(t,k,p,kl,r), Tlodz(t,k,p,s,lm){
    maNapedNaKola = mn;
}

Tamfibia::~Tamfibia(){}

void Tamfibia::podajDane(){
    Tsamochod::podajDane();
    Tlodz::podajDane();
    cout << "Podaj czy ma naped na wszystkie kola? (1 - prawda/0 - falsz):"; cin >> maNapedNaKola;
}

void Tamfibia::info(){
    Tsamochod::info();
    Tlodz::info();
    if (maNapedNaKola){
        cout << "Ma napend na wszystkie kola" << endl;
    } else {
        cout << "Nie ma napend na wszystkie kola" << endl;
    }
}

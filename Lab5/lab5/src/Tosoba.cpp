#include "Tosoba.h"
#include <iostream>

using namespace std;

Tosoba::Tosoba(){
    cout << "Utworzono obiekt klasy <Tosoba> konstruktorem bez parametrow" << endl;
    imie = "Liliia";
    nazwisko = "Hurko";
}
Tosoba::~Tosoba(){cout << "Usunieto obiekt destruktorem" << endl;}
Tosoba::Tosoba(string imie, string nazwisko){
    cout << "Utworzono obiekt konstruktorem z parametrami" << endl;
    this->imie = imie;
    this->nazwisko = nazwisko;
}

void Tosoba::wczytaj(){
    cout << "Podaj imie: "; cin >> imie;
    cout << "Podaj nazwisko: "; cin >> nazwisko;
}

void Tosoba::wyswietl(){
    cout << "Imie: " << imie << endl;
    cout << "Nazwisko: " << nazwisko << endl;
}

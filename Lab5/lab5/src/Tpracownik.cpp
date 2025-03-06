#include "Tpracownik.h"
#include <iostream>

using namespace std;

Tpracownik::Tpracownik(){
    cout << "Utworzono obiekt klasy <Tpracownik> konstruktorem bez parametrow" << endl;
    imie = "Maksym";
    nazwisko = "Melnychenko";
    firma = "Niema";
    stawka = 1500;
    premia = 0.30;
}

Tpracownik::Tpracownik(string imie, string nazwisko, string firma, float stawka, float premia){
    cout << "Utworzono obiekt klasy <Tpracownik> konstruktorem z parametrami" << endl;
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->firma = firma;
    this->stawka = stawka;
    this->premia = premia;
}

Tpracownik::~Tpracownik(){cout << "Usunieto obiekt klasy <Tpracownik> destruktorem" << endl;}

void Tpracownik::wczytaj(){
    cout << "Podaj imie: "; cin >> imie;
    cout << "Podaj nazwisko: "; cin >> nazwisko;
    cout << "Podaj firme: "; cin >> firma;
    cout << "Podaj stawke: "; cin >> stawka;
    cout << "Podaj premie w procentach (0.0-1.0): "; cin >> premia;
}

void Tpracownik::wyswietl(){
    cout << "Imie: " << imie << endl;
    cout << "Nazwisko: " << nazwisko << endl;
    cout << "Firma: " << firma << endl;
    cout << "Stawka: " << stawka << endl;
    cout << "Premia w procentach: " << premia*100 << "%" << endl;
}

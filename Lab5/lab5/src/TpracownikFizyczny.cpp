#include "TpracownikFizyczny.h"

TpracownikFizyczny::TpracownikFizyczny()
{
    cout << "Utworzono obiekt konstruktorem bez parametrow" << endl;
    liczbaGodzin = 1;
}

TpracownikFizyczny::TpracownikFizyczny(string imie, string nazwisko, string firma, float stawka, float premia, int liczbaGodzin):Tpracownik(imie, nazwisko, firma, stawka, premia)
{
    cout << "Utworzono obiekt konstruktorem z parametami" << endl;
    this->liczbaGodzin = liczbaGodzin;
}

TpracownikFizyczny::~TpracownikFizyczny(){cout << "Usunieto obiekt destruktorem" << endl;}

void TpracownikFizyczny::wyswietl(){
    Tpracownik::wyswietl();
    cout << "Liczba godzin: " << liczbaGodzin << endl;
    cout << "Placa pracownika fizycznego: " << oblicz() << endl;
}

float TpracownikFizyczny::oblicz(){
    return stawka*liczbaGodzin + (stawka*liczbaGodzin) * premia;
}

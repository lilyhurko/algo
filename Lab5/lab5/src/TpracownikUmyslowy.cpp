#include "TpracownikUmyslowy.h"

TpracownikUmyslowy::TpracownikUmyslowy()
{
    cout << "Utworzono obiekt konstruktorem bez parametrow" << endl;
}

TpracownikUmyslowy::TpracownikUmyslowy(string imie, string nazwisko, string firma, float stawka, float premia):Tpracownik(imie, nazwisko, firma, stawka, premia)
{
    cout << "Utworzono obiekt konstruktorem z parametami" << endl;
}
TpracownikUmyslowy::~TpracownikUmyslowy(){cout << "Usunieto obiekt destruktorem" << endl;}

void TpracownikUmyslowy::wyswietl(){
    Tpracownik::wyswietl();
    cout << "Placa pracownika umyslowego: " << oblicz() << endl;
}

float TpracownikUmyslowy::oblicz(){
    return stawka + stawka * premia;
}

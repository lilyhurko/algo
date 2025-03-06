#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct student{
    string imie;
    string nazwisko;
    string punkty;
};

void sortowanieQuickSort(student* tab, int n, int tryb);
void wczytajStudentow(student*&tab, int n);
void usunTabliceStudentow(student *&tab);
void wyswietlStudentow(student* tab, int n);
void sortP(student* tab, int n);

int main()
{
    int n, tryb;
    cout << "Podaj ilosc studentow: "; cin >> n;
    student *tab = new student[n];
    wczytajStudentow(tab, n);
    wyswietlStudentow(tab, n);
    cout << "Podaj tryb: "; cin >> tryb;
    sortowanieQuickSort(tab, n, tryb);
    cout << "Po sortowaniu: \n\n";
    wyswietlStudentow(tab, n);
    return 0;
}

void sortP(student *tab, int lewy, int prawy, int tryb){
    int srodek = (int)(lewy+prawy)/2;
    student pivot = tab[srodek];
    tab[srodek]=tab[prawy];
    int granica = lewy;
    for (int i = lewy; i < prawy; i++){
        if (tryb == 1){
            if (atoi(tab[i].punkty.c_str()) < atoi(pivot.punkty.c_str())){
                swap(tab[granica], tab[i]);
                granica++;
            }
        } else if (tryb == 0){
            if (atoi(tab[i].punkty.c_str()) > atoi(pivot.punkty.c_str())){
                swap(tab[granica], tab[i]);
                granica++;
            }
        }
    }
    tab[prawy]=tab[granica];
    tab[granica]=pivot;
    if (lewy < granica-1){
        sortP(tab, lewy, granica-1, tryb);
    }
    if (granica + 1 < prawy){
        sortP(tab, granica+1, prawy, tryb);
    }
}

void sortowanieQuickSort(student* tab, int n, int tryb){
    sortP(tab, 0, n-1, tryb);
}

void wczytajStudentow(student*&tab, int n){
    string sciezka,linia,text;
    ifstream plik;
    char sredniki;
    sciezka="studenci.csv";
    plik.open(sciezka);

    for(int i = 0; i < 2; i++)
        plik >> sredniki;

    for(int i=0; i<n; i++){
        plik >> linia;
        istringstream ss(linia);

        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, tab[i].punkty);
    }
    plik.close();
}

void usunTabliceStudentow(student *&tab){
    delete []tab;
}

void wyswietlStudentow(student* tab, int n){
    for (int i = 0; i < n; i++){
        if (tab[i].imie != ""){
            cout << tab[i].imie << " " << tab[i].nazwisko << ", punkty: " << tab[i].punkty << endl;
        }
    }
}

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

struct student{
    string imie;
    string nazwisko;
    int punkty;
};

void wczytajStudentow(student *&tab, int *n);
void wyswietlStudentow(student* tab, int n);
void wyszukiwanieLiniowe(student *tab, int n, int wartosc);
int wyszukiwaniBisekcyjne(student *tab, int n, int wartosc);
bool IsEmpty(student *tab);
void sortP(student *tab, int lewy, int prawy);
void sortowanieQuickSort(student* tab, int n);
void zapiszplik(student *tab, int n);
void Zad1(student *&tab, int &n);
void Zad2(student *tab, int n);
void Zad3(student *tab, int n);

int main(){
    int zad, n;
    student *tab = nullptr;

    while(1){
        cout << "Podaj numer zadania (1-3): ";
        cin >> zad;

        if (zad == 1){
            Zad1(tab, n);
        } else if (zad == 2){
            Zad2(tab, n);
        } else if (zad == 3){
            Zad3(tab, n);
        } else {
            break;
        }
        system("pause");
        system("cls");
    }
    delete []tab;
    return 0;
}

void wczytajStudentow(student *&tab, int *n){
    string linia;
    int liczbaStudentow;
    ifstream plik;
    char sredniki;
    plik.open("studenci2.csv");
    plik >> liczbaStudentow;
    for(int i = 0; i < 2; i++) plik >> sredniki;

    tab = new student[liczbaStudentow];

    for(int i=0; i<liczbaStudentow; i++){
        plik>>linia;
        stringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        ss >> tab[i].punkty;
    }
    plik.close();
    *n = liczbaStudentow;
}

void wyswietlStudentow(student* tab, int n){
    for (int i = 0; i < n; i++){
        cout << i+1 << ". " <<tab[i].imie << " " << tab[i].nazwisko << " " << tab[i].punkty << endl;
    }
}

void wyszukiwanieLiniowe(student *tab, int n, int wartosc){
    int k = 0;
    for (int i = 0; i < n; i++){
        if (tab[i].punkty == wartosc) {
            cout << tab[i].imie << " " << tab[i].nazwisko << endl;
            k++;
        }
    }
    if (k == 0) {
        cout << "Nie ma takiego studenta z taka liczba pukntow." << endl;
    }
}

int wyszukiwaniBisekcyjne(student *tab, int n, int wartosc){
    int lewy = 0, prawy = n-1, srodek, k=0;
    while(lewy<=prawy){
        srodek = (prawy+lewy)/2;
        if (tab[srodek].punkty == wartosc){
            return srodek;
        }
        if (wartosc < tab[srodek].punkty) {
            prawy = srodek-1;
        } else {
            lewy = srodek+1;
        }
    }
    return -1;
}

bool wyszukiwaniBisekcyjneTemp(student *tab, int n, int wartosc, int *index){
    int idx = wyszukiwaniBisekcyjne(tab, n, wartosc);
    if (idx == -1){
        cout << "Nie ma takiego studenta z taka liczba pukntow." << endl;
        return false;
    }
    int lewy = 0, prawy = 1;
    index[n] = -1;
    while(tab[idx+lewy].punkty == wartosc or tab[idx-prawy].punkty == wartosc){
        if (tab[idx+lewy].punkty == wartosc) {
            int e = index[n]+1;
            index[e] = idx+lewy;
            index[n] = e;
            cout << tab[idx+lewy].imie << " " << tab[idx+lewy].nazwisko << endl;
            lewy++;
        }
        if (tab[idx-prawy].punkty == wartosc) {
            int e = index[n]+1;
            index[e] = idx-prawy;
            index[n] = e;
            cout << tab[idx-prawy].imie << " " << tab[idx-prawy].nazwisko << endl;
            prawy++;
        }
    }
    return true;
}

bool IsEmpty(student *tab){
    if (tab == nullptr) {
        cout << "Nie masz danych. Otworz zadanie 1." << endl;
        return true;
    }
    return false;
}

void sortP(student *tab, int lewy, int prawy){
    int srodek = (int)(lewy+prawy)/2;
    student pivot = tab[srodek];
    tab[srodek]=tab[prawy];
    int granica = lewy;
    for (int i = lewy; i < prawy; i++){
        if (tab[i].punkty < pivot.punkty){
            swap(tab[granica], tab[i]);
            granica++;
        }
    }
    tab[prawy]=tab[granica];
    tab[granica]=pivot;
    if (lewy < granica-1){
        sortP(tab, lewy, granica-1);
    }
    if (granica + 1 < prawy){
        sortP(tab, granica+1, prawy);
    }
}


void sortowanieQuickSort(student* tab, int n){
    sortP(tab, 0, n-1);
}

void zapiszplik(student *tab, int n, int *index){
    ofstream zapis;
    cout << (index == nullptr);
    zapis.open("wyniki.csv");
    zapis<<index[n]+1<<";;"<<endl;
    for (int i=0; i<=index[n]; i++){
        zapis<<tab[index[i]].imie<<";"<<tab[index[i]].nazwisko<<";";
        zapis<<tab[index[i]].punkty<<endl;
    }

    zapis.close();
}

void Zad1(student *&tab, int &n){
    wczytajStudentow(tab, &n);
    wyswietlStudentow(tab, n);
}

void Zad2(student *tab, int n){
    if (IsEmpty(tab)) return;
    wyswietlStudentow(tab, n);
    int w;
    cout << "Podaj wartosc ktora szukasz: "; cin >> w; cout << "Wynik: " << endl;
    wyszukiwanieLiniowe(tab, n, w);
}

void Zad3(student *tab, int n){
    if (IsEmpty(tab)) return;
    sortowanieQuickSort(tab, n);
    wyswietlStudentow(tab, n);
    int w;
    cout << "Podaj wartosc ktora szukasz: "; cin >> w; cout << "Wynik: " << endl;
    int *index = new int[n+1];
    if (wyszukiwaniBisekcyjneTemp(tab, n, w, index)){
        zapiszplik(tab, n, index);
    }
    delete []index;
}

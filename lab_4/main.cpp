#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct student {
    string imie;
    string nazwisko;
    int punkty = 0;
};

void Zad1(student*&tab, int *n);
void Zad2(student*&tab, int *n);
void Zad3(student*&tab, int *n);
int PodzialNa2(student *tab, int n, int granica);
void PodzialNa3(student *tab, int n, int *m, int *k, int granica1, int granica2);
void CzytPlik(student*&tab, int *n);
void DeleteTab(student*&tab);
void wydruk(student* tab, int m, int n);
bool IsEmpty(student* tab);

int main()
{
    int zad = 1; int n;
    student *tab = new student[1];

    while (1){
        cout << "Podaj numer zadania (1-3, inna liczba - wyjscie): "; cin>> zad;
        if (zad == 1){
            Zad1(tab, &n);
        } else if (zad == 2){
            Zad2(tab, &n);
        } else if (zad == 3){
            Zad3(tab, &n);
        } else {
            cout << "Zamykam sie!" << endl;
            break;
        }
    }
    return 0;
}

void Zad1(student*&tab, int* n){
    CzytPlik(tab, n);
    cout << "Zczytalem!" << endl;
}

void Zad2(student*&tab, int* n){
    if (IsEmpty(tab)){
        cout << "Zczytaj napierw plik! Wywolaj zadanie #1" << endl;
        return;
    }
    int m = 0;
    cout << "\nLista do podzielenia: " << endl;
    wydruk(tab, m, *n);
    cout << "\nLista po podzieleniu: " << endl;
    m = PodzialNa2(tab, *n, 10);
    cout << "\nStudenci ktorzy otrzymali <=10 punktow: " << endl;
    wydruk(tab, 0, m);
    cout << "\nStudenci ktorzy otrzymali > 10 punktow: " << endl;
    wydruk(tab, m, *n);
}

void Zad3(student*&tab, int *n){
    if (IsEmpty(tab)){
        cout << "Zczytaj napierw plik! Wywolaj zadanie #1" << endl;
        return;
    }
    int m = 0; int k = 0;
    cout << "\nLista do podzielenia: " << endl;
    wydruk(tab, m, *n);
    cout << "\nLista po podzieleniu: " << endl;
    PodzialNa3(tab, *n, &m, &k, 0, 1);
    cout << "\nResta od dzielenia na 3 == 0: " << endl;
    wydruk(tab, 0, m+1);
    cout << "\nResta od dzielenia na 3 == 1: " << endl;
    wydruk(tab, m+1, k);
    cout << "\nResta od dzielenia na 3 == 2: " << endl;
    wydruk(tab, k, *n);

}

int PodzialNa2(student *tab, int n, int granica){
    int i = 0; int j = n - 1;
    while (i < j){
        while (tab[i].punkty <= granica && i < j) i++;
        while (tab[j].punkty > granica && i < j) j--;

        if (i < j){
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }

    if (tab[i].punkty <= granica){
        return i+1;
    }
    return i;
}

void PodzialNa3(student *tab, int n, int *m, int *l, int granica1, int granica2){
    int i = -1; int j = 0; int k = n;
    while (j < k){
        if (tab[j].punkty % 3 == granica1){
            i++;
            swap(tab[i], tab[j]);
            j++;
        } else {
            if (tab[j].punkty % 3 == granica2){
                k--;
                swap(tab[k], tab[j]);
            } else {
                j++;
            }
        }
    }

    *m = i; *l = k;
}

void CzytPlik(student*&tab, int *n){
    DeleteTab(tab);
    string linia;
    int liczbaStudentow;
    ifstream plik;
    char sredniki;

    plik.open("studenci.csv");
    plik >> liczbaStudentow;
    tab = new student[liczbaStudentow];
    *n = liczbaStudentow;

    for(int i = 0; i < 2; i++)
    plik >> sredniki;

    for(int i = 0; i < liczbaStudentow; i++){
        plik>>linia;
        istringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        ss >> tab[i].punkty;
    }
    plik.close();
}

void DeleteTab(student*&tab){
    delete []tab;
}

void wydruk(student* tab, int m, int n){
    for (m; m < n; m++){
        cout << tab[m].imie << " " << tab[m].nazwisko << ", ma punkty:" << tab[m].punkty << endl;
    }
}

bool IsEmpty(student* tab){
    return tab[0].punkty == 0;
}

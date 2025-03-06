#include <iostream>
#include <iomanip>
using namespace std;

void zad1(string &text, string &wzorzec, int &dlt, int &dlw);
void zad2(string text, string wzorzec, int dlt, int dlw);
void zad3(string text, string wzorzec, int dlt, int dlw);
void zad4(string text, string wzorzec, int dlt, int dlw);
void naiwne(string text, string wzorzec, int dlt, int dlw);
void zbudujTabloceDopasowan(string wzorzec, int dlw, int *p);
void kmp(string wzorzec, string text, int dlw, int dlt, int *p);

int main()
{
    int zad, dlt, dlw;//dlugosc tekstu i wzorcu
    string text, wzorzec;
    while(1){
        cout << "Podaj numer zadania (1-4): "; cin >> zad;
        if (zad == 1){
            zad1(text, wzorzec, dlt, dlw);
        } else if (zad == 2){
            zad2(text, wzorzec, dlt, dlw);
        } else if (zad == 3){
            zad3(text, wzorzec, dlt, dlw);
        } else if (zad == 4){
            zad4(text, wzorzec, dlt, dlw);
        } else {
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}

void zad1(string &text, string &wzorzec, int &dlt, int &dlw){
    cout << "Podaj tekst: "; cin.ignore(); getline(cin, text);
    cout << "Podaj wzorzec: "; getline(cin, wzorzec);
    dlt = text.length();
    dlw = wzorzec.length();
}

void naiwne(string text, string wzorzec, int dlt, int dlw){
    int j = 0, i = 0;
    while (i <= dlt-dlw){
        j = 0;
        while (j<dlw && wzorzec[j] == text[i+j]) j++;
        if (j == dlw){
            cout << i << ",";
        }
        i++;
    }
    cout << endl;
}

bool isEmpty(string text, string wzorzec){
    bool exit = false;
    if (text.length() == 0) {
        cout << "Nie podales tekstu. Wlacz zadanie 1!" << endl;
        exit = true;
    }
    if (wzorzec.length() == 0) {
        cout << "Nie podales wzorzcu. Wlacz zadanie 1!" << endl;
        exit = true;
    }

    if (exit == false){
        cout << text << endl;
        cout << wzorzec << endl;
    }
    return exit;
}
void zad2(string text, string wzorzec, int dlt, int dlw){
    if (isEmpty(text, wzorzec)) return;
    naiwne(text, wzorzec, dlt, dlw);
}

void zbudujTabliceDopasowan(string wzorzec, int dlw, int *p){
    p[0] = 0;
    p[1] = 0;
    int t = 0;
    for (int i = 1; i<=dlw; i++){
        while ((t>0) && (wzorzec[t] != wzorzec[i]))
            t = p[t];
        if (wzorzec[t] == wzorzec[i])
            t++;
        p[i+1] = t;
    }
}
void kmp(string wzorzec, string text, int dlw, int dlt, int *p){
    int i = 0, j = 0;
    while ( i < dlt-dlw+1){
        while ((wzorzec[j] == text[i+j]) && (j < dlw)) j++;
        if (j == dlw){
            cout << i << ",";
        }
        i += max(1,j-p[j]);
        j = p[j];
    }
    cout << endl;
}

void zad3(string text, string wzorzec, int dlt, int dlw){
    if (isEmpty(text, wzorzec)) return;
    int *p = new int[dlw+1];
    zbudujTabliceDopasowan(wzorzec, dlw, p);
    kmp(wzorzec, text, dlw, dlt, p);
    delete []p;
}

void tablicaPrzesuniec(string wzorzec, int dlw, int pocz, int kon, int *p){
    for (int i = 0; i <= kon-pocz; i++) p[i] = -1;
    for (int i = 0; i < dlw; i++) p[wzorzec[i]-pocz] = i;
}

void bm(string wzorzec, string text, int dlw, int dlt, int pocz, int *p){
    int j = 0;
    for (int i = 0; i <= dlt-dlw; i){
        j = dlw-1;
        while (j>-1 && wzorzec[j] == text[i+j]) j--;
        if (j==-1){
            i++;
            cout << i-1 << ",";
        } else {
            i += max(1, j-p[text[i+j]-pocz]);
        }
    }
    cout << endl;
}

void zad4(string text, string wzorzec, int dlt, int dlw){
    if (isEmpty(text, wzorzec)) return;
    int *p = new int[256];
    zbudujTabliceDopasowan(wzorzec, dlw, p);
    tablicaPrzesuniec(wzorzec, dlw, text[0], 255, p);
    bm(wzorzec, text, dlw, dlt, text[0], p);
    delete []p;
}

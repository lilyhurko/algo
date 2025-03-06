#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void wczytajPlik(string *&text, string *wzorzec, int *n);
int make_hash(int s, int off, int p, int exp);
int update_hash(int hhash, int s_prev, int s_next, int off, int p, int exp);
int kr(string pattern, string text, int p, int off, int hashP);

int main(){
    string *text;
    int n, hashP = 0;

    string wzorzec;
    wczytajPlik(text, &wzorzec, &n);
    for (int i = 0; i < wzorzec.length(); i++){
        hashP = hashP+make_hash(wzorzec[i], 97, 2, wzorzec.length()-i-1);
    }
    cout << "Podany wzorzec: " << wzorzec << endl;
    for (int i = 0; i < n; i++){
        cout << "==============================================" << endl;
        cout << "Linijka "<< i+2 << ": " << text[i] << endl;
        cout << "Linijka "<< i+2 << ": ";
        int wynik = kr(wzorzec, text[i], 2, 97, hashP);
        if (wynik == -1) cout << -1;
        cout << endl;
    }
    cout << "==============================================" << endl;
    delete []text;
    return 0;
}

void wczytajPlik(string *&text, string *wzorzec, int *n){
    string linia, smiecie;
    ifstream plik;

    plik.open("tekst.txt");
    int N = -1;
    while (getline (plik, smiecie)) N ++;
    plik.close();

    plik.open("tekst.txt");
    plik >> *wzorzec;
    text = new string[N];
    for(int i=0; i<N; i++){
        plik>>linia;
        stringstream ss(linia);
        getline(ss, text[i]);
    }
    plik.close();
    *n = N;
}

int make_hash(int s, int off, int p, int exp){
    return (s-off)*pow(p,exp);
    }

int update_hash(int hhash, int s_prev, int s_next, int off, int p, int exp){
    return (((hhash-(s_prev-off)*pow(p, exp))*p)+(s_next-off));
    }

int kr(string wzorzec, string text, int p, int off, int hashP){
    int wynik = -1, hashT = 0, i = 0, j = 0;
    for (i = 0; i < wzorzec.length(); i++) hashT = hashT+make_hash(text[i], off, p, wzorzec.length()-i-1);
    for (i = wzorzec.length(), j = 0; i<=text.length(); i++, j++){
        if (hashP == hashT){
            wynik = i-wzorzec.length();
            j = 0;
            while (j<wzorzec.length() && wzorzec[j] == text[wynik+j]) j++;
            if (j == wzorzec.length()) cout << wynik << ",";

        //    cout << wynik << " ";

        }
        if (i < text.length()){
           hashT = update_hash(hashT, text[j], text[i], off, p, wzorzec.length()-1);
        }
    }
    return wynik;
}

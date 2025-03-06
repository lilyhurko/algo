#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void sortowanieBabelkowe(int* tablica, int n, int tryb) {
    bool zmiana = true;
    while (zmiana) {
        zmiana = false;
        for (int i = 0; i < n - 1; i++) {
            if ((tryb == 1 && tablica[i] > tablica[i + 1]) || (tryb == 0 && tablica[i] < tablica[i + 1])) {
                swap(tablica[i], tablica[i + 1]);
                zmiana = true;
            }
        }
    }
}

void sortowaniePrzezWybor(int* tablica, int n, int tryb) {
    for (int i = 0; i < n - 1; i++) {
        int minIndeks = i;
        for (int j = i + 1; j < n; j++) {
            if ((tryb == 1 && tablica[j] < tablica[minIndeks]) || (tryb == 0 && tablica[j] > tablica[minIndeks])) {
                minIndeks = j;
            }
        }
        if (minIndeks != i) {
            swap(tablica[i], tablica[minIndeks]);
        }
    }
}

void sortowaniePrzezWstawianie(int* tablica, int n, int tryb) {
    for (int i = 1; i < n; i++) {
        int klucz = tablica[i];
        int j = i - 1;
        while ((tryb == 1 && j >= 0 && tablica[j] > klucz) || (tryb == 0 && j >= 0 && tablica[j] < klucz)) {
            tablica[j + 1] = tablica[j];
            j--;
        }
        tablica[j + 1] = klucz;
    }
}

void sortowaniePrzezWstawianieDwu(int** tablica, int wiersze, int kolumny, int tryb, int nrKolumny) {
    for (int i = 1; i < wiersze; i++) {
        int klucz = tablica[i][nrKolumny];
        int j = i - 1;
        while ((tryb == 1 && j >= 0 && tablica[j][nrKolumny] > klucz) || (tryb == 0 && j >= 0 && tablica[j][nrKolumny] < klucz)) {
            for (int m = 0; m < kolumny; m++) {
                tablica[j + 1][m] = tablica[j][m];
            }
            j--;
        }
        for (int m = 0; m < kolumny; m++) {
            tablica[j + 1][m] = klucz;
        }
    }
}

void wypelnienieTablicy(int* tablica, int n, int a, int b) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        tablica[i] = rand() % (b - a + 1) + a;
    }
}

void generuj(int* tablica, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        tablica[i] = rand();
    }
}


int main() {
 int wybor = 0;

    while (wybor != 5) {
        cout << "Menu:" << endl;
        cout << "1. Sortowanie babelkowe" << endl;
        cout << "2. Sortowanie przez wybor" << endl;
        cout << "3. Sortowanie przez wstawianie" << endl;
        cout << "4. Sortowanie dwuwymiarowej tablicy przez wstawianie" << endl;
        cout << "5. Wyjscie" << endl;

        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch(wybor){
        case 1: {
            int n;
            int tryb;
            cout << "Podaj ilosc elementow tablicy: ";
            cin >> n;
            int* tablica = new int[n];
            cout << "Podaj tryb sortowania (0 - malejaco, 1 - rosnaco): ";
            cin >> tryb;
            wypelnienieTablicy(tablica, n, 0, 100);
            sortowanieBabelkowe(tablica, n, tryb);
            cout << "Posortowana tablica: ";
            for (int i = 0; i < n; i++) {
            cout << tablica[i] << " ";
            }
            cout << endl;
            delete[] tablica;
            break;
            }
        case 2: {
            int n;
            int tryb;
            cout << "Podaj ilosc elementow tablicy: ";
            cin >> n;
            int* tablica = new int[n];
            cout << "Podaj tryb sortowania (0 - malejaco, 1 - rosnaco): ";
            cin >> tryb;
            wypelnienieTablicy(tablica, n, 0, 100);
            sortowaniePrzezWybor(tablica, n, tryb);
            cout << "Posortowana tablica: ";
            for (int i = 0; i < n; i++) {
            cout << tablica[i] << " ";
            }
            cout << endl;
            delete[] tablica;
            break;
            }
        case 3:{
            int n3;
            int tryb3;
            cout << "Podaj liczbe elementow tablicy: ";
            cin >> n3;
            cout << "Wybierz tryb sortowania (0 - rosnaco, 1 - malejaco): ";
            cin >> tryb3;
            int* tablica3 = new int[n3];
            wypelnienieTablicy(tablica3, n3, 0, 100);
            cout << "Tablica przed sortowaniem: ";
            for (int i = 0; i < n3; i++) {
                cout << tablica3[i] << " ";
            }
            cout << endl;
            delete[] tablica3;
            break;
            }
        case 4: {
            int wiersze, kolumny, tryb, nrKolumny;
            cout << "Podaj ilosc wierszy tablicy: ";
            cin >> wiersze;
            cout << "Podaj ilosc kolumn tablicy: ";
            cin >> kolumny;
            int** tablica = new int*[wiersze];
            for (int i = 0; i < wiersze; i++) {
                tablica[i] = new int[kolumny];
            }
            cout << "Podaj tryb sortowania (0 - malejąco, 1 - rosnąco): ";
            cin >> tryb;
            cout << "Podaj numer kolumny, wedlug ktorej sortowac: ";
            cin >> nrKolumny;
            generuj(tablica[0], wiersze * kolumny); //generuje losowe wartości dla całej tablicy
            sortowaniePrzezWstawianieDwu(tablica, wiersze, kolumny, tryb, nrKolumny);
            cout << "Posortowana tablica: " << endl;
            for (int i = 0; i < wiersze; i++) {
                for (int j = 0; j < kolumny; j++) {
                    cout << tablica[i][j] << " ";
                }
                cout << endl;
            }
            for (int i = 0; i < wiersze; i++) {
                delete[] tablica[i];
            }
            delete[] tablica;
            break;
        }


        case 5: {
            cout << "Koniec programu." << endl;
            break;
            }
            default: {
            cout << "Nie ma takiej opcji w menu." << endl;
            break;
            }
            }
            }


return 0;

        }







#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct element{
    int dane;
    element *next = nullptr;
};

struct kolejka{
    element* head = nullptr;
    element* tail = nullptr;
};

bool isEmpty(kolejka *k);
void push(kolejka *k, int x);
int pop(kolejka *k);
int first(kolejka *k);
int iloscNieparyzstych(kolejka* k);

int main(){

    kolejka *k = new kolejka;
    int il = 0;
    int val;
    do{
        cout << "Podaj ilosc liczb: "; cin >> il;
    } while (il<=0);
    for (int i = 0; i < il; i++){
        cout << "Podaj liczbe: "; cin >> val;
        push(k, val);
    }
    cout << iloscNieparyzstych(k);
    return 0;
}


int iloscNieparyzstych(kolejka* k) {
    kolejka temp;
    int ilosc = 0;
    int value;
    while (!isEmpty(k)) {
        value = pop(k);
        if (value % 2 != 0) {
            ilosc++;
        }
        push(&temp, value);
    }

    while (!isEmpty(&temp)) {
        int value = pop(&temp);
        push(k, value);
    }

    return ilosc;
}

bool isEmpty(kolejka* k) {
    return k->head == nullptr;
}

void push(kolejka* k, int x) {
    element* newElement = new element;
    newElement->dane = x;
    newElement->next = nullptr;

    if (isEmpty(k)) {
        k->head = newElement;
        k->tail = newElement;
    } else {
        k->tail->next = newElement;
        k->tail = newElement;
    }
}

int pop(kolejka* k) {
    if (isEmpty(k)) {
        cout << "Kolejka jest pusta!" << endl;
        return -1;
    }

    element* temp = k->head;
    int value = temp->dane;
    k->head = k->head->next;

    if (k->head == nullptr) {
        k->tail = nullptr;
    }

    delete temp;
    return value;
}

int first(kolejka* k) {
    if (isEmpty(k)) {
        cout << "Kolejka jest pusta!" << endl;
        return -1;
    }

    return k->head->dane;
}

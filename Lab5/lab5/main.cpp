#include <iostream>
#include <Tstudent.h>
#include <TpracownikUmyslowy.h>
#include <TpracownikFizyczny.h>

using namespace std;

void line(int);
void zad1();
int main()
{
        zad1();
        system("pause");
        system("cls");

    return 0;
}
void zad1(){
    line(75);
    Tstudent st;
    st.wyswietl();
    line(75);
    TpracownikUmyslowy tu;
    tu.wyswietl();
    line(75);
    TpracownikFizyczny tf("Nataliia", "Marushko", "Works as a mathematics teacher", 10, 0.2, 200); //Moj kolega z servera discord
    tf.wyswietl();
    line(75);
}


void line(int d){
    for (int i = 0; i < d; i++) cout << "=";
    cout << endl;
}

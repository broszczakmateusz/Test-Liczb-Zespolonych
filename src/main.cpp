#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.h"

using namespace std;

int main(int argc, char **argv)
{

if (argc < 2) {
cout << endl;
cout << " Brak opcji okreslajacej rodzaj testu." << endl;
cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
cout << endl;
return 1;
}
BazaTestu   BazaT = { nullptr, 0, 0 };

if (InicjalizujTest(&BazaT,argv[1]) == false) {
cerr << " Inicjalizacja testu nie powiodla sie." << endl;
return 1;
}

cout << endl;
cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
cout << endl;

WyrazenieZesp   WyrZ_PytanieTestowe;
LZespolona PoprawnyWynik, Odp;
Statystyka Stat;
int LicznikBledow = 1;

while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {

cout << " :? Podaj wynik dzialania " << WyrZ_PytanieTestowe << endl;
cout << " Twoja odpowiedz: ";

cin.clear();
cin >> Odp;

     do {
        if (!cin.good()) {
            cout << " :! Blad zapisu liczby zespolonej. Sprobuj jeszcze raz. " ;
            cin.clear();
            LicznikBledow++;
            cin >> Odp;

        } else {
            LicznikBledow = 1;
            PoprawnyWynik = Oblicz(WyrZ_PytanieTestowe);

            if (Odp == PoprawnyWynik) {
                cout << " :) Twoja odpowiedz jest poprawna." << endl << endl;
                Dodaj_popr(Stat);
            } else {
                cout << " :( Blad. Prawidlowym wynikiem jest:" << PoprawnyWynik << endl << endl;
            }
            break;
        }
} while (LicznikBledow <= 3);
    Dodaj_wszystkie(Stat);
}

double ProcentPopr;

cout << " Koniec testu" << endl;
cout << " Ilosc dobrych odpowiedzi: " << Stat.popr << endl;
cout << " Ilosc blednych odpowiedzi: " << Stat.wszystkie - Stat.popr << endl;
ProcentPopr = (double) (Stat.popr *100) / Stat.wszystkie;
cout << " Wynik procentowy poprawnych odpowiedzi: " << ProcentPopr << "%";


}

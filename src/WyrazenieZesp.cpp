#include <iostream>
#include "WyrazenieZesp.hh"

using std::cout;
/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

std::ostream & operator << (std::ostream & str, const WyrazenieZesp &out) {
    str << out.Arg1;
    switch (out.Op) {
        case Op_Dodaj:
            cout << "+";
            break;
        case Op_Odejmij:
            cout << "-";
            break;
        case Op_Mnoz:
            cout << "*";
            break;
        case Op_Dziel:
            cout << "/";
            break;
    }
    str << out.Arg2;
}

LZespolona Oblicz(WyrazenieZesp  WyrZ) {
    LZespolona Wynik;
    switch (WyrZ.Op) {
        case Op_Dodaj:
            Wynik = WyrZ.Arg1 + WyrZ.Arg2;
            break;
        case Op_Odejmij:
            Wynik = WyrZ.Arg1 - WyrZ.Arg2;
            break;
        case Op_Mnoz:
            Wynik = WyrZ.Arg1 * WyrZ.Arg2;
            break;
        case Op_Dziel:
            Wynik = WyrZ.Arg1 / WyrZ.Arg2;
            break;
    }
    return Wynik;

}
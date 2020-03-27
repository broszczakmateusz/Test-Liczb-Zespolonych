#include <iostream>
#include "LZespolona.hh"

/*!
 *  Wczytuje ze standardowego wejscia liczbe zespoloną
 * */
std::istream & operator >> (std::istream & str, LZespolona &in) {

    char znak;
    str >> znak;
    if (znak != '(') {
        str.setstate(std::ios::failbit);
    }
    str >> in.re;
    str >> in.im;
    str >> znak;
    if (znak != 'i') {
        str.setstate(std::ios::failbit);
    }
    str >> znak;
    if (znak != ')') {
        str.setstate(std::ios::failbit);
    }
}

/*!
 * Wyswietla liczbę zespolona na standardoe wyjscie w postaci (0+0i)
 */

std::ostream & operator << (std::ostream & str, const LZespolona &out) {

  str << "(" << out.re << std::showpos << out.im << std::noshowpos << "i)";
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;

  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Różnicę dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
    LZespolona  Wynik;

    Wynik.re = Skl1.re - Skl2.re;
    Wynik.im = Skl1.im - Skl2.im;

    return Wynik;
}

/*!
 * Realizuje mnożenie dwoch liczb zespolonych.
 *
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnożenia,
 *    Skl2 - drugi skladnik mnożenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
    LZespolona  Wynik;

    Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
    Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;

    return Wynik;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 *
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2) {

    LZespolona Sprzerzona, Wynik;
    double modul2;

    Sprzerzona = Sprzerzenie(Skl2);
    modul2 = Modul2(Skl2);
    if (modul2 != 0) {
        Wynik.re = (Skl1.re * Sprzerzona.re - Skl1.im * Sprzerzona.im) / modul2;
        Wynik.im = (Skl1.re * Sprzerzona.im + Skl1.im * Sprzerzona.re) / modul2;
        return Wynik;
    }
    else {
        std::cerr << "Nie dziel przez 0";
        exit(1);
    }
}


bool operator == (LZespolona  L1,  LZespolona  L2) {
    if ((L1.re == L2.re) && (L1.im == L2.im))
        return true;
    else
        return false;
}

bool operator != (LZespolona  L1,  LZespolona  L2) {
    return !(L1 == L2);
}

LZespolona Sprzerzenie (LZespolona Liczba)  {

    LZespolona Lsprzerzenie;

    Lsprzerzenie.re = Liczba.re;
    Lsprzerzenie.im = -Liczba.im;

    return Lsprzerzenie;
}

double Modul2(LZespolona Liczba)  {
    double modul2;
    modul2 = Liczba.re * Liczba.re + Liczba.im * Liczba.im;

    return modul2;
}
/*!
 * Tworzy liczbę zespoloną żłożoną z części rzeczywistej i części urojonej
 * Argumenty:
 *   re - część rzeczywista
 *   im - część urojona
 * Zwraca:
 *   Strukturę liczby zespolonej
 * */
/*LZespolona Utworz (double re, double im) {

    Liczba.re = re;
    Liczba.im = im;

    return Liczba;
}*/

/*!
 *  Wczytuje dwie wartosci double ze standardowego wejscia i zwraca je jako liczbe zespoloną
 * */
/*LZespolona Wczytaj() {

    double re, im;

    cin >> re >> im;

    return Utworz(re,im);
}*/

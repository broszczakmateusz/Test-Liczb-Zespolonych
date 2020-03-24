#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


LZespolona Utworz (double, double);
LZespolona Wczytaj (void);
std::istream & operator >> (std::istream & str, LZespolona &);
std::ostream & operator << (std::ostream & str, const LZespolona &out);


/*
  Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
bool operator == (LZespolona  L1,  LZespolona  L2);
bool operator != (LZespolona  L1,  LZespolona  L2);
LZespolona Sprzerzenie (LZespolona);
double Modul2(LZespolona);


#endif

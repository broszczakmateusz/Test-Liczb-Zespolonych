#ifndef Z2_STATYSTYKA_H
#define Z2_STATYSTYKA_H

struct  Statystyka {
    int  popr = 0;    /*! Pole repezentuje ilosc poprawnych odpowiedzi. */
    int  wszystkie = 0;    /*! Pole repezentuje ilosc wysztskich odpowiedzi. */
};

void Dodaj_popr (Statystyka &Stat);
void Dodaj_wszystkie (Statystyka &Stat);

#endif //Z2_STATYSTYKA_H

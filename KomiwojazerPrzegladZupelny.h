//
// Created by julia on 26.05.2017.
//

#ifndef PROJEKT3_KOMIWOJAZERPRZEGLADZUPELNY_H
#define PROJEKT3_KOMIWOJAZERPRZEGLADZUPELNY_H

#include <iostream>

class KomiwojazerPrzegladZupelny {
    int lwierzcholkow;
    int lkrawedzi;
    int v0;
    int wagaSciezki;
    int dh;
    int sptr;
    int shptr;
    int **MacierzSasiedztwa;
    int *Sciezka,*Sh;                       // Stosy w tablicy
    bool *visited;                    // Tablica odwiedzin

    const int MAXINT = 2147483647;

public:
    bool wczytaj(std::string nazwapliku);
    void TSP(int v);
    void przegladZupelny();
    ~KomiwojazerPrzegladZupelny();
    void wyswietl();
    void setLwierzcholkow(int lwierzcholkow);
    void setLkrawedzi(int lkrawedzi);
    void setMacierzSasiedztwa(int **MacierzSasiedztwa);
    void przygotuj();
};


#endif //PROJEKT3_KOMIWOJAZERPRZEGLADZUPELNY_H

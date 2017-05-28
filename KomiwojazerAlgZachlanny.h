//
// Created by julia on 27.05.2017.
//

#ifndef PROJEKT3_KOMIWOJAZERALGZACHLANNY_H
#define PROJEKT3_KOMIWOJAZERALGZACHLANNY_H
#include <iostream>
struct Edge{
    int v1;
    int v2;
    int waga;
};

class KomiwojazerAlgZachlanny {
    const int MAXINT = 2147483647;
    int lwierzcholkow;
    int lkrawedzi=0;
    bool *visited;
    int **MacierzSasiedztwa;
    int sptr=0;
    int *Sciezka;
    Edge * S;
    int v0;
    int wagaSciezki=0;

    Edge * H;
    int wagaH=0;
public:
    bool wczytaj(std::string nazwapliku);
    void algZachlanny();
    void wyswietl();
    void wyswietlwczytane();
    KomiwojazerAlgZachlanny();
    ~KomiwojazerAlgZachlanny();
    bool zmianaWierzcholka(int v);
    void setLwierzcholkow(int lwierzcholkow);
    void setLkrawedzi(int lkrawedzi);
    void setMacierzSasiedztwa(int **MacierzSasiedztwa);
    void przygotuj();

    void alg2optymalny();
    void algZachlanny1();
    bool zmianaWierzcholka1(int v);
    void wyswietl1();

};


#endif //PROJEKT3_KOMIWOJAZERALGZACHLANNY_H

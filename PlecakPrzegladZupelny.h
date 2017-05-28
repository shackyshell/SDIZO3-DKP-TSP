//
// Created by julia on 23.05.2017.
//

#ifndef PROJEKT3_PLECAK_H
#define PROJEKT3_PLECAK_H
#include <iostream>
#include "Element.h"



class PlecakPrzegladZupelny {
    Element *tab;
public:
    void setTab(Element *tab);

    void setPlecak(Element *plecak);

    void setPojemnosc(int pojemnosc);

    void setIlechcemy(int ilechcemy);

private:
    //zasoby, wszystkie dostepne przedmioty
    double tablength=0;  //ilosc przedmiotow
    int ** bruteforce;   //macierz wartosci binarnych - wszystkie kombinacje wyboru przedmiotow
    int * wartoscPlecaka;//tablica warosci dla poszczegolnych kombinacji
    int * wagaPlecaka;
    Element *plecak;
    int plecaklength;
    int max; //maksymalna wartosc jaka udalo sie znalezc
    int pojemnosc;
    int ilechcemy; //nie wiem po co to
public:
    bool wczytaj(std::string nazwapliku);
    void wyswietl();
    void wyswietlwczytane();
    void przegladZupelny();
    void decToBin(int j);
   // void wyswietlMacierz();
    ~PlecakPrzegladZupelny();

};


#endif //PROJEKT3_PLECAK_H

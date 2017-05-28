//
// Created by julia on 24.05.2017.
//

#ifndef PROJEKT3_PLECAKALGZACHLANNY_H
#define PROJEKT3_PLECAKALGZACHLANNY_H


#include <iostream>
#include "Element.h"


class PlecakAlgZachlanny {
    Element *tab;
public:
    void setTab(Element *tab);

    void setPlecak(Element *plecak);

    void setPojemnosc(int pojemnosc);

    void setIlechcemy(int ilechcemy);

private:
    //zasoby, wszystkie dostepne przedmioty
    double tablength=0;  //ilosc przedmiotow
    int wartoscPlecaka=0;
    int wagaPlecaka=0;
    int plecaklength=0;
    Element *plecak;

    //int i=0;
    int pojemnosc;
    int ilechcemy; //nie wiem po co to
public:
    bool wczytaj(std::string nazwapliku);
    void wyswietl();
    void algZachlanny();
    void sort(Element * tablica);
    void wyswietlwczytane();
    // void wyswietlMacierz();
    ~PlecakAlgZachlanny();

};

#endif //PROJEKT3_PLECAKALGZACHLANNY_H

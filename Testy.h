//
// Created by julia on 28.05.2017.
//

#ifndef PROJEKT3_TESTY_H
#define PROJEKT3_TESTY_H
#include<conio.h>
#include<string>
#include<iostream>
#include <afxres.h>
#include <iomanip>
#include <fstream>
#include "PlecakPrzegladZupelny.h"
#include "PlecakAlgZachlanny.h"
#include "KomiwojazerPrzegladZupelny.h"
#include "KomiwojazerAlgZachlanny.h"
#include "Element.h"


class Testy {
public:
    long long int frequency, start, elapsed;
    float times;
    float timems;
    float timeus;
    PlecakPrzegladZupelny tpp;
    PlecakAlgZachlanny tpz;
    KomiwojazerPrzegladZupelny tkp;
    KomiwojazerAlgZachlanny tkz;
    int plecakpojemnosc;
    Element *tablica;
    int **MacierzSasiedztwa;
    int lkrawedzi;

public:
    void ZachowajCzas();
    long long int read_QPC();
    void zapiszStatystykeDoPliku(std::string nazwapliku, float timeus);
    void zapiszDoPliku(std::string nazwapliku, std::string tresc);
    Element *losowoPlecak(int ilosc);
    void testyPlecak(std::string nazwaPliku1, std::string nazwaPliku2, int n);
    void wyswietlPlecak(int n);
    void losowoKomiwojazer(int ilosc);
    void losowoKomiwojazerPELNY(int ilosc);
    void testyKomiwojazer(std::string nazwaPliku1, std::string nazwaPliku2, int n);
    void wyswietlMacierzSasiedztwa(int n);
};


#endif //PROJEKT3_TESTY_H

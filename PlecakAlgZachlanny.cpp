//
// Created by julia on 24.05.2017.
//

#include "PlecakAlgZachlanny.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
//#include <cmath>
#include <sstream>
#include <cmath>
#include <iomanip>
using namespace std;

bool PlecakAlgZachlanny::wczytaj(std::string nazwapliku) {
    tablength=0;  //ilosc przedmiotow
    wartoscPlecaka=0;
    wagaPlecaka=0;
    plecaklength=0;

    std::fstream plik;
    plik.open( nazwapliku.c_str() );
    if( !plik.good() ) {
        cout<<"Nazwa pliku jest nieprawidlowa.\n";
        return false;
    }
    Element tmp;
    int i=0;
    plik >> pojemnosc>> ilechcemy;
    tab=new Element[ilechcemy];
    while(true){
        if( plik.good()){
            plik>>tmp.rozmiar>>tmp.wartosc;
            tmp.cennosc=(float)tmp.wartosc/tmp.rozmiar;
            tab[i]=tmp;
            tablength++;
        }
        else {
            break; //zakończ wczytywanie danych - wystąpił jakiś błąd (np. nie ma więcej danych w pliku)
        }
        i++;
    }
    plik.close();
    return true;
}

void PlecakAlgZachlanny::wyswietl() {
    cout<<endl<<"Zebrano rzeczy "<<endl;
    cout<<"o rozmiarze   "<<endl;
    for(int i=0;i<plecaklength;i++){
        cout<<plecak[i].rozmiar<<" ";
    }
    cout<<endl;
    cout<<"i wartosciach "<<endl;
    for(int i=0;i<plecaklength;i++){
        cout<<plecak[i].wartosc<<" ";
    }
    cout<<endl;
    cout<<"Laczna wartosc to "<<wartoscPlecaka<<endl;
}

void PlecakAlgZachlanny::algZachlanny() {

    this->sort(tab);

    int i=0;
    plecak=new Element[(int)tablength];
    while(wagaPlecaka<pojemnosc && tablength>0){
        if( pojemnosc>=wagaPlecaka+tab[0].rozmiar) {
            plecak[i] = tab[0];
            wartoscPlecaka += tab[0].wartosc;
            wagaPlecaka+=tab[0].rozmiar;
            tab[0]=tab[(int)tablength-1];
            tablength--;
            plecaklength++;
            this->sort(tab);
        }
        else{
            //break;
            tab[0]=tab[(int)tablength-1];
            this->sort(tab);
            tablength--;
            i--;
        }
        i++;
    }
    //wyswietl();
}



void PlecakAlgZachlanny::sort(Element *tablica) {
    int roz=tablength;
    int lpoziomow=0;
    while(roz>0){
        roz-=pow((double)2,lpoziomow);
        lpoziomow++;
    }
    for(int i=0; i<tablength; i++) {                    //uporzadkowanie tablicy
        Element element=tablica[i];
        for(int c=0; c<(lpoziomow-1);c++) {
            int j = ceil((i-1)/2);
            while (i>0 && tablica[j].cennosc<element.cennosc) {
                tablica[i] = tablica[j];
                tablica[j] = element;
                i = j;
                j = ceil((i-1)/2);
            }
            tablica[i]=element;
        }
    }
}

void PlecakAlgZachlanny::wyswietlwczytane() {
    cout<<"rozmiar"<<endl;
    for(int i=0;i<tablength;i++){
        cout<<tab[i].rozmiar<<" ";
    }
    cout<<endl;
    cout<<"wartosc"<<endl;
    for(int i=0;i<tablength;i++){
        cout<<tab[i].wartosc<<" ";
    }
    cout<<endl;
}

PlecakAlgZachlanny::~PlecakAlgZachlanny() {
    cout<<"wywoluje sie destruktor PlecakAlgZachlanny"<<endl;
    delete tab;
    delete plecak;
}






void PlecakAlgZachlanny::setTab(Element *tab) {
    PlecakAlgZachlanny::tab=new Element[ilechcemy];
    PlecakAlgZachlanny::tab = tab;
}

void PlecakAlgZachlanny::setPlecak(Element *plecak) {
    PlecakAlgZachlanny::plecak = plecak;
}

void PlecakAlgZachlanny::setPojemnosc(int pojemnosc) {
    PlecakAlgZachlanny::pojemnosc = pojemnosc;
}

void PlecakAlgZachlanny::setIlechcemy(int ilechcemy) {
    PlecakAlgZachlanny::ilechcemy = ilechcemy;
    tablength=ilechcemy;
}

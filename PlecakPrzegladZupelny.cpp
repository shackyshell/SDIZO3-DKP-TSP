//
// Created by julia on 23.05.2017.
//

#include "PlecakPrzegladZupelny.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
//#include <cmath>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

bool PlecakPrzegladZupelny::wczytaj(std::string nazwapliku) {
    tablength=0;

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
    while(true) //(true) pętla nieskończona
    {
        if( plik.good() ){
            plik>>tmp.rozmiar>>tmp.wartosc;
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

void PlecakPrzegladZupelny::wyswietlwczytane() {
    cout<<"pojemnosc plecaka "<<pojemnosc<<" ilechcemy "<<ilechcemy<<endl;
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

void PlecakPrzegladZupelny::przegladZupelny() {
    int tmp=pow(2,tablength);
    bruteforce=new int*[(int)tablength];
    wartoscPlecaka=new int[tmp];
    wagaPlecaka=new int[tmp];
    for(int j=0;j<tmp;j++){           //wypelniam zerami
        wartoscPlecaka[j]=0;
        wagaPlecaka[j]=0;
    }
    for(int i=0;i<tablength;i++){
        bruteforce[i]=new int[tmp];
    }
    for(int i=0;i<tablength;i++){   //wypelniam zerami
        for(int j=0;j<tmp;j++){
            bruteforce[i][j]=0;
        }
    }
    for(int j=1;j<tmp;j++){         //wypelniam liczbami binarnymi
        decToBin(j);
    }
    //wyswietlMacierz();

    for(int j=0;j<tmp;j++){
        for(int i=0;i<tablength;i++){
            if( bruteforce[i][j]==1) {
                wartoscPlecaka[j] += tab[i].wartosc;
                wagaPlecaka[j] += tab[i].rozmiar;
            }
        }
    }
    max=wartoscPlecaka[0];         //podjecie decyzji
    int wybor;
    for(int j=0;j<tmp;j++){
        //cout<<"wartoscPlecaka ["<<j<<"] "<<wartoscPlecaka[j]<<" o wadze: "<<wagaPlecaka[j]<<endl;
        if(wagaPlecaka[j]<=pojemnosc) {
            if (wartoscPlecaka[j] > max) {
                max = wartoscPlecaka[j];
                wybor=j;
            }
        }
    }

    plecaklength=0;
    plecak=new Element[(int)tablength];
   for(int i=0;i<tablength;i++){ //przepisanie do plecaka
        if(bruteforce[i][wybor]==1){
            plecak[plecaklength]=tab[i]; ////////////////////////////////
            plecaklength++;
        }
    }
   // wyswietl();

}





void PlecakPrzegladZupelny::decToBin(int j) {
    int tmpj=j;
    int i=0;
    int *tmptab=new int[(int)tablength];

    while(tmpj) //dopóki liczba będzie różna od zera
    {
        tmptab[i++]=tmpj%2;
        tmpj/=2;
    }

    for(int k=i-1;k>=0;k--) {
        bruteforce[(int)tablength-1-k][j]=tmptab[k];
    }
}





void PlecakPrzegladZupelny::wyswietl() {
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
    cout<<"Laczna wartosc to "<<max<<endl;
}



PlecakPrzegladZupelny::~PlecakPrzegladZupelny() {
    cout<<"wywoluje sie destruktor";
    delete tab;
    //int tmp=pow(2,tablength);
    for(int j=0;j<tablength;j++){
        delete bruteforce[j];
    }
    delete wartoscPlecaka;
    delete wagaPlecaka;
    delete plecak;
}






void PlecakPrzegladZupelny::setTab(Element *tab) {
    PlecakPrzegladZupelny::tab=new Element[ilechcemy];
    /*for(int i=0;i<ilechcemy;i++) {
        PlecakPrzegladZupelny::tab[i] = tab[i];
    }*/
    PlecakPrzegladZupelny::tab = tab;
}

void PlecakPrzegladZupelny::setPlecak(Element *plecak) {
    PlecakPrzegladZupelny::plecak = plecak;
}

void PlecakPrzegladZupelny::setPojemnosc(int pojemnosc) {
    PlecakPrzegladZupelny::pojemnosc = pojemnosc;
}

void PlecakPrzegladZupelny::setIlechcemy(int ilechcemy) {
    PlecakPrzegladZupelny::ilechcemy = ilechcemy;
    tablength=ilechcemy;
}




/*void PlecakPrzegladZupelny::wyswietlMacierz() {
        //wyswietlenie macierzy incydencji grafu;
        cout <<endl<< "   ";
        for(int i = 0; i < tablength; i++) {
            cout << setw(3) << i;
        }
        cout << endl << endl;
        for(int i = 0; i < pow(2,tablength); i++) {
            cout << setw(3) << i;
            for(int j = 0; j < tablength; j++) {
                cout << setw(3) << bruteforce[j][i];
            }
            cout << endl;
        }
        cout << endl;
}*/

//
// Created by julia on 26.05.2017.
//

#include "KomiwojazerPrzegladZupelny.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
//#include <cmath>
#include <sstream>
#include <cmath>
#include <iomanip>
using namespace std;


bool KomiwojazerPrzegladZupelny::wczytaj(string nazwapliku) {
    std::fstream plik;
    plik.open( nazwapliku.c_str() );
    if( !plik.good() ) {
        cout<<"Nazwa pliku jest nieprawidlowa.\n";
        return false;
    }
    //Element tmp;
    //int i=0;
    //tab=new Element();
    plik >> lwierzcholkow>> lkrawedzi;             // Czytamy liczbę wierzchołków i krawędzi

    Sciezka = new int [lwierzcholkow];             // Tworzymy struktury dynamiczne i inicjujemy je
    Sh = new int [lwierzcholkow];
    visited = new bool [lwierzcholkow];
    //MacierzSasiedztwa  = new bool * [lwierzcholkow];
    MacierzSasiedztwa = new int * [lwierzcholkow];

    for(int i = 0; i < lwierzcholkow; i++) {
       // MacierzSasiedztwa[i] = new bool [lwierzcholkow];
        MacierzSasiedztwa[i] = new int [lwierzcholkow];
        for(int j = 0; j < lwierzcholkow; j++) {
            //MacierzSasiedztwa[i][j] = false;
            MacierzSasiedztwa[i][j] = 0;
        }
        visited[i] = false;
    }

    sptr = shptr = 0;
    int x,y,z;
    while(true)  {                                 //(true) pętla nieskończona
        if( plik.good() ){
           // plik>>tmp.rozmiar>>tmp.wartosc;
           // tab[i]=tmp;
           // tablength++;
            plik>> x >> y >> z;
           // MacierzSasiedztwa[x][y] = MacierzSasiedztwa[y][x] = true;     // Krawędź x-y
            MacierzSasiedztwa[x][y] = MacierzSasiedztwa[y][x] = z;        // Waga krawędzi x-y           //trzebaby zrobic sprawdzanie czy wczytala sie dobra ilosc krawedzi
        }
        else {
            break;                                 //zakończ wczytywanie danych - wystąpił jakiś błąd (np. nie ma więcej danych w pliku)
        }
        //i++;
    }
    plik.close();
    return true;
}

void KomiwojazerPrzegladZupelny::przegladZupelny() {
    // Rozpoczynamy algorytm

    wagaSciezki  = MAXINT;
    dh = v0 = 0;
    TSP(v0);
    //this->wyswietl();
}



void KomiwojazerPrzegladZupelny::TSP(int v) {
    int u;

    Sh[shptr++] = v;                                                // zapamiętujemy na stosie bieżący wierzchołek

    if(shptr < lwierzcholkow)  {                                   // jeśli brak ścieżki Hamiltona, to jej szukamy
        visited[v] = true;                                         // Oznaczamy bieżący wierzchołek jako odwiedzony
        for(u = 0; u < lwierzcholkow; u++)                         // Przeglądamy sąsiadów wierzchołka v
            if(MacierzSasiedztwa[v][u]!=0 && !visited[u]){            // Szukamy nieodwiedzonego jeszcze sąsiada
                dh += MacierzSasiedztwa[v][u];                   // Dodajemy wagę krawędzi v-u do sumy
                TSP(u);                                            // Rekurencyjnie wywołujemy szukanie cyklu Hamiltona
                dh -= MacierzSasiedztwa[v][u];                   // Usuwamy wagę krawędzi z sumy
            }
        visited[v] = false;                                        // Zwalniamy bieżący wierzchołek
    }
    else if(MacierzSasiedztwa[v0][v]!=0)   {                          // Jeśli znaleziona ścieżka jest cyklem Hamiltona
        dh += MacierzSasiedztwa[v][v0];                          // to sprawdzamy, czy ma najmniejszą sumę wag
        if(dh < wagaSciezki)   {                                             // Jeśli tak,
            wagaSciezki = dh;                                                // To zapamiętujemy tę sumę
            for(u = 0; u < shptr; u++) {                           // oraz kopiujemy stos Sh do Sciezka
                Sciezka[u] = Sh[u];
            }
            sptr = shptr;
        }
        dh -= MacierzSasiedztwa[v][v0];                          // Usuwamy wagę krawędzi v-v0 z sumy
    }
    shptr--;                                                      // Usuwamy bieżący wierzchołek ze ścieżki

}

KomiwojazerPrzegladZupelny::~KomiwojazerPrzegladZupelny() {
    delete [] Sciezka;
    delete [] Sh;
    delete [] visited;

    for(int i = 0; i < lwierzcholkow; i++) {
        delete [] MacierzSasiedztwa[i];
        //delete [] MacierzSasiedztwa[i];
    }
    delete [] MacierzSasiedztwa;
    //delete [] MacierzSasiedztwa;
}



void KomiwojazerPrzegladZupelny::wyswietl() {
    if(sptr) {
        for(int i = 0; i < sptr; i++) cout << Sciezka[i] << " ";
        cout << v0 << endl;
        cout << "wagaSciezki = " << wagaSciezki << endl;
    }
    else {
        cout << "NO HAMILTONIAN CYCLE" << endl;
    }
    cout << endl;
}

void KomiwojazerPrzegladZupelny::setLwierzcholkow(int lwierzcholkow) {
    KomiwojazerPrzegladZupelny::lwierzcholkow = lwierzcholkow;
}

void KomiwojazerPrzegladZupelny::setLkrawedzi(int lkrawedzi) {
    KomiwojazerPrzegladZupelny::lkrawedzi = lkrawedzi;
}

void KomiwojazerPrzegladZupelny::setMacierzSasiedztwa(int **MacierzSasiedztwa) {
    KomiwojazerPrzegladZupelny::MacierzSasiedztwa = MacierzSasiedztwa;
}

void KomiwojazerPrzegladZupelny::przygotuj() {
    Sciezka = new int [lwierzcholkow];             // Tworzymy struktury dynamiczne i inicjujemy je
    Sh = new int [lwierzcholkow];
    visited = new bool [lwierzcholkow];
    MacierzSasiedztwa = new int * [lwierzcholkow];

    for(int i = 0; i < lwierzcholkow; i++) {
        MacierzSasiedztwa[i] = new int [lwierzcholkow];
        for(int j = 0; j < lwierzcholkow; j++) {
            MacierzSasiedztwa[i][j] = 0;
        }
        visited[i] = false;
    }
    sptr = shptr = 0;
}


//
// Created by julia on 28.05.2017.
//

#include "Testy.h"
#include <sstream>
#include <cmath>
#include <ctime>

using namespace std;

void Testy::ZachowajCzas() {
    timeus= (float) ((1000000.0 * elapsed) / frequency);
}

long long int Testy::read_QPC() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

void Testy::zapiszStatystykeDoPliku(std::string nazwapliku, float timeus) {
    std::ofstream plik;
    plik.open(nazwapliku, std::ios_base::app);
    plik<< timeus<<" ";
    plik.close();
}

void Testy::zapiszDoPliku(std::string nazwapliku, std::string tresc) {
    std::ofstream plik;
    plik.open(nazwapliku, std::ios_base::app);
    plik << tresc;
    plik.close();
}

Element *Testy::losowoPlecak(int ilosc) {
    srand(time(NULL));
    plecakpojemnosc=0;
    Element* tab=new Element[ilosc];
    for(int i=0;i<ilosc;i++){
        tab[i].rozmiar=rand()%(ilosc)+1;
        tab[i].wartosc=rand()%(ilosc)+1;
        tab[i].cennosc=(float)tab[i].wartosc/tab[i].rozmiar;
    }
    //int tmp=0;
    for(int i=0;i<ilosc;i++){
        plecakpojemnosc+=0.8*tab[i].rozmiar;
    }
    tablica=tab;
    return tab;
}


void Testy::wyswietlPlecak(int n) {
    for(int i=0;i<n;i++){
        cout<<tablica[i].rozmiar<<" ";
        cout<<tablica[i].wartosc<<" ";
        cout<<endl;
    }
}

void Testy::testyPlecak(std::string nazwaPliku1,std::string nazwaPliku2, int n) {
 //   int n=10;
    int tmp=0;
    Element* tab=losowoPlecak(n);
 //   wyswietlPlecak(n);
    tpp.setPojemnosc(plecakpojemnosc);
    tpp.setIlechcemy(n);
    tpp.setTab(tablica);
    //tpp.wyswietlwczytane();
    ostringstream ss;
    ss << n;
    string str = ss.str();
    zapiszDoPliku(nazwaPliku1, "\nTest dla ");
    zapiszDoPliku(nazwaPliku1, str);
    zapiszDoPliku(nazwaPliku1, "elementow ");
    zapiszDoPliku(nazwaPliku2, "\nTest dla ");
    zapiszDoPliku(nazwaPliku2, str);
    zapiszDoPliku(nazwaPliku2, "elementow ");
    for (int i = 0; i < 10; i++) {
        start = read_QPC();
        tpp.przegladZupelny();
        elapsed = read_QPC() - start;
        ZachowajCzas();
        tmp += timeus;
    }
    tmp = tmp / 10;
    zapiszStatystykeDoPliku(nazwaPliku1, tmp);
    tmp = 0;



    tpz.setTab(tab);
    tpz.setPojemnosc(plecakpojemnosc);
    tpz.setIlechcemy(n);
//    tpz.wyswietlwczytane();
   for (int i = 0; i < 10; i++) {
        start = read_QPC();
        tpz.algZachlanny();
        elapsed = read_QPC() - start;
        ZachowajCzas();
        tmp += timeus;
    }
    tmp = tmp / 10;
    zapiszStatystykeDoPliku(nazwaPliku2, tmp);
    tmp = 0;

}


void Testy::wyswietlMacierzSasiedztwa(int n) {
    cout <<endl<< "   ";
    for(int i = 0; i < n; i++) {
        cout << setw(3) << i;
    }
    cout << endl << endl;
    for(int i = 0; i < n; i++) {
        cout << setw(3) << i;
        for(int j = 0; j < n; j++) {
            cout << setw(3) << MacierzSasiedztwa[j][i];
        }
        cout << endl;
    }
    cout << endl;
}

void Testy::testyKomiwojazer(std::string nazwaPliku1, std::string nazwaPliku2, int n) {
    int tmp=0;
    losowoKomiwojazerPELNY(n);
    //wyswietlMacierzSasiedztwa(n);

    ostringstream ss;
    ss << n;
    string str = ss.str();
    zapiszDoPliku(nazwaPliku1, "\nTest dla ");
    zapiszDoPliku(nazwaPliku1, str);
    zapiszDoPliku(nazwaPliku1, "elementow ");
    zapiszDoPliku(nazwaPliku2, "\nTest dla ");
    zapiszDoPliku(nazwaPliku2, str);
    zapiszDoPliku(nazwaPliku2, "elementow ");

    tkp.setLwierzcholkow(n);
    tkp.setLkrawedzi(lkrawedzi);
    tkp.przygotuj();
    tkp.setMacierzSasiedztwa(MacierzSasiedztwa);

    //tkp.przegladZupelny();
    //tkp.wyswietl();
    for (int i = 0; i < 10; i++) {
        start = read_QPC();
        tkp.przegladZupelny();
        elapsed = read_QPC() - start;
        ZachowajCzas();
        tmp += timeus;
    }
    tmp = tmp / 10;
    zapiszStatystykeDoPliku(nazwaPliku1, tmp);
    tmp = 0;


    tkz.setLwierzcholkow(n);
    tkz.przygotuj();
    tkz.setMacierzSasiedztwa(MacierzSasiedztwa);

    /*tkz.wyswietlwczytane();
    tkz.algZachlanny();
    tkz.wyswietl();*/
    for (int i = 0; i < 10; i++) {
        tkz.przygotuj();
        start = read_QPC();
        tkz.algZachlanny();
        elapsed = read_QPC() - start;
        ZachowajCzas();
        //tkz.wyswietl();
        tmp += timeus;
    }
    tmp = tmp / 10;
    zapiszStatystykeDoPliku(nazwaPliku2, tmp);
    tmp = 0;

}

void Testy::losowoKomiwojazerPELNY(int ilosc) {
    MacierzSasiedztwa=new int*[ilosc];
    lkrawedzi = (((ilosc * (ilosc - 1))) / 2);
    srand(time(NULL));
    //cout << "lkrawedzi: " << lkrawedzi << endl;
    for(int i=0;i<ilosc;i++){
        MacierzSasiedztwa[i]=new int[ilosc];
    }
    for(int i=0;i<ilosc;i++){                      //wypelnienie zerami
        for(int j=0;j<ilosc;j++){
            MacierzSasiedztwa[i][j]=0;
        }
    }
    for(int i=0;i<ilosc;i++){                      //wypelnienie zerami
        for(int j=0;j<ilosc;j++){
            if(i==j){
                MacierzSasiedztwa[i][j]=0;
            }
            else {
                MacierzSasiedztwa[i][j] =MacierzSasiedztwa[j][i] = rand() % (ilosc) + 1;
            }
        }
    }
}

void Testy::losowoKomiwojazer(int ilosc) {
    int gestosc=90;
    lkrawedzi = floor((gestosc * (ilosc * (ilosc - 1))) / 200);
    srand(time(NULL));
    cout << "lkrawedzi: " << lkrawedzi << endl;
    MacierzSasiedztwa=new int*[ilosc];
    for(int i=0;i<ilosc;i++){
        MacierzSasiedztwa[i]=new int[ilosc];
    }
    for(int i=0;i<ilosc;i++){                      //wypelnienie zerami
        for(int j=0;j<ilosc;j++){
            MacierzSasiedztwa[i][j]=0;
        }
    }
    int v1, v2;
    for(int i=0;i<lkrawedzi;i++){
        v1=rand()%(ilosc);
        v2=rand()%(ilosc);
        if(v1==v2){
            i--;
        }
        else{
            MacierzSasiedztwa[v1][v2]=MacierzSasiedztwa[v2][v1]=rand()%(ilosc)+1;
        }
    }

}
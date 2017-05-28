//
// Created by julia on 27.05.2017.
//
#include <iostream>
#include "KomiwojazerAlgZachlanny.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
//#include <cmath>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

bool KomiwojazerAlgZachlanny::wczytaj(string nazwapliku) {
    std::fstream plik;
    plik.open( nazwapliku.c_str() );
    if( !plik.good() ) {
        cout<<"Nazwa pliku jest nieprawidlowa.\n";
        return false;
    }
    plik >> lwierzcholkow>> lkrawedzi;                                    // Czytamy liczbę wierzchołków i krawędzi
    visited = new bool [lwierzcholkow];
    for(int i=0;i<lwierzcholkow;i++){
        visited[i]=false;
    }
    MacierzSasiedztwa = new int * [lwierzcholkow];
    Sciezka = new int [lwierzcholkow];

    for(int i = 0; i < lwierzcholkow; i++) {
        MacierzSasiedztwa[i] = new int [lwierzcholkow];
        for(int j = 0; j < lwierzcholkow; j++) {
            MacierzSasiedztwa[i][j] = 0;
        }
        visited[i] = false;
    }
    int x,y,z;
    while(true)  {                                                        //(true) pętla nieskończona
        if( plik.good() ){
            plik>> x >> y >> z;
            MacierzSasiedztwa[x][y] = MacierzSasiedztwa[y][x] = z;        // Waga krawędzi x-y           //trzebaby zrobic sprawdzanie czy wczytala sie dobra ilosc krawedzi
        }
        else {
            break;                                                        //zakończ wczytywanie danych - wystąpił jakiś błąd (np. nie ma więcej danych w pliku)
        }
    }
    plik.close();
    return true;
}



/*nearest neighbour algorithm
 * Algorytm działa w następujący sposób[2]:

    1.Ustaw wybrany wierzchołek jako aktualny, oznacz go jako odwiedzony.
    2.Znajdź ten spośród nieodwiedzonych wierzchołków, który jest połączony z aktualnym krawędzią o najmniejszej wadze.
    3.Dołącz do rozwiązania krawędź łączącą aktualny wierzchołek z wierzchołkiem znalezionym w punkcie 2.
    4.Oznacz wierzchołek znaleziony w punkcie 2 jako odwiedzony i ustaw go jako aktualny.
    5.Jeśli pozostały jeszcze nieodwiedzone wierzchołki, przejdź do punktu 2.
    6.Dołącz do rozwiązania krawędź łączącą aktualny wierzchołek z wierzchołkiem wybranym w punkcie 1, aby zamknąć cykl.
*/

void KomiwojazerAlgZachlanny::algZachlanny() {
    sptr=0;
    wagaSciezki=0;
    //wyswietlwczytane();
    v0=0;
    Sciezka[v0]=0;                                    //zaczynam z zera
    sptr++;
    //for(int i=1; i<lwierzcholkow;i++) {
    for(int i=0; i<(lwierzcholkow-1);i++) {
        //zmianaWierzcholka(v0);
        if(zmianaWierzcholka(v0)==false){
            break;
        }
        sptr++;
    }
    visited[0]=false;                                //dojscie spowrotem do zera
   /*if(zmianaWierzcholka(v0)==true){
        visited[0]=true;
    }
    else{
        sptr--;
    }*/

    if(!zmianaWierzcholka(v0)){
         sptr--;
     }
     else{
        visited[0]=true;
     }
    //wyswietl();
    /*for(int i=0;i<lwierzcholkow;i++){
        cout<<visited[i]<<endl;
    }*/
}

bool KomiwojazerAlgZachlanny::zmianaWierzcholka(int v) {
    //v0=v;
    int minWaga=MAXINT;
    int v2=-1;
    visited[v]=true;
    for(int i=0;i<lwierzcholkow;i++){
        if(MacierzSasiedztwa[v][i]!=0){
            if(MacierzSasiedztwa[v][i]<minWaga && visited[i]==false){
                minWaga=MacierzSasiedztwa[v][i];
                v2=i;
            }
        }
    }
    if(minWaga==MAXINT){
        //cout << "lololo" << endl;
        return false;
    }
    Sciezka[sptr]=v2;
    wagaSciezki+=minWaga;
    v0=v2;
    return true;                     //zakomentuj do testow
}









void KomiwojazerAlgZachlanny::wyswietl() {
    cout<<"sptr: "<<sptr<<endl;
    if(sptr==lwierzcholkow) {
        for(int i = 0; i < sptr; i++) {
            cout << Sciezka[i] << " ";
        }
        cout << 0 << endl;
        cout << "wagaSciezki = " << wagaSciezki << endl;
    }
    else {
        cout << "NO HAMILTONIAN CYCLE" << endl;
    }
    cout << endl;
   // delete [] visited;
}






void KomiwojazerAlgZachlanny::wyswietlwczytane() {
    cout <<endl<< "   ";
    for(int i = 0; i < lwierzcholkow; i++) {
        cout << setw(3) << i;
    }
    cout << endl << endl;
    for(int i = 0; i < lwierzcholkow; i++) {
        cout << setw(3) << i;
        for(int j = 0; j < lwierzcholkow; j++) {
            cout << setw(3) << MacierzSasiedztwa[j][i];
        }
        cout << endl;
    }
    cout << endl;
}




KomiwojazerAlgZachlanny::~KomiwojazerAlgZachlanny() {
    cout << "Destrukotr" << endl;
    delete [] visited;
    for(int i = 0; i < lwierzcholkow; i++) {
        delete [] MacierzSasiedztwa[i];
    }
    delete [] MacierzSasiedztwa;
}

void KomiwojazerAlgZachlanny::setLwierzcholkow(int lwierzcholkow) {
    this->lwierzcholkow = lwierzcholkow;
}

void KomiwojazerAlgZachlanny::setLkrawedzi(int lkrawedzi) {
    KomiwojazerAlgZachlanny::lkrawedzi = lkrawedzi;
}

void KomiwojazerAlgZachlanny::setMacierzSasiedztwa(int **MacierzSasiedztwa) {
    KomiwojazerAlgZachlanny::MacierzSasiedztwa = MacierzSasiedztwa;
}

KomiwojazerAlgZachlanny::KomiwojazerAlgZachlanny() {

}

void KomiwojazerAlgZachlanny::przygotuj() {
    Sciezka=new int[lwierzcholkow];
    //cout << "przedvisited" << endl;
    visited=new bool[lwierzcholkow];
    //cout<<"tutaj"<<endl;
    for(int i=0;i<lwierzcholkow;i++){
        visited[i]=false;
    }
}








void KomiwojazerAlgZachlanny::alg2optymalny() {
    H=new Edge[lwierzcholkow];
    H=S;
  //  for(int i=0; i<(lwierzcholkow*(lwierzcholkow-3))/2;i++){
  //
  //  }
    int b;
    Edge yi;
    Edge yj;
    do {
        b = 0;
        for (int i = 1; i <= lwierzcholkow - 2; i++) {
            for(int j=i+2;j<=lwierzcholkow;j++){   //czy nie lwierzcholkow -1?
                yi.waga=yj.waga=MAXINT;
               if(MacierzSasiedztwa[i][H[j].v2]!=0){
                   yi.v1=i;
                   yi.v2=H[j].v2;
                   yi.waga=(MacierzSasiedztwa[j][H[i].v2];
               }
                if(MacierzSasiedztwa[j][H[i].v2]!=0){
                    yj.v1=j;
                    yj.v2=H[i].v2;
                    yj.waga=(MacierzSasiedztwa[j][H[i].v2];
                }
                if(H[i].waga+H[j].waga-(yi.waga+yj.waga)>b){
                    b=H[i].waga+H[j].waga-(yi.waga+yj.waga);
                }
                if(b>0){
                    H[i]=yi;
                    H[j]=yj;
                }
            }
        }
    }while(b!=0);
}



void KomiwojazerAlgZachlanny::algZachlanny1() {
    S=new Edge[lwierzcholkow];
    sptr=0;
    wagaSciezki=0;
    //wyswietlwczytane();
    v0=0;
    //S[0].v1=v0;                                    //zaczynam z zera
    //sptr++;
    //for(int i=1; i<lwierzcholkow;i++) {
    for(int i=0; i<(lwierzcholkow-1);i++) {
        //zmianaWierzcholka(v0);
        if(zmianaWierzcholka(v0)==false){
            break;
        }
        //sptr++;
    }
    visited[0]=false;                                //dojscie spowrotem do zera
    if(!zmianaWierzcholka(v0)){
        sptr--;
    }
    else{
        visited[0]=true;
    }
    //wyswietl();
    /*for(int i=0;i<lwierzcholkow;i++){
        cout<<visited[i]<<endl;
    }*/
}

bool KomiwojazerAlgZachlanny::zmianaWierzcholka1(int v) {
    //v0=v;
    int minWaga=MAXINT;
    int v2=-1;
    visited[v]=true;
    for(int i=0;i<lwierzcholkow;i++){
        if(MacierzSasiedztwa[v][i]!=0){
            if(MacierzSasiedztwa[v][i]<minWaga && visited[i]==false){
                minWaga=MacierzSasiedztwa[v][i];
                v2=i;
            }
        }
    }
    if(minWaga==MAXINT){
        //cout << "lololo" << endl;
        return false;
    }
    S[sptr].v1=v;
    S[sptr].v2=v2;
    S[sptr].waga=minWaga;
    wagaSciezki+=minWaga;
    v0=v2;
    sptr++;
    return true;                     //zakomentuj do testow
}


void KomiwojazerAlgZachlanny::wyswietl1() {
    cout<<"sptr: "<<sptr<<endl;
    if(sptr==lwierzcholkow) {
        for(int i = 0; i < sptr; i++) {
            cout << S[i].v1 << " "<< S[i].v2 << " z waga "<< S[i].waga << " ";
        }
        //cout << 0 << endl;
        cout << "wagaSciezki = " << wagaSciezki << endl;
    }
    else {
        cout << "NO HAMILTONIAN CYCLE" << endl;
    }
    cout << endl;
    // delete [] visited;
}



#include<conio.h>
#include<string>
#include<iostream>
#include <iomanip>
#include <windows.h>
#include <iomanip>
#include <afxres.h>
#include "PlecakPrzegladZupelny.h"
#include "PlecakAlgZachlanny.h"
#include "KomiwojazerPrzegladZupelny.h"
#include "KomiwojazerAlgZachlanny.h"
#include "Testy.h"

using namespace std;


string nazwapliku;
Testy t;

PlecakPrzegladZupelny *pp;
int main(int argc, char* argv[])
{
    QueryPerformanceFrequency((LARGE_INTEGER *)&t.frequency);    // t to obiekt klasy Testy

    char option;
    do{
        cout << endl;
        cout << "==== MENU GLOWNE ===" << endl;

        cout << "DYSKRETNY PROBLEM PLECAKOWY" << endl;
        cout << "1.Przeglad zupelny" << endl;
        cout << "2.Algorytm zachlanny" << endl;
        cout << "3.Algorytm oparty na programowaniu dynamicznym" << endl<<endl;

        cout << "ASYMETRYCZNY PROBLEM KOMOWOJAZERA" << endl;
        cout << "4.Przeglad zupelny" << endl;
        cout << "5.Algorytm zachlanny" << endl;
        cout << "6.Algorytm przeszukiwania lokalnego" << endl;

        cout << "7.Testy"<<endl;
        cout << "0.Wyjscie" << endl;
        cout << "Podaj opcje:";
        option = getche();
        cout << endl;

        switch (option){
            case '1':{
                pp=new PlecakPrzegladZupelny();
               // PlecakPrzegladZupelny pp;
                cout<<"Podaj nazwe pliku, z ktorego maja zostac wczytane dane: ";
                cin>>nazwapliku;
                /*pp->wczytaj(nazwapliku);
                pp->wyswietlwczytane();
                pp->przegladZupelny();*/
                if(pp->wczytaj(nazwapliku)) {
                     pp->wyswietlwczytane();
                    pp->przegladZupelny();
                    pp->wyswietl();
                }
            } break;

            case '2':{
                PlecakAlgZachlanny *pz=new PlecakAlgZachlanny();
                cout<<"Podaj nazwe pliku, z ktorego maja zostac wczytane dane: ";
                cin>>nazwapliku;
                if(pz->wczytaj(nazwapliku)) {
                    pz->wyswietlwczytane();
                    pz->algZachlanny();
                    pz->wyswietl();
                }
            }break;

            case '3':

                break;

            case '4': {
                KomiwojazerPrzegladZupelny *kp=new KomiwojazerPrzegladZupelny();
                cout<<"Podaj nazwe pliku, z ktorego maja zostac wczytane dane: ";
                cin>>nazwapliku;
                kp->wczytaj(nazwapliku);
                kp->przegladZupelny();
                kp->wyswietl();
            }  break;

            case '5':{
                KomiwojazerAlgZachlanny *kz=new KomiwojazerAlgZachlanny();
                cout<<"Podaj nazwe pliku, z ktorego maja zostac wczytane dane: ";
                cin>>nazwapliku;
                kz->wczytaj(nazwapliku);
                kz->algZachlanny();
                kz->wyswietl();
            }
                break;
            case '6': {

            }  break;
            case '7': {
                //t.testyPlecak("statpp.txt","statpz.txt",10);
                t.testyKomiwojazer("statkp.txt","statkz.txt",20);
            }  break;
        }

    } while (option != '0');


    return 0;
}



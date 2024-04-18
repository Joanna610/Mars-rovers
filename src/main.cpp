#include <iostream>
#include <fstream>
#include <memory>
#include <list>

#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "ObiektGeom.hh"
#include "Kolory.hh"
#include "Wektor3D.hh"
#include "Macierz3D.hh"
#include "Lazik.hh"
#include "LazikSFR.hh"
#include "rozmiar.h"
#include "Scena.hh"
#include "ObrysXY.hh"

using namespace std;

void wyswietl_menu(){
  cout <<endl;
  cout << "Menu: "<<endl;
  cout << " j - jazda na wprost"<<endl;
  cout << " o - zmien orientacje"<<endl;
  cout << " w - wybor lazika"<<endl;
  cout << " m - wyswietl menu"<<endl;
  cout <<endl<< " k - koniec dzialanie programu"<<endl;
}

void menu_lazikow(){
  cout <<endl;
  cout <<endl << "1. ---------- Nazwa: Sample_Fetch_Rover"<<endl;
  cout <<endl << "2. ---------- Nazwa: Perseverance"<<endl;
  cout <<endl << "3. ---------- Nazwa: Curiosity"<<endl;
  cout << "Podaj numer lazika: ";
}

void wyswietl_lazik1(shared_ptr<LazikSFR> _AktywnyLazik){
  cout <<endl<<endl;
  cout << "Aktywny lazik: "<<endl;
  cout << "1. ---------- Nazwa: Sample_Fetch_Rover"<<endl;
  cout << "          Polozenie:  "<<(*_AktywnyLazik).Polozenie <<endl;
  cout << "    Orientacja [st]:  "<<(*_AktywnyLazik).get_Kat()<<endl;
  cout <<endl;
}

void wyswietl_lazik2(shared_ptr<Lazik> _AktywnyLazik){
  cout <<endl<<endl;
  cout << "Aktywny lazik: "<<endl;
  cout << "2. ---------- Nazwa: Perseverance"<<endl;
  cout << "          Polozenie:  "<<(*_AktywnyLazik).Polozenie <<endl;
  cout << "    Orientacja [st]:  "<<(*_AktywnyLazik).get_Kat()<<endl;
  cout <<endl;
}


void wyswietl_lazik3(shared_ptr<Lazik> _AktywnyLazik){

  cout <<endl<<endl;
  cout << "Aktywny lazik: "<<endl;
  cout << "3. ---------- Nazwa: Curiosity"<<endl;
  cout << "          Polozenie:  "<<(*_AktywnyLazik).Polozenie <<endl;
  cout << "    Orientacja [st]:  "<<(*_AktywnyLazik).get_Kat()<<endl;
  cout <<endl;
}


int menu(){
  char znak_oper;
  int nr_lazika = 1, odl = 0, kat = 0;
  ObiektGeom obiektgeo;
  Lazik obiektlazik;
  Scena obiekt;
  ObrysXY obrys;

  obiekt.Inicjalizuj_Lacze(obiekt.Lacze);
  if (!Inicjalizuj_PowierzchnieMarsa(obiekt.Lacze)) return 1;

  obiekt.Lacze.Rysuj();

  wyswietl_menu();

  obiekt._AktywnyLazik =static_pointer_cast<Lazik>(obiekt._ObiektySceny.back());
  shared_ptr<LazikSFR> obiekt_do_porownania = static_pointer_cast<LazikSFR>(obiekt._AktywnyLazik);

  do{
    cout <<endl<< "Twoj wybor: ";
    cin >> znak_oper;
    switch(znak_oper){

      case 'w': {
        menu_lazikow();
        cin >> nr_lazika;

        switch(nr_lazika){
          case 1:{
            obiekt._AktywnyLazik =static_pointer_cast<Lazik>(obiekt._ObiektySceny.back());
            shared_ptr<LazikSFR> obiekt_do_porownania = static_pointer_cast<LazikSFR>(obiekt._AktywnyLazik);
            wyswietl_lazik1(obiekt_do_porownania);

            break;
          }
          case 2:{
            --obiekt.it;
            obiekt._AktywnyLazik =static_pointer_cast<Lazik>(*obiekt.it);
            wyswietl_lazik2(obiekt._AktywnyLazik);
            break;
          }
          case 3:{
            obiekt._AktywnyLazik =static_pointer_cast<Lazik>(obiekt._ObiektySceny.front());
            wyswietl_lazik3(obiekt._AktywnyLazik);
            break;
          }
          default:{
            cout << "BLAD"<<endl;
            break;
          }
        }
      break;
      }
      case 'j': {
        cout <<endl<<"Podaj odleglosc na jaka ma sie przemiescic lazik (w jednostkach sceny)."<<endl<<endl;
        cout << "Odleglosc:  ";
        cin >> odl;
        cout <<endl;
        if(nr_lazika == 1){
          (*obiekt_do_porownania).Przesuniecie_LazikaSFR(obiekt._ObiektySceny, obiekt._ObiektySceny_probki, odl, obiekt.Lacze,  0);
        }
        else
          (*obiekt._AktywnyLazik).Przesuniecie_Lazika(obiekt._ObiektySceny, odl, obiekt.Lacze,  0);
        break;
      }
      case 'o': {
        cout <<endl<<"Podaj kat obrotu w stopniach."<<endl<<endl;
        cout << "Wartosc kata:  ";
        cin >> kat;
        cout <<endl;
        if(nr_lazika == 1){
          (*obiekt_do_porownania).Przesuniecie_LazikaSFR(obiekt._ObiektySceny, obiekt._ObiektySceny_probki, 0, obiekt.Lacze,  kat);
        }
        else{
          (*obiekt._AktywnyLazik).Przesuniecie_Lazika(obiekt._ObiektySceny, 0, obiekt.Lacze,  kat);
        }
        break;
      }
      case 'm': {
        wyswietl_menu();
      break;
      }
      case 'k': {
        break;
      }
      default:{
        cout<<"Nieprawidlowy znak." <<endl;
        break;
      }
    }
  } while(znak_oper!='k');
  return 0;
}

int main()
{
  menu();
  cout << endl<< '\t'<<"Koniec programu"<<endl;
  cout <<endl;
  cout << " Ilosc aktualna wektorow: " << SWektor<double, 3>::WezIloscAktualna() <<endl;
  cout << "   Ilosc ogolna wektorow: " << SWektor<double, 3>::WezIloscOgolna() <<endl;
  cout <<endl;
}

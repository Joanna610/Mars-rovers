#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "ObiektGeom.hh"
#include "Wektor3D.hh"
#include "rozmiar.h"

Typ_kolizji ObiektGeom::Czykolizja(shared_ptr<ObiektGeom>& wsk){
return TK_BrakKolizji;
}

ObiektGeom::ObiektGeom( const char*  sNazwaPliku_BrylaWzorcowa,
						const char*  sNazwaObiektu,
						int          KolorID
						):
  _NazwaPliku_BrylaWzorcowa(sNazwaPliku_BrylaWzorcowa), _KolorID(KolorID)
{
  _NazwaObiektu = sNazwaObiektu;
  _NazwaPliku_BrylaRysowana = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
  _NazwaPliku_BrylaRysowana += "/";
  _NazwaPliku_BrylaRysowana += sNazwaObiektu;
  _NazwaPliku_BrylaRysowana += ".dat";

  Skala[0]=20;
  Skala[1]=20;
  Skala[2]=10;

  Polozenie[0] = 0;
  Polozenie[1] = 0;
  Polozenie[2] = 0;
}

ObiektGeom::ObiektGeom(){

  Skala[0]=20;
  Skala[1]=20;
  Skala[2]=10;

  Polozenie[0] = 0;
  Polozenie[1] = 0;
  Polozenie[2] = 0;
}

void ObiektGeom::zmienSkale(double x, double y, double z){
  this->Skala[0]=x;
  this->Skala[1]=y;
  this->Skala[2]=z;
}

void ObiektGeom::AktualnePolozenie_obiekt(double X, double Y, double Z){

  this->Polozenie[0] = X;
  this->Polozenie[1] = Y;
  this->Polozenie[2] = Z;
}

bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki(double kat){

  ifstream  StrmWe(_NazwaPliku_BrylaWzorcowa);
  ofstream  StrmWy(_NazwaPliku_BrylaRysowana);

  if (!(StrmWe.is_open() && StrmWy.is_open())) {
    std::cout << "    " << _NazwaPliku_BrylaWzorcowa << std::endl
	  << "    " << _NazwaPliku_BrylaRysowana << std::endl
	  << std::endl;
    return false;
  }

  Przelicz_i_Zapisz_Wierzcholki(StrmWe, StrmWy, kat);
    return true;
  }

bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki(istream& StrmWe, ostream& StrmWy, double kat){

  SWektor<double,ROZMIAR> Wsp, Wsp2;
  Wsp2 = 0;
  int Indeks_Wiersza = 0;
  StrmWe >> Wsp;
  if (StrmWe.fail())return false;
    wyliczanie_polozenia(Wsp, Wsp2, Indeks_Wiersza, StrmWe, StrmWy, kat);
  if (!StrmWe.eof()) return false;

  return Indeks_Wiersza == 0 && !StrmWy.fail();
}

void ObiektGeom::wyliczanie_polozenia(SWektor<double,ROZMIAR> Wsp, SWektor<double,ROZMIAR> Wsp2, int Indeks_Wiersza, istream& StrmWe, ostream& StrmWy, double kat){
  Macierz3D MacRot(kat);
  static SWektor<double,ROZMIAR> pom, pom2;
  pom = this->Polozenie;
  pom2 = this->Polozenie;

  do{
    for(int  Ind = 0; Ind < ROZMIAR; ++Ind){
    Wsp2[Ind] = MacRot.Macierz_rotacji[Ind] * Wsp*(this->Skala[Ind]) + this->Polozenie[Ind];
  }

  if(Wsp[2]==0){ this->_Obrys.Oblicz_obrys(Wsp2, &pom, &pom2);}

  ++Indeks_Wiersza;
  StrmWy << Wsp2[0] << " " << Wsp2[1] << " " << Wsp2[2] << endl;

  if (Indeks_Wiersza >= 4) {
    StrmWy << endl;
    Indeks_Wiersza = 0;
  }
  StrmWe >>Wsp;
  } while (!StrmWe.fail());
}



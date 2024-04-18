#include "ProbkaRegolitu.hh"
#include "ObrysXY.hh"
#include "Wektor2D.hh"
#include <iostream>

Typ_kolizji Probka_Regolitu::Czykolizja(shared_ptr<ObiektGeom>& wsk) {
  ObrysXY wspolny_prostokat;
    Wektor2D<double> lazik_regolit, lazik_krawedz, wek_pomocniczy;
    wspolny_prostokat.Test(this->_Obrys, wsk->_Obrys);

    if(wspolny_prostokat._Lewy_Gorny[0]<=wspolny_prostokat._Prawy_Dolny[0] ){
      if(wspolny_prostokat._Lewy_Gorny[1]>=wspolny_prostokat._Prawy_Dolny[1]){
        return TK_Kolizjia_probka;
      }
  }
  return TK_BrakKolizji;
}
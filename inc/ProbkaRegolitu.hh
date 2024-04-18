#ifndef PROBKA_REGOLITU_HH
#define PROBKA_REGOLITU_HH

#include "ObiektGeom.hh"
#include "Wektor3D.hh"
#include "TypKolizji.hh"

class Probka_Regolitu: public ObiektGeom{

public:
    Probka_Regolitu();
    Probka_Regolitu(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID): ObiektGeom(sNazwaPliku_BrylaWzorcowa,sNazwaObiektu,  KolorID) {
        zmienSkale(5,7,7);
    }
    Typ_kolizji Czykolizja(shared_ptr<ObiektGeom>& wsk);
};

#endif

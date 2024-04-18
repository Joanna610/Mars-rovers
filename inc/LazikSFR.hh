#ifndef LAZIKSFR_HH
#define LAZIKSFR_HH

#include <list>
#include "Lazik.hh"

class LazikSFR: public Lazik{

public:
    list<shared_ptr<Probka_Regolitu>> _ListaProbek;
    Typ_kolizji Czykolizja(shared_ptr<ObiektGeom>& wsk);

    void Przesuniecie_LazikaSFR(list<shared_ptr<ObiektGeom>> _ObiektySceny, list<shared_ptr<ObiektGeom>> _ObiektySceny_probki, double odleglosc, PzG::LaczeDoGNUPlota  Lacze,  double kat );
    void Obrut_LazikaSFR(double KatOrietacji_st, PzG::LaczeDoGNUPlota  Lacze);

    int sprawdzanie_kolizji_z_probka(list<shared_ptr<ObiektGeom>>::iterator it_pom3);
    int sprawdzanie_kolizji_z_lazikiem(list<shared_ptr<ObiektGeom>>::iterator it_pom4);
};

#endif
#ifndef LAZIK_HH
#define LAZIK_HH

#include "ObiektGeom.hh"
#include "Macierz3D.hh"

#include "Kolory.hh"
#include "lacze_do_gnuplota.hh"
#include "ObrysXY.hh"
#include "TypKolizji.hh"
#include "ProbkaRegolitu.hh"

class Lazik: public ObiektGeom {
    double KatOrietacji_st = 0;
    double OdlegloscdoPrzejechania;

public:

    Lazik(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID): ObiektGeom(sNazwaPliku_BrylaWzorcowa,sNazwaObiektu,  KolorID) {}
    Lazik();

    double get_Kat(){return KatOrietacji_st;}
    shared_ptr<Probka_Regolitu> probka_do_usuniecia = nullptr;

    Typ_kolizji Czykolizja(shared_ptr<ObiektGeom>& wsk);

    virtual const char* Nazwa() const override {return "Lazik";}
    virtual ~Lazik() {}

    void Przesuniecie_Lazika(list<shared_ptr<ObiektGeom>> _ObiektySceny, double odleglosc, PzG::LaczeDoGNUPlota  Lacze, double kat);
    void rysowanie(PzG::LaczeDoGNUPlota  Lacze);
    void Obrut_Lazika(double KatOrietacji_st, PzG::LaczeDoGNUPlota  Lacze);
    int sprawdzanie_kolizji_z_lazikiem(list<shared_ptr<ObiektGeom>>::iterator it_pom);
};

#endif
#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH
#define PR_ILOSC_WIE 4

#include <string>
#include <vector>
#include <memory>
#include "rozmiar.h"
#include "Wektor3D.hh"
#include "Macierz3D.hh"
#include "ObrysXY.hh"
#include "TypKolizji.hh"

#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA    "pliki_do_rysowania"

class ObiektGeom {

    string   _NazwaPliku_BrylaWzorcowa;
    string   _NazwaPliku_BrylaRysowana;
    string   _NazwaObiektu;
    int           _KolorID;

public:
    SWektor<double,ROZMIAR> Skala;
    ObrysXY _Obrys;
    SWektor<double,ROZMIAR> Polozenie;

    ObiektGeom();
    ObiektGeom(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID);

    virtual const char* Nazwa() const {return "ObiektGeom";} //funkcja wirtualna
    virtual ~ObiektGeom() {}

    virtual Typ_kolizji Czykolizja(shared_ptr<ObiektGeom>& wsk);
    int WezKolorID() const { return _KolorID; }
    const string & WezNazweObiektu() const { return _NazwaObiektu; }
    const string & WezNazwePliku_BrylaRysowana() const { return _NazwaPliku_BrylaRysowana; }

    bool Przelicz_i_Zapisz_Wierzcholki(double kat);
    bool Przelicz_i_Zapisz_Wierzcholki(istream& StrmWe, ostream& StrmWy,  double kat);

    void AktualnePolozenie_obiekt(double X, double Y, double Z);
    void zmienSkale(double x, double y, double z);

    void wyliczanie_polozenia(SWektor<double,ROZMIAR> Wsp, SWektor<double,ROZMIAR> Wsp2, int Indeks_Wiersza, istream& StrmWe, ostream& StrmWy, double kat);
};

#endif
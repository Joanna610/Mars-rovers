#ifndef OBRYSXY_HH
#define OBRYSXY_HH

#include "Wektor2D.hh"
#include "Wektor3D.hh"

#include<algorithm>

class ObrysXY{

public:
    Wektor2D<double> _Lewy_Gorny;
    Wektor2D<double> _Prawy_Dolny;

    ObrysXY(){_Lewy_Gorny = 0; _Prawy_Dolny = 0;}
    ObrysXY Test(ObrysXY lazik1, ObrysXY lazik2);

    ObrysXY Oblicz_obrys(SWektor<double,3> lazik, SWektor<double,3> *Polozenie_pom, SWektor<double,3> *Polozenie_pom2);
};

#endif
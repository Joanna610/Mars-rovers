#ifndef SCENA_HH
#define SCENA_HH

#include <memory>

#include"Lazik.hh"
#include"ObiektGeom.hh"
#include"ProbkaRegolitu.hh"

class Scena{

public:
    list<shared_ptr<ObiektGeom>> _ObiektySceny, _ObiektySceny_probki;
    list<shared_ptr<ObiektGeom>>::iterator it, itp ;

    PzG::LaczeDoGNUPlota  Lacze;
    shared_ptr<Lazik> _AktywnyLazik;

    void InicjujScene();
    Scena();
    Scena(Scena const&);

    void Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota  &rLacze);
    void DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom  &rOb);
    void DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const Probka_Regolitu  &rOb);
};

#endif

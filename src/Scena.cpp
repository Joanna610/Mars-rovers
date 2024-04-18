#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "Scena.hh"

#include <algorithm>

Scena::Scena(){
  this->_ObiektySceny.push_back(make_shared<Lazik>("bryly_wzorcowe/szescian3.dat","Curiosity",Kolor_Pomaranczowy));
  this->_ObiektySceny.push_back(make_shared<Lazik>("bryly_wzorcowe/szescian3.dat","Perseverance",Kolor_Czerwony));
  this->_ObiektySceny.push_back(make_shared<Lazik>("bryly_wzorcowe/szescian3.dat", "FSR", Kolor_JasnoNiebieski));

  this->_ObiektySceny_probki.push_back(make_shared<Probka_Regolitu>("bryly_wzorcowe/szescian2.dat","skalki",Kolor_Czerwony));
  this->_ObiektySceny_probki.push_back(make_shared<Probka_Regolitu>("bryly_wzorcowe/szescian2.dat","skalki1",Kolor_Czerwony));
  this->_ObiektySceny_probki.push_back(make_shared<Probka_Regolitu>("bryly_wzorcowe/szescian2.dat","skalki2",Kolor_Czerwony));
  this->_ObiektySceny_probki.push_back(make_shared<Probka_Regolitu>("bryly_wzorcowe/szescian2.dat","skalki3",Kolor_Czerwony));
  this->_ObiektySceny_probki.push_back(make_shared<Probka_Regolitu>("bryly_wzorcowe/szescian2.dat","skalki4",Kolor_Czerwony));
  this->_ObiektySceny_probki.push_back(make_shared<Probka_Regolitu>("bryly_wzorcowe/szescian2.dat","skalki5",Kolor_Czerwony));
  this->_ObiektySceny_probki.push_back(make_shared<Probka_Regolitu>("bryly_wzorcowe/szescian2.dat","skalki6",Kolor_Czerwony));
  this->_ObiektySceny_probki.push_back(make_shared<Probka_Regolitu>("bryly_wzorcowe/szescian2.dat","skalki7",Kolor_Czerwony));
  this->_ObiektySceny_probki.push_back(make_shared<Probka_Regolitu>("bryly_wzorcowe/szescian2.dat","skalki8",Kolor_Czerwony));
  this->_ObiektySceny_probki.push_back(make_shared<Probka_Regolitu>("bryly_wzorcowe/szescian2.dat","skalki9",Kolor_Czerwony));


  it = _ObiektySceny.begin();
  itp = _ObiektySceny_probki.begin();


  // =================== PROBKI ===================
  DodajDoListyRysowania(this->Lacze, **itp);
  (**itp).AktualnePolozenie_obiekt(-40,80,0);
  (**itp).Przelicz_i_Zapisz_Wierzcholki(0);

  ++itp;

  DodajDoListyRysowania(this->Lacze, **itp);
  (**itp).AktualnePolozenie_obiekt(-80,-30,0);
  (**itp).Przelicz_i_Zapisz_Wierzcholki(0);

  ++itp;

  DodajDoListyRysowania(this->Lacze, **itp);
  (**itp).AktualnePolozenie_obiekt(50,-20,0);
  (**itp).Przelicz_i_Zapisz_Wierzcholki(0);

  ++itp;

  DodajDoListyRysowania(this->Lacze, **itp);
  (**itp).AktualnePolozenie_obiekt(80,0,0);
  (**itp).Przelicz_i_Zapisz_Wierzcholki(0);

  ++itp;

  DodajDoListyRysowania(this->Lacze, **itp);
  (**itp).AktualnePolozenie_obiekt(40,-50,0);
  (**itp).Przelicz_i_Zapisz_Wierzcholki(0);

  ++itp;

  DodajDoListyRysowania(this->Lacze, **itp);
  (**itp).AktualnePolozenie_obiekt(-30,20,0);
  (**itp).Przelicz_i_Zapisz_Wierzcholki(0);

  ++itp;

  DodajDoListyRysowania(this->Lacze, **itp);
  (**itp).AktualnePolozenie_obiekt(70,-30,0);
  (**itp).Przelicz_i_Zapisz_Wierzcholki(0);

  ++itp;

  DodajDoListyRysowania(this->Lacze, **itp);
  (**itp).AktualnePolozenie_obiekt(-70,-20,0);
  (**itp).Przelicz_i_Zapisz_Wierzcholki(0);

  ++itp;

  DodajDoListyRysowania(this->Lacze, **itp);
  (**itp).AktualnePolozenie_obiekt(20,-90,0);
  (**itp).Przelicz_i_Zapisz_Wierzcholki(0);

  ++itp;

  DodajDoListyRysowania(this->Lacze, **itp);
  (**itp).AktualnePolozenie_obiekt(-50,40,0);
  (**itp).Przelicz_i_Zapisz_Wierzcholki(0);

  // =============== KONIEC PROBEK ===============
  DodajDoListyRysowania(this->Lacze, **it);
  (**it).AktualnePolozenie_obiekt(10,-25,0);
  (**it).Przelicz_i_Zapisz_Wierzcholki(0);

  ++it;

  DodajDoListyRysowania(this->Lacze, **it);
  (**it).AktualnePolozenie_obiekt(60,60,0);
  (**it).Przelicz_i_Zapisz_Wierzcholki(0);

  ++it;

  DodajDoListyRysowania(this->Lacze, **it);
  (**it).Przelicz_i_Zapisz_Wierzcholki(0);
}

void Scena::Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota  &rLacze)
{
  rLacze.ZmienTrybRys(PzG::TR_3D);
  rLacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X/2, ROMIAR_POWIERZCHNI_X/2);
  rLacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y/2, ROMIAR_POWIERZCHNI_Y/2);
  rLacze.UstawZakresZ(-0, 90);
  rLacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok

  rLacze.Inicjalizuj();  // Tutaj startuje gnuplot.
}

void Scena::DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom  &rOb)
{
  PzG::InfoPlikuDoRysowania *wInfoPliku;

  wInfoPliku = &rLacze.DodajNazwePliku(rOb.WezNazwePliku_BrylaRysowana());
  wInfoPliku->ZmienKolor(rOb.WezKolorID());
}

void Scena::DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const Probka_Regolitu  &rOb)
{
  PzG::InfoPlikuDoRysowania *wInfoPliku;

  wInfoPliku = &rLacze.DodajNazwePliku(rOb.WezNazwePliku_BrylaRysowana());
  wInfoPliku->ZmienKolor(rOb.WezKolorID());
}

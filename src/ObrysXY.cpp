#include<iostream>
#include "ObrysXY.hh"

ObrysXY ObrysXY::Test(ObrysXY lazik1, ObrysXY lazik2){
   this->_Lewy_Gorny[0] = max(lazik1._Lewy_Gorny[0], lazik2._Lewy_Gorny[0]);
   this->_Lewy_Gorny[1] = min(lazik1._Lewy_Gorny[1], lazik2._Lewy_Gorny[1]);

   this->_Prawy_Dolny[0] = min(lazik1._Prawy_Dolny[0], lazik2._Prawy_Dolny[0]);
   this->_Prawy_Dolny[1] = max(lazik1._Prawy_Dolny[1], lazik2._Prawy_Dolny[1]);

   return *this;
}

ObrysXY ObrysXY::Oblicz_obrys(SWektor<double,3> lazik, SWektor<double,3> *Polozenie_pom, SWektor<double,3> *Polozenie_pom2 ){
   if((*Polozenie_pom)[0]>lazik[0]) (*Polozenie_pom)[0] = lazik[0];
   if((*Polozenie_pom)[1]<lazik[1]) (*Polozenie_pom)[1] = lazik[1];

   if((*Polozenie_pom2)[0]<lazik[0]) (*Polozenie_pom2)[0] = lazik[0];
   if((*Polozenie_pom2)[1]>lazik[1]) (*Polozenie_pom2)[1] = lazik[1];

   this->_Lewy_Gorny[0] = (*Polozenie_pom)[0];
   this->_Lewy_Gorny[1] = (*Polozenie_pom)[1];

   this->_Prawy_Dolny[0] = (*Polozenie_pom2)[0];
   this->_Prawy_Dolny[1] = (*Polozenie_pom2)[1];
   return *this;
}


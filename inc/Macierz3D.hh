#ifndef MACIERZ3D_HH
#define MACIERZ3D_HH

#include "SMacierz.hh"
#include "rozmiar.h"

class Macierz3D{

   public:
   SMacierz<double,ROZMIAR> Macierz_rotacji;
   Macierz3D(double kat_stopnie);
};

#endif
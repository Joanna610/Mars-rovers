#include <iostream>
#include <math.h>

#include "Macierz3D.hh"

Macierz3D::Macierz3D(double kat_stopnie){
    double kat_radiany = 0;
    kat_radiany = ((round(M_PI*100)/100) * kat_stopnie)/180;

    Macierz_rotacji(0,0) = cos(kat_radiany);
    Macierz_rotacji(0,1) = -sin(kat_radiany);
    Macierz_rotacji(0,2) = 0;
    Macierz_rotacji(1,0) = sin(kat_radiany);
    Macierz_rotacji(1,1) = cos(kat_radiany);
    Macierz_rotacji(1,2) = 0;
    Macierz_rotacji(2,0) = 0;
    Macierz_rotacji(2,1) = 0;
    Macierz_rotacji(2,2) = 1;
}
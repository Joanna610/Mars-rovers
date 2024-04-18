#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include "rozmiar.h"
#include <iostream>
#include <math.h>
#include <string.h>


using namespace std;

template <typename STyp>
class Wektor2D {
    STyp Tab[2];
    static int IloscAktualna;
    static int IloscOgolna;

public:
  	Wektor2D();
  	~Wektor2D();
  	Wektor2D<STyp>(const Wektor2D<STyp> &kopia) {for(int i=0;i<2;i++)Tab[i] = kopia[i];}

	Wektor2D<STyp> operator + (const Wektor2D<STyp>& wek)const;
	Wektor2D<STyp> operator - (Wektor2D<STyp> wek);
	STyp operator * (const Wektor2D<STyp>& wek)const;
	Wektor2D<STyp> operator * (STyp& liczba)const;
	Wektor2D<STyp> operator / (STyp& liczba)const;
	STyp operator[] (int Ind) const { return Tab[Ind]; }
	STyp& operator[] (int Ind)		{ return Tab[Ind]; }

	Wektor2D<STyp> zamiana(unsigned int ity, unsigned int kta);
	Wektor2D<STyp> operator = (int liczba);
	bool operator == (STyp liczba)const;

  	static int WezIloscAktualna(){return IloscAktualna; }
  	static int WezIloscOgolna(){return IloscOgolna; }
};

template <typename STyp>
int Wektor2D<STyp>::IloscAktualna = 0;

template <typename STyp>
int Wektor2D<STyp>::IloscOgolna = 0;

template <typename STyp>
Wektor2D<STyp>::Wektor2D(){
  	++IloscAktualna;
  	++IloscOgolna;
  	for (STyp& _Wsp : Tab) _Wsp = 2;
}

template <typename STyp>
Wektor2D<STyp>::~Wektor2D(){
  	--IloscAktualna;
}


template <typename STyp>
istream& operator >> (istream& Strm, Wektor2D<STyp>& Wek) {

	for (int i = 0; i < 2; i++) {
		Strm >> Wek[i];
	}
	return Strm;
}

template <typename STyp>
ostream& operator << (ostream& Strm, const Wektor2D<STyp>& Wek) {

	for (int i = 0; i < 2; i++) {
		Strm << Wek[i];
		Strm << "  ";
	}
	return Strm;
}


template <typename STyp>
Wektor2D<STyp> Wektor2D<STyp>::operator + (const Wektor2D<STyp>& wek)const {

	Wektor2D<STyp> pom;
	for (int p = 0; p < 2; p++) {
		pom[p] = wek[p] + (*this)[p];
	}
	return pom;
}

template <typename STyp>
Wektor2D<STyp> Wektor2D<STyp>::operator - (Wektor2D<STyp> wek) {

	Wektor2D<STyp> wek_pom, wek_pom2;
	wek_pom2 = *this;
	wek_pom = 0;

	for (int p = 0; p < 2; p++) {
		wek_pom[p] = wek_pom2[p] - wek[p];
	}
	return wek_pom;
}

template <typename STyp>
STyp Wektor2D<STyp>::operator * (const Wektor2D<STyp>& wek)const {

	STyp mnoz;
	mnoz = 0;
	for (int t = 0; t < 2; t++) {
		mnoz = (*this)[t] * wek[t] + mnoz;
	}
	return mnoz;
}

template <typename STyp>
Wektor2D<STyp> Wektor2D<STyp>::operator * (STyp& liczba)const {

	Wektor2D<STyp> wek;
	for (int p = 0; p < 2; p++) {
		wek[p] = (*this)[p] * liczba;
	}
	return wek;
}

template <typename STyp>
Wektor2D<STyp> Wektor2D<STyp>::operator / (STyp& liczba)const {

	Wektor2D<STyp> wek;
	if (liczba == 0) return wek;

	for (int p = 0; p < 2; p++) {
		wek[p] = (*this)[p] / liczba;
	}
	return wek;
}

template <typename STyp>
bool Wektor2D<STyp>::operator == (STyp liczba)const {

	for (int p = 0; p < 2; p++) {
		if ((*this)[p] != liczba) return false;
	}
	return true;
}

template <typename STyp>
Wektor2D<STyp> Wektor2D<STyp>::zamiana(unsigned int ity, unsigned int kta) {

	swap((*this)[ity], (*this)[kta]);

	return *this;
}

template <typename STyp>
Wektor2D<STyp> Wektor2D<STyp>::operator = (int liczba){

	for (int p = 0; p < 2; p++) {
		(*this)[p] = liczba;
	}
	return *this;
}

#endif

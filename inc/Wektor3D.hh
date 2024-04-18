#ifndef SWEKTOR_HH
#define SWEKTOR_HH

#include "rozmiar.h"
#include <iostream>
#include <math.h>
#include <string.h>

template <typename STyp, int SWymiar>
class SWektor {
	STyp Tab[SWymiar];
        static int IloscAktualna;
        static int IloscOgolna;

public:
  	SWektor();
  	~SWektor();
  	SWektor<STyp, SWymiar>(const SWektor<STyp, SWymiar> &kopia) {for(int i=0;i<SWymiar;i++)Tab[i] = kopia[i];}

	SWektor<STyp, SWymiar> operator + (const SWektor<STyp, SWymiar>& wek)const;
	SWektor<STyp, SWymiar> operator - (SWektor<STyp, SWymiar> wek);
	STyp operator * (const SWektor<STyp, SWymiar>& wek)const;
	SWektor<STyp, SWymiar> operator * (STyp& liczba)const;
	SWektor<STyp, SWymiar> operator / (STyp& liczba)const;
	STyp operator[] (int Ind) const { return Tab[Ind]; }
	STyp& operator[] (int Ind)		{ return Tab[Ind]; }

	SWektor<STyp, SWymiar> zamiana(unsigned int ity, unsigned int kta);
	SWektor<STyp, SWymiar> operator = (int liczba);
	SWektor<STyp, SWymiar> operator = (SWektor<STyp, SWymiar> wek);
	bool operator == (SWektor<STyp, SWymiar> wek);
	bool operator == (STyp liczba)const;
  	static int WezIloscAktualna(){return IloscAktualna; }
  	static int WezIloscOgolna(){return IloscOgolna; }
};

template <typename STyp, int SWymiar>
int SWektor<STyp,SWymiar>::IloscAktualna = 0;

template <typename STyp, int SWymiar>
int SWektor<STyp,SWymiar>::IloscOgolna = 0;

template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar>::SWektor(){
  	++IloscAktualna;
  	++IloscOgolna;
  	for (STyp& _Wsp : Tab) _Wsp = 2;
}

template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar>::~SWektor(){
  	--IloscAktualna;
}


template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream& Strm, SWektor<STyp, SWymiar>& Wek) {

	for (int i = 0; i < SWymiar; i++) {
		Strm >> Wek[i];
	}
	return Strm;
}

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream& Strm, const SWektor<STyp, SWymiar>& Wek) {

	for (int i = 0; i < SWymiar; i++) {
		Strm << Wek[i];
		Strm << "  ";
	}
	return Strm;
}


template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar> SWektor<STyp, SWymiar>::operator + (const SWektor<STyp, SWymiar>& wek)const {

	SWektor<STyp, SWymiar> pom;
	for (int p = 0; p < SWymiar; p++) {
		pom[p] = wek[p] + (*this)[p];
	}
	return pom;
}

template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar> SWektor<STyp, SWymiar>::operator - (SWektor<STyp, SWymiar> wek) {

	SWektor<STyp, SWymiar> wek_pom, wek_pom2;
	wek_pom2 = *this;
	wek_pom = 0;

	for (int p = 0; p < SWymiar; p++) {
		wek_pom[p] = wek_pom2[p] - wek[p];
	}
	return wek_pom;
}

template <typename STyp, int SWymiar>
STyp SWektor<STyp, SWymiar>::operator * (const SWektor<STyp, SWymiar>& wek)const {

	STyp mnoz;
	mnoz = 0;
	for (int t = 0; t < SWymiar; t++) {
		mnoz = (*this)[t] * wek[t] + mnoz;
	}
	return mnoz;
}

template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar> SWektor<STyp, SWymiar>::operator * (STyp& liczba)const {

	SWektor<STyp, SWymiar> wek;
	for (int p = 0; p < SWymiar; p++) {
		wek[p] = (*this)[p] * liczba;
	}
	return wek;
}

template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar> SWektor<STyp, SWymiar>::operator / (STyp& liczba)const {

	SWektor<STyp, SWymiar> wek;
	if (liczba == 0) return wek;

	for (int p = 0; p < SWymiar; p++) {
		wek[p] = (*this)[p] / liczba;
	}
	return wek;
}

template <typename STyp, int SWymiar>
bool SWektor<STyp, SWymiar>::operator == (STyp liczba)const {

	for (int p = 0; p < SWymiar; p++) {
		if ((*this)[p] != liczba) return false;
	}
	return true;
}

template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar> SWektor<STyp, SWymiar>::zamiana(unsigned int ity, unsigned int kta) {

	swap((*this)[ity], (*this)[kta]);
	return *this;
}

template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar> SWektor<STyp, SWymiar>::operator = (int liczba){

	for (int p = 0; p < SWymiar; p++) {
		(*this)[p] = liczba;
	}
	return *this;
}

template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar> SWektor<STyp, SWymiar>::operator = (SWektor<STyp, SWymiar> wek){

    for (int j = 0; j < ROZMIAR; j++) {
		(*this)[j] = wek[j];
	}
	return *this;
}

template <typename STyp, int SWymiar>
bool SWektor<STyp, SWymiar>::operator == (SWektor<STyp, SWymiar> wek){

    if((*this)[0] == wek[0] && (*this)[1] == wek[1] && (*this)[2] == wek[2]) return true;
    else return false;
}

#endif

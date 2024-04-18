#ifndef SMACIERZ_HH
#define SMACIERZ_HH

#include "rozmiar.h"
#include "Wektor3D.hh"
#include <iostream>
#include <vector>

template <typename SmTyp, int SWymiar>
class SMacierz {
	SWektor<SmTyp, SWymiar> tablica[SWymiar];

public:
	SMacierz() { for (int i = 0; i < SWymiar; i++) tablica[i] = 0; }

	const SWektor<SmTyp, SWymiar>& operator[] (int Kol) const { return tablica[Kol]; }
	SWektor<SmTyp, SWymiar>& operator[] (int Kol) { return tablica[Kol]; }

	const SmTyp operator() (int Wi, int Ko) const { return tablica[Wi][Ko]; }
	SmTyp& operator() (int Wi, int Ko) { return tablica[Wi][Ko]; }
	SMacierz<SmTyp, SWymiar> wyzeruj();
	SmTyp wyznacznik_gauss();
	SMacierz<SmTyp, SWymiar> transponuj()const;
	SMacierz<SmTyp, SWymiar> zamiana(unsigned int ity, unsigned int kta);
	SMacierz<SmTyp, SWymiar>  operator * (SWektor<SmTyp, SWymiar>  wek_odp);
};

template <typename SmTyp, int SWymiar>
std::istream& operator >> (std::istream& Strm, SMacierz<SmTyp, SWymiar>& Mac) {

	for (int i = 0; i < ROZMIAR; i++) {
		Strm >> Mac[i];
	}
	return Strm;
}

template <typename SmTyp, int SWymiar>
std::ostream& operator << (std::ostream& Strm, const SMacierz<SmTyp, SWymiar>& Mac) {

	for (int i = 0; i < ROZMIAR; i++) {
		Strm << Mac[i] << std::endl;
	}
	return Strm;
}

template <typename SmTyp, int SWymiar>
SMacierz<SmTyp, SWymiar> SMacierz<SmTyp, SWymiar>::wyzeruj() {

	int n = 1, p, k = 1;
	for (p = 0; p < ROZMIAR - 1; p++) {
		while (n < ROZMIAR) {
			if ((*this)(p, p) == 0) (*this) = this->zamiana(p, p + 1);
			(*this)[n] = (*this)[n] - (((*this)[p] / (*this)(p, p)) * (*this)(n, p));

			n++;
		}
		k++;
		n = k;
	}
	return *this;
}

template <typename SmTyp, int SWymiar>
SmTyp SMacierz<SmTyp, SWymiar>::wyznacznik_gauss() {

	SMacierz<SmTyp, SWymiar> mac2;
	mac2 = *this;
	SmTyp wyznacznik;
	mac2 = mac2.wyzeruj();

	for (int i = 0; i < ROZMIAR; i++) {
		wyznacznik = mac2(i, i) * wyznacznik;
	}
	return wyznacznik;
}

template <typename SmTyp, int SWymiar>
SMacierz<SmTyp, SWymiar> SMacierz<SmTyp, SWymiar>::transponuj()const {

	SMacierz<SmTyp, SWymiar> trans;

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			trans(i, j) = (*this)(j, i);
		}
	}
	return trans;
}

template <typename SmTyp, int SWymiar>
SMacierz<SmTyp, SWymiar> SMacierz<SmTyp, SWymiar>::zamiana(unsigned int ity, unsigned int kta) {

	swap((*this)[ity], (*this)[kta]);

	return *this;
}

template <typename SmTyp, int SWymiar>
SMacierz<SmTyp, SWymiar>  SMacierz<SmTyp, SWymiar>::operator * (SWektor<SmTyp, SWymiar>  wek_odp) {

	SWektor<SmTyp, ROZMIAR>  wektor_odp;

	for (int p = 0; p < ROZMIAR; p++) {
		wektor_odp[p] = (*this)[p] * wek_odp;
	}
	return wektor_odp;
}

#endif

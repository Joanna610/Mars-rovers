#include<iostream>
#include<chrono>
#include<thread>
#include<math.h>

#include "Lazik.hh"

Typ_kolizji Lazik::Czykolizja(shared_ptr<ObiektGeom>& wsk) {
    ObrysXY wspolny_prostokat;
        wspolny_prostokat.Test(this->_Obrys, wsk->_Obrys);
        if(wspolny_prostokat._Lewy_Gorny[0]<=wspolny_prostokat._Prawy_Dolny[0] ){
            if(wspolny_prostokat._Lewy_Gorny[1]>=wspolny_prostokat._Prawy_Dolny[1]){
                return TK_Kolizjia_lazik;
            }
        }

    return TK_BrakKolizji;
}

void Lazik::Przesuniecie_Lazika(list<shared_ptr<ObiektGeom>> _ObiektySceny, double odleglosc, PzG::LaczeDoGNUPlota  Lacze,  double kat){
    list<shared_ptr<ObiektGeom>>::iterator it_pom;
    it_pom = _ObiektySceny.begin();

    double kat_rad = 0;
    static double kat_pom = 0;
    double jednostka_x = 0, jednostka_y = 0, pomocnicza = 0;
    static double pomocnicza_x = 0, pomocnicza_y = 0;

    Obrut_Lazika(kat, Lacze);

    kat = kat+kat_pom;
    kat_pom = kat;
    kat_rad = ((round(M_PI*100)/100) * kat)/180;
    KatOrietacji_st = kat;

    pomocnicza_x = this->Polozenie[0];
    pomocnicza_y = this->Polozenie[1];

    while(pomocnicza <= odleglosc){
        jednostka_x = pomocnicza*cos(kat_rad);
        jednostka_y = pomocnicza*sin(kat_rad);

        this->Polozenie[0] = jednostka_x + pomocnicza_x;
        this->Polozenie[1] = jednostka_y + pomocnicza_y;

        pomocnicza++;
        this->Przelicz_i_Zapisz_Wierzcholki(kat);
        if(sprawdzanie_kolizji_z_lazikiem(it_pom)==1) return;
        rysowanie(Lacze);
    }
}

int Lazik::sprawdzanie_kolizji_z_lazikiem(list<shared_ptr<ObiektGeom>>::iterator it_pom){

    for(int i = 0;i<3;i++){
    shared_ptr<Lazik> obiekt_do_porownania = static_pointer_cast<Lazik>(*it_pom);
    shared_ptr<ObiektGeom> lazik_do_porownania = make_shared<ObiektGeom>(*this);
        if((**it_pom).Polozenie == this->Polozenie){}
        else{
            if((*obiekt_do_porownania).Czykolizja(lazik_do_porownania) == TK_Kolizjia_lazik) {
                std::cout << "KOLIZJA Z LAZIKIEM"<<std::endl;
                return 1;
            }
        }
        ++it_pom;
    }
    for(int i = 0;i<3;i++)--it_pom;
    return 0;
}

void Lazik::Obrut_Lazika(double KatOrietacji_st, PzG::LaczeDoGNUPlota  Lacze){

    static double jednostka = 0;
    if(KatOrietacji_st >=0){
        KatOrietacji_st = KatOrietacji_st+jednostka;
        for(; jednostka<KatOrietacji_st; jednostka++){
            this->Przelicz_i_Zapisz_Wierzcholki(jednostka);
            rysowanie(Lacze);
        }
    }
    else{
        KatOrietacji_st = KatOrietacji_st+jednostka;
        for(; jednostka>KatOrietacji_st; jednostka--){
            this->Przelicz_i_Zapisz_Wierzcholki(jednostka);
            rysowanie(Lacze);
        }
    }
}

void Lazik::rysowanie(PzG::LaczeDoGNUPlota  Lacze){
    this_thread::sleep_for(chrono::milliseconds(20));
    Lacze.Rysuj();
}

Lazik::Lazik(){}


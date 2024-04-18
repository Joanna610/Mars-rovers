#include <iostream>
#include<chrono>
#include<thread>
#include<math.h>

#include "LazikSFR.hh"

void LazikSFR::Przesuniecie_LazikaSFR(list<shared_ptr<ObiektGeom>> _ObiektySceny, list<shared_ptr<ObiektGeom>> _ObiektySceny_probki, double odleglosc, PzG::LaczeDoGNUPlota  Lacze,  double kat ){
    list<shared_ptr<ObiektGeom>>::iterator it_pom4, it_pom3;
    it_pom4 = _ObiektySceny.begin();
    it_pom3 = _ObiektySceny_probki.begin();

    double kat_rad = 0;
    static double kat_pom = 0;
    double jednostka_x = 0, jednostka_y = 0, pomocnicza = 0;
    static double pomocnicza_x = 0, pomocnicza_y = 0;

    kat = kat+kat_pom;
    kat_pom = kat;
    kat_rad = ((round(M_PI*100)/100) * kat)/180;

    pomocnicza_x = this->Polozenie[0];
    pomocnicza_y = this->Polozenie[1];
    Obrut_LazikaSFR(kat, Lacze);

    while(pomocnicza <= odleglosc){
        jednostka_x = pomocnicza*cos(kat_rad);
        jednostka_y = pomocnicza*sin(kat_rad);

        this->Polozenie[0] = jednostka_x + pomocnicza_x;
        this->Polozenie[1] = jednostka_y + pomocnicza_y;

        pomocnicza++;
        this->Przelicz_i_Zapisz_Wierzcholki(kat);


        if(sprawdzanie_kolizji_z_lazikiem(it_pom4)==1) return;
        if(sprawdzanie_kolizji_z_probka(it_pom3)==1) return;

        this_thread::sleep_for(chrono::milliseconds(20));
        Lacze.Rysuj();
    }
}

int LazikSFR::sprawdzanie_kolizji_z_lazikiem(list<shared_ptr<ObiektGeom>>::iterator it_pom4){
    for(int i = 0;i<3;i++){
        shared_ptr<Lazik> obiekt_do_porownania = static_pointer_cast<Lazik>(*it_pom4);
        shared_ptr<ObiektGeom> lazik_do_porownania = make_shared<ObiektGeom>(*this);
        if((**it_pom4).Polozenie == this->Polozenie){}
        else{
            if((*obiekt_do_porownania).Czykolizja(lazik_do_porownania) == TK_Kolizjia_lazik) {
                std::cout << "KOLIZJA Z LAZIKIEM"<<std::endl;
                return 1;
            }
        }
        ++it_pom4;
    }
    for(int i = 0;i<3;i++)--it_pom4;
    return 0;
}

int LazikSFR::sprawdzanie_kolizji_z_probka(list<shared_ptr<ObiektGeom>>::iterator it_pom3){
    for(int i = 0; i< 10;i++){
        shared_ptr<Probka_Regolitu> probka_do_porownania = static_pointer_cast<Probka_Regolitu>(*it_pom3);
        shared_ptr<ObiektGeom> lazik_do_porownania = make_shared<ObiektGeom>(*this);
        if((*probka_do_porownania).Czykolizja(lazik_do_porownania) == TK_Kolizjia_probka) {
            std::cout << "KOLIZJA Z PROBKA"<<std::endl;
            return 1;
        }
        ++it_pom3;
    }
    for(int i = 0;i<10;i++) --it_pom3;
    return 0;
}

void LazikSFR::Obrut_LazikaSFR(double KatOrietacji_st, PzG::LaczeDoGNUPlota  Lacze){
    static double jednostka = 0;
    if(KatOrietacji_st >= 0){
        KatOrietacji_st = KatOrietacji_st+jednostka;
        for(; jednostka<KatOrietacji_st; jednostka++){
            this->Przelicz_i_Zapisz_Wierzcholki(jednostka);
            this_thread::sleep_for(chrono::milliseconds(20));
            Lacze.Rysuj();
        }
    }
    else{
        KatOrietacji_st = KatOrietacji_st+jednostka;
        for(; jednostka>KatOrietacji_st; jednostka--){
            this->Przelicz_i_Zapisz_Wierzcholki(jednostka);
            this_thread::sleep_for(chrono::milliseconds(20));
            Lacze.Rysuj();
        }
    }
}
#pragma once
#ifndef WYPOZYCZALNIA_H
#define WYPOZYCZALNIA_H
#include <iostream>
#include <vector>
#include "PrzyrzadPomiarowy.h"
#include "Wypozyczenie.h"


class Wypozyczalnia {
public:
    std::vector<PrzyrzadPomiarowy*> listaPrzyrzadow;
    std::vector<Wypozyczenie> listaWypozyczen;
        void Oferta();
        void wypozyczPrzedmiot();
        void zapisz_do_pliku2(const std::string& Nazwa_pliku);
        void wczytaj_z_pliku();
        void wczytaj_z_pliku2();
        void dodajPrzyrzad(PrzyrzadPomiarowy* przyrzad);
        void wypisz_co_siedem();
        void wypisz_co_piec();
        void wypisz_co_piec2();
        void zwrocPrzedmiot();
        void zapisz_do_pliku(const std::string&Nazwa_pliku);
        bool CzyPrzyrzadDostepny(const std::string& nazwaPrzyrzadu) const;
        void wyswietlPrzyrzady();
        ~Wypozyczalnia();
};

#endif // !WYPOZYCZALNIA_H

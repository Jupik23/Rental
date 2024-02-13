#include "PrzyrzadPomiarowy.h"
#include "Wypozyczalnia.h"
#include "Wypozyczenie.h"
#include <windows.h>
#include <iostream>

int main() {
    Wypozyczenie wyp;
    Wypozyczalnia wypozyczalnia;
    int opcja;
    do {
        std::cout << "===== MENU =====\n"
            << "1. Oferta wypozyczalni\n"
            << "2. Wypozycz przyrzad\n"
            << "3. Zwroc przyrzad\n"
            << "4. Wyswietl zarezerwowane przyrzady\n"
            << "5. Zapisz do pliku(dodaj przyrzad)\n"
            << "6. Wczytaj z pliku\n"
            << "7. Wyjscie\n"
            << "Wybierz opcje (1-7):     " << std::endl;
        std::cin >> opcja;

        switch (opcja) {
        case 1: {
            wypozyczalnia.Oferta();
            break;
        }
        case 2: {
            std::cout << "===WYPOZYCZ PRZEDMIOT===" << std::endl;          
            wypozyczalnia.wypozyczPrzedmiot();
            break;
        }              
        case 3: {// Usuñ rezerwacjê
            std::cout << "===ZWROC PRZEDMIOT===" << std::endl;
            wypozyczalnia.zwrocPrzedmiot();
            break;
        }
        case 4: {//lista zarezerwowanych przyrzadow
            std::cout<<"====WYSWIETL ZAREZERWOWANE PRZYRZADY===="<<std::endl;
            wypozyczalnia.wypisz_co_piec2();
       
            break;
     
        }
        case 5: {//dodawanie przyrzadu do pliku
            int opcja2;

            do {
                std::cout << "1. Dodaj multimetr\n"
                    << "2. Dodaj generator\n"
                    << "3. Dodaj oscyloskop\n"
                    << "Wybierz opcje (1-3):  " << std::endl;

                std::cin >> opcja2;
                switch (opcja2) {
                case 1: {
                    // Dodaj multimetr
                    std::string nazwaOsoby;
                    std::string nazwaMultimetru;
                    double rozdzielczoscMultimetru;
                    double cenaMultimetru;
                    int lk;
                    int ilosc;

                    std::cout << "Podaj imie i nazwisko osoby dodajacej: ";
                    std::cin.ignore();
                    std::getline(std::cin, nazwaOsoby);

                    std::cout << "Podaj nazwe multimetru: ";
                    std::cin.ignore();
                    std::getline(std::cin, nazwaMultimetru);

                    std::cout << "Podaj liczbe kanalow generatora: ";
                    std::cin >> lk;

                    std::cout << "Multimetr dostepny?[0/1]: ";
                    std::cin >> ilosc;

                    std::cout << "Podaj rozdzielczosc multimetru: ";
                    std::cin >> rozdzielczoscMultimetru;

                    std::cout << "Podaj cene multimetru: ";
                    std::cin >> cenaMultimetru;

                    Multimetr* multimetr = new Multimetr(nazwaOsoby,"Multimetr", nazwaMultimetru, lk, ilosc, rozdzielczoscMultimetru, cenaMultimetru);
                    wypozyczalnia.dodajPrzyrzad(multimetr);
                    break;

                }
                case 2: {
                    // Dodaj generator
                    std::string nazwaOsoby;
                    std::string nazwaGeneratora;
                    double maxCzestotliwoscGeneratora;
                    double cenaGeneratora;
                    int lk;
                    int ilosc;

                    std::cout << "Podaj imie i nazwisko osoby dodajacej: ";
                    std::cin.ignore();
                    std::getline(std::cin, nazwaOsoby);

                    std::cout << "Podaj nazwe generatora: ";
                    std::cin.ignore();
                    std::getline(std::cin, nazwaGeneratora);

                    std::cout << "Podaj liczbe kanalow generatora:  ";
                    std::cin >> lk;

                    std::cout << "Generator dostepny?[0/1]:    ";
                    std::cin >> ilosc;

                    std::cout << "Podaj maksymalna czestotliwosc generatora: ";
                    std::cin >> maxCzestotliwoscGeneratora;

                    std::cout << "Podaj cene generatora: ";
                    std::cin >> cenaGeneratora;

                    Generator* generator = new Generator(nazwaOsoby,"Generator", nazwaGeneratora, lk, ilosc, maxCzestotliwoscGeneratora, cenaGeneratora);
                    wypozyczalnia.dodajPrzyrzad(generator);

                    break;
                }
                case 3: {
                    // Dodaj oscyloskop
                    std::string nazwaOsoby;
                    std::string nazwaOscyloskopu;
                    double maxCzestotliwoscProbkowania;
                    double cenaOscyloskopu;
                    int lk;
                    int ilosc;

                    std::cout << "Podaj imie i nazwisko osoby dodajacej: ";
                    std::cin.ignore();
                    std::getline(std::cin, nazwaOsoby);

                    std::cout << "Podaj nazwe oscyloskopu: ";
                    std::cin.ignore();
                    std::getline(std::cin, nazwaOscyloskopu);

                    std::cout << "Podaj liczbe kanalow oscyloskopu:  ";
                    std::cin >> lk;

                    std::cout << "Oscyloskop dostepny?[0/1]:    ";
                    std::cin >> ilosc;

                    std::cout << "Podaj maksymalna czestotliwosc probkowania oscyloskopu: ";
                    std::cin >> maxCzestotliwoscProbkowania;

                    std::cout << "Podaj cene oscyloskopu: ";
                    std::cin >> cenaOscyloskopu;

                    Oscyloskop* oscyloskop = new Oscyloskop(nazwaOscyloskopu,"Oscyloskop", nazwaOscyloskopu, lk, ilosc, maxCzestotliwoscProbkowania, cenaOscyloskopu);
                    wypozyczalnia.dodajPrzyrzad(oscyloskop);
                    break;
                } 
                default: {
                    std::cout << "NIEPRAWID£OWA OPCJA" << std::endl;
                    break;
                }
                }

            } while (opcja2 < 1 || opcja2 > 3);
            break;
        }
        case 6: {//wczytanie z pliku
            wypozyczalnia.wczytaj_z_pliku();
            wypozyczalnia.wczytaj_z_pliku2();
            break;
        }
        case 7:
            wypozyczalnia.zapisz_do_pliku("przyrzady.txt");
            wypozyczalnia.zapisz_do_pliku2("wypozyczenia.txt");
            std::cout << "Program zakonczony." << std::endl;
            break;
        default: {
            std::cout << "NIEPRAWIDLOWA OPCJA" << std::endl;

            break;
        }
        }
       
    } while (opcja != 7);

    return 0;

}  
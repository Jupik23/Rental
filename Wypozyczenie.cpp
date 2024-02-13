#include "Wypozyczenie.h"
#include "PrzyrzadPomiarowy.h"

Wypozyczenie::Wypozyczenie() {}

Wypozyczenie::Wypozyczenie(const int& id, const std::string& dane, const std::string& odkiedy, const std::string& dokiedy) :
	ID_listaPrzedmiotow(id), osobaWypozyczajaca(dane), dataWypozyczenia(odkiedy), dataOddania(dokiedy) {
}




  
#pragma once
#ifndef WYPOZYCZENIE_H
#define WYPOZYCZENIE_H
#include <iostream>
#include <vector>
#include <string>
#include "PrzyrzadPomiarowy.h"

class Wypozyczenie {
private:
    int ID_listaPrzedmiotow;
    std::string osobaWypozyczajaca;
    std::string dataWypozyczenia;
    std::string dataOddania;

    
public:
    Wypozyczenie();
    Wypozyczenie(const int& id, const std::string& dane, const std::string& odkiedy, const std::string& dokiedy);
    int getID()const {
        return ID_listaPrzedmiotow;
    }
    std::string getOsobaWypozyczajaca() const {
		return osobaWypozyczajaca;
	}
    std::string getDataWypozyczenia() const {
        return dataWypozyczenia;
    }
    std::string getDataOddania() const {
		return dataOddania;
	}
    void setID(const int& id) {
        this->ID_listaPrzedmiotow = id;
    }
    void setOsobaWypozyczajaca(const std::string& osobaWypozyczajaca) {
        this->osobaWypozyczajaca = osobaWypozyczajaca;
    }
    void setDataWypozyczenia(const std::string& dataWypozyczenia) {
		this->dataWypozyczenia = dataWypozyczenia;
	}
    void setDataOddania(const std::string& dataOddania) {
        this->dataOddania = dataOddania;
    }


   
     
};




#endif // !WYPOZYCZENIE_H

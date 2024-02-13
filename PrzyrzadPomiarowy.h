#pragma once
#ifndef PRZYRZADPOMIAROWY_H
#define PRZYRZADPOMIAROWY_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class PrzyrzadPomiarowy {
	std::string Osobawypo;
	std::string Typ_Przyrzadu;
	std::string Nazwa_Przyrzadu;
	int kanaly;
	bool Dostepnosc;
public:
	PrzyrzadPomiarowy(const std::string osobawp, const std::string& typ, const std::string& name, int kan, bool dost);
	virtual void wyswietlInformacje()const;
	virtual std::string zapisz_do_pliku()const;
	~PrzyrzadPomiarowy();
	 


	bool czyDostepny() const {
		return Dostepnosc;
	}

	void zmienDostepnosc(bool dost) {
		Dostepnosc = dost;
	}

	std::string getNazwa() const {
		return Nazwa_Przyrzadu;
	}
	std::string getImie()const {
		return	Osobawypo;
	}
};



class Multimetr : public PrzyrzadPomiarowy {
	double rozdzielczosc;
	double Cena;
	public:
		Multimetr(const std::string osobawp, const std::string& typ, const std::string& nazwa, int kanaly, bool dostepnosc, double rozdzielczosc, double cena);
		~Multimetr();
		void wyswietlInformacje()const override;
		std::string zapisz_do_pliku() const override;
		
};



class Oscyloskop : public PrzyrzadPomiarowy {
	double maxCzestotliwoscProbkowania;
	double Cena;
public:
	Oscyloskop(const std::string osobawp, const std::string& typ, const std::string& nazwa, int kanaly, bool dostepnosc, double MaxCzP, double Cena);
	void wyswietlInformacje()const override;
	std::string zapisz_do_pliku() const override;
	~Oscyloskop();
};



class Generator : public PrzyrzadPomiarowy {
	double MaxCzestosliwoscSygnalu;
	double Cena;
public:
	Generator(const std::string osobawp, const std::string& typ, const std::string& nazwa, int kanaly, bool dostepnosc, double MaxCzS, double Cena);
	void wyswietlInformacje()const override;
	std::string zapisz_do_pliku() const override;
	~Generator();


};

#endif // PRZYRZADPOMIAROWY_H
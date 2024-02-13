#include "PrzyrzadPomiarowy.h"

PrzyrzadPomiarowy::PrzyrzadPomiarowy(const std::string osobawp, const std::string& typ, const std::string& nazwa, int kanaly, bool dostepnosc)
	:	Osobawypo(osobawp),	Typ_Przyrzadu(typ), Nazwa_Przyrzadu(nazwa), kanaly(kanaly), Dostepnosc(dostepnosc) {}

void PrzyrzadPomiarowy::wyswietlInformacje()const {
		std::cout << "Typ: " << Typ_Przyrzadu << std::endl;
		std::cout << "Nazwa: " << Nazwa_Przyrzadu << std::endl;
		std::cout << "Liczba kanalow: " << kanaly << std::endl;
		std::cout << "Dostepnosc: " << (Dostepnosc ? "Dostepny" : "Niedostepny") << std::endl;}

std::string PrzyrzadPomiarowy::zapisz_do_pliku() const {
	std::ostringstream oss;
	oss << "Osoba wypozyczajaca: " << Osobawypo << "\n";
	oss << "Typ przyrzadu: " << Typ_Przyrzadu << "\n";
	oss << "Nazwa: " << Nazwa_Przyrzadu << "\n";
	oss << "Kanaly: " << kanaly << "\n";
	oss << "Dostepnosc: " << (Dostepnosc ? "Dostepny" : "Niedostepny") << "\n";
	return oss.str();
}


PrzyrzadPomiarowy::~PrzyrzadPomiarowy() {}


Multimetr::Multimetr(const std::string osobawp, const std::string& typ, const std::string& nazwa, int kanaly, bool dostepnosc, double rozdzielczosc, double cena)
	: PrzyrzadPomiarowy(osobawp,typ, nazwa, kanaly, dostepnosc), rozdzielczosc(rozdzielczosc), Cena(cena) {}

void Multimetr::wyswietlInformacje()const {
	PrzyrzadPomiarowy::wyswietlInformacje();
	std::cout<<"Maksymalna rozdzielczosc:	"<< rozdzielczosc <<std::endl;
	std::cout << "Cena:	" << Cena << std::endl;}

std::string Multimetr::zapisz_do_pliku() const {
	std::ostringstream oss;
	oss << PrzyrzadPomiarowy::zapisz_do_pliku();
	oss << "Maksymalna rozdzielczosc: " << rozdzielczosc << "\n";
	oss << "Cena: " << Cena << "\n";
	return oss.str();
}

Multimetr::~Multimetr(){}


Oscyloskop::Oscyloskop(const std::string osobawp, const std::string& typ, const std::string& nazwa, int kanaly, bool dostepnosc, double maxCzestotliwoscProbkowania, double cena)
	: PrzyrzadPomiarowy(osobawp,typ, nazwa, kanaly, dostepnosc), maxCzestotliwoscProbkowania(maxCzestotliwoscProbkowania), Cena(cena) {}

void Oscyloskop::wyswietlInformacje()const {
	PrzyrzadPomiarowy::wyswietlInformacje();
	std::cout << "Maksymalna czestotliwosc probkowania: " << maxCzestotliwoscProbkowania << std::endl;
	std::cout << "Cena: " << Cena << std::endl;}

std::string Oscyloskop::zapisz_do_pliku() const {
	std::ostringstream oss;
    oss<<PrzyrzadPomiarowy::zapisz_do_pliku();
	oss << "Maksymalna czêstotliwoœæ próbkowania: " << maxCzestotliwoscProbkowania << "\n";
	oss << "Cena: " << Cena << "\n";
	return oss.str();
}

Oscyloskop::~Oscyloskop(){}


Generator::Generator(const std::string osobawp, const std::string& typ, const std::string& nazwa, int kanaly, bool dostepnosc, double maxCzestotliwoscSygnalu, double cena)
	: PrzyrzadPomiarowy(osobawp,typ, nazwa, kanaly, dostepnosc), MaxCzestosliwoscSygnalu(maxCzestotliwoscSygnalu), Cena(cena) {}

void Generator::wyswietlInformacje()const{
	PrzyrzadPomiarowy::wyswietlInformacje();
	std::cout << "Maksymalna czestotliwosc sygnalu: " << MaxCzestosliwoscSygnalu << std::endl;
	std::cout << "Cena: " << Cena << std::endl;}

std::string Generator::zapisz_do_pliku() const {
	std::ostringstream oss;
	oss<<PrzyrzadPomiarowy::zapisz_do_pliku();
	oss << "Maksymalna czestotliwosc sygnalu: " << MaxCzestosliwoscSygnalu << "\n";
	oss << "Cena: " << Cena << "\n";
	return oss.str();
}

Generator::~Generator(){}
